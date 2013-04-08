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
#include "Objects/object3DFile.h"

class Car
{
public:
    // ================= Constructores/Destructores ======================
    Car(QString folder, Point3D * position);
    Car(const Car& car);
    ~Car();

    // ============================ Methods ===============================
    void              render();
    void              display();
    void              setPosition(Point3D * p_position);
    Point3D         * getPosition();
    void              setDirection(Vector3D * p_direction);
    Vector3D        * getDirection();
    void              setBBMin(Point3D * p_bbMin);
    Point3D         * getBBMin();
    void              setBBMax(Point3D * p_bbMax);
    Point3D         * getBBMax();

    Object3DFile* getChasisObj();
    void setChasisObj(Object3DFile *object);

    Object3DFile* getWheelObj();
    void setWheelObj(Object3DFile *object);

    Object3DFile* getWheelFrontRightObj();
    void setWheelFrontRightObj(Object3DFile *object);

    Object3DFile* getWheelFrontLeftObj();
    void setWheelFrontLeftObj(Object3DFile *object);

    Object3DFile* getWheelRearRightObj();
    void setWheelRearRightObj(Object3DFile *object);

    Object3DFile* getWheelRearLeftObj();
    void setWheelRearLeftObj(Object3DFile *object);

private:
    // ========================== Data Members ============================
    Object3DFile *_chasisObj;
    Object3DFile *_wheelObj;
    Object3DFile *_wheelFrontRight;
    Object3DFile *_wheelFrontLeft;
    Object3DFile *_wheelRearRight;
    Object3DFile *_wheelRearLeft;

    Point3D         * _p_position;
    Vector3D        * _p_direction;
    Point3D         * _p_bbMin;
    Point3D         * _p_bbMax;
    // ============================ Methods ===============================

};

#endif // CARINSTANCE_H
