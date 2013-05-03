#include "modelManager.h"
#include "Utils/util.h"
#include "Objects/object3DFile.h"
#include "Objects/absObject3D.h"
#include <assimp/DefaultLogger.hpp>
#include <assimp/Logger.hpp>
#include <Log/assimpLog.h>

#include <QDir>
#include <QDebug>
#include <QTime>

ModelManager * ModelManager::_p_modelManager = NULL;

ModelManager::ModelManager()
{
}
ModelManager::~ModelManager()
{
}

ModelManager * ModelManager::getModelManager(){
    if( !_p_modelManager ) {
        _p_modelManager = new ModelManager();
    }

    return _p_modelManager;
}

/*-------------------------------------------------------------------
 |  Function setFolderToLoad
 |
 |  Purpose: Set the folder and filters to load models
 |  Parameters: QString folderPath: Path to the folder that contains models, relative to current project
 |              QStringList modelFilters: Filter extension for loading models
 |              QStringList textureFilters: Filter exentsion for loading textures
 |  Returns:
 *-------------------------------------------------------------------*/
void ModelManager::setFolderToLoad(QString folderPath, QStringList modelFilters, QStringList textureFilters){
    _folderPath = folderPath;
    _modelFilters = modelFilters;
    _textureFilters = textureFilters;
}


void ModelManager::loadModels(){
    QString fullFolderPath = (QDir::currentPath() + _folderPath); //Full path to the model folder
    QDir modelsDir(fullFolderPath); //Directory of models
    QStringList modelsList; //List of model filenames
    map<QString, GLuint> textureMap; //Texture map (TextureName -> TextureBindId)
    int loadTexturesTime;
    int loadModelsTime;

    ilInit(); /* Initialization of DevIL texture loader */

    QTime myTimer;
    myTimer.start();

    // ***********************  ASSIMP LOGGER ***********************
    // Create a logger instance
    Assimp::DefaultLogger::create("",Assimp::Logger::VERBOSE);
    // Now I am ready for logging my stuff
    Assimp::DefaultLogger::get()->info("this is my info-call");

    const unsigned int severity = Assimp::Logger::Err|Assimp::Logger::Info|Assimp::Logger::Err|Assimp::Logger::Warn | Assimp::Logger::Debugging | Assimp::Logger::Info | Assimp::Logger::VERBOSE;
    // Attaching it to the default logger
    Assimp::DefaultLogger::get()->attachStream( new AssimpLog(), severity);


    //*********************** TEXTURE PRELOADING **************************
    textureMap = loadTextures(fullFolderPath, _textureFilters); //Preload all textures of all models
    loadTexturesTime = myTimer.elapsed();


    //*********************** MODEL LOADING **************************
    modelsList = modelsDir.entryList(_modelFilters, QDir::Files); //List all models of the directory


    unsigned int i;
#pragma omp parallel for private(i) firstprivate(fullFolderPath) shared(modelsList, textureMap) default(none)
    for(i=0; i < modelsList.size(); i++){ //Load all models
        QString modelName = modelsList[i];
        qDebug() << "CARGANDO MODELO" << modelName;
        unsigned int assimpFlags = aiProcess_ValidateDataStructure| aiProcess_FlipUVs;
        if(modelName.startsWith("_")){
            assimpFlags = aiProcess_OptimizeMeshes |aiProcess_ValidateDataStructure| aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_TransformUVCoords | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph;
        }
        Object3DFile *object3D = new Object3DFile(fullFolderPath, modelName, &textureMap, assimpFlags, false);
        _models[modelName] = object3D;
    }
    loadModelsTime = myTimer.elapsed() - loadTexturesTime;


    //Bind all textures and render models
    for(std::map<QString,Object3DFile*>::iterator i = _models.begin(); i != _models.end(); i++){
        Object3DFile *object3D = i->second;
        qDebug() << "************************************RENDER******************************************* " << object3D->getName();
        object3D->render();
        object3D->release();
    }

    qDebug() << "Total en cargar texturas " << loadTexturesTime;
    qDebug() << "Total en cargar modelos " << loadModelsTime;

    qDebug() << "Ha tardado en cargar total: " << myTimer.elapsed();
}

/*-------------------------------------------------------------------
 |  Function loadTextures
 |
 |  Purpose: Load textures and generate a map between names and IL identifiers
 |  Parameters[in]: QString folderName : Full path name to the folder, QString filter : Texture file extension, for example "*.dds"
 |  Returns:
 *-------------------------------------------------------------------*/
map<QString, GLuint> ModelManager::loadTextures(QString folderName, QStringList filters){
    QDir myDir(folderName);
    QStringList list;
    QString textureName;
    QString fullTexturePath;
    map<QString, GLuint> textureIdMap;
    ILuint imageId;
    GLuint textureId;
    bool success;

    list = myDir.entryList(filters, QDir::Files); //List files in directory



    for(int i = 0; i < list.size(); i++){
        textureName = list[i];
        fullTexturePath = folderName + textureName;
        ilGenImages(1, &imageId); // Grab a new image name.(DEVIL)
        success = ilLoadImage(fullTexturePath.toAscii());

        if(success){
            ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);
            if(success){
                glGenTextures(1,&textureId); //Generate texture ID (OPENGL)
                glBindTexture(GL_TEXTURE_2D, textureId); //Bind the texture
                textureIdMap[fullTexturePath] = textureId; //Save textureId to the map

                //Set texture parameteres
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR ); //MIMAP LINEAR IS NOT VALID FOR MAG FILTER!
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

                GLfloat fLargest;
                glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);
                glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest ); //Applies maximum aviable anisotropy for better texture quality on distance when using mipmaps

                glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);   //Requires GL 1.4. Removed from GL 3.1 and above. //Generate Mipmap for different quality on distance movement

                glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
                             ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
                             ilGetData()); //Load texture to OPEN GL memory
                ilBindImage(imageId);
                ilDeleteImage(imageId);
                //qDebug() << "CORRECTO " << textureName;
            }
            else{
                qDebug() << "ERROR WHILE TRANSFORMING TEXTURE TO OPENGL "  << textureName;
            }
        }else{
            qDebug() << "ERROR AL CARGAR LA TEXTURA" << textureName;
        }
    }
    return textureIdMap;
}

/*-------------------------------------------------------------------
 |  Function getModel
 |
 |  Purpose: Getter. Gets the model with the specified filename
 |  Parameters: string modelName : The name of the file of the model
 *-------------------------------------------------------------------*/
Object3DFile * ModelManager::getModel(QString modelName){
    return _models[modelName];
}
