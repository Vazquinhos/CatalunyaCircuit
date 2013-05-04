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

    //glCallLists(_displayLists.size(), GL_UNSIGNED_INT, &_displayLists[0]);


    _p_enviroment->displayModels();

    for(unsigned int i = 0; i < _v_cars.size(); i++){
        _v_cars[i]->displayModels();
    }


}

/*-------------------------------------------------------------------
 |  Function checkVisibility
 |
 |  Purpose: Modify visibility of the objects taking in consideration distance to the camera
 |  Parameters: Point3D *pointCamera : Position of the camera, int distance : Maximum distance that the object will be visible
 *-------------------------------------------------------------------*/
void ObjectManager::checkVisibility(Point3D *pointCamera, int distance){
    vector<GLuint> displayLists;
    vector<GLuint> enviromentLists = _p_enviroment->checkVisibility(pointCamera,  distance);

    displayLists.insert(displayLists.end(), enviromentLists.begin(), enviromentLists.end());

    for(unsigned int i = 0; i < _v_cars.size(); i++){
        vector<GLuint> carLists =  _v_cars[i]->checkVisibility(pointCamera,  distance);
        displayLists.insert(displayLists.end(), carLists.begin(), carLists.end());
    }

    this->_displayLists = displayLists;
}
