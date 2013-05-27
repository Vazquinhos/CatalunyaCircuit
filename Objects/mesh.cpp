#include "mesh.h"


/*-------------------------------------------------------------------
|  Function Mesh
|  Purpose: Creator. Default creator that initializes all values to invalid ones
*-------------------------------------------------------------------*/
Mesh::Mesh()
{
    _vertexBufferBindId = INVALID_OGL_VALUE; //Initialize values to invalid ones
    _faceIndexBufferBindId = INVALID_OGL_VALUE;
    _numIndices  = 0;
    _materialIndex = INVALID_MATERIAL;
    _gi_displayListId = 0;
    _isVisible = true;
}

/*-------------------------------------------------------------------
|  Function ~Mesh
|  Purpose: Destructor. Default destructor that cleans memory and deletes all buffer bindings
*-------------------------------------------------------------------*/
Mesh::~Mesh()
{
    if (_vertexBufferBindId != INVALID_OGL_VALUE) //Clean buffers
    {
        glDeleteBuffers(1, &_vertexBufferBindId);
    }

    if (_faceIndexBufferBindId != INVALID_OGL_VALUE)
    {
        glDeleteBuffers(1, &_faceIndexBufferBindId);
    }
}

/*-------------------------------------------------------------------
|  Function generateMeshBuffers
|  Purpose:     Generates all buffers of this mesh
|  Parameters:  const vector<float> &verticesCoord  = Vector with all vertex info to generate its buffer array buffer id
|               const vector<float> &texturesCoord  = Vector with all textures info to generate its buffer array buffer id
|               const vector<float> &normalsCoord   = Vector with all normals info to generate its buffer array buffer id
|               const vector<unsigned int> &indices = Vector with all face indexes info to generate its buffer array buffer id
*-------------------------------------------------------------------*/
void Mesh::render(const aiScene *scene, vector<btScalar> *verticesCoord, vector<float> *texturesCoord, vector<float> *normalsCoord, vector<int> *indices, vector<Texture *> *_vTextures, bool saveVertex)
{
    //*********************** Upload vertex, normals, textures coords to memory ***********************
    _numIndices = indices->size();

    glGenBuffers(1, &_vertexBufferBindId); //Generate buffer id for vertex
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferBindId); //Bind the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(btScalar) * verticesCoord->size(), &(*verticesCoord)[0], GL_STATIC_DRAW); //Put position, normals, textures positions to buffer

    glGenBuffers(1, &_texturesBufferBindId); //Generate buffer id for vertex
    glBindBuffer(GL_ARRAY_BUFFER, _texturesBufferBindId); //Bind the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * texturesCoord->size(), &(*texturesCoord)[0], GL_STATIC_DRAW);

    glGenBuffers(1, &_normalsBufferBindId); //Generate buffer id for vertex
    glBindBuffer(GL_ARRAY_BUFFER, _normalsBufferBindId); //Bind the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * normalsCoord->size(), &(*normalsCoord)[0], GL_STATIC_DRAW);

    glGenBuffers(1, &_faceIndexBufferBindId); //Generate buffer for face indexes
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _faceIndexBufferBindId); //Bind index buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * _numIndices, &(*indices)[0], GL_STATIC_DRAW); //Put mesh face indexes

    //*********************** Bind all arrays generating a display list for the mesh ***********************

    glEnableClientState(GL_VERTEX_ARRAY);           // Enable Vertex Arrays
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);        // Enable Texture Coord Arrays
    glEnableClientState(GL_NORMAL_ARRAY);           // Enable Normal Arrays

    if (glIsList(_gi_displayListId)) { //If we already have a display list, we delete it
        glDeleteLists(_gi_displayListId, 1);
    }
    _gi_displayListId = glGenLists(1); //Generate new display list identifier
    glNewList(_gi_displayListId, GL_COMPILE); //Starting rendering in memory

    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferBindId); //Bind vertex array of the mesh
    glVertexPointer( 3, GL_DOUBLE, 0, 0); // Set The Vertex Pointer To Vertex Data

    glBindBuffer(GL_ARRAY_BUFFER, _texturesBufferBindId); //Bind texture array of the mesh
    glTexCoordPointer(3, GL_FLOAT, 0, 0); // Set The Vertex Pointer To TexCoord Data

    glBindBuffer(GL_ARRAY_BUFFER, _normalsBufferBindId); //Bind normal array of the mesh
    glNormalPointer(GL_FLOAT, sizeof(float)*3, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _faceIndexBufferBindId); //Bind integer array of the mesh with face indexes info

    const unsigned int MaterialIndex = _materialIndex; //Bind texture of the mesh

    if (MaterialIndex < _vTextures->size() && (*_vTextures)[_materialIndex]) {
        apply_material(scene->mMaterials[_materialIndex]);
        glBindTexture(GL_TEXTURE_2D, (*_vTextures)[MaterialIndex]->_textureBindId);
    }

    glDrawElements(GL_TRIANGLES, _numIndices, GL_UNSIGNED_INT, 0); //Renders the object deleting shared vertex between faces (IS SLOWER THAN glDrawArrays!!)
    //glDrawArrays(GL_TRIANGLES, 0, _numIndices);

    glEndList(); //Finish rendering in memory

    glDisableClientState(GL_VERTEX_ARRAY);          // Disable Vertex Arrays
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);       // Disable Texture Coord Arrays
    glDisableClientState(GL_NORMAL_ARRAY);          // Disable Normal Arrays

    //btTriangleIndexVertexArray *mIndexVertexArray = new btTriangleIndexVertexArray(numIndices/3, &(*indices)[0], sizeof(int)*3, verticesCoord->size(), &(*verticesCoord)[0], sizeof(btScalar)*3);
    //btVector3 aabbMin(_p_minVertex->getX(),_p_minVertex->getY(),_p_minVertex->getZ()),aabbMax(_p_maxVertex->getX(),_p_maxVertex->getY(),_p_maxVertex->getZ());
    //bool useQuantizedAabbCompression=true;


    //collisionShape = new btBvhTriangleMeshShape(mIndexVertexArray, useQuantizedAabbCompression, aabbMin, aabbMax);

    if(saveVertex){
        _verticesCoord = *verticesCoord;
        //for(unsigned int i = 0; i < verticesCoord->size(); ++i){

        //}
    }
}

