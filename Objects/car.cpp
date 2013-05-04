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
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Car::Car(QString folderPath, Point3D *position, btDiscreteDynamicsWorld *dynamicsWorld)
{
    ModelManager *manager = ModelManager::getModelManager();
    QString wheelsFolder = QString("_Cars/Wheels/");
    this->_p_position = position;

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

// ============================ Methods ===============================


/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void Car::setPosition(Point3D * p_position)
{
    _p_position = p_position;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * Car::getPosition()
{
    return _p_position;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void Car::setDirection(Vector3D * p_direction)
{
    _p_direction = p_direction;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Vector3D * Car::getDirection()
{
    return _p_direction;
}

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

    _chasisObj->display();
    _wheelObj->display();
    _wheelFrontRight->display();
    _wheelFrontLeft->display();
    _wheelRearRight->display();
    _wheelRearLeft->display();
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

    vector<GLuint> displayListsChassis = _chasisObj->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsWheel = _wheelObj->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsWFR = _wheelFrontRight->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsWFL = _wheelFrontLeft->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsWRR = _wheelRearRight->checkVisibility(pointCamera, distance);
    vector<GLuint> displayListsWRL =  _wheelRearLeft->checkVisibility(pointCamera, distance);

    displayLists.insert( displayLists.end(), displayListsChassis.begin(), displayListsChassis.end() );
    displayLists.insert( displayLists.end(), displayListsWheel.begin(), displayListsWheel.end() );
    displayLists.insert( displayLists.end(), displayListsWFR.begin(), displayListsWFR.end() );
    displayLists.insert( displayLists.end(), displayListsWFL.begin(), displayListsWFL.end() );
    displayLists.insert( displayLists.end(), displayListsWRR.begin(), displayListsWRR.end() );
    displayLists.insert( displayLists.end(), displayListsWRL.begin(), displayListsWRL.end() );

    return displayLists;

}

/*-------------------------------------------------------------------
 |  Function getWorldTransform
 |
 |  Purpose: Gets the model transformation that must be applied to the object
 |  Parameters: btTransform &worldTrans: Transformation of the model generated by the motion state
 *-------------------------------------------------------------------*/
void Car::getWorldTransform(btTransform &worldTrans) const{
    worldTrans = _worldTrans;
}

/*-------------------------------------------------------------------
 |  Function setWorldTransform
 |
 |  Purpose: Sets the model transformation that must be applied to the object. This function is AUTOMATICALLY called
 |           when a movement of the object is done
 |  Parameters: btTransform &worldTrans: Transformation of the model generated by the motion state
 *-------------------------------------------------------------------*/
void Car::setWorldTransform(const btTransform &worldTrans){
    _worldTrans = worldTrans;
    //qDebug() <<"COCHE MOVIENDOSE " << worldTrans.getOrigin().getX() << " " << worldTrans.getOrigin().getY() << " " << worldTrans.getOrigin().getZ();
}
