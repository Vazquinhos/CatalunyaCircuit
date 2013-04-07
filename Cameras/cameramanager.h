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
    void                   setCamera(QString a_name, CameraAbs * a_camera);
    QString                getCCSCameraInfoToExport( void );
    void                   setCameraOnCar(Point3D *position);

private:

    // =========================== Data Members =================================
    static CameraManager * _cameraManager;
    std::map<QString, CameraAbs*> _cameras;
    bool _cameraOnCar; //This variable set if camera is focused on cars
};

#endif // CAMERAMANAGER_H
