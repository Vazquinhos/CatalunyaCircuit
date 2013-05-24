/*
 * Archivo: sphericalcamera.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "sphericalcamera.h"

// ================= Constructores/Destructores ======================
/*-------------------------------------------------------------------
 |  Defaul Constructor
 |
 |  Purpose: Construct a SphericalCamera object with default vaules.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
SphericalCamera::SphericalCamera() : CameraAbs()
{
    _type = SPHERICAL;
}
SphericalCamera::SphericalCamera( QString a_name ): CameraAbs( a_name )
{
    _type = SPHERICAL;
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
SphericalCamera::SphericalCamera(const SphericalCamera&sphericalCamera) : CameraAbs(sphericalCamera)
{
}

/*-------------------------------------------------------------------
 |  Default Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
SphericalCamera::~SphericalCamera()
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
QString SphericalCamera::getTypeInQString()
{
    return "SphericalCamera";
}

/*-------------------------------------------------------------------
 |  Function update
 |
 |  Purpose: updates the parameters of the camera.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void SphericalCamera::update()
{
    float yaw, pitch, zoom;

    getYawPitch(yaw, pitch);
    yaw = yaw*PI/180;
    pitch = pitch*PI/180;
    zoom = getZoom();

    Point3D * position = new Point3D( zoom*cos(yaw)*cos(pitch) + getPosition()->getX(),
                                      zoom*sin(yaw)*cos(pitch) + getPosition()->getY(),
                                      zoom*sin(pitch) + getPosition()->getZ() );

    Vector3D * up = new Vector3D(-cos(yaw)*sin(pitch),
                                 -sin(yaw)*sin(pitch),
                                 cos(pitch) );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(position->getX(),
              position->getY(),
              position->getZ(),
              getPosition()->getX(), getPosition()->getY(), getPosition()->getZ(),
              up->getX(), up->getY(), up->getZ() );

}

/*-------------------------------------------------------------------
 |  Function render
 |
 |  Purpose: renderize a representation of the camera
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
/*void SphericalCamera::render()
{
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(getPosition()->getX(),getPosition()->getY(), getPosition()->getZ());
        glutSolidSphere(2.0f, 100, 100);
    glPushAttrib(GL_CURRENT_BIT);
    glPopMatrix();
}*/
