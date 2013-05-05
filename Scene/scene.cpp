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
#include <bullet/btBulletDynamicsCommon.h> //Physics Simulation, Bullet
#include "GL/glut.h"
char frames[15];
const int font=(int)GLUT_BITMAP_9_BY_15;

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
    QStringList carFolders;
    carFolders<< "Ferrari/"<<"Hrt/"<<"India/"<<"Lotus/"<<"Mclaren/"<<"Mercedes/"<<"RedBull/"<<"Renault/"<<"Sauber/"<<"Virgin/"<<"Williams/";
    // ========================== Physics / Bullet ========================
    _broadphase = new btDbvtBroadphase(); //Boradphase checks what pair of objects are colliding. Important if there are many objects on the scene
    _collisionConfiguration = new btDefaultCollisionConfiguration(); //Collision configuration
    _dispatcher = new btCollisionDispatcher(_collisionConfiguration); //Dispatcher for dectect collisions and make callbacks
    _solver = new btSequentialImpulseConstraintSolver(); //Handles object interactions like gravity
    _dynamicsWorld = new btDiscreteDynamicsWorld(_dispatcher,_broadphase,_solver,_collisionConfiguration); //World simulator
    _dynamicsWorld->setGravity(btVector3(0,0,-9.81f));//Sets the gravity (choose -10m/s² on Z axis)


    Enviroment *enviroment = new Enviroment(_dynamicsWorld);
    _objectManager = ObjectManager::getObjectManager();

    unsigned int numCars = 10;
    int xPos = 70;
    for(unsigned int i = 0; i < numCars; i++){
        Car *c1 = new Car("Cars/" + carFolders[qrand() % (carFolders.size()-1)], new Point3D(xPos,50,4), _dynamicsWorld);
         _objectManager->addCar(c1);
         xPos+=1;
    }
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
    delete _dynamicsWorld;
    delete _solver;
    delete _dispatcher;
    delete _collisionConfiguration;
    delete _broadphase;
}

// ============================ Methods ===============================

/*-------------------------------------------------------------------
 |  Function display
 |
 |  Purpose: Displays all objects
 *-------------------------------------------------------------------*/
void Scene::display(float fps)
{

    sprintf(frames, "FPS = %f", fps);
    paint2DText(20,20,(void *)font,frames);
    this->_objectManager->displayAll();


}

/*-------------------------------------------------------------------
 |  Function simulatePhisics
 |
 |  Purpose: Do all physics simulation
 |  Returns: bool True if screen must be updated, false otherwise
 *-------------------------------------------------------------------*/
void Scene::simulatePhisics(btScalar timeStep)
{
    _dynamicsWorld->stepSimulation(timeStep,10);  // Do world simulation every 1/60 s
}

void Scene::paint2DText(float x, float y, void *font,const char *string)
{
    const char *c;
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 1024, 0, 768);
    glScalef(1, -1, 1);
    glTranslatef(0, -768, 0);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glLoadIdentity();

    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}
