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
    Enviroment *enviroment = new Enviroment();


    _objectManager = ObjectManager::getObjectManager();

    enviromentObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Circuit/").toAscii().data(), "circuit.3ds", aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
    enviromentObj->setScale(new Point3D(0.01, 0.01, 0.01));
    enviroment->setRepresentation(enviromentObj); //Set enviroment representation



    _objectManager->setEnviroment(enviroment); //Add enviroment to object manager
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
    AbsObject3D *object;

    object = this->_objectManager->getEnviroment()->getRepresentation();
    object->display();
}
