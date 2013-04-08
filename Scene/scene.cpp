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

    Car *c1 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(2.5f,-130.5f,-2));
    /*Car *c2 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(-2.5f,-122.0f,-2));
    Car *c3 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(2.35f,-114.5f,-2));
    Car *c4 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(-2.55f,-106.5f,-2));
    Car *c5 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(2.2f,-99.0f,-2));
    Car *c6 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(-2.7f,-90.5f,-2));*/

    _objectManager = ObjectManager::getObjectManager();

    enviromentObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Circuit/").toAscii().data(), "circuit.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
    enviromentObj->setScale(new Point3D(1, 1, 1));
    enviromentObj->setRotation(new Point3D(90,0,0));
    enviroment->setRepresentation(enviromentObj); //Set enviroment representation


    _objectManager->setEnviroment(enviroment); //Add enviroment to object manager
    _objectManager->addCar(c1); //Add ferrari
    /*_objectManager->addCar(c2);
    _objectManager->addCar(c3);
    _objectManager->addCar(c4);
    _objectManager->addCar(c5);
    _objectManager->addCar(c6);*/
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
