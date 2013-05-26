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
/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose: Construct a default LightManager. Private.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
LightManager::LightManager()
{
}

// ============================ Methods ===============================
/*-------------------------------------------------------------------
 |  Function getLightManager
 |
 |  Purpose: Get the Light manager
 |  Parameters:
 |  Returns: LightManager: returns the LightManager's instance.
 *-------------------------------------------------------------------*/
LightManager * LightManager::getLightManager()
{
    if(!_lightManager)
        _lightManager = new LightManager();

    return _lightManager;
}

/*-------------------------------------------------------------------
 |  Function getLight
 |
 |  Purpose: Gets a light with a given name
 |  Parameters[in]: QString light_name: name of the light
 |  Returns:
 *-------------------------------------------------------------------*/
void LightManager::setupDefault()
{
    //Point3D * pos = new Point3D(146.0f, 161.0f, -64.0f);
    //150,160+i*10,-76.85
    Point3D * pos = new Point3D(0, 0, 80);
    sfvector dif;
    dif.push_back(0.8f);
    dif.push_back(0.8f);
    dif.push_back(0.8f);
    dif.push_back(1.0f);

    sfvector amb;
    amb.push_back(0.5f);
    amb.push_back(0.5f);
    amb.push_back(0.5f);
    amb.push_back(1.0f);

    sfvector spe;
    spe.push_back(0.5f);
    spe.push_back(0.5f);
    spe.push_back(0.5f);
    spe.push_back(1.0f);

    sfvector col;
    col.push_back(1.0f);
    col.push_back(1.0f);
    col.push_back(0.79f);
    col.push_back(1.0f);

    Light * light = new Light(QString("Light0"));
    light->setAmbient(amb);
    light->setPosition(pos);
    light->setColor(col);
    light->setSpecular(spe);
    light->setDiffuse(dif);

    LightManager::getLightManager()->addLight(light);

    Point3D * pos2 = new Point3D(0, 0, 0);
    sfvector dif2;
    dif2.push_back(0.8f);
    dif2.push_back(0.8f);
    dif2.push_back(0.8f);
    dif2.push_back(1.0f);

    sfvector amb2;
    amb2.push_back(0.5f);
    amb2.push_back(0.5f);
    amb2.push_back(0.5f);
    amb2.push_back(1.0f);

    sfvector spe2;
    spe2.push_back(0.5f);
    spe2.push_back(0.5f);
    spe2.push_back(0.5f);
    spe2.push_back(1.0f);

    sfvector col2;
    col2.push_back(1.0f);
    col2.push_back(1.0f);
    col2.push_back(0.79f);
    col2.push_back(1.0f);

    SwivelLight * light2 = new SwivelLight(QString("swivelLight0"));
    light2->setAmbient(amb2);
    light2->setPosition(pos2);
    light2->setColor(col2);
    light2->setSpecular(spe2);
    light2->setDiffuse(dif2);

    LightManager::getLightManager()->addLight(light2);
}

/*-------------------------------------------------------------------
 |  Function getLight
 |
 |  Purpose: Gets a light with a given name
 |  Parameters[in]: QString light_name: name of the light
 |  Returns:
 *-------------------------------------------------------------------*/
Light * LightManager::getLight(QString light_name)
{
    return _lights[light_name];
}

/*-------------------------------------------------------------------
 |  Function setLight
 |
 |  Purpose: Sets a light into the map
 |  Parameters[in]: Light *light: Light to be added.
 |  Returns:
 *-------------------------------------------------------------------*/
void LightManager::addLight(Light *light)
{
    _lights[light->getName()] = light;
}

/*-------------------------------------------------------------------
 |  Function getActiveLight
 |
 |  Purpose: Gets the current active light
 |  Parameters:
 |  Returns: Light*: Current active camera.
 *-------------------------------------------------------------------*/
Light * LightManager::getActiveLight()
{
    return _lights[_active];
}

/*-------------------------------------------------------------------
 |  Function setActiveLight
 |
 |  Purpose: Sets a light into the map
 |  Parameters[in]: QString active: name of active camera want to set.
 |  Returns:
 *-------------------------------------------------------------------*/
void LightManager::setActiveLight(QString active)
{
    _active = active;
}

/*-------------------------------------------------------------------
 |  Function update
 |
 |  Purpose: Update the lights.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void LightManager::update()
{

    _lights[_active]->update(GL_LIGHT0);
}
std::map<QString, Light*>
LightManager::getLights()
{
    return _lights;
}


/*-------------------------------------------------------------------
 |  Function getXMLCameraInfoToExport
 |
 |  Purpose: Gets the info of the cameras to export them into the XML
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
QString LightManager::getCCSLightsInfoToExport(  )
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


