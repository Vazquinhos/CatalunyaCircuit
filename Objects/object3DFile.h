/*
 * Archivo: object3DFile.h
 * Fecha: 23/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *  Clase: Object3DFile
 * Descripcion: Clase que representa un objeto 3D de la escena. Carga un objeto desde fichero
 */

#ifndef Object3DAssimp_H_
#define Object3DAssimp_H_

#include "absObject3D.h"

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <IL/il.h>                  //Devil image loader for textures
#include <vector>

using namespace std;

class Object3DFile : public AbsObject3D{

private:
    #define INVALID_OGL_VALUE 0xFFFFFFFF //Default invalid initial values
    #define INVALID_MATERIAL 0xFFFFFFFF

    struct Mesh {
        Mesh();
        ~Mesh();

        void generateMeshBuffers(const std::vector<float>& verticesCoord, const std::vector<float>& texturesCoord, const std::vector<float>& normalsCoord,
                                 const std::vector<unsigned int>& Indices);
        GLuint vertexBufferBindId;      //Vertex buffer array ID bind
        GLuint texturesBufferBindId;    //Textures buffer array ID bind
        GLuint normalsBufferBindId;     //Normals buffer array ID bind
        GLuint faceIndexBufferBindId;   //Face index buffer array ID bind
        unsigned int numIndices;        //Number of face indexes
        unsigned int materialIndex;     //Material index of the mesh

        Point3D     * _p_minVertex; //Min vertex of the mesh
        Point3D     * _p_maxVertex; //Max vertex of the mesh
        Point3D     * _p_center; //Center of the mesh
        GLuint        _gi_displayListId; //Display list of the mesh
        bool _isVisible; //Visibility of the mesh
        void checkVisibility(Point3D *pointCamera, int distance);
    };

    struct Texture{
        GLenum _textureTarget; //Texture tarjet ex: TEXTURE_2D
        GLuint _textureBindId; //Texture id bind
    };

    Assimp::Importer _importer;
    vector<Mesh*> _vMeshes; //Meshes of the object with normals, vertex and texture coordinates
    vector<Texture*> _vTextures; //Texture info

    QString _baseDirectory; //Base directory path of the object
    QString _filename; //Filename

    //Object loading methods
    bool loadFromFile(map<QString, GLuint> *textureIdMap, unsigned int assimpFlags);
    bool generateObjectBuffers(const aiScene* pScene);
    bool loadMaterials(const aiScene* pScene, map<QString, GLuint> *textureIdMap);
    void apply_material(const aiMaterial *mtl);

    //Auxiliary methods
    void set_float4(float f[4], float a, float b, float c, float d);
    void color4_to_float4(const aiColor4D *c, float f[4]);

public:
    Object3DFile();
    Object3DFile(QString directory, QString filename, map<QString, GLuint> *textureIdMap, unsigned int assimpFlags, bool isMovable);
    virtual ~Object3DFile();

    void release();
    void checkVisibility(Point3D *pointCamera, int distance);
    void display();
    void render(); //Inherited method
};

#endif /* Object3DAssimp_H_ */
