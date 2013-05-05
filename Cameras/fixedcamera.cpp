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

void FixedCamera::update()
{
    float yaw, pitch;

    getYawPitch(yaw, pitch);
    yaw = yaw*PI/180;
    pitch = pitch*PI/180;

    Point3D * pointToLook = new Point3D( cos(yaw)*cos(pitch) + getPosition()->getX(),
                                      sin(yaw)*cos(pitch) + getPosition()->getY(),
                                      sin(pitch) + getPosition()->getZ() );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(getPosition()->getX(),
              getPosition()->getY(),
              getPosition()->getZ(),
              pointToLook->getX(),
              pointToLook->getY(),
              pointToLook->getZ(),
              0, 0, 1 );
}

void FixedCamera::animate()
{

}
