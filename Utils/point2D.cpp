/*
 * Archivo: montmelocircuit.h
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "point2D.h"

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose: Construct a Point2D object with default vaules.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point2D::Point2D()
{
    _x = 0;
    _y = 0;
}

/*-------------------------------------------------------------------
 |  Argument Constructor
 |
 |  Purpose: Construct a Point2D object with specific values.
 |  Parameters[in]: float a_x = value for x;
 |                  float a_y = value for y;
 |  Parameters[out]:
 |  Returns:
 *-------------------------------------------------------------------*/
Point2D::Point2D( float a_x, float a_y)
{
    _x = a_x;
    _y = a_y;
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose: Constructs a Point2D object using another Point2D object.
 |  Parameters: const Point2D& a_pnt = Point2D to copy;
 |  Returns:
 *-------------------------------------------------------------------*/
Point2D::Point2D( const Point2D& a_pnt)
{
    _x = a_pnt.getX();
    _y = a_pnt.getY();
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point2D::~Point2D()
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
Point2D::getX() const
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
Point2D::getY() const
{
    return _y;
}

/*-------------------------------------------------------------------
 |  Function getCoordinates
 |
 |  Purpose: Getter. Gets the X and Y coordinates of the point.
 |  Parameters[in]:
 |  Parameters[out]: float& a_x = value of coordinate X
                     float& a_y = value of coordinate Y
 |  Returns:
 *-------------------------------------------------------------------*/
void
Point2D::getCoordinates(float& a_x, float& a_y)
{
    a_x = _x;
    a_y = _y;
}

/*-------------------------------------------------------------------
 |  Function setCoordinates
 |
 |  Purpose: Setter. Sets the X and Y coordinates of the point.
 |  Parameters[in]: float a_x = value of coordinate X
                    float a_y = value of coordinate Y
 |  Parameters[out]:
 |  Returns:
 *-------------------------------------------------------------------*/
void
Point2D::setCoordinates(float a_x, float a_y)
{
    _x = a_x;
    _y = a_y;
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
Point2D::operator !=( const Point2D& a_pnt)
{
    return !((_x == a_pnt.getX()) &&
             (_y == a_pnt.getY()));
}

/*-------------------------------------------------------------------
 |  Operator ==
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
bool
Point2D::operator ==( const Point2D& a_pnt)
{
 return ((_x == a_pnt.getX()) &&
         (_y == a_pnt.getY()));
}
