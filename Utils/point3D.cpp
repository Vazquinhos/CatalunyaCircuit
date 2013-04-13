/*
 * Archivo: montmelocircuit.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "point3D.h"
#include "math.h"

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose: Construct a Point3D object with default vaules.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D::Point3D( void )
{
    _x = 0;
    _y = 0;
    _z = 0;
}

/*-------------------------------------------------------------------
 |  Argument Constructor
 |
 |  Purpose: Construct a Point3D object with specific values.
 |  Parameters[in]: float a_x = value for x;
 |                  float a_y = value for y;
                    float a_z = value for z;
 |  Parameters[out]:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D::Point3D( float a_x, float a_y, float a_z)
{
    _x = a_x;
    _y = a_y;
    _z = a_z;
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose: Constructs a Point3D object using another Point3D object.
 |  Parameters: const Point3D& a_pnt = Point3D to copy;
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D::Point3D( const Point3D& a_pnt)
{
    _x = a_pnt.getX();
    _y = a_pnt.getY();
    _z = a_pnt.getZ();
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D::~Point3D( void )
{

}

// ============================ Methods ===============================

/*-------------------------------------------------------------------
 |  Function getX
 |
 |  Purpose: Getter. Gets the X coordinate of the point.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
float
Point3D::getX( void ) const
{
    return _x;
}

/*-------------------------------------------------------------------
 |  Function getY
 |
 |  Purpose: Getter. Gets the Y coordinate of the point.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
float
Point3D::getY( void ) const
{
    return _y;
}

/*-------------------------------------------------------------------
 |  Function getZ
 |
 |  Purpose: Getter. Gets the Z coordinate of the point.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
float
Point3D::getZ( void ) const
{
    return _z;
}

/*-------------------------------------------------------------------
 |  Function getCoordinates
 |
 |  Purpose: Getter. Gets the X and Y coordinates of the point.
 |  Parameters[in]:
 |  Parameters[out]: float& a_x = value of coordinate X
                     float& a_y = value of coordinate Y
                     flaot& a_z = value of coordinate Z
 |  Returns:
 *-------------------------------------------------------------------*/
void
Point3D::getCoordinates(float& a_x, float& a_y, float& a_z)
{
    a_x = _x;
    a_y = _y;
    a_z = _z;
}

/*-------------------------------------------------------------------
 |  Function setCoordinates
 |
 |  Purpose: Setter. Sets the X and Y coordinates of the point.
 |  Parameters[in]: float a_x = value of coordinate X
                    float a_y = value of coordinate Y
                    float a_z = value of coordinate Z
 |  Parameters[out]:
 |  Returns:
 *-------------------------------------------------------------------*/
void
Point3D::setCoordinates(float a_x, float a_y, float a_z)
{
    _x = a_x;
    _y = a_y;
    _z = a_z;
}

// ============================ Operators ===================================

/*-------------------------------------------------------------------
 |  Operator !=
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
bool
Point3D::operator !=( const Point3D& a_pnt)
{
    return !((_x == a_pnt.getX()) &&
             (_y == a_pnt.getY()) &&
             (_z == a_pnt.getZ()));
}

/*-------------------------------------------------------------------
 |  Operator ==
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
bool
Point3D::operator ==( const Point3D& a_pnt)
{
 return ((_x == a_pnt.getX()) &&
         (_y == a_pnt.getY()) &&
         (_z == a_pnt.getZ()));
}

/*-------------------------------------------------------------------
 |  Operator |
 |
 |  Purpose: Get distance between two points
 |  Parameters: The point to calculate the distance to
 |  Returns: The distance to the point
 *-------------------------------------------------------------------*/
float Point3D::getDistance( const Point3D *a_pnt1){
    return sqrt(pow(a_pnt1->getX()-_x, 2) + pow(a_pnt1->getY()-_y, 2) + pow(a_pnt1->getZ()-_z, 2));
}
