/*
 * Archivo: scene.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "scene.h"

// ================= Constructores/Destructores ======================
/*-------------------------------------------------------------------
 |
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Scene::Scene()
{
    Object3DFile *enviromentObj;
    Object3DFile *ferrariObj;

    Enviroment *enviroment = new Enviroment();
    Car *ferrari = new Car();

    _objectManager = ObjectManager::getObjectManager();

    enviromentObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Circuit/").toAscii().data(), "circuit.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
    enviromentObj->setScale(new Point3D(1, 1, 1));
    enviromentObj->setRotation(new Point3D(90,0,0));
    enviroment->setRepresentation(enviromentObj); //Set enviroment representation

    ferrariObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Cars/Ferrari/").toAscii().data(), "ferrari.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    ferrariObj->setTranslation(new Point3D(0, 3, -2));
    ferrariObj->setRotation(new Point3D(0,0,90));
    ferrariObj->setScale(new Point3D(1, 1, 1));
    ferrari->setRepresentation(ferrariObj);


    _objectManager->setEnviroment(enviroment); //Add enviroment to object manager
    _objectManager->addCar(ferrari); //Add ferrari
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Scene::Scene(const Scene &scene)
{
}

/*-------------------------------------------------------------------
 |  Function
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Scene::~Scene()
{
}

// ============================ Methods ===============================

void Scene::display(){
    this->_objectManager->displayAll();
}
