/*
 * Archivo: object3DFile.cpp
 * Fecha: 23/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *  Clase: Object3DFile
 * Descripcion: Clase que representa un objeto 3D de la escena. Carga un objeto desde fichero
 */

#ifndef OBJECT3DASSIMP_H_
#define OBJECT3DASSIMP_H_

#include "object3DFile.h"
#include "Utils/util.h"
#include <QFile>
#include <QDir>
#include <algorithm>

/******************************* PUBLIC *****************************************/

/*-------------------------------------------------------------------
 |  Function Object3DFile
 |  Purpose: Creator. Default creator
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Object3DFile::Object3DFile() {
}

/*-------------------------------------------------------------------
 |  Function Object3DFile
 |  Purpose: Destructor. Default destructor, cleans all needed memory by this class.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Object3DFile::~Object3DFile() {
}

/*-------------------------------------------------------------------
 |  Function Object3DFile
 |  Purpose: Creator. Loads a supported 3D object from the specified directory and filename
 |  Parameters: const char* directory = Directory of the file to load
 |              const char* filename  = Name of the file to load
 *-------------------------------------------------------------------*/
Object3DFile::Object3DFile(QString fullFolderPath, QString filename, map<QString, GLuint> *textureIdMap, unsigned int assimpFlags){
    setName(filename);
    _baseDirectory = fullFolderPath;
    _filename = filename;
    _isVisible = true;
    loadFromFile(textureIdMap, assimpFlags);
}

bool Object3DFile::isVisible(){
    return _isVisible;
}
/*-------------------------------------------------------------------
 |  Function loadFromFile
 |  Purpose: Loads object 3D from the specified path in constructor
 |  Parameters: map<QString, GLuint> *textureIdMap: Map of textures <Path, bindId>
 |              unsigned int assimpFlags: Assimp flags for optimization process
 *-------------------------------------------------------------------*/
bool Object3DFile::loadFromFile(map<QString, GLuint> *textureIdMap, unsigned int assimpFlags){
    bool loadedSuccesful = false;
    QString path = _baseDirectory + _filename; //Current relative project path
    const aiScene* pScene = _importer.ReadFile(path.toStdString(), assimpFlags); //Loads and optmizes object

    if (!pScene) {
        qDebug() << "Error before loading: " << _importer.GetErrorString();
    }else{
        loadedSuccesful = true;
        mapMaterials(pScene, textureIdMap);
    }
    return loadedSuccesful;
}

/*-------------------------------------------------------------------
|  Function render()
|  Purpose: Renderizes the object by calling all buffer arrays of all meshes. Generates a display list for every mesh and instance
*-------------------------------------------------------------------*/
void Object3DFile::render() {
    const aiScene *scene = _importer.GetScene();
    const aiNode *node = scene->mRootNode;
    generateObjectBuffers(scene);

    renderInstances(node);
}

/*-------------------------------------------------------------------
|  Function loadMaterials
|  Purpose: Loads all materials of the given assimp Object by saving the bind id of every texture
|  Parameters:     const aiScene* pScene = The assimp object info to load its textures
*-------------------------------------------------------------------*/
void Object3DFile::mapMaterials(const aiScene* pScene, map<QString, GLuint> *textureIdMap)
{
    Texture *texture;
    _vTextures.reserve(pScene->mNumMaterials); //Resize textures vector to copy all assimp imported meshes
    // Initialize the materials
    for (unsigned int i = 0 ; i < pScene->mNumMaterials ; i++) {
        const aiMaterial* pMaterial = pScene->mMaterials[i];
        GLuint id;

        if (pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0) {
            aiString Path;

            if (pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &Path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS) {
                QString FullPath = _baseDirectory + Path.data;
                texture = new Texture();

                id = (*textureIdMap)[FullPath];
                texture->_textureBindId = id;
            }
        }
        _vTextures.push_back(texture);
    }
}

/*-------------------------------------------------------------------
|  Function release
|  Purpose: Clean memory allocated by assim importer
*-------------------------------------------------------------------*/
void Object3DFile::release(){
    _importer.FreeScene();
}

/*-------------------------------------------------------------------
|  Function checkVisibility
|  Purpose: Check de visibility of every mesh of the object
*-------------------------------------------------------------------*/
vector<GLuint> Object3DFile::checkVisibility(Point3D *pointCamera, int distance){
    vector<GLuint> displayLists;
    Point3D *punto;
    Instance *instance;
    int d;

    for(unsigned int i=0; i < _vInstances.size(); i++){
        instance = _vInstances[i];
        punto = instance->getCenter();
        d = punto->getDistance(pointCamera);
        //if(d < distance){
            displayLists.push_back(instance->getDisplayList());
            _isVisible = true;
        //}else{
          //  _isVisible = false;
        //}
        //qDebug() << "PUNTO MODELO " << punto->getX() << ":" << punto->getY() << ":" << punto->getZ() << " PUNTO CAMARA " << pointCamera->getX() << ":" << pointCamera->getY() << ":" << pointCamera->getZ() << "DISTANCIA" << d << " TOTAL " << distance;
        //qDebug() << "MIN " << _p_minVertex->getX() << " : " << _p_minVertex->getY() << " : " << _p_minVertex->getZ() << " MAX "<< _p_maxVertex->getX() << " : "<< _p_maxVertex->getY() << _p_maxVertex->getZ();
    }
    return displayLists;
}

