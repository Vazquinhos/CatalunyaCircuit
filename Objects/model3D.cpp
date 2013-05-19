/*
 * Archivo: Model3D.cpp
 * Fecha: 23/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *  Clase: Model3D
 * Descripcion: Clase que representa un objeto 3D de la escena. Carga un objeto desde fichero
 */

#ifndef OBJECT3DASSIMP_H_
#define OBJECT3DASSIMP_H_

#include "Objects/model3D.h"
#include "Utils/util.h"
#include <QFile>
#include <QDir>
#include <algorithm>

/******************************* PUBLIC *****************************************/

/*-------------------------------------------------------------------
 |  Function Model3D
 |  Purpose: Creator. Default creator
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Model3D::Model3D() {
}

/*-------------------------------------------------------------------
 |  Function Model3D
 |  Purpose: Destructor. Default destructor, cleans all needed memory by this class.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Model3D::~Model3D() {
}

/*-------------------------------------------------------------------
 |  Function Model3D
 |  Purpose: Creator. Loads a supported 3D object from the specified directory and filename
 |  Parameters: const char* directory = Directory of the file to load
 |              const char* filename  = Name of the file to load
 *-------------------------------------------------------------------*/
Model3D::Model3D(QString fullFolderPath, QString filename, unsigned int assimpFlags){
    setName(filename);
    _baseDirectory = fullFolderPath;
    _filename = filename;
    _isVisible = true;
    loadFromFile(assimpFlags);
}

// ============================ GETTER / SETTER ==============================


/*-------------------------------------------------------------------
 |  Function setVisibility
 |
 |  Purpose: Sets the visibility of the object
 |  Parameters: bool visibility : The visibility of the object
 *-------------------------------------------------------------------*/
void Model3D::setVisibility(bool visibility){
    _isVisible = visibility;
}

/*-------------------------------------------------------------------
 |  Function getVisibility
 |
 |  Purpose: gets the visibility of the object
 |  Returns: The boolean visibility of the object
 *-------------------------------------------------------------------*/
bool Model3D::getVisibility(){
    return _isVisible;
}

/*-------------------------------------------------------------------
 |  Function setName
 |
 |  Purpose: Sets the name of the object
 |  Parameters: string name : The name of the object
 *-------------------------------------------------------------------*/
void Model3D::setName(QString name){
    _filename = name;
}

/*-------------------------------------------------------------------
 |  Function getName
 |
 |  Purpose: gets the name of the object
 |  Returns: The string name of the object
 *-------------------------------------------------------------------*/
QString Model3D::getName(){
    return _filename;
}


/*-------------------------------------------------------------------
 |  Function getCenter
 |
 |  Purpose: Getter of the center
 |  Returns: The the center vertex of the object
 *-------------------------------------------------------------------*/
Point3D * Model3D::getCenter(){
    return _p_center;
}

/*-------------------------------------------------------------------
 |  Function setCenter
 |
 |  Purpose: Setter of the center
 |  Parameters: Point3D *center : The the center vertex of the object
 *-------------------------------------------------------------------*/
void Model3D::setCenter(Point3D *center){
    this->_p_center = center;
}

/*-------------------------------------------------------------------
 |  Function setTranslation
 |
 |  Purpose: Setter. Sets the translation of the object
 |  Parameters[in]: Point3D * translation = New translation of the object
 |  Returns:
 *-------------------------------------------------------------------*/
void Model3D::setTranslation(Point3D * translation)
{
    _p_translation = translation;
}

Point3D * Model3D::getTranslation()
{
    return _p_translation;
}

/*-------------------------------------------------------------------
 |  Function setRotation
 |
 |  Purpose: Setter. Sets the rotation of the object
 |  Parameters[in]: Point3D * rotation = New rotation of the object
 |  Returns:
 *-------------------------------------------------------------------*/
void Model3D::setRotation(Point3D * rotation)
{
    _p_rotation = rotation;
}

/*-------------------------------------------------------------------
 |  Function getRotation
 |
 |  Purpose: Getter. Gets the rotation of the object
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * Model3D::getRotation()
{
    return _p_rotation;
}

/*-------------------------------------------------------------------
 |  Function setScale
 |
 |  Purpose: Setter. Sets the  the object
 |  Parameters[in]: Point3D * scale = Sets the scale of the object
 |  Returns:
 *-------------------------------------------------------------------*/
void Model3D::setScale(Point3D * scale)
{
    _p_scale = scale;
}


