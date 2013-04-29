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

#include <omp.h>


/******************************* PUBLIC *****************************************/

/*-------------------------------------------------------------------
 |  Function Object3DFile
 |
 |  Purpose: Creator. Default creator
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Object3DFile::Object3DFile() {
}

/*-------------------------------------------------------------------
 |  Function Object3DFile
 |
 |  Purpose: Creator. Loads a supported 3D object from the specified directory and filename
 |  Parameters: const char* directory = Directory of the file to load
 |              const char* filename  = Name of the file to load
 |  Returns:
 *-------------------------------------------------------------------*/
Object3DFile::Object3DFile(QString directory, QString filename, map<QString, GLuint> *textureIdMap, unsigned int assimpFlags, bool isMovable){
    setName(filename);
    setMovable(isMovable);
    _baseDirectory = directory;
    _filename = filename;
    loadFromFile(textureIdMap, assimpFlags);
}

/*-------------------------------------------------------------------
 |  Function Object3DFile
 |
 |  Purpose: Destructor. Default destructor, cleans all needed memory by this class.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Object3DFile::~Object3DFile() {
}

/*-------------------------------------------------------------------
 |  Function loadFromFile
 |
 |  Purpose: Loads object 3D from the specified path in constructor
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
bool Object3DFile::loadFromFile(map<QString, GLuint> *textureIdMap, unsigned int assimpFlags){

    bool loadedSuccesful = false;

    QString path = _baseDirectory + _filename; //Current relative project path

    const aiScene* pScene = _importer.ReadFile(path.toStdString(), assimpFlags);

    if (!pScene) {
        qDebug() << "Error before loading: " << _importer.GetErrorString();
    }else{
        loadMaterials(pScene, textureIdMap);
    }

    return loadedSuccesful;
}

/*-------------------------------------------------------------------
|  Function renderizeObject
|
|  Purpose: Renderizes the object by calling all buffer arrays of all meshes.
|  Parameters:
|  Returns:
*-------------------------------------------------------------------*/
void Object3DFile::render() {
    const aiScene *scene = _importer.GetScene();
    const aiNode *node = scene->mRootNode;
    generateObjectBuffers(scene);
    renderInstances(scene, node, node->mTransformation);
}

/******************************* PRIVATE *****************************************/

/*-------------------------------------------------------------------
|  Function generateObjectBuffers
|
|  Purpose: Generates all buffer arrays of all meshes by copying and parsing the needed info from the aiScene provided
|  Parameters: const aiScene* pScene = The assimp object info of the object
|  Returns:
*-------------------------------------------------------------------*/
bool Object3DFile::generateObjectBuffers(const aiScene* pScene)
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
        minX = maxX =  pPos->x;
        minY = maxY =  pPos->y;
        minZ = maxZ =  pPos->z;

        _vMeshes.reserve(numMeshes); //Resize meshes vector to copy all assimp imported meshes


        // Initialize the meshes in the scene one by one
        int i;
        for (i = 0 ; i < numMeshes ; i++) {
            aiMesh = pScene->mMeshes[i];
            Mesh *mesh = new Mesh();
            //Generate buffers for the mesh and copy data of the assimp importer
            mesh->materialIndex = aiMesh->mMaterialIndex;

            vector<float> verticesCoord;
            vector<float> normalsCoord;
            vector<float> texturesCoord;
            vector<unsigned int> indices;
            int size = aiMesh->mNumVertices*3;
            int sizeFaces =aiMesh->mNumFaces;

            verticesCoord.reserve(size);
            normalsCoord.reserve(size);
            texturesCoord.reserve(size);
            indices.reserve(sizeFaces);

            const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

            //Copy vertex, normals, textures positions data from the importer to be able to generate a buffer

            float minXmesh, minYmesh, minZmesh; //Max cooridnate vertex of the mesh
            float maxXmesh, maxYmesh, maxZmesh; //Min coordinate vertex of the mesh

            pPos      = &(aiMesh->mVertices[0]);
            minXmesh = maxXmesh =  pPos->x;
            minYmesh = maxYmesh =  pPos->y;
            minZmesh = maxZmesh =  pPos->z;

            unsigned int k;
            for (k = 0 ; k < aiMesh->mNumVertices ; k++) {
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

            //Copy face data from the importer to be able to generate a buffer
            int j;
            for (j = 0 ; j < sizeFaces ; j++) {
                const aiFace& Face = aiMesh->mFaces[j];
                indices.push_back(Face.mIndices[0]);
                indices.push_back(Face.mIndices[1]);
                indices.push_back(Face.mIndices[2]);
            }

            //Generate and initialize the buffers with the copied data from importer
            mesh->render(verticesCoord, texturesCoord, normalsCoord, indices, _vTextures);

            _vMeshes.push_back(mesh);
        }

        this->setMinVertex(new Point3D(minX, minY, minZ));
        this->setMaxVertex(new Point3D(maxX, maxY, maxZ));
        this->setCenter(new Point3D((minX + maxX)/ 2, (minY + maxY)/2, (minZ + maxZ)/2));

    }

    return true;
}