/*-------------------------------------------------------------------
 |  Function display
 |  Purpose: Call display list for display the object. If the object
 |           has been updated, render must be called
 *-------------------------------------------------------------------*/
void Object3DFile::display() {
    for(unsigned int i=0; i < _vInstances.size(); i++){
        glCallList(_vInstances[i]->getDisplayList());
    }
}

/******************************* PRIVATE *****************************************/

/*-------------------------------------------------------------------
|  Function generateObjectBuffers
|  Purpose: Generates all buffer arrays of all meshes by copying and parsing the needed info from the aiScene provided
|  Parameters: const aiScene* pScene = The assimp object info of the object
*-------------------------------------------------------------------*/
void Object3DFile::generateObjectBuffers(const aiScene* pScene)
{
    float minX, minY, minZ; //Max cooridnate vertex of all model
    float maxX, maxY, maxZ; //Min coordinate vertex of all model
    int numMeshes = pScene->mNumMeshes;
    const aiMesh* aiMesh;
    const aiVector3D* pPos;
    const aiVector3D* pNormal;
    const aiVector3D* pTexCoord;

    if(numMeshes > 0){
        aiMesh = pScene->mMeshes[0];
        pPos      = &(aiMesh->mVertices[0]);
        minX = maxX =  pPos->x; //Initialize min and max at the first vertex of the first mesh of all model
        minY = maxY =  pPos->y;
        minZ = maxZ =  pPos->z;

        _vMeshes.reserve(numMeshes); //Resize meshes vector to copy all assimp imported meshes

        // Initialize the meshes in the scene one by one
        for (int i = 0 ; i < numMeshes ; i++) {
            aiMesh = pScene->mMeshes[i];
            Mesh *mesh = new Mesh();

            //Generate buffers for the mesh and copy data of the assimp importer
            mesh->_materialIndex = aiMesh->mMaterialIndex;

            vector<btScalar> verticesCoord; //Vectors for temporally store mesh data
            vector<float> normalsCoord;
            vector<float> texturesCoord;
            vector<int> indices;
            int size = aiMesh->mNumVertices*3;
            int sizeFaces =aiMesh->mNumFaces;

            verticesCoord.reserve(size); //Reserve memory for mesh data
            normalsCoord.reserve(size);
            texturesCoord.reserve(size);
            indices.reserve(sizeFaces);

            const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);
            //Copy vertex, normals, textures positions data from the importer to be able to generate a buffer
            float minXmesh, minYmesh, minZmesh; //Max cooridnate vertex of the mesh
            float maxXmesh, maxYmesh, maxZmesh; //Min coordinate vertex of the mesh

            pPos      = &(aiMesh->mVertices[0]);
            minXmesh = maxXmesh =  pPos->x; //Initialize min and max of the mesh at the first vertex of the mesh
            minYmesh = maxYmesh =  pPos->y;
            minZmesh = maxZmesh =  pPos->z;

            for (unsigned int k = 0 ; k < aiMesh->mNumVertices ; k++) {
                pPos      = &(aiMesh->mVertices[k]);
                pNormal   = &(aiMesh->mNormals[k]);
                pTexCoord = aiMesh->HasTextureCoords(0) ? &(aiMesh->mTextureCoords[0][k]) : &Zero3D;

                minX = min(minXmesh, pPos->x);
                maxX = max(maxXmesh, pPos->x);

                minY = min(minYmesh, pPos->y);
                maxY = max(maxYmesh, pPos->y);

                minZ = min(minZmesh, pPos->z);
                maxZ = max(maxZmesh, pPos->z);

                verticesCoord.push_back(pPos->x);
                verticesCoord.push_back(pPos->y);
                verticesCoord.push_back(pPos->z);
                normalsCoord.push_back(pNormal->x);
                normalsCoord.push_back(pNormal->y);
                normalsCoord.push_back(pNormal->z);
                texturesCoord.push_back(pTexCoord->x);
                texturesCoord.push_back(pTexCoord->y);
                texturesCoord.push_back(pTexCoord->z);
            }
            mesh->_p_minVertex = new Point3D(minXmesh, minYmesh, minZmesh);
            mesh->_p_maxVertex = new Point3D(maxXmesh, maxYmesh, maxZmesh);
            mesh->_p_center = new Point3D((minXmesh + maxXmesh) / 2 , (minYmesh + maxYmesh) / 2, (minZmesh + maxZmesh) / 2);

            minX = min(minX, minXmesh);
            maxX = max(maxX, maxXmesh);

            minY = min(minY, minYmesh);
            maxY = max(maxY, maxYmesh);

            minZ = min(minZ, minZmesh);
            maxZ = max(maxZ, maxZmesh);

            //Copy face data from the importer to be able to generate a buffer with indexed vertices (faces share vertex)
            for (int j = 0 ; j < sizeFaces ; j++) {
                const aiFace& Face = aiMesh->mFaces[j];
                indices.push_back(Face.mIndices[0]);
                indices.push_back(Face.mIndices[1]);
                indices.push_back(Face.mIndices[2]);
            }
            //Generate and initialize the buffers with the copied data from importer, renders every mesh
            mesh->render(pScene,&verticesCoord, &texturesCoord, &normalsCoord, &indices, &_vTextures);
            _vMeshes.push_back(mesh);
        }
        this->setMinVertex(new Point3D(minX, minY, minZ));
        this->setMaxVertex(new Point3D(maxX, maxY, maxZ));
        this->setCenter(new Point3D((minX + maxX)/ 2, (minY + maxY)/2, (minZ + maxZ)/2));
    }
}

