/*
 * Archivo: light.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: Light
 * Descripcion: Clase que contiene la iluminación de la escena. Puede haber diferentes instancias de esta clase.
 */


#ifndef SWIVELLIGHT_H
#define SWIVELLIGHT_H

#include "Utils/util.h"
#include "Lights/light.h"

#include <vector>

class SwivelLight : public Light
{
public:
    // ================= Constructores/Destructores ======================
    SwivelLight( QString a_name );
    ~SwivelLight();

    // ============================ Methods ===============================
    void              update(double elapsedTime, GLenum lightName);
    void              startAnimation();
    void              stopAnimation();
private:
    // ========================== Data Members ============================
    bool             _animationExec;
    float            _radius;
    float            _angle;
    double          _animationTime;
    Point3D        * _center;

    // ============================ Methods ===============================
};

#endif // SWIVELLIGHT_H