/*-------------------------------------------------------------------
|  Function loadMaterials
|
|  Purpose: Loads all materials of the given assimp Object by saving the bind id of every texture
|  Parameters:     const aiScene* pScene = The assimp object info to load its textures
|  Returns:
*-------------------------------------------------------------------*/
bool Object3DFile::loadMaterials(const aiScene* pScene, map<QString, GLuint> *textureIdMap)
{
    bool ret = true;
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
                //apply_material(pMaterial);
                qDebug() << "BIND TEXTURE CORRECT " << id << " " << FullPath;
            }
        }
        _vTextures.push_back(texture);
    }
    return ret;
}


/*-------------------------------------------------------------------
|  Function apply_material
|
|  Purpose: Applies special effects for a given material, for example plastic or light/reflection
|  Parameters:     const aiMaterial *mtl = The material to apply special effects
|  Returns:
*-------------------------------------------------------------------*/
void Object3DFile::apply_material(const aiMaterial *mtl)
{
    float c[4];

    GLenum fill_mode;
    int ret1, ret2;
    aiColor4D diffuse;
    aiColor4D specular;
    aiColor4D ambient;
    aiColor4D emission;
    float shininess, strength;
    int two_sided;
    int wireframe;
    unsigned int max;

    set_float4(c, 0.8f, 0.8f, 0.8f, 1.0f);
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse))
        color4_to_float4(&diffuse, c);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, c);

    set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_SPECULAR, &specular))
        color4_to_float4(&specular, c);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c);

    set_float4(c, 0.2f, 0.2f, 0.2f, 1.0f);
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_AMBIENT, &ambient))
        color4_to_float4(&ambient, c);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, c);

    set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_EMISSIVE, &emission))
        color4_to_float4(&emission, c);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, c);

    max = 1;
    ret1 = aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS, &shininess, &max);
    max = 1;
    ret2 = aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS_STRENGTH, &strength, &max);
    if((ret1 == AI_SUCCESS) && (ret2 == AI_SUCCESS))
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess * strength);
    else {
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0f);
        set_float4(c, 0.0f, 0.0f, 0.0f, 0.0f);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c);
    }

    max = 1;
    if(AI_SUCCESS == aiGetMaterialIntegerArray(mtl, AI_MATKEY_ENABLE_WIREFRAME, &wireframe, &max))
        fill_mode = wireframe ? GL_LINE : GL_FILL;
    else
        fill_mode = GL_FILL;
    glPolygonMode(GL_FRONT_AND_BACK, fill_mode);

    max = 1;
    if((AI_SUCCESS == aiGetMaterialIntegerArray(mtl, AI_MATKEY_TWOSIDED, &two_sided, &max)) && two_sided)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);

}

/*-------------------------------------------------------------------
|  Function set_float4
|
|  Purpose: Auxiliar. Puts given floats into the array
|  Parameters:     float f[4] = Array to put values into
                float a, float b, float c, float d = Values to put into the array
|  Returns:
*-------------------------------------------------------------------*/
void Object3DFile::set_float4(float f[4], float a, float b, float c, float d)
{
    f[0] = a;
    f[1] = b;
    f[2] = c;
    f[3] = d;
}

/*-------------------------------------------------------------------
|  Function color4_to_float4
|
|  Purpose: Auxiliar. Puts given color info into the specified array
|  Parameters:     const aiColor4D *c = The color to read its info
                float f[4] = The array to put info
|  Returns:
*-------------------------------------------------------------------*/
void Object3DFile::color4_to_float4(const aiColor4D *c, float f[4])
{
    f[0] = c->r;
    f[1] = c->g;
    f[2] = c->b;
    f[3] = c->a;
}

