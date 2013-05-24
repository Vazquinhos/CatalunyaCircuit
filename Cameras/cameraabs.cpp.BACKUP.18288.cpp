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
 |  Purpose: Construct a camera object with default vaules.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraAbs::CameraAbs()
{
    _zoom = 10;
<<<<<<< HEAD
    _yaw = 57;
    _pitch = 359.5;
=======
    _yaw = 359.5;
    _pitch = 57;
    _mode = PERSPECTIVE;
>>>>>>> 390d689d1c3fb3d223d93b08f508aee3e3eb8e59
    _name = QString("Not init");
    setPosition(new Point3D(224.533f, -68.3924f, -46.2934f));

    _dirVec = new Vector3D(cos(_yaw)*cos(_pitch),
                           sin(_yaw)*cos(_pitch),
                           sin(_pitch) );
}

/*-------------------------------------------------------------------
 |  Argument Constructor
 |
 |  Purpose: Construct a camera with specific name and default values.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraAbs::CameraAbs(QString a_name)
{
    _zoom = 10;
    _yaw = 57;
    _pitch = 359.5;
    _name = a_name;
    setPosition(new Point3D(224.533f, -68.3924f, -46.2934f));
    _dirVec = new Vector3D(cos(_yaw)*cos(_pitch),
                           sin(_yaw)*cos(_pitch),
                           sin(_pitch) );
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose: Constructs a camera object using another camera object.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
CameraAbs::CameraAbs(const CameraAbs &cameraAbs)
{
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
    _p_position->~Point3D();
}

// ============================ Methods ===============================
/*-------------------------------------------------------------------
 |  Function resizeProjection
 |
 |  Purpose:
 |  Parameters[in]: int w: new width of the context.
 |                  int h: new height of the context.
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::resizeProjection(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

<<<<<<< HEAD
    if(w>=h)
        gluPerspective(60.0, 1.0*w/h, 0.1, 40000);
    else
        gluPerspective(60.0*h/w, 1.0*w/h, 0.1, 40000);
=======
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
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(getPosition()->getX(),getPosition()->getY(), getPosition()->getZ());
        glutSolidSphere(2.0f, 100, 100);
    glPopAttrib();
    glPopMatrix();
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
>>>>>>> 390d689d1c3fb3d223d93b08f508aee3e3eb8e59
}

/*-------------------------------------------------------------------
 |  Function setPosition
 |
 |  Purpose: Sets Position of the camera.
 |  Parameters[in]: Point3D * p_position: Object Point3D with the
 |                  coordinates of the camera.
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::setPosition(Point3D * p_position)
{
    _p_position = p_position;
}

/*-------------------------------------------------------------------
 |  Function getPosition
 |
 |  Purpose: Gets the position of the camera
 |  Parameters:
 |  Returns: Point3D*: Object Point3D with the coordinates x, y and z
 |  of the camera.
 *-------------------------------------------------------------------*/
Point3D * CameraAbs::getPosition()
{
    return _p_position;
}

/*-------------------------------------------------------------------
<<<<<<< HEAD
 |  Function SetPointToLook
 |
 |  Purpose: Sets the look point of the camera
 |  Parameters[in]: Point3D *point: Sets the point to look.
 |  Return:
 *-------------------------------------------------------------------*/
void CameraAbs::setPointToLook(Point3D *point){
    _pointToLook = point;
}

/*-------------------------------------------------------------------
 |  Function GetPointToLook
 |
 |  Purpose: Gets the look point of the camera
 |  Parameters:
 |  Returns: The look point of the camera
 *-------------------------------------------------------------------*/
Point3D *CameraAbs::getPointToLook(){
    return _pointToLook;
}

/*-------------------------------------------------------------------
 |  Function getType
=======
 |  Function
>>>>>>> 390d689d1c3fb3d223d93b08f508aee3e3eb8e59
 |
 |  Purpose: Gets the type of the camera
 |  Parameters: none
 |  Returns: The camera_type, defined in utils.h
 *-------------------------------------------------------------------*/
camera_type CameraAbs::getType()
{
    return _type;
}
/*-------------------------------------------------------------------
 |  Function getSettingInfo
 |
 |  Purpose: Gets the settings of the camera
 |  Parameters: none
 |  Returns: The QString with the type
 *-------------------------------------------------------------------*/
QString
CameraAbs::getSettingsInfo()
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
 |  Function getName
 |
 |  Purpose: Gets the name of the camera
 |  Parameters: none
 |  Returns: The QString with the name
 *-------------------------------------------------------------------*/
QString CameraAbs::getName()
{
    return _name;
}

/*-------------------------------------------------------------------
 |  Function setName
 |
 |  Purpose: Sets the name of the camera
 |  Parameters: The QString with the name
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::setName( QString a_name )
{
    _name = a_name;
}

/*-------------------------------------------------------------------
 |  Function setYawPitch
 |
 |  Purpose: Sets the value of the yaw and the pitch
 |  Parameters[in]: float yaw: float value of the yaw.
 |                  float pitch: float value of the pitch.
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::setYawPitch(float yaw, float pitch)
{
    _yaw = yaw;
    _pitch = pitch;
}

/*-------------------------------------------------------------------
 |  Function addYawPitch
 |
 |  Purpose: Add an increment to the yaw and the pitch
 |  Parameters[in]: float yaw: float value of increment for the yaw.
 |                  float pitch: float value of increment for the pitch.
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::addYawPitch(float yaw, float pitch)
{
    _yaw += yaw/2;
    _pitch -= pitch/2;

    if(_yaw>=360)	_yaw=_yaw-360;
    if(_yaw<0)	    _yaw=_yaw+360;
    if(_pitch>=360)	_pitch=_pitch-360;
    if(_pitch<0)	_pitch=_pitch+360;
}

/*-------------------------------------------------------------------
 |  Function getYawPitch
 |
 |  Purpose: Gets the name of the camera
 |  Parameters[out]: float yaw: float variable to get yaw.
 |                   float pitch: float variable to get pitch.
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::getYawPitch(float &yaw, float &pitch)
{
    yaw = _yaw;
    pitch = _pitch;
}

/*-------------------------------------------------------------------
 |  Function setZoom
 |
 |  Purpose: Sets the zoom of the camera
 |  Parameters[in]: float zoom: float value of the zoom.
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::setZoom(float zoom)
{
    _zoom = zoom;
}

/*-------------------------------------------------------------------
 |  Function getZoom
 |
 |  Purpose: Gets the zoom of the camera
 |  Parameters:
 |  Returns: float: float value of the zoom
 *-------------------------------------------------------------------*/
float CameraAbs::getZoom()
{
    return _zoom;
}

/*-------------------------------------------------------------------
 |  Function setYaw
 |
 |  Purpose: Sets the yaw of the camera
 |  Parameters[in]: float yaw: float value of the yaw.
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::setYaw( float yaw )
{
    _yaw = yaw;
}

/*-------------------------------------------------------------------
 |  Function setPitch
 |
 |  Purpose: Sets the pitch of the camera
 |  Parameters[in]: float pitch: float value of the pitch.
 |  Returns:
 *-------------------------------------------------------------------*/
void CameraAbs::setPitch( float pitch )
{
    _pitch = pitch;
}

float CameraAbs::getYaw(float yaw){
    return _yaw;
}

float CameraAbs::getPitch(float pitch){
    return _pitch;
}

Vector3D*
CameraAbs::getDirectionVector()
{
    return _dirVec;
}

void
CameraAbs::setDirectionVector(Vector3D* a_vec)
{
    _dirVec = a_vec;
}
