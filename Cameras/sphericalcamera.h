/*
 * Archivo: sphericalcamera.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: SphericalCamera
 * Padre: CameraAbs
 * Descripcion: Camara esférica, nos permite visualizar un objeto central desde qualquier vista.
 */

#ifndef SPHERICALCAMERA_H
#define SPHERICALCAMERA_H

#include "cameraabs.h"

class SphericalCamera : public CameraAbs
{
public:

    // ================= Constructores/Destructores ======================
    SphericalCamera();
    SphericalCamera(const SphericalCamera& sphericalCamera);
    ~SphericalCamera();

    // ============================ Methods ===============================
    virtual QString     getTypeInQString( void );
    void update();
    void render();
private:
    // ========================== Data Members ============================


    // ============================ Methods ===============================
};

#endif // SPHERICALCAMERA_H
