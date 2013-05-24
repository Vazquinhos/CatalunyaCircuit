/*
 * Archivo: fixedcamera.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: FixedCamera
 * Padre: CameraAbs
 * Descripcion: Camara fija, en posición, pero puede contener algun movimiento de animación o cambió de angulo.
 */


#ifndef FIXEDCAMERA_H
#define FIXEDCAMERA_H

#include "cameraabs.h"

class FixedCamera : public CameraAbs
{
public:
    // ================= Constructores/Destructores ======================
    FixedCamera();
    FixedCamera(QString a_name);
    FixedCamera(const FixedCamera& fixedCamera);
    ~FixedCamera();

    // ============================ Methods ===============================
    virtual QString     getTypeInQString();
    virtual void        update();
    //virtual void        render();
    void                animate();


private:
    // ========================== Data Members ============================


    // ============================ Methods ===============================

};

#endif // FIXEDCAMERA_H
