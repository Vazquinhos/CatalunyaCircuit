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
    _folder = (QDir::currentPath() + folder).toStdString();
    this->_p_position = position;
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


// ============================ Inherited Methods ===============================
/*-------------------------------------------------------------------
 |  Function loadModels
 |
 |  Purpose: Loads all models without textures
 *-------------------------------------------------------------------*/
void Car::loadModels(){
    _chasisObj = new Object3DFile(_folder, "chasis.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    _chasisObj->setTranslation(_p_position);
    _chasisObj->setRotation(new Point3D(0,0,90));

    _wheelObj = new Object3DFile(_folder, "wheel.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    _wheelObj->setTranslation(_p_position);
    _wheelObj->setRotation(new Point3D(0,0,90));

    _wheelFrontRight = new Object3DFile(_folder, "wheelFrontRight.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    _wheelFrontRight->setTranslation(_p_position);
    _wheelFrontRight->setRotation(new Point3D(0,0,90));

    _wheelFrontLeft = new Object3DFile(_folder, "wheelFrontLeft.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    _wheelFrontLeft->setTranslation(_p_position);
    _wheelFrontLeft->setRotation(new Point3D(0,0,90));

    _wheelRearRight = new Object3DFile(_folder, "wheelRearRight.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    _wheelRearRight->setTranslation(_p_position);
    _wheelRearRight->setRotation(new Point3D(0,0,90));

    _wheelRearLeft = new Object3DFile(_folder, "wheelRearLeft.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    _wheelRearLeft->setTranslation(_p_position);
    _wheelRearLeft->setRotation(new Point3D(0,0,90));
}

/*-------------------------------------------------------------------
 |  Function loadModelsTextures
 |
 |  Purpose: Loads textures of all models
 *-------------------------------------------------------------------*/
void Car::loadModelsTextures(){
    this->_chasisObj->loadTextures();
    this->_wheelObj->loadTextures();
    this->_wheelFrontRight->loadTextures();
    this->_wheelFrontLeft->loadTextures();
    this->_wheelRearRight->loadTextures();
    this->_wheelRearLeft->loadTextures();
}

/*-------------------------------------------------------------------
 |  Function renderModels
 |
 |  Purpose: Render all models
 *-------------------------------------------------------------------*/
void Car::renderModels(){
    this->_chasisObj->render();
    this->_wheelObj->render();
    this->_wheelFrontRight->render();
    this->_wheelFrontLeft->render();
    this->_wheelRearRight->render();
    this->_wheelRearLeft->render();
}

/*-------------------------------------------------------------------
 |  Function displayModels
 |
 |  Purpose: Displays all models
 *-------------------------------------------------------------------*/
void Car::displayModels(){
    this->_chasisObj->display();
    this->_wheelObj->display();
    this->_wheelFrontRight->display();
    this->_wheelFrontLeft->display();
    this->_wheelRearRight->display();
    this->_wheelRearLeft->display();
}
