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
#include "Cameras/sphericalcamera.h"
#include "Cameras/fixedcamera.h"
#include "Cameras/freecamera.h"
#include "Loaders/settingsimporter.h"

#include <QDir>

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
    _currentCameraIndex = 1;
}

// ============================ Methods ===============================

/*-------------------------------------------------------------------
 |  getCameraManager
 |
 |  Purpose: Gets the singleton of the camera
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraManager * CameraManager::getCameraManager()
{
    if(_cameraManager == NULL){
        _cameraManager = new CameraManager();
        _cameraManager->setupCameras();
    }

    return _cameraManager;
}

void CameraManager::render()
{
    CameraAbs* camera;
    for(std::map<QString, CameraAbs*>::iterator iter =  _cameras.begin(); iter !=  _cameras.end(); ++iter)
    {
        camera = iter->second;
        if(!camera || _p_activeCamera==camera)
            continue;
        camera->render();
    }
}

void CameraManager::setupCameras() {
    SphericalCamera * spCam = new SphericalCamera(QString("spherical"));
    FreeCamera * frCam = new FreeCamera(QString("free"));
    FreeCamera* fxCam = new FreeCamera(QString("CarViewerCamera"));
    FixedCamera* fxCamCar = new FixedCamera(QString("CarCamera"));

    FreeCamera * frCamTEST = new FreeCamera(QString("freeTest"));
    frCamTEST->setPosition(new Point3D(210.696f, -68.176f, -45.7906));
    //(150,-76.85,-200+i*10+zIncrement)

    Point3D* point= new Point3D(152.742,137.498,-74.439);
    fxCam->setPosition(point);
    fxCam->setYawPitch(135,337);

    frCam->setPosition(new Point3D(214.621,39.6959,-73.664));
    frCam->setYawPitch(59,356);

    _cameraManager->addCamera(spCam);
    _cameraManager->addCamera(frCam);
    _cameraManager->addCamera(frCamTEST);
    _cameraManager->addCamera(fxCam);
    _cameraManager->addCamera(fxCamCar);
    _cameraManager->setActiveCamera("free");

    SettingsImporter *importer = new SettingsImporter(QDir::currentPath() + "/cameras.ccs");
    importer->SetParameters(true,
                                       false,//ui->car_chk->isChecked(),
                                       false);
    importer->Execute();
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
void CameraManager::addCamera(CameraAbs * a_camera)
{
    _cameras[a_camera->getName()] = a_camera;
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
 |  getXMLCameraInfoToExport()
 |
 |  Purpose: Gets the info of the cameras to export them into the XML
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
QString CameraManager::getCCSCameraInfoToExport()
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

void CameraManager::setPointToLookAnimationCameras(Point3D* pointToLook, Vector3D* vectorDir )
{
    for (int i = 1; i <= 24; ++i)
    {
        QString name;
        if(i <10)
            name = QString("Recorrido0%1").arg(i);
        else
            name = QString("Recorrido%1").arg(i);
        ((FixedCamera*)_cameras[name])->setPointToLook(pointToLook);
    }

    ((FixedCamera*) _cameras[QString("CarCamera")])->setPointToLook(new Point3D(pointToLook->getX() + vectorDir->getX(),
                                                                                pointToLook->getY() + vectorDir->getY(),
                                                                                pointToLook->getZ()+1));
/*
    Point3D* currentCamPos =  getActiveCamera()->getPosition();

    Vector3D* currentDistanceVec = new Vector3D(pointToLook->getX()- currentCamPos->getX(),
                                                pointToLook->getY()- currentCamPos->getY(),
                                                pointToLook->getZ()- currentCamPos->getZ());

     QString name = getActiveCamera()->getName();

     int number = name.rightRef(2).toString().toInt();

     Point3D* nextCamPos;
     if( number < 10 )
     nextCamPos = (_cameras[QString("Recorrido0%1").arg(number + 1)])->getPosition();
     else
     nextCamPos = (_cameras[QString("Recorrido%1").arg(number + 1)])->getPosition();
     Vector3D* nextDistanceVec = new Vector3D(pointToLook->getX()- nextCamPos->getX(),
                                              pointToLook->getY()- nextCamPos->getY(),
                                              pointToLook->getZ()- nextCamPos->getZ());

     if( nextDistanceVec->module() < currentDistanceVec->module() )
        setActiveCamera(QString("Recorrido%1").arg(number + 1));

     setActiveCamera(QString("Recorrido%1").arg(number));
*/
}

void CameraManager::setActiveCamera(CameraAbs * camera)
{
    //Comprobamos si es una camara del manager.
    //Si no lo es, la añadimos.
    QString camera_name = camera->getName();
    if(_cameras.find(camera_name) == _cameras.end())
    {
        if(camera_name == "CarCamera")
            _cameraOnCar = true;
        else
            _cameraOnCar = false;
        _cameras[camera_name] = camera;
    }

    //Ponemos la camara como camara activa.
    _p_activeCamera = camera;
}

void CameraManager::setActiveCamera(QString name)
{
    if(name == "CarCamera")
        _cameraOnCar = true;
    else
        _cameraOnCar = false;
    _p_activeCamera = this->getCamera(name);
}

std::map<QString,CameraAbs*>
CameraManager::getCameras()
{
    return _cameras;
}

void CameraManager::updateAnimation(Point3D * carPosition)
{
    Point3D * cameraPosition;
    float value1, value2;

    QString name1;
    QString name2;

    if(!_cameraOnCar)
    {
        if(_currentCameraIndex < 9)
        {
            name1 = QString("Recorrido0%1").arg(_currentCameraIndex);
            name2 = QString("Recorrido0%1").arg(_currentCameraIndex+1);
        }
        else if(_currentCameraIndex < 10)
        {
            name1 = QString("Recorrido0%1").arg(_currentCameraIndex);
            name2 = QString("Recorrido%1").arg(_currentCameraIndex+1);
        }
        else
        {
            name1 = QString("Recorrido%1").arg(_currentCameraIndex);
            name2 = QString("Recorrido%1").arg(_currentCameraIndex+1);
        }

        if(_currentCameraIndex < 24)
        {
            cameraPosition = _cameras[name1]->getPosition();
            value1 = cameraPosition->getDistance(carPosition);

            cameraPosition = _cameras[name2]->getPosition();
            value2 = cameraPosition->getDistance(carPosition);

            if(value2 < value1)
            {
                _currentCameraIndex++;
                if(_cameras[name2]!=NULL)
                    setActiveCamera(name2);
            }
            else
            {
                if(_cameras[name1]!=NULL)
                    setActiveCamera(name1);
            }
        }
    }
}
