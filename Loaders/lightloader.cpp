/*
 * Archivo: lightloader.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "lightloader.h"

LightLoader * LightLoader::_lightLoader = NULL;

// ================= Constructores/Destructores ======================

LightLoader::LightLoader()
{

}

LightLoader::~LightLoader()
{

}

// ============================ Methods ===============================

LightLoader * LightLoader::getLightLoader()
{
    if (_lightLoader == NULL)
        _lightLoader = new LightLoader();

    return _lightLoader;
}

