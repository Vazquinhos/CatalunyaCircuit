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

    glPushMatrix();
    glTranslatef(_p_position->getX(), _p_position->getY(), _p_position->getZ());
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
