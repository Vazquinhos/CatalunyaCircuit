/*
 * Archivo: lightmanager.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "lightmanager.h"

LightManager * LightManager::_lightManager = NULL;

// ================= Constructores/Destructores ======================
LightManager::LightManager()
{
}

// ============================ Methods ===============================
/*-------------------------------------------------------------------
 |  getLightManager()
 |
 |  Purpose: Get the camera manager
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
LightManager * LightManager::getLightManager()
{
    if(!_lightManager)
        _lightManager = new LightManager();

    return _lightManager;
}

/*-------------------------------------------------------------------
 |  getLight(QString light_name)
 |
 |  Purpose: Gets a light with a given name
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Light * LightManager::getLight(QString light_name)
{
    return _lights[light_name];
}

/*-------------------------------------------------------------------
 |  setLight(QString light_name, Light *light)
 |
 |  Purpose: Sets a light into the map
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void LightManager::setLight(QString light_name, Light *light)
{
    _lights[light_name] = light;
}
/*-------------------------------------------------------------------
 |  getXMLCameraInfoToExport( void )
 |
 |  Purpose: Gets the info of the cameras to export them into the XML
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
QString LightManager::getCCSCameraInfoToExport(  )
{
    QString string_to_rtn;
    // Auxiliar varables to get the information of each camera
    Light* light;
    QString info_light;

    // We iterate over all the lights getting their info and concatenating in one string
    for(std::map<QString, Light*>::iterator iter =  _lights.begin(); iter !=  _lights.end(); ++iter)
    {

        light = iter->second;
        if(!light)
            continue;
        info_light = light->getSettingsInfo();
        string_to_rtn += info_light;
    }

    return string_to_rtn;
}