/*-------------------------------------------------------------------
|  Function release
|
|  Purpose: Clean memory allocated by assim importer
*-------------------------------------------------------------------*/
void Object3DFile::release(){
    _importer.FreeScene();
}

/*-------------------------------------------------------------------
|  Function checkVisibility
|
|  Purpose: Check de visibility of every mesh of the object
*-------------------------------------------------------------------*/
vector<GLuint> Object3DFile::checkVisibility(Point3D *pointCamera, int distance){
    vector<GLuint> displayLists;
    Instance *instance;

    (void) pointCamera;
    (void) distance;

    for(unsigned int i = 0; i < _vInstances.size(); i++){
        instance = _vInstances[i];
        displayLists.push_back(instance->_displayListId);
    }

    return displayLists;
}

/*-------------------------------------------------------------------
 |  Function display
 |
 |  Purpose: Call display list for display the object. If the object
 |   has been updated, render must be called
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void Object3DFile::display() {
    Instance *instance;
    for(unsigned int i = 0; i < _vInstances.size(); i++){
        instance = _vInstances[i];
        glPushMatrix();
        glCallList(instance->_displayListId); //Call display list for display the object
        glPopMatrix();
    }
}

/******************************* MESH *****************************************/

/*-------------------------------------------------------------------
|  Function Mesh
|
|  Purpose: Creator. Default creator that initializes all values to invalid ones
|  Parameters:
|  Returns:
*-------------------------------------------------------------------*/
Object3DFile::Mesh::Mesh()
{
    vertexBufferBindId = INVALID_OGL_VALUE; //Initialize values to invalid ones
    faceIndexBufferBindId = INVALID_OGL_VALUE;
    numIndices  = 0;
    materialIndex = INVALID_MATERIAL;
    _gi_displayListId = 0;
    _isVisible = true;
}


/*-------------------------------------------------------------------
|  Function checkVisibility
|
|  Purpose: Check de visibility of the mesh
*-------------------------------------------------------------------*/
/*
void Object3DFile::Mesh::checkVisibility(Point3D *pointCamera, int distance){
    Point3D *punto = new Point3D(_p_center->getX(), _p_center->getY(), _p_center->getZ() );
    int d = punto->getDistance(pointCamera);
    //qDebug() << "PUNTO MODELO " << punto->getX() << ":" << punto->getY() << ":" << punto->getZ() << " PUNTO CAMARA " << pointCamera->getX() << ":" << pointCamera->getY() << ":" << pointCamera->getZ() << "DISTANCIA" << d << " TOTAL " << distance;
    //qDebug() << "MIN " << _p_minVertex->getX() << " : " << _p_minVertex->getY() << " : " << _p_minVertex->getZ() << " MAX "<< _p_maxVertex->getX() << " : "<< _p_maxVertex->getY() << _p_maxVertex->getZ();
    if(d < distance){
        _isVisible = true;
    }else{
        _isVisible = false;
    }
}
*/

/*-------------------------------------------------------------------
|  Function ~Mesh
|
|  Purpose: Destructor. Default destructor that cleans memory and deletes all buffer bindings
|  Parameters:
|  Returns:
*-------------------------------------------------------------------*/
Object3DFile::Mesh::~Mesh()
{
    if (vertexBufferBindId != INVALID_OGL_VALUE) //Clean buffers
    {
        glDeleteBuffers(1, &vertexBufferBindId);
    }

    if (faceIndexBufferBindId != INVALID_OGL_VALUE)
    {
        glDeleteBuffers(1, &faceIndexBufferBindId);
    }
}

