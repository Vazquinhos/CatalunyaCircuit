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

class Point3D{

public:
    // ================= Constructores/Destructores ======================
    Point3D( void );
    Point3D(float a_x, float a_y, float a_z);
    Point3D(const Point3D& a_pnt);
    ~Point3D( void );

    // ============================ Methods ===============================
    float getX( void ) const;
    float getY( void ) const;
    float getZ( void ) const;
    void setCoordinates( float a_x, float a_y, float a_z);
    void getCoordinates( float& a_x, float& a_y, float& a_z);
    float getDistance( const Point3D* a_pnt1);

    // ============================ Operators =============================
    bool operator==( const Point3D& a_pnt);
    bool operator!=( const Point3D& a_pnt);

private:
    // =========================== Data Members ===========================
    float _x;
    float _y;
    float _z;
};
#endif // Point3D_H
