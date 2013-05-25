/*
 * Archivo: freecamera.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "freecamera.h"
#include <QString>

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose: Construct a FreeCamera object with default vaules.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
FreeCamera::FreeCamera() : CameraAbs()
{
    _type = FREE;
}
FreeCamera::FreeCamera( QString a_name ): CameraAbs( a_name )
{
    _type = FREE;
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
FreeCamera::FreeCamera(const FreeCamera &freeCamera) : CameraAbs(freeCamera)
{
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
FreeCamera::~FreeCamera()
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
QString FreeCamera::getTypeInQString()
{
    return "FreeCamera";
}

/*-------------------------------------------------------------------
 |  Function update
 |
 |  Purpose: updates the parameters of the camera.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void FreeCamera::update()
{
    Point3D* pointToLook = new Point3D(_dirVec->getX() + getPosition()->getX(),
                                       _dirVec->getY() + getPosition()->getY(),
                                       _dirVec->getZ() + getPosition()->getZ());
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(getPosition()->getX(),
              getPosition()->getY(),
              getPosition()->getZ(),
              pointToLook->getX(),
              pointToLook->getY(),
              pointToLook->getZ(),
              0, 0, 1);
}

/*-------------------------------------------------------------------
 |  Function render
 |
 |  Purpose: renderize a representation of the camera
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
/*void FreeCamera::render()
{
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(getPosition()->getX(),getPosition()->getY(), getPosition()->getZ());
        glutSolidSphere(2.0f, 100, 100);
    glPushAttrib(GL_CURRENT_BIT);
    glPopMatrix();
}*/

void FreeCamera::move(float velocity, bool front)
{
    float yaw, pitch;

    getYawPitch(yaw, pitch);
    yaw = yaw*PI/180;
    pitch = pitch*PI/180;

    _dirVec = new Vector3D(cos(yaw)*cos(pitch),
                           sin(yaw)*cos(pitch),
                           sin(pitch) );

    getYawPitch(yaw, pitch);
    if(!front)
    {
        yaw = yaw - 90;
        pitch = 0;
        if(yaw < 0)
            yaw = yaw + 360;

    }

    yaw = yaw*PI/180;
    pitch = pitch*PI/180;

    Vector3D * direction = new Vector3D(cos(yaw)*cos(pitch),
                                        sin(yaw)*cos(pitch),
                                        sin(pitch) );

    direction->normalize();

    move(direction->getX()*velocity, direction->getY()*velocity, direction->getZ()*velocity);
}

void FreeCamera::move(float incrementX, float incrementY, float incrementZ)
{
    Point3D * newPosition = new Point3D(getPosition()->getX()+incrementX,
                                        getPosition()->getY()+incrementY,
                                        getPosition()->getZ()+incrementZ);
    setPosition(newPosition);
}

Vector3D*
FreeCamera::getDirectionVector()
{
    return _dirVec;
}
