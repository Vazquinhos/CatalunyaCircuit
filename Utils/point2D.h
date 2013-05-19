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

#ifndef Point2D_H
#define Point2D_H

class Point2D{

public:
    // ================= Constructores/Destructores ======================
    Point2D( void );
    Point2D(float a_x, float a_y);
    Point2D(const Point2D& a_pnt);
    ~Point2D( void );

    // ============================ Methods ===============================

    float getX( void ) const;
    float getY( void ) const;
    void setCoordinates( float a_x, float a_y);
    void getCoordinates( float& a_x, float& a_y);

    // ============================ Operators ===================================
    bool operator==( const Point2D& a_pnt);
    bool operator!=( const Point2D& a_pnt);

private:
    // =========================== Data Members =================================
    float _x;
    float _y;

};
#endif // Point2D_H
