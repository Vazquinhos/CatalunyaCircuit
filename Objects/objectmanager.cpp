/*
 * Archivo: objectmanager.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "objectmanager.h"
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
    if( !_p_objectManager )
        _p_objectManager = new ObjectManager();

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

void ObjectManager::renderCar(int i)
{
    _v_cars[i]->render();
}

void ObjectManager::renderEnviroment()
{
    _p_enviroment->render();
}

void ObjectManager::renderAll()
{
    unsigned int i;
    _p_enviroment->render();

    for(i = 0; i < _v_cars.size(); i++)
        _v_cars[i]->render();
}