/*-------------------------------------------------------------------
 |  Function getScale
 |
 |  Purpose: Getter. Gets the scale of  the object
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * Model3D::getScale()
{
    return _p_scale;
}

/*-------------------------------------------------------------------
 |  Function setMinVertex
 |
 |  Purpose: Setter. Sets the min vertex coordinates the object
 |  Parameters[in]: Point3D * minVertex = New min coordinates to set
 |  Returns:
 *-------------------------------------------------------------------*/
void Model3D::setMinVertex(Point3D * minVertex)
{
    _p_minVertex = minVertex;
}

/*-------------------------------------------------------------------
 |  Function getMinVertex
 |
 |  Purpose: Getter. Gets the min coordinates of the object
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * Model3D::getMinVertex()
{
    return _p_minVertex;
}

/*-------------------------------------------------------------------
 |  Function setMaxVertex
 |
 |  Purpose: Setter. Sets the max vertex coordinates the object
 |  Parameters[in]: Point3D * maxVertex = max vertex coordinates to set
 |  Returns:
 *-------------------------------------------------------------------*/
void Model3D::setMaxVertex(Point3D * maxVertex)
{
    _p_maxVertex = maxVertex;
}

/*-------------------------------------------------------------------
 |  Function getMaxVertex
 |
 |  Purpose: Getter. Gets the max vertex coordinates of the object
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * Model3D::getMaxVertex()
{
    return _p_maxVertex;
}



// ============================================================================
// ============================ IMPORTER METHODS ==============================
// ============================================================================

/*-------------------------------------------------------------------
 |  Function loadFromFile
 |  Purpose: Loads object 3D from the specified path in constructor
 |  Parameters: map<QString, GLuint> *textureIdMap: Map of textures <Path, bindId>
 |              unsigned int assimpFlags: Assimp flags for optimization process
 *-------------------------------------------------------------------*/
bool Model3D::loadFromFile(unsigned int assimpFlags){
    bool loadedSuccesful = false;
    QString path = _baseDirectory + _filename; //Current relative project path
    const aiScene* pScene = _importer.ReadFile(path.toStdString(), assimpFlags); //Loads and optmizes object

    if (!pScene) {
        qDebug() << "Error before loading: " << _importer.GetErrorString();
    }else{
        loadedSuccesful = true;
    }
    return loadedSuccesful;
}

/*-------------------------------------------------------------------
|  Function render()
|  Purpose: Renderizes the object by calling all buffer arrays of all meshes. Generates a display list for every mesh and MeshInstance
*-------------------------------------------------------------------*/
void Model3D::render(map<QString, GLuint> *textureIdMap) {
    const aiScene *scene = _importer.GetScene();
    const aiNode *node = scene->mRootNode;

     mapMaterials(scene, textureIdMap);

    generateObjectBuffers(scene);

    renderMeshInstances(node);
}

/*-------------------------------------------------------------------
|  Function loadMaterials
|  Purpose: Loads all materials of the given assimp Object by saving the bind id of every texture
|  Parameters:     const aiScene* pScene = The assimp object info to load its textures
*-------------------------------------------------------------------*/
void Model3D::mapMaterials(const aiScene* pScene, map<QString, GLuint> *textureIdMap)
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
void Model3D::release(){
    _importer.FreeScene();
}

/*-------------------------------------------------------------------
|  Function checkVisibility
|  Purpose: Check de visibility of every mesh of the object
|  Returns: A vector with display lists of all visible objects
*-------------------------------------------------------------------*/
void Model3D::checkVisibility(vector<GLuint> *displayLists){
    MeshInstance *meshInstance;

    //CameraAbs *camera =  CameraManager::getCameraManager()->getCamera("free");
    //qDebug() << "HOLA";
    //Vector3D vCamera = (camera->getPointToLook()->getVector(camera->getPosition()));
    //Vector3D vObject;
    //qDebug() << "HOLA2";

    for(unsigned int i=0; i < _vMeshInstances.size(); i++){
        meshInstance = _vMeshInstances[i];
        //vObject =  meshInstance->getCenter()->getVector(camera->getPosition());


        //qDebug() << "V1 " <<  vCamera.getX() << " " << vCamera.getY() << " " << vCamera.getZ();
        //qDebug() << "V2 " <<  vObject.getX() << " " << vObject.getY() << " " << vObject.getZ();

        //qDebug() << "ANGULO " <<  vCamera.angle(vObject);
        //if(vCamera.angle(vObject) < 1.570795){ // 90 degree
            displayLists->push_back(meshInstance->getDisplayList());
            _isVisible = true;
        //}else{
          //  _isVisible = false;
        //}
    }
}

