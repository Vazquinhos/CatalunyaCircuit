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


#ifndef LIGHT_H
#define LIGHT_H

#include "Utils/util.h"
#include <vector>

class Light
{
public:
    // ================= Constructores/Destructores ======================
    Light();
    Light(const Light&ligjt);
    ~Light();

    // ============================ Methods ===============================
    void              render();
    void              update();
    void              setColor(sfvector v_color);
    sfvector          getColor();
    void              setEspecular(sfvector v_especular);
    sfvector          getEspecular();
    void              setAmbient(sfvector v_ambient);
    sfvector          getAmbient();
    void              setPosition(Point3D * p_position);
    Point3D         * getPosition();
    QString           getSettingsInfo();
    void              setName( QString a_name);
    QString           getName();
private:
    // ========================== Data Members ============================
    sfvector         _v_color;
    sfvector         _v_especular;
    sfvector         _v_ambient;
    Point3D        * _p_position;
    QString         _name;

    // ============================ Methods ===============================
};

#endif // LIGHT_H
