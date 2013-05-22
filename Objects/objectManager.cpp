/*
 * Archivo: objectmanager.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "objectManager.h"
#include <stdio.h>

ObjectManager * ObjectManager::_p_objectManager = NULL;

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
ObjectManager::ObjectManager()
{
    _v_gridPositions.push_back(new Point3D(223.74,55.1665,-76));
    _v_gridPositions.push_back(new Point3D(223.461,64.0395,-76));
    _v_gridPositions.push_back(new Point3D(231.666,67.7427,-76));
    _v_gridPositions.push_back(new Point3D(231.872,77.4715,-76));
    _v_gridPositions.push_back(new Point3D(240.263,81.1895,-76));
    _driveCar = NULL;
}

// ============================ Methods ===============================

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
ObjectManager * ObjectManager::getObjectManager()
{
    if( !_p_objectManager ) {
        _p_objectManager = new ObjectManager();
    }

    return _p_objectManager;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Car * ObjectManager::getCar(int i)
{
    return _v_cars[i];
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void ObjectManager::addCar(Car * ap_car)
{
    _v_cars.push_back(ap_car);
}

/*-------------------------------------------------------------------
 |  Function setActiveDriveCar
 |
 |  Purpose: Sets de active driving car taking prior position of existing one
 |  Parameters: Car *car: The drive car to add
 *-------------------------------------------------------------------*/
void ObjectManager:: setActiveDriveCar(Car *car){
    if(_driveCar){
        car->setPosition(_driveCar->getPosition());
        delete _driveCar;
    }else{
        car->setPosition(_v_gridPositions[1]);
    }
    _driveCar = car;
    checkVisibility();
}

/*-------------------------------------------------------------------
 |  Function getActiveDriveCar
 |
 |  Purpose: Getter
 |  Returns: The active drive car
 *-------------------------------------------------------------------*/
Car * ObjectManager::getActiveDriveCar(){
    return _driveCar;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Add a car at the i position of the grid
 |  Parameters: Car * ap_car: the car to add
 |              int pos: Position of the grid
 |  Returns:    bool If the car could have been added or max cars has been reached
 *-------------------------------------------------------------------*/
bool ObjectManager::addCarAtPosition(Car * ap_car, int pos)
{
    bool added = false;

    if(pos < _v_gridPositions.size()){
        ap_car->setPosition(_v_gridPositions[pos]);
        _v_cars.push_back(ap_car);
        added = true;
    }
    return added;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void ObjectManager::rmvCar(int a_index)
{
    //TESTEAR
    _v_cars.erase( _v_cars.begin() + a_index );
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void ObjectManager::setEnviroment(Enviroment * enviroment)
{
    _p_enviroment = enviroment;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment * ObjectManager::getEnviroment()
{
    return _p_enviroment;
}


/*-------------------------------------------------------------------
 |  Function displayAll
 |
 |  Purpose: Displays all objects
 *-------------------------------------------------------------------*/
void ObjectManager::displayAll(){

    glCallLists(_displayLists.size(), GL_UNSIGNED_INT, &_displayLists[0]);

    for(unsigned int i = 0; i < _v_cars.size(); i++){
        _v_cars[i]->displayModels();
    }
    if(_driveCar){
        _driveCar->displayModels();
    }
}

/*-------------------------------------------------------------------
 |  Function checkVisibility
 |
 |  Purpose: Modify visibility of the objects taking in consideration distance to the camera
 |  Parameters: Point3D *pointCamera : Position of the camera, int distance : Maximum distance that the object will be visible
 *-------------------------------------------------------------------*/
void ObjectManager::checkVisibility(){
    _displayLists.clear();
    _p_enviroment->checkVisibility(&_displayLists);

    for(unsigned int i = 0; i < _v_cars.size(); i++){
        _v_cars[i]->checkVisibility();
    }

    if(_driveCar){
        _driveCar->checkVisibility();
    }
}
