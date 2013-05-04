/*
 * Archivo: absObject.cpp
 * Fecha: 23/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 *  Clase: AbsObject3D
 * Descripcion: Clase Abstracta que engloba todas las operaciones basicas para cualquier objeto 3D independientemente
 * de su estructura o implementacion
 */

#include "absObject3D.h"

// ================= Constructores/Destructores ======================
/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
AbsObject3D::AbsObject3D() {
    _p_translation = new Point3D();
    _p_rotation = new Point3D();
    _p_scale = new Point3D(1,1,1);
    _p_minVertex = new Point3D();
    _p_maxVertex = new Point3D();
    _isVisible = true;
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose: Destruct and free memory
 *-------------------------------------------------------------------*/
AbsObject3D::~AbsObject3D()
{
    this->_p_translation->~Point3D();
    this->_p_rotation->~Point3D();
    this->_p_scale->~Point3D();
    this->_p_minVertex->~Point3D();
    this->_p_maxVertex->~Point3D();
    this->_p_center->~Point3D();
}

// ============================ Methods ==============================


/*-------------------------------------------------------------------
 |  Function setVisibility
 |
 |  Purpose: Sets the visibility of the object
 |  Parameters: bool visibility : The visibility of the object
 *-------------------------------------------------------------------*/
void AbsObject3D::setVisibility(bool visibility){
    _isVisible = visibility;
}

/*-------------------------------------------------------------------
 |  Function getVisibility
 |
 |  Purpose: gets the visibility of the object
 |  Returns: The boolean visibility of the object
 *-------------------------------------------------------------------*/
bool AbsObject3D::getVisibility(){
    return _isVisible;
}

/*-------------------------------------------------------------------
 |  Function setName
 |
 |  Purpose: Sets the name of the object
 |  Parameters: string name : The name of the object
 *-------------------------------------------------------------------*/
void AbsObject3D::setName(QString name){
    _name = name;
}

/*-------------------------------------------------------------------
 |  Function getName
 |
 |  Purpose: gets the name of the object
 |  Returns: The string name of the object
 *-------------------------------------------------------------------*/
QString AbsObject3D::getName(){
    return _name;
}


/*-------------------------------------------------------------------
 |  Function getCenter
 |
 |  Purpose: Getter of the center
 |  Returns: The the center vertex of the object
 *-------------------------------------------------------------------*/
Point3D * AbsObject3D::getCenter(){
    return _p_center;
}

/*-------------------------------------------------------------------
 |  Function setCenter
 |
 |  Purpose: Setter of the center
 |  Parameters: Point3D *center : The the center vertex of the object
 *-------------------------------------------------------------------*/
void AbsObject3D::setCenter(Point3D *center){
    this->_p_center = center;
}

/*-------------------------------------------------------------------
 |  Function setTranslation
 |
 |  Purpose: Setter. Sets the translation of the object
 |  Parameters[in]: Point3D * translation = New translation of the object
 |  Returns:
 *-------------------------------------------------------------------*/
void AbsObject3D::setTranslation(Point3D * translation)
{
    _p_translation = translation;
}

Point3D * AbsObject3D::getTranslation()
{
    return _p_translation;
}

/*-------------------------------------------------------------------
 |  Function setRotation
 |
 |  Purpose: Setter. Sets the rotation of the object
 |  Parameters[in]: Point3D * rotation = New rotation of the object
 |  Returns:
 *-------------------------------------------------------------------*/
void AbsObject3D::setRotation(Point3D * rotation)
{
    _p_rotation = rotation;
}

/*-------------------------------------------------------------------
 |  Function getRotation
 |
 |  Purpose: Getter. Gets the rotation of the object
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * AbsObject3D::getRotation()
{
    return _p_rotation;
}

/*-------------------------------------------------------------------
 |  Function setScale
 |
 |  Purpose: Setter. Sets the  the object
 |  Parameters[in]: Point3D * scale = Sets the scale of the object
 |  Returns:
 *-------------------------------------------------------------------*/
void AbsObject3D::setScale(Point3D * scale)
{
    _p_scale = scale;
}


/*-------------------------------------------------------------------
 |  Function getScale
 |
 |  Purpose: Getter. Gets the scale of  the object
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * AbsObject3D::getScale()
{
    return _p_scale;
}

/*-------------------------------------------------------------------
 |  Function setMinVertex
 |
 |  Purpose: Setter. Sets the min vertex coordinates the object
 |  Parameters[in]: Point3D * minVertex = New min coordinates to set
 |  Returns:
 *-------------------------------------------------------------------*/
void AbsObject3D::setMinVertex(Point3D * minVertex)
{
    _p_minVertex = minVertex;
}

/*-------------------------------------------------------------------
 |  Function getMinVertex
 |
 |  Purpose: Getter. Gets the min coordinates of the object
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * AbsObject3D::getMinVertex()
{
    return _p_minVertex;
}

/*-------------------------------------------------------------------
 |  Function setMaxVertex
 |
 |  Purpose: Setter. Sets the max vertex coordinates the object
 |  Parameters[in]: Point3D * maxVertex = max vertex coordinates to set
 |  Returns:
 *-------------------------------------------------------------------*/
void AbsObject3D::setMaxVertex(Point3D * maxVertex)
{
    _p_maxVertex = maxVertex;
}

/*-------------------------------------------------------------------
 |  Function getMaxVertex
 |
 |  Purpose: Getter. Gets the max vertex coordinates of the object
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Point3D * AbsObject3D::getMaxVertex()
{
    return _p_maxVertex;
}

