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
#include "Objects/absModels.h"

class Car : AbsModels
{
public:
    // ================= Constructores/Destructores ======================
    Car(QString folder, Point3D * position);
    Car(const Car& car);
    ~Car();

    // ============================ Methods ===============================
    void              setPosition(Point3D * p_position);
    Point3D         * getPosition();
    void              setDirection(Vector3D * p_direction);
    Vector3D        * getDirection();
    void              setBBMin(Point3D * p_bbMin);
    Point3D         * getBBMin();
    void              setBBMax(Point3D * p_bbMax);
    Point3D         * getBBMax();

    // ============================ Inherited Methods ===============================
    void loadModels();
    void loadModelsTextures();
    void renderModels();
    void displayModels();

private:
    // ========================== Data Members ============================
    Object3DFile *_chasisObj;
    Object3DFile *_wheelObj;
    Object3DFile *_wheelFrontRight;
    Object3DFile *_wheelFrontLeft;
    Object3DFile *_wheelRearRight;
    Object3DFile *_wheelRearLeft;

    std::string _folder;

    Point3D         * _p_position;
    Vector3D        * _p_direction;
    Point3D         * _p_bbMin;
    Point3D         * _p_bbMax;
    // ============================ Methods ===============================

};

#endif // CARINSTANCE_H
