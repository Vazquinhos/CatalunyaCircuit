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
#include <bullet/btBulletCollisionCommon.h>
#include <Objects/mesh.h>
#include <Objects/texture.h>
#include <Objects/instance.h>
#include "math.h"

using namespace std;

class Object3DFile : public AbsObject3D{

private:
    QString _baseDirectory; //Base directory path of the object
    QString _filename; //Filename

    Assimp::Importer _importer;
    vector<Mesh*> _vMeshes; //Meshes of the object with normals, vertex and texture coordinates
    vector<Texture*> _vTextures; //Texture info
    vector<Instance*> _vInstances;
    bool _isVisible;

    //Object loading methods
    bool loadFromFile(map<QString, GLuint> *textureIdMap, unsigned int assimpFlags);
    void generateObjectBuffers(const aiScene* pScene);
    void mapMaterials(const aiScene* pScene, map<QString, GLuint> *textureIdMap);
    void renderInstances(const aiNode *node);
    void renderNode(const aiNode *node);

public:
    Object3DFile();
    Object3DFile(QString directory, QString filename, map<QString, GLuint> *textureIdMap, unsigned int assimpFlags);
    virtual ~Object3DFile();
    void release();

    btCompoundShape *getCollisionShape();
    vector<GLuint> checkVisibility(Point3D *pointCamera, int distance);
    bool isVisible();
    void display();
    void render(); //Inherited method
};

#endif /* Object3DAssimp_H_ */
