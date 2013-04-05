/*
 * Archivo: enviroment.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "enviroment.h"

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::Enviroment()
{
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::Enviroment(const Enviroment &enviroment)
{
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::~Enviroment()
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
void Enviroment::render()
{
}

/*-------------------------------------------------------------------
 |  Function getRepresentation
 |
 |  Purpose: Getter. Gets the representation of the enviroment
 |  Parameters:
 |  Returns: Object3DFile = the representation of the enviroment
 *-------------------------------------------------------------------*/
Object3DFile* Enviroment::getRepresentation(){
    return this->_object3D;
}

/*-------------------------------------------------------------------
 |  Function setRepresentation
 |
 |  Purpose: Setter. Sets the representation of the enviroment
 |  Parameters: Object3DFile object = the representation of the enviroment
 |  Returns:
 *-------------------------------------------------------------------*/
 void Enviroment::setRepresentation(Object3DFile *object){
    this->_object3D = object;
    this->_object3D->render();
 }

