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

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Car::Car()
{
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
    this->_object3D->display();
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
 |  Purpose: Getter. Gets the representation of the car
 |  Parameters:
 |  Returns: Object3DFile = the representation of the car
 *-------------------------------------------------------------------*/
Object3DFile* Car::getRepresentation(){
    return this->_object3D;
}

/*-------------------------------------------------------------------
 |  Function setRepresentation
 |
 |  Purpose: Setter. Sets the representation of the car
 |  Parameters: Object3DFile object = the representation of the car
 |  Returns:
 *-------------------------------------------------------------------*/
 void Car::setRepresentation(Object3DFile *object){
    this->_object3D = object;
    this->_object3D->render();
 }
