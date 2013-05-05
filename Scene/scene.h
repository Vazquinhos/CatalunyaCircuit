/*
 * Archivo: scene.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: Scene
 * Descripcion: Clase que encapsula el pintado de cada uno de los fragmentos, el tamaño de estos,
 */


#ifndef SCENE_H
#define SCENE_H

#include "Objects/objectManager.h"
#include "Objects/absObject3D.h"
#include "Objects/object3DFile.h"
#include <QDir>
#include <Objects/enviroment.h>
#include <Cameras/cameramanager.h>
#include <QTime>

#include <bullet/btBulletDynamicsCommon.h>

class Scene
{
public:
    // ================= Constructores/Destructores ======================
    Scene();
    Scene(const Scene& scene);
    ~Scene();
    // ============================ Methods ===============================
    void display(float fps);
    void simulatePhisics(btScalar timeStep);
    void paint2DText(float x, float y, void *font,const char *string);

private:
    // ========================== Data Members ============================
    ObjectManager *_objectManager;

    // ========================== Physics / Bullet ========================
    QTime _stepTimer;
    btBroadphaseInterface* _broadphase;
    btDefaultCollisionConfiguration* _collisionConfiguration;
    btCollisionDispatcher* _dispatcher;
    btSequentialImpulseConstraintSolver* _solver;
    btDiscreteDynamicsWorld* _dynamicsWorld;

    // ============================ Methods ===============================
};

#endif // SCENE_H
