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
            _terrain3D = new Object3DFile(_circuitFolder, "terrain.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _terrain3D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _vallas3D = new Object3DFile(_circuitFolder, "vallas.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _vallas3D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _gradas13D = new Object3DFile(_circuitFolder, "gradas1.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _gradas13D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _gradas23D = new Object3DFile(_circuitFolder, "gradas2.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _gradas23D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _gradas33D = new Object3DFile(_circuitFolder, "gradas3.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _gradas33D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _gradas43D = new Object3DFile(_circuitFolder, "gradas4.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _gradas43D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _gradas53D = new Object3DFile(_circuitFolder, "gradas5.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _gradas53D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _gradas63D = new Object3DFile(_circuitFolder, "gradas6.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _gradas63D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _gradas73D = new Object3DFile(_circuitFolder, "gradas7.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _gradas73D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _gradas83D = new Object3DFile(_circuitFolder, "gradas8.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _gradas83D->setRotation(new Point3D(90,0,0));
        }

#pragma omp section
        {
            _objects13D = new Object3DFile(_circuitFolder, "objects1.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
            _objects13D->setRotation(new Point3D(90,0,0));
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
    _sky3D->loadTextures();
    _forest13D->loadTextures();
    _forest23D->loadTextures();
    _forest33D->loadTextures();
    _forest43D->loadTextures();
    _terrain3D->loadTextures();
    _vallas3D->loadTextures();
    _gradas13D->loadTextures();
    _gradas23D->loadTextures();
    _gradas33D->loadTextures();
    _gradas43D->loadTextures();
    _gradas53D->loadTextures();
    _gradas63D->loadTextures();
    _gradas73D->loadTextures();
    _gradas83D->loadTextures();
    _objects13D->loadTextures();
}

/*-------------------------------------------------------------------
 |  Function renderModels
 |
 |  Purpose: Render all models
 *-------------------------------------------------------------------*/
void Enviroment::renderModels(){
    _sky3D->render();
    _forest13D->render();
    _forest23D->render();
    _forest33D->render();
    _forest43D->render();
    _terrain3D->render();
    _vallas3D->render();
    _gradas13D->render();
    _gradas23D->render();
    _gradas33D->render();
    _gradas43D->render();
    _gradas53D->render();
    _gradas63D->render();
    _gradas73D->render();
    _gradas83D->render();
    _objects13D->render();
}

/*-------------------------------------------------------------------
 |  Function displayModels
 |
 |  Purpose: Displays all models
 *-------------------------------------------------------------------*/
void Enviroment::displayModels(){
    _sky3D->display();
    _forest13D->display();
    _forest23D->display();
    _forest33D->display();
    _forest43D->display();
    _terrain3D->display();
    _vallas3D->display();
    _gradas13D->display();
    _gradas23D->display();
    _gradas33D->display();
    _gradas43D->display();
    _gradas53D->display();
    _gradas63D->display();
    _gradas73D->display();
    _gradas83D->display();
    _objects13D->display();
}

/*-------------------------------------------------------------------
 |  Function checkVisibility
 |
 |  Purpose: Modify visibility of the objects taking in consideration distance to the camera
 |  Parameters: Point3D *pointCamera : Position of the camera, int distance : Maximum distance that the object will be visible
 *-------------------------------------------------------------------*/
void Enviroment::checkVisibility(Point3D *pointCamera, int distance){

}


