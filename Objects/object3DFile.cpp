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
Object3DFile::Object3DFile(std::string directory, std::string filename, unsigned int assimpFlags){
    this->_baseDirectory = directory;
    this->_filename = filename;
    this->loadFromFile(assimpFlags);
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
bool Object3DFile::loadFromFile(unsigned int assimpFlags){

    bool loadedSuccesful = false;

    QString path; //Current relative project path
    path.append(_baseDirectory.c_str()); //Append object directory
    path.append(_filename.c_str()); //Append object filename

    const aiScene* pScene = _importer.ReadFile(path.toAscii().data(), assimpFlags);

    if (!pScene) {
        qDebug() << "Error before loading: " << _importer.GetErrorString();
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
    glEnableClientState(GL_VERTEX_ARRAY);           // Enable Vertex Arrays
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);	// Enable Texture Coord Arrays
    glEnableClientState(GL_NORMAL_ARRAY);           // Enable Normal Arrays

    for (unsigned int i = 0 ; i < _vMeshes.size() ; i++) {
        glBindBuffer(GL_ARRAY_BUFFER, _vMeshes[i].vertexBufferBindId); //Bind vertex array of the mesh
        glVertexPointer( 3, GL_FLOAT, 0, 0); // Set The Vertex Pointer To Vertex Data

        glBindBuffer(GL_ARRAY_BUFFER, _vMeshes[i].texturesBufferBindId); //Bind texture array of the mesh
        glTexCoordPointer(3, GL_FLOAT, 0, 0); // Set The Vertex Pointer To TexCoord Data

        glBindBuffer(GL_ARRAY_BUFFER, _vMeshes[i].normalsBufferBindId); //Bind normal array of the mesh
        glNormalPointer(GL_FLOAT, sizeof(float)*3, 0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _vMeshes[i].faceIndexBufferBindId); //Bind integer array of the mesh with face indexes info

        const unsigned int MaterialIndex = _vMeshes[i].materialIndex; //Bind texture of the mesh

        if (MaterialIndex < _vTextures.size() && _vTextures[MaterialIndex]) {
            glBindTexture(GL_TEXTURE_2D, _vTextures[MaterialIndex]->_textureBindId);
        }

        glDrawElements(GL_TRIANGLES, _vMeshes[i].numIndices, GL_UNSIGNED_INT, 0); //Renders the object deleting shared vertex between faces
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
    const aiMesh* mesh;
    const aiVector3D* pPos;
    const aiVector3D* pNormal;
    const aiVector3D* pTexCoord;
    if(numMeshes > 0){
        mesh = pScene->mMeshes[0];
        pPos      = &(mesh->mVertices[0]);
        minX = maxX =  pPos->x;
        minY = maxY =  pPos->y;
        minZ = maxZ =  pPos->z;

        _vMeshes.resize(numMeshes); //Resize meshes vector to copy all assimp imported meshes
        _vTextures.resize(pScene->mNumMaterials); //Resize textures vector to copy all assimp imported meshes

        // Initialize the meshes in the scene one by one
        for (unsigned int i = 0 ; i < numMeshes ; i++) {
            mesh = pScene->mMeshes[i];
            //Generate buffers for the mesh and copy data of the assimp importer
            _vMeshes[i].materialIndex = mesh->mMaterialIndex;

            vector<float> verticesCoord;
            vector<float> normalsCoord;
            vector<float> texturesCoord;

            vector<unsigned int> indices;

            const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

            //Copy vertex, normals, textures positions data from the importer to be able to generate a buffer
            for (unsigned int k = 0 ; k < mesh->mNumVertices ; k++) {
                pPos      = &(mesh->mVertices[k]);
                pNormal   = &(mesh->mNormals[k]);
                pTexCoord = mesh->HasTextureCoords(0) ? &(mesh->mTextureCoords[0][k]) : &Zero3D;

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
            for (unsigned int j = 0 ; j < mesh->mNumFaces ; j++) {
                const aiFace& Face = mesh->mFaces[j];
                indices.push_back(Face.mIndices[0]);
                indices.push_back(Face.mIndices[1]);
                indices.push_back(Face.mIndices[2]);
            }

            //Generate and initialize the buffers with the copied data from importer
            _vMeshes[i].generateMeshBuffers(verticesCoord, texturesCoord, normalsCoord, indices);
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
bool Object3DFile::loadMaterials(const aiScene* pScene)
{
    bool ret = true;
    ilInit(); /* Initialization of DevIL */

    // Initialize the materials
    for (unsigned int i = 0 ; i < pScene->mNumMaterials ; i++) {
        const aiMaterial* pMaterial = pScene->mMaterials[i];

        _vTextures[i] = NULL;

        if (pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0) {
            aiString Path;

            if (pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &Path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS) {
                std::string FullPath = string(_baseDirectory) + Path.data;
                _vTextures[i] = new Texture();

                //Load textures with DevIL

                bool success = ilLoadImage(FullPath.c_str());

                if (success) {
                    success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);
                    if(success){
                        glGenTextures(1, &_vTextures[i]->_textureBindId);
                        glBindTexture(GL_TEXTURE_2D, _vTextures[i]->_textureBindId);

                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR ); //MIMAP LINEAR IS NOT VALID FOR MAG FILTER!
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

                        GLfloat fLargest;
                        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &fLargest);
                        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, fLargest ); //Applies maximum aviable anisotropy for better texture quality on distance when using mipmaps

                        glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);   //Requires GL 1.4. Removed from GL 3.1 and above. //Generate Mipmap for different quality on distance movement

                        apply_material(pMaterial);
                        glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
                                     ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
                                     ilGetData());

                        //ilDeleteImage(_vTextures[i]->_textureBindId);
                        qDebug() << "Loaded texture " << FullPath.c_str();
                    }
                    else{
                        qDebug() << "Error while converting textureto GL format " << FullPath.c_str();
                    }
                }
                else {
                    qDebug() << "Loaded texture path ERROR" << FullPath.c_str();

                }
            }
        }

    }


    _importer.FreeScene();

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

void Object3DFile::loadTextures(){
    generateObjectBuffers(_importer.GetScene());
    loadMaterials(_importer.GetScene());
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

