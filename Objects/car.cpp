/*
 * Archivo: carsintance.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "car.h"
#include <QDir>
#include <Objects/modelManager.h>
// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Car::Car(const Car& car)
{
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Car::~Car()
{
}

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Car::Car(QString folderPath, Point3D *position, btDiscreteDynamicsWorld *dynamicsWorld)
{
    ModelManager *manager = ModelManager::getModelManager();
    QString wheelsFolder = QString("Cars/Wheels/");

    _chasisObj= manager->getModel(folderPath + "chasis.3ds");
    _wheelObj= manager->getModel(folderPath + "wheel.3ds");
    _wheelFrontRight= manager->getModel(wheelsFolder + "wheelFrontRight.3ds");
    _wheelFrontLeft= manager->getModel(wheelsFolder + "wheelFrontLeft.3ds");
    _wheelRearRight= manager->getModel(wheelsFolder + "wheelRearRight.3ds");
    _wheelRearLeft= manager->getModel(wheelsFolder + "wheelRearLeft.3ds");

    _worldTrans = btTransform(btQuaternion(0,0,0,700),btVector3(position->getX(),position->getY(),position->getZ()));

    _chassisCollisionShape = new btBoxShape(btVector3(1,0.4,3));

    btScalar mass = 1;
    btVector3 fallInertia(0,0,0);
    _chassisCollisionShape->calculateLocalInertia(mass,fallInertia);


    btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass,this,_chassisCollisionShape,fallInertia);

    int randX = qrand() % ((9 + 1) - 1) + 1;
    int randY = qrand() % ((9 + 1) - 1) + 1;

    _fallRigidBody = new btRigidBody(fallRigidBodyCI);
    _fallRigidBody->setLinearVelocity(btVector3(randX,randY,0));
    _fallRigidBody->setAngularVelocity(btVector3(randX,randY,0));
    _fallRigidBody->setFriction(20);
    dynamicsWorld->addRigidBody(_fallRigidBody);
}


// ============================ Methods ===============================

// ============================ Inherited Methods ===============================
/*-------------------------------------------------------------------
 |  Function displayModels
 |
 |  Purpose: Displays all models
 *-------------------------------------------------------------------*/
void Car::displayModels(){
    btScalar transformation[16];

    glPushMatrix();

    _worldTrans.getOpenGLMatrix(transformation);

    glMultMatrixd(transformation);

    if(isVisible()){
        _chasisObj->display();
        _wheelObj->display();
        _wheelFrontRight->display();
        _wheelFrontLeft->display();
        _wheelRearRight->display();
        _wheelRearLeft->display();
    }

    glPopMatrix();
}

/*-------------------------------------------------------------------
 |  Function checkVisibility
 |
 |  Purpose: Modify visibility of the objects taking in consideration distance to the camera
 |  Parameters: Point3D *pointCamera : Position of the camera, int distance : Maximum distance that the object will be visible
 *-------------------------------------------------------------------*/
vector<GLuint> Car::checkVisibility(Point3D *pointCamera, int distance){
    vector<GLuint> displayLists;

    checkIsVisible(pointCamera, distance, _worldTrans);

    return displayLists;
}

