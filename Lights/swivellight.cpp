/*
 * Archivo: light.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla 1242528
 *          Alejandro Vázquez    1242110
 *          Fernando Perera      1244166
 *          Darío Orgaz Manjón   1244844
 *          Gabriel Diaz Arias   12
 */

#include "swivellight.h"

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose: Construct a empty light object
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
SwivelLight::SwivelLight( QString a_name ):Light( a_name )
{
    _animationExec = false;
    _radius = 1.0f;
    _animationTime = 0;
    _type = SWIVEL;
}

SwivelLight::~SwivelLight()
{

}

// ============================ Methods ===============================
void SwivelLight::update(double elapsedTime, GLenum lightName)
{
    if(_animationExec == true)
    {
        float angle = _animationTime*360.0f/100000.0f;
        float incx = _radius*cos(angle);
        float incy = _radius*sin(angle);
        qDebug() << "";
        _p_position->setCoordinates(incx + _center->getX(),
                                    incy + _center->getY(),
                                    _center->getZ());
        _animationTime += elapsedTime;

        if(_animationTime > 100000.0f)
            _animationTime = 0;
    }

    Light::update(lightName);
}

void SwivelLight::startAnimation()
{
    _animationExec = true;
    _center = _p_position;
}

void SwivelLight::stopAnimation()
{
    _animationExec = false;
    _p_position = _center;
}
