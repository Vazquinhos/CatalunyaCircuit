/*
 * Archivo: fixedcamera.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "fixedcamera.h"

// ================= Constructores/Destructores ======================
/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
FixedCamera::FixedCamera() : CameraAbs()
{
    _type = FIXED;
}
FixedCamera::FixedCamera( QString a_name ): CameraAbs( a_name )
{
    _type = FIXED;
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
FixedCamera::FixedCamera(const FixedCamera&fixedCamera) : CameraAbs(fixedCamera)
{
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
FixedCamera::~FixedCamera()
{
}

// ============================ Methods ===============================
/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Gets the type in a QString format
 |  Parameters: none
 |  Returns: The QString with the type
 *-------------------------------------------------------------------*/
QString FixedCamera::getTypeInQString( void )
{
    return "FixedCamera";
}
