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
void Object3DFile::renderizeObject() {
    Mesh *mesh;

    generateObjectBuffers(_importer.GetScene());

    glEnableClientState(GL_VERTEX_ARRAY);           // Enable Vertex Arrays
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);	// Enable Texture Coord Arrays
    glEnableClientState(GL_NORMAL_ARRAY);           // Enable Normal Arrays

    for (unsigned int i = 0 ; i < _vMeshes.size() ; i++) {
        mesh = _vMeshes[i];
        glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBufferBindId); //Bind vertex array of the mesh
        glVertexPointer( 3, GL_FLOAT, 0, 0); // Set The Vertex Pointer To Vertex Data

        glBindBuffer(GL_ARRAY_BUFFER, mesh->texturesBufferBindId); //Bind texture array of the mesh
        glTexCoordPointer(3, GL_FLOAT, 0, 0); // Set The Vertex Pointer To TexCoord Data

        glBindBuffer(GL_ARRAY_BUFFER, mesh->normalsBufferBindId); //Bind normal array of the mesh
        glNormalPointer(GL_FLOAT, sizeof(float)*3, 0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->faceIndexBufferBindId); //Bind integer array of the mesh with face indexes info

        const unsigned int MaterialIndex = mesh->materialIndex; //Bind texture of the mesh

        if (MaterialIndex < _vTextures.size() && _vTextures[MaterialIndex]) {
            glBindTexture(GL_TEXTURE_2D, _vTextures[MaterialIndex]->_textureBindId);
        }
        //glDrawElements(GL_TRIANGLES, mesh->numIndices, GL_UNSIGNED_INT, 0); //Renders the object deleting shared vertex between faces
        glDrawArrays(GL_TRIANGLES, 0, mesh->numIndices);
    }

    glDisableClientState(GL_VERTEX_ARRAY);          // Disable Vertex Arrays
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);	// Disable Texture Coord Arrays
    glDisableClientState(GL_NORMAL_ARRAY);          // Disable Normal Arrays
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
    float minX, minY, minZ; //Max cooridnate vertex
    float maxX, maxY, maxZ; //Min coordinate vertex
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

        _vMeshes.resize(numMeshes); //Resize meshes vector to copy all assimp imported meshes


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
            unsigned int k;
            for (k = 0 ; k < aiMesh->mNumVertices ; k++) {
                pPos      = &(aiMesh->mVertices[k]);
                pNormal   = &(aiMesh->mNormals[k]);
                pTexCoord = aiMesh->HasTextureCoords(0) ? &(aiMesh->mTextureCoords[0][k]) : &Zero3D;

                minX = min(minX, pPos->x);
                maxX = max(maxX, pPos->x);

                minY = min(minY, pPos->y);
                maxY = max(maxY, pPos->y);

                minZ = min(minZ, pPos->z);
                maxZ = max(maxZ, pPos->z);

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

            //Copy face data from the importer to be able to generate a buffer
            int j;
            for (j = 0 ; j < sizeFaces ; j++) {
                const aiFace& Face = aiMesh->mFaces[j];
                indices.push_back(Face.mIndices[0]);
                indices.push_back(Face.mIndices[1]);
                indices.push_back(Face.mIndices[2]);
            }

            //Generate and initialize the buffers with the copied data from importer
            mesh->generateMeshBuffers(verticesCoord, texturesCoord, normalsCoord, indices);

            _vMeshes[i] = mesh;
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

    _vTextures.resize(pScene->mNumMaterials); //Resize textures vector to copy all assimp imported meshes
    // Initialize the materials
    for (unsigned int i = 0 ; i < pScene->mNumMaterials ; i++) {
        const aiMaterial* pMaterial = pScene->mMaterials[i];
        GLuint id;
        _vTextures[i] = NULL;

        if (pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0) {
            aiString Path;

            if (pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &Path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS) {
                QString FullPath = _baseDirectory + Path.data;
                _vTextures[i] = new Texture();

                id = (*textureIdMap)[FullPath];
                _vTextures[i]->_textureBindId = id;
                //apply_material(pMaterial);
                qDebug() << "BIND TEXTURE CORRECT " << id << " " << FullPath;
            }
        }

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
}

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
void Object3DFile::Mesh::generateMeshBuffers(const vector<float> &verticesCoord,
                                             const vector<float> &texturesCoord, const vector<float> &normalsCoord, const vector<unsigned int> &indices)
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
}

#endif /* OBJECT3DASSIMP_H_ */