/*-------------------------------------------------------------------
|  Function apply_material
|  Purpose: Applies special effects for a given material, for example plastic or light/reflection
|  Parameters:     const aiMaterial *mtl = The material to apply special effects
*-------------------------------------------------------------------*/
void Mesh::apply_material(const aiMaterial *mtl)
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

    c[0] = 0.8f;
    c[1] = 0.8f;
    c[2] = 0.8f;
    c[3] = 1.0f;
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse)){
        c[0] = diffuse.r;
        c[1] = diffuse.g;
        c[2] = diffuse.b;
        c[3] = diffuse.a;
    }

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, c);

    c[0] = 0.0f;
    c[1] = 0.0f;
    c[2] = 0.0f;
    c[3] = 1.0f;
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_SPECULAR, &specular))
    {
        c[0] = specular.r;
        c[1] = specular.g;
        c[2] = specular.b;
        c[3] = specular.a;
    }

    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c);

    c[0] = 0.2f;
    c[1] = 0.2f;
    c[2] = 0.2f;
    c[3] = 1.0f;
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_AMBIENT, &ambient)){
        c[0] = ambient.r;
        c[1] = ambient.g;
        c[2] = ambient.b;
        c[3] = ambient.a;
    }

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, c);

    c[0] = 0.0f;
    c[1] = 0.0f;
    c[2] = 0.0f;
    c[3] = 1.0f;
    if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_EMISSIVE, &emission))
    {
        c[0] = emission.r;
        c[1] = emission.g;
        c[2] = emission.b;
        c[3] = emission.a;
    }

    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, c);

    max = 1;
    ret1 = aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS, &shininess, &max);
    max = 1;
    ret2 = aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS_STRENGTH, &strength, &max);
    if((ret1 == AI_SUCCESS) && (ret2 == AI_SUCCESS))
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess * strength);
    else {
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 80.0f);
        c[0] = 0.0f;
        c[1] = 0.0f;
        c[2] = 0.0f;
        c[3] = 0.0f;
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c);
    }

    max = 1;
    if(AI_SUCCESS == aiGetMaterialIntegerArray(mtl, AI_MATKEY_ENABLE_WIREFRAME, &wireframe, &max))
    {
        fill_mode = wireframe ? GL_LINE : GL_FILL;
    }
    else{
        fill_mode = GL_FILL;
    }
    glPolygonMode(GL_FRONT_AND_BACK, fill_mode);


    max = 1;
    if((AI_SUCCESS == aiGetMaterialIntegerArray(mtl, AI_MATKEY_TWOSIDED, &two_sided, &max)) && !two_sided){
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }
    else{
            glDisable(GL_CULL_FACE);
        }
}


