/*
 * Archivo: cameramanager.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: CameraManager
 * Descripcion: Clase Singelton utilizada para gestionar las camaras del proyecto.
 */

#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <QString>
#include<map>

#include "cameraabs.h"

class CameraManager
{
    // ================= Constructores/Destructores ======================
private: CameraManager();
public: ~CameraManager();

public:
    // ============================ Public Methods ===============================
    static CameraManager * getCameraManager();
    CameraAbs            * getCamera(QString a_camera_name);
    void                   addCamera(CameraAbs *a_camera);
    void                   deleteCamera( QString a_name );
    QString                getCCSCameraInfoToExport();
    CameraAbs            * getActiveCamera();
    void                   setActiveCamera(CameraAbs * camera);
    void                   setActiveCamera(QString name);
    std::map<QString,CameraAbs*> getCameras();
    void                   render();
    void                   setPointToLookAnimationCameras(Point3D* pointToLook);
    void                   updateAnimation(Point3D* carPosition);

private:

    // =========================== Data Members =================================
    static CameraManager * _cameraManager;
    std::map<QString, CameraAbs*> _cameras;
    bool _cameraOnCar; //This variable set if camera is focused on cars
    CameraAbs * _p_activeCamera;
    int _currentCameraIndex;

     // ============================ Private Methods ===============================
    void setupCameras();
};

#endif // CAMERAMANAGER_H
