/*
 * Archivo: freecamera.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: FreeCamera
 * Padre: CameraAbs
 * Descripcion: Camara libre, con movimiento en 3 dimensiones.
 */

#ifndef FREECAMERA_H
#define FREECAMERA_H

#include "cameraabs.h"

class FreeCamera : public CameraAbs
{
public:

    // ================= Constructores/Destructores ======================
    FreeCamera();
    FreeCamera(QString a_name);
    FreeCamera(const FreeCamera& freeCamera);
    ~FreeCamera();

    // ============================ Methods ===============================
    virtual QString     getTypeInQString();
    virtual void        update();
    //virtual void        render();
    virtual void        move(float velocity, bool front);
    void                move(float incrementX, float incrementY, float incrementZ);


private:
    // ========================== Data Members ============================


    // ============================ Methods ===============================
};

#endif // FREECAMERA_H
