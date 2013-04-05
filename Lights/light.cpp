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
Light::Light()
{
}

Light::Light(const Light& light)
{
}

Light::~Light()
{
    _v_color.clear();
    _v_especular.clear();
    _v_ambient.clear();
    _p_position->~Point3D();
}

// ============================ Methods ===============================
void Light::setColor(sfvector v_color)
{
    _v_color = v_color;
}

sfvector Light::getColor()
{
    return _v_color;
}

void Light::setEspecular(sfvector v_especular)
{
    _v_especular = v_especular;
}

sfvector Light::getEspecular()
{
    return _v_especular;
}

void Light::setAmbient(sfvector v_ambient)
{
    _v_ambient = v_ambient;
}

sfvector Light::getAmbient()
{
    return _v_ambient;
}

void Light::setPosition(Point3D * p_position)
{
    _p_position = p_position;
}

Point3D * Light::getPosition()
{
    return _p_position;
}

void Light::render()
{

}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Gets the settings of the camera
 |  Parameters: none
 |  Returns: The QString with the type
 *-------------------------------------------------------------------*/
void Light::update()
{

}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Gets the settings of the light
 |  Parameters: none
 |  Returns: The QString with the info
  *-------------------------------------------------------------------*/
QString
Light::getSettingsInfo( void )
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
    QString list_especular = "<especular>";
    QString single_especular;
    for(unsigned int i = 0; i < _v_especular.size(); ++i)
    {
        single_especular.setNum(_v_especular[i]);
        list_especular += single_especular;
        list_especular += QString(" ");
    }
    single_especular += QString("</especular>\n");

    // Getting the ambient light
    QString list_ambient = "<ambient>";
    QString single_ambient;
    for(unsigned int i = 0; i < _v_especular.size(); ++i)
    {
        single_ambient.setNum(_v_especular[i]);
        list_ambient += single_ambient;
        list_ambient += QString(" ");
    }
    list_ambient += QString("</ambient>\n");

    // Getting the position of the light
    QString x,y,z;
    x.setNum(_p_position->getX());
    y.setNum(_p_position->getY());
    z.setNum(_p_position->getZ());

    string_to_rtn = QString("<light>\n")+list_colors +
            list_especular + list_ambient +
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
QString Light::getName( void )
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

