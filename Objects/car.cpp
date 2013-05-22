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
 |  getPosition
 |  Purpose: Get the position of the car
 |  Returns: The position of the car
 *-------------------------------------------------------------------*/
Point3D * Car::getPosition(){
    btTransform transform;
    this->_chasisObj->getWorldTransform(transform);
    return new Point3D(transform.getOrigin().getX(), transform.getOrigin().getY(),transform.getOrigin().getZ());
}

/*-------------------------------------------------------------------
 |  setPosition
 |  Purpose: Set the position of the car
 *-------------------------------------------------------------------*/
void Car::setPosition(Point3D *position){
    btTransform transform;
    this->_chasisObj->getWorldTransform(transform);
    transform.setOrigin(btVector3(position->getX(),position->getY(),position->getZ()));
    this->_chasisObj->setWorldTransform(transform);
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
    setModelsWithPos(folderPath, position);

    _chassisCollisionShape = new btBoxShape(btVector3(1,0.4,3));

    btScalar mass = 700;
    btVector3 fallInertia(0,0,0);
    _chassisCollisionShape->calculateLocalInertia(mass,fallInertia);


    btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass,_chasisObj,_chassisCollisionShape,fallInertia);

    //int randX = qrand() % ((9 + 1) - 1) + 1;
    //int randY = qrand() % ((9 + 1) - 1) + 1;

    _fallRigidBody = new btRigidBody(fallRigidBodyCI);
    //_fallRigidBody->setLinearVelocity(btVector3(randX,randY,0));
    //_fallRigidBody->setAngularVelocity(btVector3(randX,randY,0));
    _fallRigidBody->setFriction(1);
    dynamicsWorld->addRigidBody(_fallRigidBody);
}

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Car::Car(QString folderPath, Point3D *position)
{
    setModelsWithPos(folderPath, position);
}

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Car::Car(QString folderPath)
{
    setModelsWithPos(folderPath, new Point3D(0,0,0));
}

/*-------------------------------------------------------------------
 |  Default setModels
 |
 |  Purpose:Get all models from model manager
 |  Parameters: QString folderPath: Folder that contains models of the car
 *-------------------------------------------------------------------*/
void Car::setModelsWithPos(QString folderPath, Point3D *position){
    ModelManager *manager = ModelManager::getModelManager();
    QString wheelsFolder = QString("Cars/Wheels/");
    btTransform transform;
    btQuaternion rotationX(btVector3(1,0,0), btScalar(-1.570796327));

    transform = btTransform(btQuaternion(0,0,30,700),btVector3(position->getX(),position->getY(),position->getZ()));
    transform.setRotation(rotationX);



    _chasisObj= manager->getPyisicsObject(folderPath + "chasis.3ds", transform);
    _wheelObj= manager->getPyisicsObject(folderPath + "wheel.3ds", transform);
    _wheelFrontRight= manager->getPyisicsObject(wheelsFolder + "wheelFrontRight.3ds", transform);
    _wheelFrontLeft= manager->getPyisicsObject(wheelsFolder + "wheelFrontLeft.3ds", transform);
    _wheelRearRight= manager->getPyisicsObject(wheelsFolder + "wheelRearRight.3ds", transform);
    _wheelRearLeft= manager->getPyisicsObject(wheelsFolder + "wheelRearLeft.3ds", transform);
}

// ============================ Methods ===============================
void Car::turnRight(){
    Point3D *position = getPosition();
    position->setX(position->getX()+1);
    setPosition(position);
}
void Car::turnLeft(){
    Point3D *position = getPosition();
    position->setX(position->getX()-1);
    setPosition(position);
}
void Car::accelerate(){
    Point3D *position = getPosition();
    position->setX(position->getY()+1);
    setPosition(position);
}
void Car::brake(){
    Point3D *position = getPosition();
    position->setX(position->getY()-1);
    setPosition(position);
}
// ============================ Inherited Methods ===============================
/*-------------------------------------------------------------------
 |  Function displayModels
 |
 |  Purpose: Displays all models
 *-------------------------------------------------------------------*/
void Car::displayModels(){
    if(_chasisObj->isVisible()){
        _chasisObj->display();
        _wheelObj->display();
        _wheelFrontRight->display();
        _wheelFrontLeft->display();
        _wheelRearRight->display();
        _wheelRearLeft->display();
    }
}

/*-------------------------------------------------------------------
 |  Function checkVisibility
 |
 |  Purpose: Modify visibility of the objects taking in consideration distance to the camera
 |  Parameters: Point3D *pointCamera : Position of the camera, int distance : Maximum distance that the object will be visible
 *-------------------------------------------------------------------*/
vector<GLuint> Car::checkVisibility(){
    vector<GLuint> displayLists;

    _chasisObj->checkVisibility();

    return displayLists;
}

