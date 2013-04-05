/*
 * Archivo: carinstance.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *
 * Clase: CarInstance
 * Descripcion: Representa cada una de las instancias de los posibles coches en carrera.
 */

#ifndef CARINSTANCE_H
#define CARINSTANCE_H

#include "Utils/util.h"
#include "Utils/vector3D.h"

class Car
{
public:
    // ================= Constructores/Destructores ======================
    Car();
    Car(const Car& car);
    ~Car();

    // ============================ Methods ===============================
    void              render();
    void              setPosition(Point3D * p_position);
    Point3D         * getPosition();
    void              setDirection(Vector3D * p_direction);
    Vector3D        * getDirection();
    void              setBBMin(Point3D * p_bbMin);
    Point3D         * getBBMin();
    void              setBBMax(Point3D * p_bbMax);
    Point3D         * getBBMax();

private:
    // ========================== Data Members ============================
    Point3D         * _p_position;
    Vector3D        * _p_direction;
    Point3D         * _p_bbMin;
    Point3D         * _p_bbMax;
    // ============================ Methods ===============================

};

#endif // CARINSTANCE_H