/*-------------------------------------------------------------------
|  Function generateMeshBuffers
|
|  Purpose:     Generates all buffers of this mesh
|  Parameters:  const vector<float> &verticesCoord  = Vector with all vertex info to generate its buffer array buffer id
|               const vector<float> &texturesCoord  = Vector with all textures info to generate its buffer array buffer id
|               const vector<float> &normalsCoord   = Vector with all normals info to generate its buffer array buffer id
|               const vector<unsigned int> &indices = Vector with all face indexes info to generate its buffer array buffer id
|  Returns:
*-------------------------------------------------------------------*/
void Object3DFile::Mesh::render(const vector<float> &verticesCoord,
                                const vector<float> &texturesCoord, const vector<float> &normalsCoord, const vector<unsigned int> &indices, const vector<Texture *> &_vTextures)
{

    numIndices = indices.size();

    glGenBuffers(1, &vertexBufferBindId); //Generate buffer id for vertex
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferBindId); //Bind the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticesCoord.size(), &verticesCoord[0], GL_STATIC_DRAW); //Put position, normals, textures positions to buffer

    glGenBuffers(1, &texturesBufferBindId); //Generate buffer id for vertex
    glBindBuffer(GL_ARRAY_BUFFER, texturesBufferBindId); //Bind the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * texturesCoord.size(), &texturesCoord[0], GL_STATIC_DRAW);


    glGenBuffers(1, &normalsBufferBindId); //Generate buffer id for vertex
    glBindBuffer(GL_ARRAY_BUFFER, normalsBufferBindId); //Bind the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * normalsCoord.size(), &normalsCoord[0], GL_STATIC_DRAW);

    glGenBuffers(1, &faceIndexBufferBindId); //Generate buffer for face indexes
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, faceIndexBufferBindId); //Bind index buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * numIndices, &indices[0], GL_STATIC_DRAW); //Put mesh face indexes








    glEnableClientState(GL_VERTEX_ARRAY);           // Enable Vertex Arrays
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);	// Enable Texture Coord Arrays
    glEnableClientState(GL_NORMAL_ARRAY);           // Enable Normal Arrays


    if (glIsList(_gi_displayListId)) { //If we already have a display list, we delete it
        glDeleteLists(_gi_displayListId, 1);
    }
    _gi_displayListId = glGenLists(1); //Generate new display list identifier
    glNewList(_gi_displayListId, GL_COMPILE); //Starting rendering in memory



    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferBindId); //Bind vertex array of the mesh
    glVertexPointer( 3, GL_FLOAT, 0, 0); // Set The Vertex Pointer To Vertex Data

    glBindBuffer(GL_ARRAY_BUFFER, texturesBufferBindId); //Bind texture array of the mesh
    glTexCoordPointer(3, GL_FLOAT, 0, 0); // Set The Vertex Pointer To TexCoord Data

    glBindBuffer(GL_ARRAY_BUFFER, normalsBufferBindId); //Bind normal array of the mesh
    glNormalPointer(GL_FLOAT, sizeof(float)*3, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, faceIndexBufferBindId); //Bind integer array of the mesh with face indexes info

    const unsigned int MaterialIndex = materialIndex; //Bind texture of the mesh

    if (MaterialIndex < _vTextures.size() && _vTextures[materialIndex]) {
        glBindTexture(GL_TEXTURE_2D, _vTextures[MaterialIndex]->_textureBindId);
    }
    //glDrawElements(GL_TRIANGLES, mesh->numIndices, GL_UNSIGNED_INT, 0); //Renders the object deleting shared vertex between faces (IS SLOWER THAN glDrawArrays!!)
    glDrawArrays(GL_TRIANGLES, 0, numIndices);

    glEndList(); //Finish rendering in memory

    glDisableClientState(GL_VERTEX_ARRAY);          // Disable Vertex Arrays
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);	// Disable Texture Coord Arrays
    glDisableClientState(GL_NORMAL_ARRAY);          // Disable Normal Arrays
}



void Object3DFile::renderInstances(const aiScene* scene, const aiNode* node, aiMatrix4x4 transformation){

    Mesh *mesh;


    aiMatrix4x4 transform;


    transformation.Transpose();

    glPushMatrix();




    if(node->mNumMeshes > 0){
        Instance *instance = new Instance();
        instance->_displayListId = glGenLists(1); //Generate new display list identifier
        glNewList(instance->_displayListId, GL_COMPILE); //Starting rendering in memory


        glMultMatrixf((float*)&transformation);

        for(unsigned int i = 0; i < node->mNumMeshes ; i++){
            mesh = _vMeshes[node->mMeshes[i]];
            glCallList(mesh->_gi_displayListId);
        }

         glEndList(); //Finish rendering in memory
          _vInstances.push_back(instance);

    }else{
        transform = node->mTransformation * transformation;
    }







    for (unsigned int i = 0; i < node->mNumChildren; ++i)
    {
        qDebug() << "INSTANCIA" << node->mChildren[i]->mName.C_Str();
        renderInstances(scene, node->mChildren[i], transform);
    }





     glPopMatrix();



}

#endif /* OBJECT3DASSIMP_H_ */

