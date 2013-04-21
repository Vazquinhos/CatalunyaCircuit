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
Car::Car(Point3D * position)
{
    ModelManager *manager = ModelManager::getModelManager();
    this->_p_position = position;

    _chasisObj= manager->getModel("chasis.3ds");
    _wheelObj= manager->getModel("wheel.3ds");
    _wheelFrontRight= manager->getModel("wheelFrontRight.3ds");
    _wheelFrontLeft= manager->getModel("wheelFrontLeft.3ds");
    _wheelRearRight= manager->getModel("wheelRearRight.3ds");
    _wheelRearLeft= manager->getModel("wheelRearLeft.3ds");
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
    _chasisObj->display();
    _wheelObj->display();
    _wheelFrontRight->display();
    _wheelFrontLeft->display();
    _wheelRearRight->display();
    _wheelRearLeft->display();
}

/*-------------------------------------------------------------------
 |  Function checkVisibility
 |
 |  Purpose: Modify visibility of the objects taking in consideration distance to the camera
 |  Parameters: Point3D *pointCamera : Position of the camera, int distance : Maximum distance that the object will be visible
 *-------------------------------------------------------------------*/
void Car::checkVisibility(Point3D *pointCamera, int distance){
        _chasisObj->checkVisibility(pointCamera, distance);
        _wheelObj->checkVisibility(pointCamera, distance);
        _wheelFrontRight->checkVisibility(pointCamera, distance);
        _wheelFrontLeft->checkVisibility(pointCamera, distance);
        _wheelRearRight->checkVisibility(pointCamera, distance);
        _wheelRearLeft->checkVisibility(pointCamera, distance);
}
