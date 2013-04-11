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
    QTime myTimer;
    myTimer.start();

    Enviroment *enviroment = new Enviroment("/Media/Models/Circuit/",  "/Media/Models/Sky/");

    Car *c1 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(2.5f,-130.5f,-2));
    Car *c2 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(-2.5f,-122.0f,-2));
    Car *c3 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(2.35f,-114.5f,-2));
    Car *c4 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(-2.55f,-106.5f,-2));
    Car *c5 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(2.2f,-99.0f,-2));
    Car *c6 = new Car("/Media/Models/Cars/Ferrari/", new Point3D(-2.7f,-90.5f,-2));


#pragma omp parallel sections
    {
#pragma omp section
        {
            enviroment->loadModels();
        }
#pragma omp section
        {
            c1->loadModels();
        }
#pragma omp section
        {
            c2->loadModels();
        }
#pragma omp section
        {
            c3->loadModels();
        }
#pragma omp section
        {
            c4->loadModels();
        }
#pragma omp section
        {
            c5->loadModels();
        }
#pragma omp section
        {
            c6->loadModels();
        }
    }


   int loadModel = myTimer.elapsed();

    enviroment->loadModelsTextures();
    c1->loadModelsTextures();
    c2->loadModelsTextures();
    c3->loadModelsTextures();
    c4->loadModelsTextures();
    c5->loadModelsTextures();
    c6->loadModelsTextures();

    int loadTextures = myTimer.elapsed() - loadModel ;

    enviroment->renderModels();
    c1->renderModels();
    c2->renderModels();
    c3->renderModels();
    c4->renderModels();
    c5->renderModels();
    c6->renderModels();

    int render = myTimer.elapsed() - loadModel - loadTextures;

    _objectManager = ObjectManager::getObjectManager();

    _objectManager->setEnviroment(enviroment); //Add enviroment to object manager


    _objectManager->addCar(c1); //Add ferrari
    _objectManager->addCar(c2);
    _objectManager->addCar(c3);
    _objectManager->addCar(c4);
    _objectManager->addCar(c5);
    _objectManager->addCar(c6);

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
