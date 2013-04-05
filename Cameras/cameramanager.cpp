/*
 * Archivo: cameramanager.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "cameramanager.h"

CameraManager * CameraManager::_cameraManager = NULL;

// ================= Constructores/Destructores ======================
/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraManager::CameraManager()
{
}

// ============================ Methods ===============================

/*-------------------------------------------------------------------
 |  getCameraManager( void )
 |
 |  Purpose: Gets the singleton of the camera
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraManager * CameraManager::getCameraManager( void )
{
    if(!_cameraManager)
    _cameraManager = new CameraManager();

    return _cameraManager;
}

/*-------------------------------------------------------------------
 |  getCamera(QString camera_name)
 |
 |  Purpose: Gets a camera with a given name
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraAbs * CameraManager::getCamera(QString camera_name)
{
    if(_cameras.find(camera_name) != _cameras.end())
        return _cameras[camera_name];
    return NULL;
}

/*-------------------------------------------------------------------
 |  setCamera(std::string name, CameraAbs * camera)
 |
 |  Purpose:Sets a new camera
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraManager::setCamera(QString a_name, CameraAbs * a_camera)
{
    _cameras[a_name] = a_camera;
}

/*-------------------------------------------------------------------
 |  getXMLCameraInfoToExport( void )
 |
 |  Purpose: Gets the info of the cameras to export them into the XML
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
QString CameraManager::getCCSCameraInfoToExport( void )
{
    QString string_to_rtn;

    // Auxiliar varables to get the information of each camera
    CameraAbs* camera;
    QString info_camera;

     // We iterate over all the cameras getting their info and concatenating in one string
    for(std::map<QString, CameraAbs*>::iterator iter =  _cameras.begin(); iter !=  _cameras.end(); ++iter)
    {

        camera = iter->second;
        if(!camera)
            continue;
        info_camera = camera->getSettingsInfo();
        string_to_rtn += info_camera;
    }
    return string_to_rtn;
}
