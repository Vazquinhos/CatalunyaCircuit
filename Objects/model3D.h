/*
 * Archivo: object3D.h
 * Fecha: 23/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *  Clase: Model3D
 * Descripcion: Clase que representa un objeto 3D de la escena. Carga un objeto desde fichero
 */

#ifndef Model3DAssimp_H_
#define Model3DAssimp_H_


#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <IL/il.h>                  //Devil image loader for textures
#include <vector>
#include <bullet/btBulletCollisionCommon.h>
#include <Objects/mesh.h>
#include <Objects/texture.h>
#include <Objects/meshInstance.h>
#include "math.h"
#include "Cameras/cameramanager.h"
#include "Cameras/cameraabs.h"
#include "Utils/vector3D.h"

using namespace std;

class Model3D{

private:
    // ========================== Data Members ===========================
    // ========================== Importer Members ===========================
    QString _baseDirectory; //Base directory path of the object
    QString _filename; //Filename
    Assimp::Importer _importer;
    vector<Mesh*> _vMeshes; //Meshes of the object with normals, vertex and texture coordinates
    vector<Texture*> _vTextures; //Texture info
    vector<MeshInstance*> _vMeshInstances;

    // ========================== Model Members ===========================
    Point3D     * _p_translation;
    Point3D     * _p_rotation;
    Point3D     * _p_scale;
    Point3D     * _p_minVertex;
    Point3D     * _p_maxVertex;
    Point3D     * _p_center;
    bool _isVisible;

    CameraManager* _camMngr;

    // ========================== Importer Methods ===========================
    bool loadFromFile(unsigned int assimpFlags);
    void generateObjectBuffers(const aiScene* pScene);
    void mapMaterials(const aiScene* pScene, map<QString, GLuint> *textureIdMap);
    void renderMeshInstances(const aiNode *node);
    void renderNode(const aiNode *node);

public:
    Model3D();
    Model3D(QString directory, QString filename, unsigned int assimpFlags);
    virtual ~Model3D();

    // ============================ GETTER SETTER ==============================
    void               setTranslation(Point3D * translation);
    Point3D          * getTranslation();
    void               setRotation(Point3D * rotation);
    Point3D          * getRotation();
    void               setScale(Point3D * scale);
    Point3D          * getScale();
    void               setMinVertex(Point3D * minVertex);
    Point3D          * getMinVertex();
    void               setMaxVertex(Point3D * maxVertex);
    Point3D          * getMaxVertex();
    Point3D          * getCenter();
    void               setCenter(Point3D *center);
    void setName(QString name);
    QString getName();
    void setVisibility(bool visibility);
    bool getVisibility();
    btCompoundShape *getCollisionShape(btTransform transform);

    void display();
    void render(map<QString, GLuint> *textureIdMap);
    void checkVisibility(vector<GLuint> *displayLists);
    void putDisplayLists(vector<GLuint> *displayLists);

    void drawCenters();

    void release();
};

#endif /* Model3DAssimp_H_ */
