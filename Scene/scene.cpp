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
#include <QTime>
#include <IL/il.h>                  //Devil image loader for textures

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

    ilInit(); /* Initialization of DevIL texture loader */

    QTime myTimer;
    myTimer.start();

    Enviroment *enviroment = new Enviroment("/Media/Models/Circuit/");


    Car *c1 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(2.5f,-130.5f,-2));



    enviroment->loadModels();
    c1->loadModels();



    int loadModel = myTimer.elapsed();

    enviroment->loadModelsTextures();
    c1->loadModelsTextures();

    int loadTextures = myTimer.elapsed() - loadModel ;

    enviroment->renderModels();
    c1->renderModels();

    int render = myTimer.elapsed() - loadModel - loadTextures;

    _objectManager = ObjectManager::getObjectManager();
    _objectManager->setEnviroment(enviroment); //Add enviroment to object manager
    _objectManager->addCar(c1); //Add ferrari

    qDebug() << "Ha tardado en cargar modelos: " << loadModel;
    qDebug() << "Ha tardado en cargar texturas: " << loadTextures;
    qDebug() << "Ha tardado en renderizados: " << render;
    qDebug() << "Ha tardado en cargar total: " << myTimer.elapsed();
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
