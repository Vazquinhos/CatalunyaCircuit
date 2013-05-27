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
#include "Objects/model3D.h"
#include <QDir>
#include <Objects/enviroment.h>
#include <Cameras/cameramanager.h>
#include <QTime>
#include <string>
#include <bullet/btBulletDynamicsCommon.h>
#include <Objects/bsplinemanager.h>
#include <Objects/objectManager.h>
#include <Objects/carautomatic.h>

using namespace std;

class Scene
{
public:
    // ================= Constructores/Destructores ======================
    ~Scene();
    // ============================ Methods ===============================
    void display(float fps);
    void simulatePhisics(btScalar timeStep);
    void paint2DText(float x, float y, void *font, const char *string);
    void turnDebugMode();
    static Scene * getScene();
    void startCarAnimation();
    void stopCarAnimation();

    // ============================ Inherited ===============================
    void update();
private:
    // ========================== Data Members ============================
    Scene();
    ObjectManager  *    _objectManager;
    BSplineManager *    _bSplineManager;
    bool                _debugMode;
    // ========================== Physics / Bullet ========================
    QTime _stepTimer;
    btBroadphaseInterface* _broadphase;
    btDefaultCollisionConfiguration* _collisionConfiguration;
    btCollisionDispatcher* _dispatcher;
    btSequentialImpulseConstraintSolver* _solver;
    btDiscreteDynamicsWorld* _dynamicsWorld;

    static Scene * _scene;
    CarAutomatic * c2;

    // ============================ Methods ===============================
};

#endif // SCENE_H
