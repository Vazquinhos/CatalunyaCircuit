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
// All rights reserved.´

#include "vector3D.h" // Class declaration

#include <math.h>
#include <QDebug>

// ================= Constructores/Destructores ======================
/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose: Construct a Vector3D object with default vaules.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Vector3D::Vector3D( void )
{
    _x = 0;
    _y = 0;
    _z = 0;
}

/*-------------------------------------------------------------------
 |  Argument Constructor
 |
 |  Purpose: Construct a Vector3D object with specific values.
 |  Parameters[in]: float a_x = value for X;
 |                  float a_y = value for Y;
                    float a_z = value for Z;
 |  Parameters[out]:
 |  Returns:
 *-------------------------------------------------------------------*/
Vector3D::Vector3D( float a_x, float a_y, float a_z )
{
    _x = a_x;
    _y = a_y;
    _z = a_z;
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose: Constructs a Vector3D object using another Vector3D object.
 |  Parameters: const Vector3D& a_pnt = Vector3D to copy;
 |  Returns:
 *-------------------------------------------------------------------*/
Vector3D::Vector3D( const Vector3D& a_vec )
{
    _x = a_vec.getX();
    _y = a_vec.getY();
    _z = a_vec.getZ();
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Vector3D::~Vector3D( void )
{

}

// ============================ Methods ===============================

/*-------------------------------------------------------------------
 |  Function angle
 |
 |  Purpose: Calculate the angle between the vector and another vector.
 |  Parameters[in]: const Vector3D& a_vec = Vector to get the angle with;
 |  Returns: double angle = value of angle of the vector.
 *-------------------------------------------------------------------*/
double
Vector3D::angle( const Vector3D& a_vec )
{
    return acos( ((*this)^a_vec) / (module() * a_vec.module()));
}

/*-------------------------------------------------------------------
 |  Function module
 |
 |  Purpose: Calculate the module of the vector.
 |  Parameters:
 |  Returns: double module = value of module of the vector.
 *-------------------------------------------------------------------*/
double
Vector3D::module( void ) const
{
    return sqrt(_x*_x + _y*_y +_z*_z);
}

/*-------------------------------------------------------------------
 |  Function makeContrary
 |
 |  Purpose: Change direction of the vector to the oposite.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void
Vector3D::makeContrary( void )
{
    _x = _x*-1;
    _y = _y*-1;
    _z = _z*-1;
}

/*-------------------------------------------------------------------
 |  Function normalize
 |
 |  Purpose: Normalize the vector.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void
Vector3D::normalize( void )
{
    double modul = module();

    _x = _x/modul;
    _y = _y/modul;
    _z = _z/modul;
}

/*-------------------------------------------------------------------
 |  Function setCoordinates
 |
 |  Purpose: Setter. Sets the X and Y coordinates of the point.
 |  Parameters[in]: float a_x = value of coordinate X
 |                  float a_y = value of coordinate Y
 |                  float a_z = value of coordinate Z
 |  Parameters[out]:
 |  Returns:
 *-------------------------------------------------------------------*/
void
Vector3D::setCoordinates(float a_x, float a_y, float a_z)
{
    _x = a_x;
    _y = a_y;
    _z = a_z;
}

/*-------------------------------------------------------------------
 |  Function getCoordinates
 |
 |  Purpose: Getter. Gets the X and Y coordinates of the vector.
 |  Parameters[in]:
 |  Parameters[out]: float& a_x = value of coordinate X
 |                   float& a_y = value of coordinate Y
 |                   flaot& a_z = value of coordinate Z
 |  Returns:
 *-------------------------------------------------------------------*/
void
Vector3D::getCoordinates(float& a_x, float& a_y, float& a_z)
{
    a_x = _x;
    a_y = _y;
    a_z = _z;
}

/*-------------------------------------------------------------------
 |  Function getX
 |
 |  Purpose: Getter. Gets the X coordinate of the vector.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
float
Vector3D::getX( void ) const
{
    return _x;
}

/*-------------------------------------------------------------------
 |  Function getY
 |
 |  Purpose: Getter. Gets the Y coordinate of the vector.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
float
Vector3D::getY( void ) const
{
    return _y;
}

/*-------------------------------------------------------------------
 |  Function getZ
 |
 |  Purpose: Getter. Gets the Z coordinate of the vector.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
float
Vector3D::getZ( void ) const
{
    return _z;
}

// ============================ Operators ===================================

/*-------------------------------------------------------------------
 |  Operator ==
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
bool
Vector3D::operator==( const Vector3D& a_vec )
{
    return ((_x == a_vec.getX()) && ( _y == a_vec.getY()) && (_z == a_vec.getZ()));
}

/*-------------------------------------------------------------------
 |  Operator ^
 |
 |  Purpose: Escalar Product between the vector and another vector.
 |  Parameters[in]: const Vector3D& a_vec = //TODO;
 |  Returns:
 *-------------------------------------------------------------------*/
double
Vector3D::operator^( const Vector3D& a_vec )
{
    return ((_x * a_vec.getX() ) + (_y * a_vec.getY())+  (_z * a_vec.getZ()));
}

/*-------------------------------------------------------------------
 |  Operator ^
 |
 |  Purpose: Product between the vector and a scalar.
 |  Parameters[in]: const double& a_scalar = Scalar to multiplicate with.
 |  Returns:
 *-------------------------------------------------------------------*/
Vector3D
Vector3D::operator^( const double& a_scalar )
{
    float x,y,z;

    x = _x * a_scalar;
    y = _y * a_scalar;
    z = _z * a_scalar;

    return Vector3D(x,y,z);
}

/*-------------------------------------------------------------------
 |  Operator *
 |
 |  Purpose: Vectorial Product between the vector and another vector.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Vector3D
Vector3D::operator*( const Vector3D& a_vec )
{
    float x, y , z;

    x = ( _y * a_vec.getZ() ) - ( a_vec.getY() * _z );
    y = ( _x * a_vec.getZ() ) - ( a_vec.getX() * _z );
    z = ( _x * a_vec.getY() ) - ( a_vec.getX() * _y );

    return Vector3D(x,y,z);
}