/*-------------------------------------------------------------------
 |  Function renderNode
 |  Purpose: Recursively renders a node and all of its children
 |  Parameteres: const aiNode* node: Root node for rendering
 *-------------------------------------------------------------------*/
void Object3DFile::renderNode(const aiNode* node){
    Mesh *mesh;
    const aiNode *child;
    GLuint displayList;
    aiMatrix4x4 transform = node->mTransformation;
    transform.Transpose();



    for(unsigned int i = 0; i < node->mNumMeshes ; i++){
        mesh = _vMeshes[node->mMeshes[i]];
        displayList = glGenLists(1); //Generate new display list identifier
        glNewList(displayList, GL_COMPILE); //Starting rendering in memory

        glPushMatrix();
        glMultMatrixf((float*)&transform); //Apply transformation for the node
        glCallList(mesh->_gi_displayListId); //Node rendering
        glPopMatrix();
        glEndList();

        _vInstances.push_back(new Instance(mesh->_p_minVertex, mesh->_p_maxVertex, mesh->_p_center, displayList));
    }


    for(unsigned int i = 0; i < node->mNumChildren; i++){ //Recursively render its childs
        child = node->mChildren[i];


        for(unsigned int i = 0; i < child->mNumMeshes ; i++){
            mesh = _vMeshes[child->mMeshes[i]];

            displayList = glGenLists(1); //Generate new display list identifier
            glNewList(displayList, GL_COMPILE); //Starting rendering in memory
            glPushMatrix();
            glMultMatrixf((float*)&transform); //Apply transformation for the node
            glCallList(mesh->_gi_displayListId); //Node rendering
            glPopMatrix();
            glEndList();

            _vInstances.push_back(new Instance(mesh->_p_minVertex, mesh->_p_maxVertex, mesh->_p_center, displayList));
        }


    }


}

/*-------------------------------------------------------------------
|  Function renderInstances
|
|  Purpose:     Render instances of all object
|  Parameters:  const aiScene* scene: Assimp scene that contains all model info
|               const aiNode* node: node that will be rendered
*-------------------------------------------------------------------*/
void Object3DFile::renderInstances(const aiNode* node){
    const aiNode *child;
    const aiNode* lastObject;
    Mesh *mesh;
    GLuint displayList;
    //Here we are in the root node that does not contain any mesh, and its transformation is not applied

    for(unsigned int i = 0; i < node->mNumChildren; i++){
        child = node->mChildren[i];

        if(child->mNumChildren > 0){ //If the node has children, it is a "root instance" that we will keep as lastObject rendered
            renderNode(child); //Also we render this "root instance"
            lastObject = child;
        }else if(child->mNumMeshes > 0){ //If it has meshes, it won't have any instances
            renderNode(child);
        }else { //If it doesn't have any mesh or any child, it only has a transformation
            aiMatrix4x4 transform = child->mTransformation;
            transform.Transpose(); //Apply transformation



            for(unsigned int j = 0; j < lastObject->mNumChildren; j++){
                child = lastObject->mChildren[j];
                for(unsigned int k = 0; k < child->mNumMeshes ; k++){
                    mesh = _vMeshes[child->mMeshes[k]];
                    displayList = glGenLists(1); //Generate new display list identifier
                    glNewList(displayList, GL_COMPILE); //Starting rendering in memory

                    glPushMatrix();         //Render the childs of last succesfully rendered object
                    glMultMatrixf((float*)&transform);
                    glCallList(mesh->_gi_displayListId);
                    glPopMatrix();

                    glEndList();


                    _vInstances.push_back(new Instance(mesh->_p_minVertex, mesh->_p_maxVertex, mesh->_p_center, displayList));
                }
            }

        }
    }
}

btCompoundShape* Object3DFile::getCollisionShape(){
    btCompoundShape *shape = new btCompoundShape();
    btTransform transform;
    Mesh *mesh;

    for(unsigned int i = 0; i < _vMeshes.size(); i++){
        mesh = _vMeshes[i];
        shape->addChildShape(transform, mesh->collisionShape);
    }

    return shape;
}

#endif /* OBJECT3DASSIMP_H_ */
