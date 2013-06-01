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
#include "Sound/SoundManager.h"
#include "Lights/lightmanager.h"
#include "Lights/light.h"
#include "Objects/modelManager.h"

char _frames[15]; //String that shows fps
// ================= Constructores/Destructores ======================
Scene * Scene::_scene = NULL;
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

    _debugMode = false;

    Enviroment *enviroment = new Enviroment(_dynamicsWorld);
    _objectManager = ObjectManager::getObjectManager();

    c2 = new CarAutomatic("Cars/" + carFolders[1 % (carFolders.size()-1)], QDir::currentPath() + "/Media/BSplines/Correct/bsplineGabriel.obj");
    _objectManager->addCar(c2);

    _objectManager->setEnviroment(enviroment); //Add enviroment to object manager


    _bSplineManager = BSplineManager::getBSplineManager();
    _race = false;
}
void
Scene::setCarAutomatic( QString a)
{
    c2 = new CarAutomatic(a, QDir::currentPath() + "/Media/BSplines/Correct/bsplineGabriel.obj");
    _objectManager->addCar(c2);
}

 CarAutomatic * Scene::getCarAutomatic(){
    return c2;
 }

Scene * Scene::getScene()
{
    if(_scene==NULL)
        _scene = new Scene();
    return _scene;
}

void
Scene::fallCar()
{
    Car *c1 = new Car("Cars/Ferrari/", new Point3D(223.494,54.6941,-46.3775), _dynamicsWorld);
    _objectManager->addCar(c1);
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

void
Scene::startCarAnimation()
{
    c2->startRace();
    _race = true;
}

void Scene::stopCarAnimation()
{
    c2->resetRace();
    _race = false;
}
// ============================ Methods ===============================
void Scene::turnDebugMode()
{
    _debugMode = !_debugMode;
}

/*-------------------------------------------------------------------
 |  Function display
 |
 |  Purpose: Displays all objects
 |  Parameters: float fps: Actual frames per second screen refresh to show on screen
 *-------------------------------------------------------------------*/
void Scene::display(float fps)
{

    (void) fps;

    CameraManager::getCameraManager()->getActiveCamera()->update();
    //sprintf(_frames, "FPS = %f", fps);
    //paint2DText(20,20,(void *)GLUT_BITMAP_9_BY_15,_frames);
    this->_objectManager->displayAll();



    if(_debugMode && !_race)
    {
        _bSplineManager->display();
        LightManager::getLightManager()->getActiveLight()->render();
        CameraManager::getCameraManager()->render();
        //ModelManager::getModelManager()->drawCenters();

        /*Point3D *carPos = ObjectManager::getObjectManager()->getCar(0)->getPosition();
        //Point3D *cameraPos = CameraManager::getCameraManager()->getCamera("free")->getPosition();
        Point3D *cameraPos = CameraManager::getCameraManager()->getCamera(QString("freeTest"))->getPosition();


        glPushMatrix();

        glPushAttrib(GL_CURRENT_BIT);
        glDisable(GL_LIGHTING);

        // Eix X (vermell)
        glColor3f(1.0,0.0,0.0);
        //glutSolidSphere(100, 20,20);

        glBegin(GL_LINES);
        glLineWidth(1.0f);
        glVertex3f(0,0,0);
        glVertex3f(carPos->getX(),carPos->getY(),carPos->getZ());
        glEnd();


        glColor3f(0.0,1.0,0.0);
        glBegin(GL_LINES);
        glLineWidth(1.0f);
        glVertex3f(0,0,0);
        glVertex3f(cameraPos->getX(), cameraPos->getY(),cameraPos->getZ());
        glEnd();



        glEnable(GL_LIGHTING);

        glPopAttrib();
        glPopMatrix();*/

    }

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

/*-------------------------------------------------------------------
 |  Function paint2DText
 |
 |  Purpose:     Prints on screen a text
 |  Parameters:  float x: X Position of the text
 |               float y: Y Position of the text
 |               void *font: Font to render the text
 |               const char *string: String to show
 *-------------------------------------------------------------------*/
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
