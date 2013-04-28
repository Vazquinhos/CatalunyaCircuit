/*
 * Archivo: scene.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "scene.h"
#include <QTime>
#include <IL/il.h>                  //Devil image loader for textures
#include <bullet/btBulletDynamicsCommon.h> //Physics Simulation, Bullet

// ================= Constructores/Destructores ======================
/*-------------------------------------------------------------------
 |
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Scene::Scene()
{
    // ========================== Physics / Bullet ========================
    _broadphase = new btDbvtBroadphase(); //Boradphase checks what pair of objects are colliding. Important if there are many objects on the scene
    _collisionConfiguration = new btDefaultCollisionConfiguration(); //Collision configuration
    _dispatcher = new btCollisionDispatcher(_collisionConfiguration); //Dispatcher for dectect collisions and make callbacks
    _solver = new btSequentialImpulseConstraintSolver(); //Handles object interactions like gravity
    _dynamicsWorld = new btDiscreteDynamicsWorld(_dispatcher,_broadphase,_solver,_collisionConfiguration); //World simulator
    _dynamicsWorld->setGravity(btVector3(0,0,-9.81f));//Sets the gravity (choose -10m/s² on Z axis)


    Enviroment *enviroment = new Enviroment(_dynamicsWorld);

    Car *c1 = new Car(new Point3D(148,20,4), _dynamicsWorld);
    Car *c2 = new Car(new Point3D(154,20,4), _dynamicsWorld);
    Car *c3 = new Car(new Point3D(160,20,4), _dynamicsWorld);
    Car *c4 = new Car(new Point3D(166,20,4), _dynamicsWorld);
    Car *c5 = new Car(new Point3D(172,20,4), _dynamicsWorld);

    _objectManager = ObjectManager::getObjectManager();
    _objectManager->setEnviroment(enviroment); //Add enviroment to object manager
    _objectManager->addCar(c1);
    _objectManager->addCar(c2);
    _objectManager->addCar(c3);
    _objectManager->addCar(c4);
    _objectManager->addCar(c5);
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Scene::Scene(const Scene &scene)
{
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Scene::~Scene()
{
    delete _dynamicsWorld;
    delete _solver;
    delete _dispatcher;
    delete _collisionConfiguration;
    delete _broadphase;
}

// ============================ Methods ===============================

/*-------------------------------------------------------------------
 |  Function display
 |
 |  Purpose: Displays all objects
 *-------------------------------------------------------------------*/
void Scene::display(){
    this->_objectManager->displayAll();
}

/*-------------------------------------------------------------------
 |  Function simulatePhisics
 |
 |  Purpose: Do all physics simulation
 |  Returns: bool True if screen must be updated, false otherwise
 *-------------------------------------------------------------------*/
bool Scene::simulatePhisics(){
    btCollisionObjectArray activeObjects;
    btCollisionObject *object;
    int i = 0;
    bool isSomethingMoving = false;

    _dynamicsWorld->stepSimulation(1/60.f,10);  // Do world simulation every 1/60 s

    activeObjects = _dynamicsWorld->getCollisionWorld()->getCollisionObjectArray(); //Look for an active object in the world in order to check if update screen is needed

    while(i < activeObjects.size() && !isSomethingMoving){
        object = activeObjects[i];
        if(object->isActive()){
            isSomethingMoving = true;
        }
        i++;
    }

    if(isSomethingMoving){
        qDebug() << " ALGO SE MUEVE ";
    }

    return isSomethingMoving;
}
