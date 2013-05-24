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
 |  Purpose:
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
 |  Function
 |
 |  Purpose: Gets the type in a QString format
 |  Parameters: none
 |  Returns: The QString with the type
 *-------------------------------------------------------------------*/
QString FreeCamera::getTypeInQString()
{
    return "FreeCamera";
}

void FreeCamera::update()
{
    float yaw, pitch;

    getYawPitch(yaw, pitch);
    yaw = yaw*PI/180;
    pitch = pitch*PI/180;

    Point3D* pointToLook = new Point3D( -cos(pitch)*sin(yaw) + getPosition()->getX(),
                                        sin(pitch) + getPosition()->getY(),
                                        -cos(pitch)*cos(yaw) + getPosition()->getZ() );

/*
    Point3D* pointToLook = new Point3D( cos(yaw)*sin(pitch) + getPosition()->getX(),
                                        sin(pitch) + getPosition()->getY(),
                                        cos(yaw)*cos(pitch) + getPosition()->getZ() );*/

    /*Vector3D * up = new Vector3D(-cos(yaw)*sin(pitch),
                                 -sin(yaw)*sin(pitch),
                                 cos(pitch) );
*/
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(getPosition()->getX(),
              getPosition()->getY(),
              getPosition()->getZ(),
              pointToLook->getX(),
              pointToLook->getY(),
              pointToLook->getZ(),
              0, 1, 0 );
}

void FreeCamera::render()
{

}

void FreeCamera::move(float velocity, bool front)
{
    float yaw, pitch;

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

    Vector3D * direction = new Vector3D( -cos(pitch)*sin(yaw),
                                        sin(pitch),
                                        -cos(pitch)*cos(yaw));
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
