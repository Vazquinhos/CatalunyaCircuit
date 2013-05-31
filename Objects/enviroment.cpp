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
    _semNormal =  new Semaphore();

    // ========================== Phisics Bullet =================
    //int width = 40000, length = 40000;
    //btScalar maxHeight = 10.f;
    //unsigned char* heightfieldData = new unsigned char[width*length];
    //{
            //for (int i=0;i<width*length;i++)
            //{
                //heightfieldData[i]=-76.3;
            //}
        //}
    _groundShape = new btStaticPlaneShape(btVector3(0,0,1),-77.3);
            //new btHeightfieldTerrainShape(width,length,heightfieldData,maxHeight,2,false,false);
    _groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,1,0)));
    btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0,_groundMotionState,_groundShape,btVector3(0,0,0));
    _groundRigidBody = new btRigidBody(groundRigidBodyCI);
    dynamicsWorld->addRigidBody(_groundRigidBody); //Add rigid body to the world

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


Semaphore * Enviroment::getSemaphore(){
    return _semNormal;
}

/*-------------------------------------------------------------------
 |  Function checkVisibility
 |
 |  Purpose: Modify visibility of the objects taking in consideration distance to the camera
 |  Parameters: Point3D *pointCamera : Position of the camera, int distance : Maximum distance that the object will be visible
 *-------------------------------------------------------------------*/
void Enviroment::checkVisibility(vector<GLuint> *displayLists){

    _sky->putDisplayLists(displayLists);
    _terrain->checkVisibility(displayLists);
    _advertisement->checkVisibility(displayLists);
    _objects->checkVisibility(displayLists);
    //_fences->checkVisibility(displayLists);
    //_pneumatic_fences->checkVisibility(displayLists);

    //_walls->checkVisibility(displayLists);
    //_forest->checkVisibility(displayLists);

    _buildings1->checkVisibility(displayLists);
    _buildings2->checkVisibility(displayLists);
    _buildings3->checkVisibility(displayLists);
    _buildings4->checkVisibility(displayLists);
    _buildings5->checkVisibility(displayLists);
    _buildings6->checkVisibility(displayLists);

    _semNormal->getModel()->checkVisibility(displayLists);

}


