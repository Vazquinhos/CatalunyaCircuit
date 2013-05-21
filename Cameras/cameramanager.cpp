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
    _cameraOnCar = false;
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
 |  addCamera(QString a_name, CameraAbs * a_camera)
 |
 |  Purpose:Adds a new camera
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraManager::addCamera(QString a_name, CameraAbs * a_camera)
{
    _cameras[a_name] = a_camera;
}

/*-------------------------------------------------------------------
 |  deleteCamera( QString a_name )
 |
 |  Purpose:Deletes the camera
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraManager::deleteCamera( QString a_name )
{
     if(!(_cameras.find(a_name) == _cameras.end()))
        _cameras.erase(a_name);
}
/*-------------------------------------------------------------------
 |  setCameraOnCar(Point3D position)
 |
 |  Purpose:Sets a camera on a car
 |  Parameters:position
 |  Returns:none
 *-------------------------------------------------------------------*/
void CameraManager::setCameraOnCar(Point3D *position)
{

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

CameraAbs * CameraManager::getActiveCamera()
{
    return _p_activeCamera;
}

void CameraManager::setActiveCamera(CameraAbs * camera)
{
    //Comprobamos si es una camara del manager.
    //Si no lo es, la añadimos.
    QString camera_name = camera->getName();
    if(_cameras.find(camera->getName()) == _cameras.end())
    {
        _cameras[camera->getName()] = camera;
    }

    //Ponemos la camara como camara activa.
    _p_activeCamera = camera;
}

void CameraManager::setActiveCamera(QString name)
{
    _p_activeCamera = this->getCamera(name);
}

std::map<QString,CameraAbs*>
CameraManager::getCameras( void )
{
    return _cameras;
}
