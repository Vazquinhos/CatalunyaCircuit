#include "modelManager.h"
#include "Utils/util.h"
#include "Objects/model3D.h"
#include <assimp/DefaultLogger.hpp>
#include <assimp/Logger.hpp>
#include <Log/assimpLog.h>
#include <QMutex>


#include <QDir>
#include <QDebug>
#include <QTime>

ModelManager * ModelManager::_p_modelManager = NULL;

/**************************************************** PUBLIC ***************************************************************/

/*-------------------------------------------------------------------
 |  Function ModelManager()
 |  Purpose: Creator.
 *-------------------------------------------------------------------*/
ModelManager::ModelManager()
{
    _p_mutex = new QMutex();
}

/*-------------------------------------------------------------------
 |  Function ModelManager()
 |  Purpose: Destructor.
 *-------------------------------------------------------------------*/
ModelManager::~ModelManager()
{
}

/*-------------------------------------------------------------------
 |  Function getModelManager()
 |  Purpose: Gets singleton MeshInstance of the object.
 |  Returns: ModelManager manager :The singleton MeshInstance.
 *-------------------------------------------------------------------*/
ModelManager * ModelManager::getModelManager(){
    if( !_p_modelManager ) {
        _p_modelManager = new ModelManager();
    }

    return _p_modelManager;
}

/*-------------------------------------------------------------------
 |  Function setFolderToLoad
 |  Purpose: Set the folder and filters to load models
 |  Parameters: QString folderPath: Path to the folder that contains models, relative to current project
 |              QStringList modelFilters: Filter extension for loading models
 |              QStringList textureFilters: Filter exentsion for loading textures
 *-------------------------------------------------------------------*/
void ModelManager::setFolderToLoad(QString folderPath, QStringList modelFilters, QStringList textureFilters){
    _folderPath = folderPath;
    _modelFilters = modelFilters;
    _textureFilters = textureFilters;
}

/*-------------------------------------------------------------------
 |  Function getModel
 |
 |  Purpose: Getter. Gets the model with the specified filename
 |  Parameters: string modelName : The name of the file of the model
 *-------------------------------------------------------------------*/
Model3D*  ModelManager::getModel(QString modelName){
    //_p_mutex->lock();
    return _models[modelName];
    // _p_mutex->unlock();
}

/*-------------------------------------------------------------------
 |  Function getPyisicsObject
 |
 |  Purpose: Getter. Gets the model with the specified filename
 |  Parameters: string modelName : The name of the file of the model
 *-------------------------------------------------------------------*/
PhysicsObject3D * ModelManager::getPyisicsObject(QString modelName, btTransform transform){
    return new PhysicsObject3D(_models[modelName], transform);
}


/*-------------------------------------------------------------------
 |  Function loadModels()
 |  Purpose: Load all models. All folder information must be set properly before calling this method
 *-------------------------------------------------------------------*/
