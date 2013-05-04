/*
 * Archivo: enviroment.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "enviroment.h"
#include "Objects/modelManager.h"
#include <QDir>
#include <QString>

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::Enviroment(btDiscreteDynamicsWorld *dynamicsWorld)
{
    ModelManager *manager = ModelManager::getModelManager();
    _sky = manager->getModel("Circuit/sky.3ds");
    _terrain = manager->getModel("Circuit/terrain.3ds");
    _advertisement = manager->getModel("Circuit/advertisement.3ds");
    _flags = manager->getModel("Circuit/flags.3ds");
    _objects = manager->getModel("Circuit/objects.3ds");
    _fences = manager->getModel("Circuit/fences.3ds");
    _pneumatic_fences = manager->getModel("Circuit/pneumatic_fences.3ds");
    _walls = manager->getModel("Circuit/walls.3ds");
    _forest = manager->getModel("Circuit/forest.3ds");
    _buildings1 = manager->getModel("Circuit/buildings1.3ds");
    _buildings2 = manager->getModel("Circuit/buildings2.3ds");
    _buildings3 = manager->getModel("Circuit/buildings3.3ds");
    _buildings4 = manager->getModel("Circuit/buildings4.3ds");
    _buildings5 = manager->getModel("Circuit/buildings5.3ds");
    _buildings6 = manager->getModel("Circuit/buildings6.3ds");

    // ========================== Phisics Bullet =================
    _groundShape = new btStaticPlaneShape(btVector3(0,0,1),-75);
    _groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-1,0)));
    btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0,_groundMotionState,_groundShape,btVector3(0,0,0));
    _groundRigidBody = new btRigidBody(groundRigidBodyCI);
    dynamicsWorld->addRigidBody(_groundRigidBody); //Add rigid body to the world
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::Enviroment(const Enviroment &enviroment)
{
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::~Enviroment()
{
}

// ============================ Methods ===============================


// ============================ Inherited Methods ===============================
/*-------------------------------------------------------------------
 |  Function displayModels
 |
 |  Purpose: Displays all models
 *-------------------------------------------------------------------*/
void Enviroment::displayModels(){

    _sky->display();
    _terrain->display();
    _advertisement->display();
    _terrain->display();
    _flags->display();
    _objects->display();
    _fences->display();
    _pneumatic_fences->display();
    _walls->display();
    _forest->display();
    _buildings1->display();
    _buildings2->display();
    _buildings3->display();
    _buildings4->display();
    _buildings5->display();
    _buildings6->display();
}

/*-------------------------------------------------------------------
 |  Function checkVisibility
 |
 |  Purpose: Modify visibility of the objects taking in consideration distance to the camera
 |  Parameters: Point3D *pointCamera : Position of the camera, int distance : Maximum distance that the object will be visible
 *-------------------------------------------------------------------*/
vector<GLuint> Enviroment::checkVisibility(Point3D *pointCamera, int distance){
    vector<GLuint> displayLists;

    vector<GLuint> displayListsSky = _sky->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsTerrain = _terrain->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsAdvertisement = _advertisement->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsFlags = _flags->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsObjects = _objects->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsFences = _fences->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsPneumatics = _pneumatic_fences->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsWalls = _walls->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsForest = _forest->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsBuildings1 =  _buildings1->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsBuildings2 = _buildings2->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsBuildings3 =  _buildings3->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsBuildings4 = _buildings4->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsBuildings5 = _buildings5->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsBuildings6 = _buildings6->checkVisibility(pointCamera, distance);

    displayLists.insert( displayLists.end(), displayListsSky.begin(), displayListsSky.end() );
    displayLists.insert( displayLists.end(), displayListsTerrain.begin(), displayListsTerrain.end() );
    displayLists.insert( displayLists.end(), displayListsAdvertisement.begin(), displayListsAdvertisement.end() );
    displayLists.insert( displayLists.end(), displayListsFlags.begin(), displayListsFlags.end() );
    displayLists.insert( displayLists.end(), displayListsObjects.begin(), displayListsObjects.end() );
    displayLists.insert( displayLists.end(), displayListsFences.begin(), displayListsFences.end() );
    displayLists.insert( displayLists.end(), displayListsPneumatics.begin(), displayListsPneumatics.end() );
    displayLists.insert( displayLists.end(), displayListsWalls.begin(), displayListsWalls.end() );
    displayLists.insert( displayLists.end(), displayListsForest.begin(), displayListsForest.end() );
    displayLists.insert( displayLists.end(), displayListsBuildings1.begin(), displayListsBuildings1.end() );
    displayLists.insert( displayLists.end(), displayListsBuildings2.begin(), displayListsBuildings2.end() );
    displayLists.insert( displayLists.end(), displayListsBuildings3.begin(), displayListsBuildings3.end() );
    displayLists.insert( displayLists.end(), displayListsBuildings4.begin(), displayListsBuildings4.end() );
    displayLists.insert( displayLists.end(), displayListsBuildings5.begin(), displayListsBuildings5.end() );
    displayLists.insert( displayLists.end(), displayListsBuildings6.begin(), displayListsBuildings6.end() );

    return displayLists;
}


