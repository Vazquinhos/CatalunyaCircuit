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
Enviroment::Enviroment(std::string circuitFolder, std::string skyFolder)
{
    _circuitFolder = (QDir::currentPath() + circuitFolder.c_str()).toStdString();
    _skyFolder = (QDir::currentPath() + skyFolder.c_str()).toStdString();;
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


// ============================ Inherited Methods ===============================
/*-------------------------------------------------------------------
 |  Function loadModels
 |
 |  Purpose: Loads all models without textures
 *-------------------------------------------------------------------*/
void Enviroment::loadModels(){
    _circuit3D = new Object3DFile(_circuitFolder, "circuit.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
    _circuit3D->setRotation(new Point3D(90,0,0));

    _sky3D = new Object3DFile(_skyFolder, "sky.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
    _sky3D->setRotation(new Point3D(90,0,0));
}

/*-------------------------------------------------------------------
 |  Function loadModelsTextures
 |
 |  Purpose: Loads textures of all models
 *-------------------------------------------------------------------*/
void Enviroment::loadModelsTextures(){
    _circuit3D->loadTextures();
    _sky3D->loadTextures();
}

/*-------------------------------------------------------------------
 |  Function renderModels
 |
 |  Purpose: Render all models
 *-------------------------------------------------------------------*/
void Enviroment::renderModels(){
    _circuit3D->render();
    _sky3D->render();
}

/*-------------------------------------------------------------------
 |  Function displayModels
 |
 |  Purpose: Displays all models
 *-------------------------------------------------------------------*/
void Enviroment::displayModels(){
    _circuit3D->display();
    _sky3D->display();
}


