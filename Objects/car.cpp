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
// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Car::Car(QString folder, Point3D * position)
{
    Object3DFile *chasisObj;
    Object3DFile *wheelObj;
    Object3DFile *wheelFrontRightObj;
    Object3DFile *wheelFrontLeftObj;
    Object3DFile *wheelRearRightObj;
    Object3DFile *wheelRearLeftObj;

    chasisObj = new Object3DFile((QDir::currentPath() + folder).toAscii().data(), "chasis.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    chasisObj->setTranslation(position);
    chasisObj->setRotation(new Point3D(0,0,90));
    chasisObj->setScale(new Point3D(1, 1, 1));
    setChasisObj(chasisObj);

    wheelObj = new Object3DFile((QDir::currentPath() + folder).toAscii().data(), "wheel.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    wheelObj->setTranslation(position);
    wheelObj->setRotation(new Point3D(0,0,90));
    wheelObj->setScale(new Point3D(1, 1, 1));
    setWheelObj(wheelObj);

    wheelFrontRightObj = new Object3DFile((QDir::currentPath() + folder).toAscii().data(), "wheelFrontRight.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    wheelFrontRightObj->setTranslation(position);
    wheelFrontRightObj->setRotation(new Point3D(0,0,90));
    wheelFrontRightObj->setScale(new Point3D(1, 1, 1));
    setWheelFrontRightObj(wheelFrontRightObj);

    wheelFrontLeftObj = new Object3DFile((QDir::currentPath() + folder).toAscii().data(), "wheelFrontLeft.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    wheelFrontLeftObj->setTranslation(position);
    wheelFrontLeftObj->setRotation(new Point3D(0,0,90));
    wheelFrontLeftObj->setScale(new Point3D(1, 1, 1));
    setWheelFrontLeftObj(wheelFrontLeftObj);

    wheelRearRightObj = new Object3DFile((QDir::currentPath() + folder).toAscii().data(), "wheelRearRight.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    wheelRearRightObj->setTranslation(position);
    wheelRearRightObj->setRotation(new Point3D(0,0,90));
    wheelRearRightObj->setScale(new Point3D(1, 1, 1));
    setWheelRearRightObj(wheelRearRightObj);

    wheelRearLeftObj = new Object3DFile((QDir::currentPath() + folder).toAscii().data(), "wheelRearLeft.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    wheelRearLeftObj->setTranslation(position);
    wheelRearLeftObj->setRotation(new Point3D(0,0,90));
    wheelRearLeftObj->setScale(new Point3D(1, 1, 1));
    setWheelRearLeftObj(wheelRearLeftObj);
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
void Car::render()
{

}

/*-------------------------------------------------------------------
 |  Function display
 |
 |  Purpose: Displays this object once rendered
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void Car::display()
{
    this->_chasisObj->display();
    this->_wheelObj->display();
    this->_wheelFrontRight->display();
    this->_wheelFrontLeft->display();
    this->_wheelRearRight->display();
    this->_wheelRearLeft->display();
}

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

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void Car::setBBMin(Point3D * p_bbMin)
{
    _p_bbMin = p_bbMin;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * Car::getBBMin()
{
    return _p_bbMin;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void Car::setBBMax(Point3D * p_bbMax)
{
    _p_bbMax = p_bbMax;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * Car::getBBMax()
{
    return _p_bbMax;
}

/*-------------------------------------------------------------------
 |  Function getRepresentation
 |
 |  Purpose: Getter. Gets the chasis of the car
 |  Parameters:
 |  Returns: Object3DFile = the chasis of the car
 *-------------------------------------------------------------------*/
Object3DFile* Car::getChasisObj(){
    return this->_chasisObj;
}

/*-------------------------------------------------------------------
 |  Function setChasisObj
 |
 |  Purpose: Setter. Sets the chasis of the car
 |  Parameters: Object3DFile object = the chasis of the car
 |  Returns:
 *-------------------------------------------------------------------*/
void Car::setChasisObj(Object3DFile *object){
    this->_chasisObj = object;
    this->_chasisObj->render();
}

/*-------------------------------------------------------------------
  |  Function getWheelObj
  |
  |  Purpose: Getter. Gets the wheel of the car
  |  Parameters:
  |  Returns: Object3DFile = the wheel of the car
  *-------------------------------------------------------------------*/
Object3DFile* Car::getWheelObj(){
    return this->_wheelObj;
}

/*-------------------------------------------------------------------
  |  Function setWheelObj
  |
  |  Purpose: Setter. Sets the wheel of the car
  |  Parameters: Object3DFile object = the wheel of the car
  |  Returns:
  *-------------------------------------------------------------------*/
void Car::setWheelObj(Object3DFile *object){
    this->_wheelObj = object;
    this->_wheelObj->render();
}

/*-------------------------------------------------------------------
  |  Function getWheelFrontRightObj
  |
  |  Purpose: Getter. Sets the WheelFrontRight of the car
  |  Parameters:
  |  Returns:
  *-------------------------------------------------------------------*/
Object3DFile* Car::getWheelFrontRightObj(){
    return this->_wheelFrontRight;
}

/*-------------------------------------------------------------------
  |  Function setWheelFrontRightObj
  |
  |  Purpose: Setter. Sets the FrontRightObj of the car
  |  Parameters: Object3DFile object = the FrontRightObj of the car
  |  Returns:
  *-------------------------------------------------------------------*/
void Car::setWheelFrontRightObj(Object3DFile *object){
    this->_wheelFrontRight = object;
    this->_wheelFrontRight->render();
}

/*-------------------------------------------------------------------
  |  Function getWheelFrontLeftObj
  |
  |  Purpose: Getter. Sets the WheelFrontLeft of the car
  |  Parameters:
  |  Returns:
  *-------------------------------------------------------------------*/
Object3DFile* Car::getWheelFrontLeftObj(){
    return this->_wheelFrontLeft;
}

/*-------------------------------------------------------------------
  |  Function setWheelFrontLeftObj
  |
  |  Purpose: Setter. Sets the FrontLeft wheel of the car
  |  Parameters: Object3DFile object = the FrontLeft of the car
  |  Returns:
  *-------------------------------------------------------------------*/
void Car::setWheelFrontLeftObj(Object3DFile *object){
    this->_wheelFrontLeft = object;
    this->_wheelFrontLeft->render();
}

/*-------------------------------------------------------------------
  |  Function getWheelRearRightObj
  |
  |  Purpose: Getter. Sets the WheelRearRight wheel of the car
  |  Parameters:
  |  Returns:
  *-------------------------------------------------------------------*/
Object3DFile* Car::getWheelRearRightObj(){
    return this->_wheelRearRight;
}

/*-------------------------------------------------------------------
  |  Function setWheelRearRightObj
  |
  |  Purpose: Setter. Sets the WheelRearRight wheel of the car
  |  Parameters: Object3DFile object = the WheelRearRight wheel of the car
  |  Returns:
  *-------------------------------------------------------------------*/
void Car::setWheelRearRightObj(Object3DFile *object){
    this->_wheelRearRight = object;
    this->_wheelRearRight->render();
}

/*-------------------------------------------------------------------
  |  Function getWheelRearLeftObj
  |
  |  Purpose: Getter. Sets the WheelRearLeft wheel of the car
  |  Parameters:
  |  Returns:
  *-------------------------------------------------------------------*/
Object3DFile* Car::getWheelRearLeftObj(){
    return this->_wheelRearLeft;
}

/*-------------------------------------------------------------------
  |  Function setWheelRearLeftObj
  |
  |  Purpose: Setter. Sets the WheelRearLeft wheel of the car
  |  Parameters: Object3DFile object = the WheelRearLeft of the car
  |  Returns:
  *-------------------------------------------------------------------*/
void Car::setWheelRearLeftObj(Object3DFile *object){
    this->_wheelRearLeft = object;
    this->_wheelRearLeft->render();
}
