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
    btScalar *openglMatrix = new btScalar[16];
    this->_chasisObj->getWorldTransform(transform);

    //transform.getOpenGLMatrix(openglMatrix);
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
    btTransform transformChasis;
    btTransform transformWheelFR;

    transformChasis = btTransform(btQuaternion(0,0,30,700),btVector3(position->getX(),position->getY(),position->getZ()));
    transformWheelFR = btTransform(btQuaternion(0,0,30,700),btVector3(position->getX()-1.7369 ,position->getY()+0.1339,position->getZ()-2.628));

    _chasisObj= manager->getPyisicsObject(folderPath + "chasis.3ds", transformChasis);
    _wheelObj= manager->getPyisicsObject(folderPath + "wheel.3ds", transformChasis);
    _wheelFrontRight= manager->getPyisicsObject(wheelsFolder + "wheelOrigin.3ds", transformWheelFR);
    _wheelFrontLeft= manager->getPyisicsObject(wheelsFolder + "wheelOrigin.3ds", transformChasis);
    _wheelRearRight= manager->getPyisicsObject(wheelsFolder + "wheelOrigin.3ds", transformChasis);
    _wheelRearLeft= manager->getPyisicsObject(wheelsFolder + "wheelOrigin.3ds", transformChasis);


    _cameraMode = FRONTAL_CAMERA;
    _cameraOffsets[(int)FRONTAL_CAMERA] = OffsetYawPitch(new Point3D(0,0,1), new Point2D(271.5, 342.5));
    _cameraOffsets[(int)REAR_CAMERA] = OffsetYawPitch(new Point3D(0,0,1), new Point2D(90, 359.5));
    _cameraOffsets[(int)LEFT_CAMERA] = OffsetYawPitch(new Point3D(0,0,1), new Point2D(183, 356));
    _cameraOffsets[(int)RIGHT_CAMERA] = OffsetYawPitch(new Point3D(0,0,1), new Point2D(1, 0.5));
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
    updateCurrentCameraPos();
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
    updateCurrentCameraPos();
}
/*-------------------------------------------------------------------
 |  Default accelerate
 |
 |  Purpose:Accelerate the car
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::accelerate(){
    Point3D *position = getPosition();
    position->setX(position->getZ()+1);
    setPosition(position);
    updateCurrentCameraPos();
}
/*-------------------------------------------------------------------
 |  Default brake
 |
 |  Purpose:Brake the car
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::brake(){
    Point3D *position = getPosition();
    position->setX(position->getZ()-1);
    setPosition(position);
    updateCurrentCameraPos();
}

/*-------------------------------------------------------------------
 |  Default viewCameraOffeset
 |
 |  Purpose: Views the front camera of the car
 |  Parameters: Point3D* offset: offset of the camera with car position
 |              Point2D *yawPitch: yaw and pitch values of the camera
 *-------------------------------------------------------------------*/
void Car::viewCameraOffeset(OffsetYawPitch offset){
    CameraManager*  manager;
    FixedCamera*    camera;
    manager = CameraManager::getCameraManager();
    camera = dynamic_cast<FixedCamera*>(manager->getCamera("CarCamera"));

    camera->setPosition(*getPosition() + *offset.cameraOffset);
    camera->setYawPitch(offset.cameraYawPitch->getX(), offset.cameraYawPitch->getY());
    manager->setActiveCamera("CarCamera");
}

/*-------------------------------------------------------------------
 |  Default viewCamera
 |
 |  Purpose: Update current camera position when the car is moved (no pitch no yaw)
 *-------------------------------------------------------------------*/
void Car::updateCurrentCameraPos(){
    OffsetYawPitch offset = _cameraOffsets[_cameraMode];
    CameraManager*  manager;
    FixedCamera*    camera;
    manager = CameraManager::getCameraManager();
    camera = dynamic_cast<FixedCamera*>(manager->getCamera("CarCamera"));

    camera->setPosition(*getPosition() + *offset.cameraOffset);
    manager->setActiveCamera("CarCamera");
}

/*-------------------------------------------------------------------
 |  Default viewCamera
 |
 |  Purpose: Views the front camera of the car
 |  Parameters: cameraMode: camera mode to view
 *-------------------------------------------------------------------*/
void Car::viewCamera(int cameraMode){
    viewCameraOffeset(_cameraOffsets[cameraMode]);
}

/*-------------------------------------------------------------------
 |  Default viewCurrentCamera
 |
 |  Purpose:Views the current camera of the car (last viewed), and updates the position of the camera reading the car position
 |  Parameters:
 *-------------------------------------------------------------------*/
void Car::viewCurrentCamera(){
    viewCameraOffeset(_cameraOffsets[_cameraMode]);
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

