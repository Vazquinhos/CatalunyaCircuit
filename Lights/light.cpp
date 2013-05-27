/*
 * Archivo: light.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla 1242528
 *          Alejandro Vázquez    1242110
 *          Fernando Perera      1244166
 *          Darío Orgaz Manjón   1244844
 *          Gabriel Diaz Arias   12
 */

#include "light.h"

// ================= Constructores/Destructores ======================
/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose: Construct a empty light object
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Light::Light( QString a_name )
{
    _name = a_name;
    _v_color = sfvector();
    _v_ambient = sfvector();
    _v_diffuse = sfvector();
    _v_specular = sfvector();
    _type = NORMAL;
}
/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose: Constructs a light object using another light object.
 |  Parameters: const light& a_pnt = light to copy;
 |  Returns:
 *-------------------------------------------------------------------*/
Light::Light(const Light& light)
{
}

Light::~Light()
{
    _v_color.clear();
    _v_specular.clear();
    _v_ambient.clear();
    _p_position->~Point3D();
}

// ============================ Methods ===============================
/*-------------------------------------------------------------------
 |  Function setColor
 |
 |  Purpose: Gets the color of the light.
 |  Parameters[in]: sfvector v_color: color RGBA in floats.
 |  Returns:
 *-------------------------------------------------------------------*/
void Light::setColor(sfvector v_color)
{
    _v_color = v_color;
}

/*-------------------------------------------------------------------
 |  Function getColor
 |
 |  Purpose: Gets the color of the light.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
sfvector Light::getColor()
{
    return _v_color;
}

/*-------------------------------------------------------------------
 |  Function setSpecular
 |
 |  Purpose: Sets the specular values.
 |  Parameters[in]: sfvector v_specular: specular vector
 |  Returns:
 *-------------------------------------------------------------------*/
void Light::setSpecular(sfvector v_specular)
{
    _v_specular = v_specular;
}

/*-------------------------------------------------------------------
 |  Function getSpecular
 |
 |  Purpose: Gets the specular value of the light.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
sfvector Light::getSpecular()
{
    return _v_specular;
}

/*-------------------------------------------------------------------
 |  Function setAmbient
 |
 |  Purpose: Sets the ambient values.
 |  Parameters[in]: sfvector v_ambient: ambient vector
 |  Returns:
 *-------------------------------------------------------------------*/
void Light::setAmbient(sfvector v_ambient)
{
    _v_ambient = v_ambient;
}

/*-------------------------------------------------------------------
 |  Function getAmbient
 |
 |  Purpose: Gets the ambient value of the light.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
sfvector Light::getAmbient()
{
    return _v_ambient;
}

/*-------------------------------------------------------------------
 |  Function setDiffuse
 |
 |  Purpose: Sets the diffuse values.
 |  Parameters[in]: sfvector v_diffuse: diffuse vector
 |  Returns:
 *-------------------------------------------------------------------*/
void Light::setDiffuse(sfvector v_diffuse)
{
    _v_diffuse = v_diffuse;
}

/*-------------------------------------------------------------------
 |  Function getDiffuse
 |
 |  Purpose: Gets the diffuse value of the light.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
sfvector Light::getDiffuse()
{
    return _v_diffuse;
}

/*-------------------------------------------------------------------
 |  Function setPosition
 |
 |  Purpose: Sets the position of the light.
 |  Parameters[in]: Point3D * p_position: position vector
 |  Returns:
 *-------------------------------------------------------------------*/
void Light::setPosition(Point3D * p_position)
{
    _p_position = p_position;
}

/*-------------------------------------------------------------------
 |  Function getPosition
 |
 |  Purpose: Gets the position of the light.
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * Light::getPosition()
{
    return _p_position;
}

void Light::render()
{
    glEnable(GL_BLEND);
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glColor4f(1.0, 1.0, 0.8, 0.5);
    glTranslatef(_p_position->getX(), _p_position->getY(), _p_position->getZ());
    glutSolidSphere(20.0, 100, 100);
    glPopAttrib();
    glPopMatrix();
    glDisable(GL_BLEND);
}


/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Update the parameters of the light.
 |  Parameters: GLenum lightName: Constant GL_LIGHT0..7 to set the
 |          parameters.
 |  Returns:
 *-------------------------------------------------------------------*/