/*-------------------------------------------------------------------
 |  Function display
 |  Purpose: Call display list for display the object. If the object
 |           has been updated, render must be called
 *-------------------------------------------------------------------*/
void Model3D::display() {
    for(unsigned int i=0; i < _vMeshInstances.size(); i++){
        glCallList(_vMeshInstances[i]->getDisplayList());
    }
}

/******************************* PRIVATE *****************************************/

/*-------------------------------------------------------------------
|  Function generateObjectBuffers
|  Purpose: Generates all buffer arrays of all meshes by copying and parsing the needed info from the aiScene provided
|  Parameters: const aiScene* pScene = The assimp object info of the object
*-------------------------------------------------------------------*/
void Model3D::generateObjectBuffers(const aiScene* pScene)
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
void Model3D::renderNode(const aiNode* node){
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

        aiVector3D center = aiVector3D(mesh->_p_center->getX(), mesh->_p_center->getY(), mesh->_p_center->getZ());
        center = node->mTransformation*center;

        aiVector3D min = aiVector3D(mesh->_p_minVertex->getX(), mesh->_p_minVertex->getY(), mesh->_p_minVertex->getZ());
        min = node->mTransformation*center;

        aiVector3D max = aiVector3D(mesh->_p_maxVertex->getX(), mesh->_p_maxVertex->getY(), mesh->_p_maxVertex->getZ());
        max = node->mTransformation*center;

        _vMeshInstances.push_back(new MeshInstance(new Point3D(min.x, min.y, min.z), new Point3D(max.x, max.y, max.z), new Point3D(center.x, center.y, center.z), displayList));
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


            aiVector3D center = aiVector3D(mesh->_p_center->getX(), mesh->_p_center->getY(), mesh->_p_center->getZ());
            center = node->mTransformation*center;

            aiVector3D min = aiVector3D(mesh->_p_minVertex->getX(), mesh->_p_minVertex->getY(), mesh->_p_minVertex->getZ());
            min = node->mTransformation*center;

            aiVector3D max = aiVector3D(mesh->_p_maxVertex->getX(), mesh->_p_maxVertex->getY(), mesh->_p_maxVertex->getZ());
            max = node->mTransformation*center;

            _vMeshInstances.push_back(new MeshInstance(new Point3D(min.x, min.y, min.z), new Point3D(max.x, max.y, max.z), new Point3D(center.x, center.y, center.z), displayList));
        }


    }


}

/*-------------------------------------------------------------------
|  Function renderMeshInstances
|
|  Purpose:     Render MeshInstances of all object
|  Parameters:  const aiScene* scene: Assimp scene that contains all model info
|               const aiNode* node: node that will be rendered
*-------------------------------------------------------------------*/
void Model3D::renderMeshInstances(const aiNode* node){
    const aiNode *child;
    const aiNode* lastObject;
    Mesh *mesh;
    GLuint displayList;
    //Here we are in the root node that does not contain any mesh, and its transformation is not applied

    for(unsigned int i = 0; i < node->mNumChildren; i++){
        child = node->mChildren[i];

        if(child->mNumChildren > 0){ //If the node has children, it is a "root MeshInstance" that we will keep as lastObject rendered
            renderNode(child); //Also we render this "root MeshInstance"
            lastObject = child;
        }else if(child->mNumMeshes > 0){ //If it has meshes, it won't have any MeshInstances
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

                    aiVector3D center = aiVector3D(mesh->_p_center->getX(), mesh->_p_center->getY(), mesh->_p_center->getZ());
                    center = node->mChildren[i]->mTransformation*center;

                    aiVector3D min = aiVector3D(mesh->_p_minVertex->getX(), mesh->_p_minVertex->getY(), mesh->_p_minVertex->getZ());
                    min = node->mChildren[i]->mTransformation*center;

                    aiVector3D max = aiVector3D(mesh->_p_maxVertex->getX(), mesh->_p_maxVertex->getY(), mesh->_p_maxVertex->getZ());
                    max = node->mChildren[i]->mTransformation*center;

                    _vMeshInstances.push_back(new MeshInstance(new Point3D(min.x, min.y, min.z), new Point3D(max.x, max.y, max.z), new Point3D(center.x, center.y, center.z), displayList));
                }
            }

        }
    }
}

btCompoundShape* Model3D::getCollisionShape(btTransform transform){
    btCompoundShape *shape = new btCompoundShape();
    Mesh *mesh;

    for(unsigned int i = 0; i < _vMeshes.size(); i++){
        mesh = _vMeshes[i];
        shape->addChildShape(transform, mesh->collisionShape);
    }

    return shape;
}

#endif /* OBJECT3DASSIMP_H_ */
