/*
 * Archivo: cameraabs.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "cameraabs.h"
#include <QString>

// ================= Constructores/Destructores ======================
/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraAbs::CameraAbs()
{
    _zoom = 10;
    _yaw = 0;
    _pitch = 0;
    _mode = PERSPECTIVE;
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraAbs::CameraAbs(const CameraAbs &cameraAbs)
{
    this->_mode        = cameraAbs._mode;
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraAbs::~CameraAbs()
{
}

// ============================ Methods ===============================
/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::resizeProjection(int w, int h)
{
   if (_mode == PERSPECTIVE)
   {
       if(w<=h)
           gluPerspective(60, w/h, 0.1, 500);
       else
           gluPerspective(60*h/w, h/w, 0.1, 500);
   }
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::update()
{
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::render()
{
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::setModeProjection(mode_projection mode)
{
    _mode = mode;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
mode_projection CameraAbs::getModeProjection()
{
    return _mode;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::setPosition(Point3D * p_position)
{
    _p_position = p_position;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * CameraAbs::getPosition()
{
    return _p_position;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::setDirection(Vector3D * p_direction)
{
    _p_direction = p_direction;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Vector3D * CameraAbs::getDirection()
{
    return _p_direction;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::setUp(Vector3D * p_up)
{
    _p_up = p_up;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Vector3D * CameraAbs::getUp()
{
    return _p_up;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Gets the type of the camera
 |  Parameters: none
 |  Returns: The camera_type, defined in utils.h
 *-------------------------------------------------------------------*/
camera_type CameraAbs::getType( void )
{
    return _type;
}
/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Gets the settings of the camera
 |  Parameters: none
 |  Returns: The QString with the type
 *-------------------------------------------------------------------*/
QString
CameraAbs::getSettingsInfo( void )
{
    // We make a qstring to add all the settins info
    QString settings_to_return;

    // The position of the camera
    QString x,y,z;
    x.setNum(_p_position->getX());
    y.setNum(_p_position->getY());
    z.setNum(_p_position->getZ());

    // The direction of the camera
    QString dx,dy,dz;
    dx.setNum(_p_direction->getX());
    dy.setNum(_p_direction->getY());
    dz.setNum(_p_direction->getZ());

    // The vector up of the camera
    QString ux,uy,uz;
    ux.setNum(_p_up->getX());
    uy.setNum(_p_up->getY());
    uz.setNum(_p_up->getZ());

    // Getting the type of the camera, with the concrete method
    // of each concrete camera.
    QString type = getTypeInQString();

    // Getting the name of the camera
    QString name = getName();

    settings_to_return = QString("<camera>\n") +  QString("<type>") + type +
            QString("</type>\n") + QString("<name>\n")  + name +
            QString("</name>\n") + QString("<position>\n") +
            QString("<x>") + x + QString("</x>\n") +
            QString("<y>") + y + QString("</y>\n") +
            QString("<z>") + z + QString("</z>\n") +
            QString("</position>\n") + QString("<direction>\n") +
            QString("<x>") + dx + QString("</x>\n") +
            QString("<y>") + dy + QString("</y>\n") +
            QString("<z>") + dz + QString("</z>\n") +
            QString("</direction>\n") + QString("<up>\n") +
            QString("<x>") + ux + QString("</x>\n") +
            QString("<y>") + uy + QString("</y>\n") +
            QString("<z>") + uz + QString("</z>\n") +
            QString("</up>\n") + QString("</camera>\n");

    return settings_to_return;
}
/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Gets the name of the camera
 |  Parameters: none
 |  Returns: The QString with the name
 *-------------------------------------------------------------------*/
QString CameraAbs::getName( void )
{
    return _name;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Sets the name of the camera
 |  Parameters: The QString with the name
 |  Returns: nothing
 *-------------------------------------------------------------------*/
void CameraAbs::setName( QString a_name )
{
    _name = a_name;
}

void CameraAbs::setYawPitch(float yaw, float pitch)
{
    _yaw = yaw;
    _pitch = pitch;
}

void CameraAbs::addYawPitch(float yaw, float pitch)
{
    _yaw += yaw/2;
    _pitch -= pitch/2;

    if(_yaw>=360)	_yaw=_yaw-360;
    if(_yaw<0)	    _yaw=_yaw+360;
    if(_pitch>=360)	_pitch=_pitch-360;
    if(_pitch<0)	_pitch=_pitch+360;
}

void CameraAbs::getYawPitch(float &yaw, float &pitch)
{
    yaw = _yaw;
    pitch = _pitch;
}

void CameraAbs::setZoom(float zoom)
{
    _zoom = zoom;
}

float CameraAbs::getZoom()
{
    return _zoom;
}
