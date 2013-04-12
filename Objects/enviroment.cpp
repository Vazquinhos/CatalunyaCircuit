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

#pragma omp parallel sections
    {
#pragma omp section
        {
            _circuit3D = new Object3DFile(_circuitFolder, "circuit.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _circuit3D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _sky3D = new Object3DFile(_skyFolder, "sky.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _sky3D->setRotation(new Point3D(90,0,0));
        }
#pragma omp section
        {
            _forest13D = new Object3DFile(_circuitFolder, "forest1.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _forest13D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _forest23D = new Object3DFile(_circuitFolder, "forest2.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _forest23D->setRotation(new Point3D(90,0,0));
        }


#pragma omp section
        {
            _forest33D = new Object3DFile(_circuitFolder, "forest3.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _forest33D->setRotation(new Point3D(90,0,0));
        }


#pragma omp section
        {
            _forest43D = new Object3DFile(_circuitFolder, "forest4.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _forest43D->setRotation(new Point3D(90,0,0));
        }
    }

}

/*-------------------------------------------------------------------
 |  Function loadModelsTextures
 |
 |  Purpose: Loads textures of all models
 *-------------------------------------------------------------------*/
void Enviroment::loadModelsTextures(){
    _circuit3D->loadTextures();
    _sky3D->loadTextures();
    _forest13D->loadTextures();
    _forest23D->loadTextures();
    _forest33D->loadTextures();
    _forest43D->loadTextures();
}

/*-------------------------------------------------------------------
 |  Function renderModels
 |
 |  Purpose: Render all models
 *-------------------------------------------------------------------*/
void Enviroment::renderModels(){
    _circuit3D->render();
    _sky3D->render();
    _forest13D->render();
    _forest23D->render();
    _forest33D->render();
    _forest43D->render();
}

/*-------------------------------------------------------------------
 |  Function displayModels
 |
 |  Purpose: Displays all models
 *-------------------------------------------------------------------*/
void Enviroment::displayModels(){
    _circuit3D->display();
    _sky3D->display();
    _forest13D->display();
    _forest23D->display();
    _forest33D->display();
    _forest43D->display();
}


