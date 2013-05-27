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
 |  Purpose: Construct a FixedCamera object with default vaules.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
FixedCamera::FixedCamera() : CameraAbs()
{
    _type = FIXED;

    _pointToLook = new Point3D(0,0,0);


}
FixedCamera::FixedCamera( QString a_name ): CameraAbs( a_name )
{
    _type = FIXED;
     _pointToLook = new Point3D(0,0,0);
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
 |  Function getTypeInQString
 |
 |  Purpose: Gets the type in a QString format
 |  Parameters: none
 |  Returns: The QString with the type
 *-------------------------------------------------------------------*/
QString FixedCamera::getTypeInQString()
{
    return "FixedCamera";
}

/*-------------------------------------------------------------------
 |  Function update
 |
 |  Purpose: updates the parameters of the camera.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void FixedCamera::update()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(getPosition()->getX(),
              getPosition()->getY(),
              getPosition()->getZ(),
              _pointToLook->getX(),
              _pointToLook->getY(),
              _pointToLook->getZ(),
              0, 0, 1 );
}

void FixedCamera::animate()
{

}

/*-------------------------------------------------------------------
 |  Function render
 |
 |  Purpose: renderize a representation of the camera
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
/*void FixedCamera::render()
{
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(getPosition()->getX(),getPosition()->getY(), getPosition()->getZ());
        glutSolidSphere(2.0f, 100, 100);
    glPopAttrib();
    glPopMatrix();
}*/

void FixedCamera::setPointToLook(Point3D *ap_point)
{
    _pointToLook = ap_point;
}

Point3D* FixedCamera::getPointToLook()
{
    return _pointToLook;
}