void Light::update(GLenum lightName)
{

        float pos[4];
        float dif[4];
        float amb[4];
        float spe[4];
        float col[4];
        _p_position->getCoordinates(pos[0], pos[1], pos[2]);

        pos[4] = 1.0f;
        dif[0] = _v_diffuse[0];         dif[1] = _v_diffuse[1];
        dif[2] = _v_diffuse[2];         dif[3] = _v_diffuse[3];

        amb[0] = _v_ambient[0];         amb[1] = _v_ambient[1];
        amb[2] = _v_ambient[2];         amb[3] = _v_ambient[3];

        spe[0] = _v_specular[0];        spe[1] = _v_specular[1];
        spe[2] = _v_specular[2];        spe[3] = _v_specular[3];

        col[0] = _v_color[0];           col[1] = _v_color[1];
        col[2] = _v_color[2];           col[3] = _v_color[3];

        glDisable(lightName);
        glLightfv(lightName,GL_POSITION, pos);
        glLightfv(lightName,GL_DIFFUSE,  dif);
        glLightfv(lightName,GL_SPECULAR, spe);
        glLightfv(lightName,GL_AMBIENT,  amb);
        glLightfv(lightName,GL_COLOR,    col);
        glEnable(lightName);
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Gets the settings of the light
 |  Parameters: none
 |  Returns: The QString with the info
  *-------------------------------------------------------------------*/
QString
Light::getSettingsInfo()
{
    QString string_to_rtn;

    // Getting the colors
    QString list_colors = "<colors>";
    QString single_color;
    for(unsigned int i = 0; i < _v_color.size(); ++i)
    {
        single_color.setNum(_v_color[i]);
        list_colors += single_color;
        list_colors += QString(" ");
    }
    list_colors += QString("</colors>\n");

    // Getting the especular light
    QString list_specular = "<specular>";
    QString single_specular;
    for(unsigned int i = 0; i < _v_specular.size(); ++i)
    {
        single_specular.setNum(_v_specular[i]);
        list_specular += single_specular;
        list_specular += QString(" ");
    }
    single_specular += QString("</specular>\n");

    // Getting the ambient light
    QString list_ambient = "<ambient>";
    QString single_ambient;
    for(unsigned int i = 0; i < _v_ambient.size(); ++i)
    {
        single_ambient.setNum(_v_ambient[i]);
        list_ambient += single_ambient;
        list_ambient += QString(" ");
    }
    list_ambient += QString("</ambient>\n");

    // Getting the diffuse light
    QString list_diffuse = "<diffuse>";
    QString single_diffuse;
    for(unsigned int i = 0; i < _v_diffuse.size(); ++i)
    {
        single_ambient.setNum(_v_diffuse[i]);
        list_diffuse += single_ambient;
        list_diffuse += QString(" ");
    }
    list_diffuse += QString("</diffuse>\n");

    // Getting the position of the light
    QString x,y,z;
    x.setNum(_p_position->getX());
    y.setNum(_p_position->getY());
    z.setNum(_p_position->getZ());

    string_to_rtn = QString("<light>\n")+list_colors +
            list_specular + list_ambient + list_diffuse +
            QString("<position>\n") +
            QString("<x>") + x + QString("</x>\n") +
            QString("<y>") + y + QString("</y>\n") +
            QString("<z>") + z + QString("</z>\n") +
            QString("</position>\n") + QString("</light>\n");

    return string_to_rtn;
}
/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Gets the name of the light
 |  Parameters: none
 |  Returns: The QString with the name
 *-------------------------------------------------------------------*/
QString Light::getName()
{
    return _name;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Sets the name of the light
 |  Parameters: The QString with the name
 |  Returns: nothing
 *-------------------------------------------------------------------*/
void Light::setName( QString a_name )
{
    _name = a_name;
}

void Light::setType( light_type a_type )
{
    _type = a_type;
}

light_type
Light::getType()
{
    return _type;
}