void ModelManager::loadModels(){
    QString fullFolderPath = (QDir::currentPath() + _folderPath); //Full path to the model folder
    QStringList modelsList; //List of model filenames
    map<QString, GLuint> textureMap; //Texture map (TextureName -> TextureBindId)

    ilInit(); /* Initialization of DevIL texture loader */

    //Assimp logger

    /*
    // Create a logger MeshInstance
    Assimp::DefaultLogger::create("",Assimp::Logger::VERBOSE);
    // Now I am ready for logging my stuff
    Assimp::DefaultLogger::get()->info("this is my info-call");

    const unsigned int severity = Assimp::Logger::Err|Assimp::Logger::Info|Assimp::Logger::Err|Assimp::Logger::Warn | Assimp::Logger::Debugging | Assimp::Logger::Info | Assimp::Logger::VERBOSE;
    // Attaching it to the default logger
    Assimp::DefaultLogger::get()->attachStream( new AssimpLog(), severity);
    */

    //Texture preoloading
    textureMap = loadTextures(fullFolderPath, _textureFilters); //Preload all textures of all models

    //Model loading
    modelsList = listFilesInFolder(fullFolderPath, _modelFilters); //List all models of the directory


    int i;
    int size = modelsList.size();
    int progress = 47/size;
#pragma omp parallel for private(i) firstprivate(fullFolderPath, size) shared(modelsList, textureMap, progress) default(none)
    for(i=0; i < size; i++){ //Load all models
        QString modelName = modelsList[i];
        unsigned int assimpFlags = aiProcess_JoinIdenticalVertices | aiProcess_SortByPType | aiProcess_Triangulate | aiProcess_SplitLargeMeshes| aiProcess_FindInstances | aiProcess_RemoveRedundantMaterials | aiProcess_OptimizeMeshes | aiProcess_ImproveCacheLocality| aiProcess_FlipUVs;
        if(modelName.contains("Ferrari") || modelName.contains("Hrt")){
            assimpFlags = aiProcess_TransformUVCoords | aiProcess_JoinIdenticalVertices |aiProcess_SortByPType | aiProcess_Triangulate | aiProcess_SplitLargeMeshes| aiProcess_FindInstances | aiProcess_RemoveRedundantMaterials | aiProcess_OptimizeMeshes | aiProcess_ImproveCacheLocality;
        }
        QString model = QString("Loading model: ") + modelName;
        progress++;
        emit NewModel( model, progress);

        Model3D *object3D = new Model3D(fullFolderPath + modelName.left(modelName.lastIndexOf("/")+1), modelName.right(modelName.size() - modelName.lastIndexOf("/")), &textureMap, assimpFlags);
        _models[modelName] = object3D;
    }

    emit finish();
}


void ModelManager::render(){
    //Bind all textures and render models
    for(std::map<QString,Model3D*>::iterator i = _models.begin(); i != _models.end(); i++){
        Model3D *object3D = i->second;
        object3D->render();
        object3D->release();
    }
}
/**************************************************** PRIVATE ***************************************************************/

/*-------------------------------------------------------------------
 |  Function listFilesInFolder
 |  Purpose: Get all files of a folder and its subfolders recursively
 |  Parameters: QString fullFolderPath: Full path to the initial folder to scan
 |              QStringList fileFilters: File filters ex ".3ds"
 |  Returns: A list containing a path to the files without including fullFolderPath
 *-------------------------------------------------------------------*/
QStringList ModelManager::listFilesInFolder(QString fullFolderPath, QStringList fileFilters){
    QDir modelsDir(fullFolderPath);
    QStringList folderFilter;
    folderFilter <<"*";
    QStringList fileList = modelsDir.entryList(fileFilters, QDir::Files); //List all models of the directory;
    QStringList folderList = modelsDir.entryList(folderFilter, QDir::Dirs); //List all models of the directory
    QStringList fileListFolder;
    QString path;

    for(int i = 2; i < folderList.size(); i++){ //Starting at 2 avoiding back folders /. and /..
        path = (fullFolderPath + folderList[i] + "/");
        fileListFolder = listFilesInFolder(path, fileFilters);

        for(int j = 0; j < fileListFolder.size(); j++){
            fileList.push_back(folderList[i] + "/" + fileListFolder[j]);
        }
    }
    return fileList;
}

/*-------------------------------------------------------------------
 |  Function loadTextures
 |
 |  Purpose: Load textures and generate a map between names and IL identifiers
 |  Parameters[in]: QString folderName : Full path name to the folder, QString filter : Texture file extension, for example "*.dds"
 |  Returns:
 *-------------------------------------------------------------------*/
map<QString, GLuint> ModelManager::loadTextures(QString folderName, QStringList filters){
    QStringList list;
    QString textureName;
    QString fullTexturePath;
    map<QString, GLuint> textureIdMap;
    ILuint imageId;
    GLuint textureId;
    bool success;

    list = listFilesInFolder(folderName, filters);

    int size = list.size();
    for(int i = 0; i < size; i++){
        textureName = list[i];
        fullTexturePath = folderName + textureName;

        QString model = QString("Loading texture: ") + textureName;
        emit NewModel( model, i*47/size);

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
            }
            else{
                qDebug() << "ERROR WHILE TRANSFORMING TEXTURE TO OPENGL "  << fullTexturePath;
            }
        }else{
            //qDebug() << "ERROR AL CARGAR LA TEXTURA" << fullTexturePath;
        }
    }
    return textureIdMap;
}
