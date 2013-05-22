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
Car::Car(QString folderPath)
{
    setModelsWithPos(folderPath, new Point3D(0,0,0));
}

// ================= Getter / Setter ==================================
/*-------------------------------------------------------------------
 |  Default getCameraMode
 |
 |  Purpose:Get current camera mode
 |  Returns: Current camera mode identifier
 *-------------------------------------------------------------------*/
int Car::getCameraMode(){
    return _cameraMode;
}
/*-------------------------------------------------------------------
 |  Default setCameraMode
 |
 |  Purpose:Set current camera mode
 |  Parameters: int mode: Valid camera mode to set, validity is not checked.
 *-------------------------------------------------------------------*/
void Car::setCameraMode(int mode){
    _cameraMode = mode;
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

    _cameraMode = FRONTAL_CAMERA;
    _frontCameraOffset = new Point3D(0,0,2);
    _frontCameraYawPitch = new Point2D(271.5, 342.5);
    _rearCameraOffset  = new Point3D(0,0,2);
    _rearCameraYawPitch = new Point2D(90, 359.5);
    _rightCameraOffset  = new Point3D(0,0,2);
    _rightCameraYawPitch = new Point2D(183, 356);
    _leftCameraOffset  = new Point3D(0,0,2);
    _leftCameraYawPitch = new Point2D(1, 0.5);
}

// ============================ Methods ===============================
/*-------------------------------------------------------------------
 |  Default turnRight
 |
 |  Purpose:Turn right the car
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::turnRight(){
    Point3D *position = getPosition();
    position->setX(position->getX()-1);
    setPosition(position);
    viewCurrentCamera();
}
/*-------------------------------------------------------------------
 |  Default turnLeft
 |
 |  Purpose:Turn left the car
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::turnLeft(){
    Point3D *position = getPosition();
    position->setX(position->getX()+1);
    setPosition(position);
    viewCurrentCamera();
}
/*-------------------------------------------------------------------
 |  Default accelerate
 |
 |  Purpose:Accelerate the car
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::accelerate(){
    Point3D *position = getPosition();
    position->setX(position->getY()+1);
    setPosition(position);
    viewCurrentCamera();
}
/*-------------------------------------------------------------------
 |  Default brake
 |
 |  Purpose:Brake the car
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::brake(){
    Point3D *position = getPosition();
    position->setX(position->getY()-1);
    setPosition(position);
    viewCurrentCamera();
}

/*-------------------------------------------------------------------
 |  Default viewCamera
 |
 |  Purpose: Views the front camera of the car
 |  Parameters: Point3D* offset: offset of the camera with car position
 |              Point2D *yawPitch: yaw and pitch values of the camera
 *-------------------------------------------------------------------*/
void Car::viewCamera(Point3D* offset, Point2D *yawPitch){
    CameraManager*  manager;
    FixedCamera*    camera;
    manager = CameraManager::getCameraManager();
    camera = dynamic_cast<FixedCamera*>(manager->getCamera("CarCamera"));

    camera->setPosition(*getPosition() + *offset);
    camera->setYawPitch(yawPitch->getX(), yawPitch->getY());
    manager->setActiveCamera("CarCamera");
}

/*-------------------------------------------------------------------
 |  Default viewCamera
 |
 |  Purpose: Update current camera position when the car is moved (no pitch no yaw)
 *-------------------------------------------------------------------*/
void updateCurrentCameraPos(){

}

/*-------------------------------------------------------------------
 |  Default viewCurrentCamera
 |
 |  Purpose:Views the current camera of the car (last viewed), and updates the position of the camera reading the car position
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::viewCurrentCamera(){
    switch(_cameraMode){
    case FRONTAL_CAMERA:
        viewFrontCamera();
        break;
    case REAR_CAMERA:
        viewRearCamera();
        break;
    case LEFT_CAMERA:
        viewLeftCamera();
        break;
    case RIGHT_CAMERA:
        viewRightCamera();
        break;
    }
}
/*-------------------------------------------------------------------
 |  Default viewFrontCamera
 |
 |  Purpose:Views the front camera of the car
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::viewFrontCamera(){
    _cameraMode = FRONTAL_CAMERA;
    viewCamera(_frontCameraOffset, _frontCameraYawPitch);
}

/*-------------------------------------------------------------------
 |  Default viewRearCamera
 |
 |  Purpose:Views the rear camera of the car
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::viewRearCamera(){
    _cameraMode = REAR_CAMERA;
    viewCamera(_rearCameraOffset, _rearCameraYawPitch);
}

/*-------------------------------------------------------------------
 |  Default viewLeftCamera
 |
 |  Purpose:Views the left camera of the car
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::viewLeftCamera(){
    _cameraMode = LEFT_CAMERA;
    viewCamera(_leftCameraOffset, _leftCameraYawPitch);
}

/*-------------------------------------------------------------------
 |  Default viewRightCamera
 |
 |  Purpose:Views the right camera of the car
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::viewRightCamera(){
    _cameraMode = RIGHT_CAMERA;
    viewCamera(_rightCameraOffset, _rightCameraYawPitch);
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

