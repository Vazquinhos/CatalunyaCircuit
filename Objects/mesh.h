#ifndef MESH_H
#define MESH_H
#include <Objects/texture.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <Utils/util.h>
#include <vector>
#include <bullet/btBulletCollisionCommon.h>

using namespace std;

class Mesh
{
public:
    Mesh();
    ~Mesh();

    void render(const aiScene* scene, vector<btScalar> *verticesCoord, vector<float> *texturesCoord, vector<float> *normalsCoord,
                vector<int> *Indices, vector<Texture *> *_vTextures, bool saveVertex);
    GLuint _vertexBufferBindId;      //Vertex buffer array ID bind
    GLuint _texturesBufferBindId;    //Textures buffer array ID bind
    GLuint _normalsBufferBindId;     //Normals buffer array ID bind
    GLuint _faceIndexBufferBindId;   //Face index buffer array ID bind
    unsigned int _numIndices;        //Number of face indexes
    unsigned int _materialIndex;     //Material index of the mesh

    Point3D     * _p_minVertex; //Min vertex of the mesh
    Point3D     * _p_maxVertex; //Max vertex of the mesh
    Point3D     * _p_center; //Center of the mesh
    GLuint        _gi_displayListId; //Display list of the mesh
    btBvhTriangleMeshShape *collisionShape;
    bool _isVisible; //Visibility of the mesh
    vector<btScalar> _verticesCoord;

    void apply_material(const aiMaterial *mtl);

private:
    #define INVALID_OGL_VALUE 0xFFFFFFFF //Default invalid initial values
    #define INVALID_MATERIAL 0xFFFFFFFF
};

#endif // MESH_H
