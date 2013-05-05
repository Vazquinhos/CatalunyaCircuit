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
CameraAbs::CameraAbs( void )
{
    _zoom = 10;
    _yaw = 15;
    _pitch = 30;
    _mode = PERSPECTIVE;
    _name = QString("Not init");
    setPosition(new Point3D(0.0f, 0.0f, 0.0f));
}

/*-------------------------------------------------------------------
 |  Argument Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraAbs::CameraAbs(QString a_name)
{
    _zoom = 10;
    _yaw = 15;
    _pitch = 30;
    _mode = PERSPECTIVE;
    _name = a_name;
    setPosition(new Point3D(0.0f, 0.0f, 0.0f));
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
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   if (_mode == PERSPECTIVE)
   {
       if(w>=h)
           gluPerspective(60.0, 1.0*w/h, 0.1, 40000);
       else
           gluPerspective(60.0*h/w, 1.0*w/h, 0.1, 40000);
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

    // Getting the type of the camera, with the concrete method
    // of each concrete camera.
    QString type = getTypeInQString();

    // Getting the yaw value
    QString yaw;
    yaw.setNum(_yaw);

    // Getting the pitch value
    QString pitch;
    pitch.setNum(_pitch);
    // Getting the zoom value
    QString zoom;
    zoom.setNum(_zoom);

    // Getting the name of the camera
    QString name = getName();

    settings_to_return = QString("<camera>\n") +  QString("<type>") + type +
            QString("</type>\n") + QString("<name>\n")  + name +
            QString("</name>\n") + QString("<position>\n") +
            QString("<x>") + x + QString("</x>\n") +
            QString("<y>") + y + QString("</y>\n") +
            QString("<z>") + z + QString("</z>\n") +
            QString("</position>\n") +
            QString("<yaw>") + yaw + QString("</yaw>\n") +
            QString("<pitch>") + pitch + QString("</pitch>\n") +
            QString("<zoom>") + zoom + QString("</zoom>\n") +
            QString("</camera>\n");

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

void CameraAbs::setYaw( float yaw )
{
    _yaw = yaw;
}

void CameraAbs::setPitch( float pitch )
{
    _pitch = pitch;
}
