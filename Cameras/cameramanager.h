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
    // ============================ Methods ===============================
    static CameraManager * getCameraManager();
    CameraAbs            * getCamera(QString a_camera_name);
    void                   addCamera(QString a_name, CameraAbs * a_camera);
    void                   deleteCamera( QString a_name );
    QString                getCCSCameraInfoToExport( void );
    void                   setCameraOnCar(Point3D *position);
    CameraAbs            * getActiveCamera();
    void                   setActiveCamera(CameraAbs * camera);
    void                   setActiveCamera(QString name);
    std::map<QString,CameraAbs*> getCameras();

private:

    // =========================== Data Members =================================
    static CameraManager * _cameraManager;
    std::map<QString, CameraAbs*> _cameras;
    bool _cameraOnCar; //This variable set if camera is focused on cars
    CameraAbs * _p_activeCamera;
};

#endif // CAMERAMANAGER_H
