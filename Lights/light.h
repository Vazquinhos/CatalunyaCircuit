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
    Light(QString a_name);
    Light(const Light&ligjt);
    virtual ~Light();

    // ============================ Methods ===============================
    void              render();
    void              update(GLenum lightName);
    void              setColor(sfvector v_color);
    sfvector          getColor();
    void              setSpecular(sfvector v_specular);
    sfvector          getSpecular();
    void              setAmbient(sfvector v_ambient);
    sfvector          getAmbient();
    void              setDiffuse(sfvector v_diffuse);
    sfvector          getDiffuse();
    void              setPosition(Point3D * p_position);
    Point3D         * getPosition();
    QString           getSettingsInfo();
    void              setName( QString a_name);
    QString           getName();
    light_type        getType();
    void              setType( light_type a_type );
protected:
    // ========================== Data Members ============================
    sfvector         _v_color;
    sfvector         _v_specular;
    sfvector         _v_ambient;
    sfvector         _v_diffuse;
    Point3D        * _p_position;
    QString          _name;
    light_type       _type;

    // ============================ Methods ===============================
};

#endif // LIGHT_H
