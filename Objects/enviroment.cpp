/*
 * Archivo: enviroment.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "enviroment.h"
#include <QDir>

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::Enviroment(QString folder)
{
    Object3DFile *enviromentObj;
    enviromentObj = new Object3DFile((QDir::currentPath() + folder).toAscii().data(), "circuit.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation

    enviromentObj->setScale(new Point3D(1, 1, 1));
    enviromentObj->setRotation(new Point3D(90,0,0));
    setRepresentation(enviromentObj); //Set enviroment representation
}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::Enviroment(const Enviroment &enviroment)
{
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::~Enviroment()
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
void Enviroment::render()
{
}

/*-------------------------------------------------------------------
 |  Function display
 |
 |  Purpose: Displays this object once rendered
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
void Enviroment::display()
{
    this->_object3D->display();
}

/*-------------------------------------------------------------------
 |  Function getRepresentation
 |
 |  Purpose: Getter. Gets the representation of the enviroment
 |  Parameters:
 |  Returns: Object3DFile = the representation of the enviroment
 *-------------------------------------------------------------------*/
Object3DFile* Enviroment::getRepresentation(){
    return this->_object3D;
}

/*-------------------------------------------------------------------
 |  Function setRepresentation
 |
 |  Purpose: Setter. Sets the representation of the enviroment
 |  Parameters: Object3DFile object = the representation of the enviroment
 |  Returns:
 *-------------------------------------------------------------------*/
 void Enviroment::setRepresentation(Object3DFile *object){
    this->_object3D = object;
    this->_object3D->render();
 }

