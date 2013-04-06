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
    Object3DFile *chasisObj;
    Object3DFile *wheelObj;
    Object3DFile *wheelFrontRightObj;
    Object3DFile *wheelFrontLeftObj;
    Object3DFile *wheelRearRightObj;
    Object3DFile *wheelRearLeftObj;

    Enviroment *enviroment = new Enviroment();
    Car *ferrari = new Car();

    _objectManager = ObjectManager::getObjectManager();

    enviromentObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Circuit/").toAscii().data(), "circuit.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FlipUVs | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load enviroment representation
    enviromentObj->setScale(new Point3D(1, 1, 1));
    enviromentObj->setRotation(new Point3D(90,0,0));
    enviroment->setRepresentation(enviromentObj); //Set enviroment representation

    chasisObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Cars/Ferrari/").toAscii().data(), "chasis.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    chasisObj->setTranslation(new Point3D(0, 3, -2));
    chasisObj->setRotation(new Point3D(0,0,90));
    chasisObj->setScale(new Point3D(1, 1, 1));
    ferrari->setChasisObj(chasisObj);

    wheelObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Cars/Ferrari/").toAscii().data(), "wheel.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    wheelObj->setTranslation(new Point3D(0, 3, -2));
    wheelObj->setRotation(new Point3D(0,0,90));
    wheelObj->setScale(new Point3D(1, 1, 1));
    ferrari->setWheelObj(wheelObj);

    wheelFrontRightObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Cars/Ferrari/").toAscii().data(), "wheelFrontRight.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    wheelFrontRightObj->setTranslation(new Point3D(0, 3, -2));
    wheelFrontRightObj->setRotation(new Point3D(0,0,90));
    wheelFrontRightObj->setScale(new Point3D(1, 1, 1));
    ferrari->setWheelFrontRightObj(wheelFrontRightObj);

    wheelFrontLeftObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Cars/Ferrari/").toAscii().data(), "wheelFrontLeft.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    wheelFrontLeftObj->setTranslation(new Point3D(0, 3, -2));
    wheelFrontLeftObj->setRotation(new Point3D(0,0,90));
    wheelFrontLeftObj->setScale(new Point3D(1, 1, 1));
    ferrari->setWheelFrontLeftObj(wheelFrontLeftObj);

    wheelRearRightObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Cars/Ferrari/").toAscii().data(), "wheelRearRight.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    wheelRearRightObj->setTranslation(new Point3D(0, 3, -2));
    wheelRearRightObj->setRotation(new Point3D(0,0,90));
    wheelRearRightObj->setScale(new Point3D(1, 1, 1));
    ferrari->setWheelRearRightObj(wheelRearRightObj);

    wheelRearLeftObj = new Object3DFile((QDir::currentPath() + "/Media/Models/Cars/Ferrari/").toAscii().data(), "wheelRearLeft.3ds", aiProcess_Triangulate | aiProcess_PreTransformVertices | aiProcess_ImproveCacheLocality | aiProcess_RemoveRedundantMaterials | aiProcess_GenUVCoords | aiProcess_TransformUVCoords | aiProcess_FindInstances | aiProcess_OptimizeMeshes | aiProcess_OptimizeGraph); //Load ferrari representation
    wheelRearLeftObj->setTranslation(new Point3D(0, 3, -2));
    wheelRearLeftObj->setRotation(new Point3D(0,0,90));
    wheelRearLeftObj->setScale(new Point3D(1, 1, 1));
    ferrari->setWheelRearLeftObj(wheelRearLeftObj);

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
