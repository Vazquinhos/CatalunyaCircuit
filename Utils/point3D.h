/*
 * Archivo: montmelocircuit.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

// -*- mode: C++ -*-
// Copyright(c) 2013 Grafics per Computador 2
// All rights reserved.

#ifndef Point3D_H
#define Point3D_H

#include "Utils/vector3D.h"

class Point3D{

public:
    // ================= Constructores/Destructores ======================
    Point3D();
    Point3D(const float a_x, float a_y, float a_z);
    Point3D(Point3D& a_pnt);
    ~Point3D();

    // ============================ Methods ===============================
    float getX() const;
    float getY() const;
    float getZ() const;
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setCoordinates( float a_x, float a_y, float a_z);
    void getCoordinates( float& a_x, float& a_y, float& a_z);
    float getDistance( const Point3D* a_pnt1);
    Vector3D getVector(const Point3D &a_pnt);

    // ============================ Operators =============================
    bool operator==( const Point3D& a_pnt);
    bool operator!=( const Point3D& a_pnt);
    Point3D* operator+( const Point3D& a_pnt);
    Vector3D* resta(Point3D* a_pnt);

private:
    // =========================== Data Members ===========================
    float _x;
    float _y;
    float _z;
};
#endif // Point3D_H
