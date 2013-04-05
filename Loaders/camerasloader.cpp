/*
 * Archivo: camerasloader.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "camerasloader.h"

CamerasLoader * CamerasLoader::_camerasLoader = NULL;

// ================= Constructores/Destructores ======================

CamerasLoader::CamerasLoader()
{
}

CamerasLoader::~CamerasLoader()
{
}

// ============================ Methods ===============================
CamerasLoader * CamerasLoader::getCamerasLoader()
{
    if (_camerasLoader == NULL)
        _camerasLoader = new CamerasLoader();

    return _camerasLoader;
}
