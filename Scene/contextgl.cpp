#include <QtGui/QMouseEvent>
#include "contextgl.h"
#include "Objects/modelManager.h"
#include <QApplication>
#include <QTimeLine>
#include <QStringList>
#include <Ui/loaderqt.h>
#include <QThread>
#include "Cameras/cameramanager.h"
#include "Cameras/fixedcamera.h"
#include "GL/glut.h"



GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{
    setMouseTracking(true);
}

GLWidget::~GLWidget()
{
    if (_scene)
        delete _scene;
    if (shader)
        delete shader;
}

/*****************************************************************************
 * initializeGL()
 *      Called at context creation. Sets initial state.
 *****************************************************************************/
void GLWidget::initializeGL()
{
    LoaderQt* loader = new LoaderQt();
    loader->show();

    //#ifndef __APPLE__

    // 0) OpenGL 2.0 support test
    //    (needed for shading)
    //----------------------------------------------------------

    glewInit();

    if (glewIsSupported("GL_VERSION_2_0"))
    {
        qDebug() << "Ready for OpenGL 2.0";
    }
    else
    {
        qDebug() << "OpenGL 2.0 not supported";
        QApplication::exit(-1);
    }

    //#endif
    // 1) Go for a well known initialization state.
    //    (essential stuff only)
    //----------------------------------------------------------

    // 1a) Setting default values to clean buffers
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClearDepth(1.0f); // This is the default OpenGL value, but I'm making it explicit for you

    // 1c) Enable depth testing
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    //1) Initialize variables
    initializeWorld();
}


/*****************************************************************************
 * initializeWorld()
 *      Makes all needed inicialization that is not part of openGL config
 *****************************************************************************/
void GLWidget::initializeWorld(){
    ModelManager *modelManager = ModelManager::getModelManager();
    QStringList modelFilters;
    QStringList textureFilters;

    /*_countFrames = 0; //Current number of frames measured before reset
    _maxCountFrames = 300; //Max frames before calculating fps*/
    _fps = 0;

    // 1) Load Models
    modelFilters << "*.3ds";
    textureFilters << "*";

    modelManager->setFolderToLoad("/Media/Models/", modelFilters, textureFilters);
    modelManager->loadModels();

    _scene = new Scene();
    _objectManager = ObjectManager::getObjectManager();
    _cameraManager = CameraManager::getCameraManager();

    // 2) Init our own architecture (camera, lights, action!)
    //----------------------------------------------------------
    SphericalCamera * spCam = new SphericalCamera(QString("spherical"));
    _cameraManager->addCamera(QString("spherical"), spCam);
    FreeCamera * frCam = new FreeCamera();
    _cameraManager->addCamera(QString("free"), frCam);

    _cameraManager->setActiveCamera("free");

    _indexCamera = 0;
    _maxVisibleDistance = 200;
    _objectManager->checkVisibility(_cameraManager->getActiveCamera()->getPosition(), _maxVisibleDistance);

    glEnable(GL_TEXTURE_2D);

    // 3) Init shaders
    //----------------------------------------------------------
    //shader =  new QGLShaderProgram();
    //initializeShaders(QString("simple"));

    //4) Init physics simulation
    _physicsEventTimer = new QTimer(this);
    connect(_physicsEventTimer, SIGNAL(timeout()), this, SLOT(simulatePhysics()));
    _physicsEventTimer->start(18);

    //4) Init physics simulation
    _displayEventTimer = new QTimer(this);
    connect(_displayEventTimer, SIGNAL(timeout()), this, SLOT(updateGL()));
    _displayEventTimer->start(0);

    _displayTimer.start();
    _physicsTimer.start();
}

void GLWidget::simulatePhysics()
{
    _scene->simulatePhisics(_physicsTimer.restart()/1000.0f);
}



/*****************************************************************************
 * resizeGL()
 *      Called at context resizing. Controls aspect ratio changes.
 *****************************************************************************/
void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    _cameraManager->getActiveCamera()->resizeProjection(w, h);
}

/*****************************************************************************
 * resizeGL()
 *      Called automatically after init, on possible clock events,
 *      or after UpdateGL requests. Controls context painting.
 *****************************************************************************/
void GLWidget::paintGL()
{

    //OBTENER EL ELAPSED TIME COMO LA RESTA ENTRE EL TIEMPO DE AHORA I EL ANTERIOR.
    double d_elapsedTime = _displayTimer.elapsed();
    double _fps = 1000.0f/_displayTimer.elapsed();
    _displayTimer.restart();

    _totalTime += d_elapsedTime;
    float elapsedTime = (float)d_elapsedTime/1000.f;
/*
    qDebug() << "FPS: " << _fps;
    qDebug() << "Elap: " << elapsedTime;
    qDebug() << "Total: " << _totalTime;
    qDebug() << _cameraManager->getActiveCamera()->getName();
*/

    // Clean buffers:
    // COLOR to ensure final representation has no waste from previous renders
    // DEPTH to ensure correct representation of objects given the depht testing used
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    // Update camera to its current position
    _cameraManager->getActiveCamera()->update();

    // Update the scene (all the objects)
    _scene->display(_fps);
}

/*****************************************************************************
 * resizeGL()
 *      Called on mouse click. Controls this input.
 *****************************************************************************/
void GLWidget::mousePressEvent(QMouseEvent *event)
{

    if (event->buttons() & Qt::LeftButton)
    {
        posCam.setCoordinates(event->x(), event->y());
    }

}


/*****************************************************************************
 * resizeGL()
 *      Called on mouse move. Controls this input.
 *****************************************************************************/
void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        _cameraManager->getActiveCamera()
                ->addYawPitch(posCam.getX()- event->x(),  posCam.getY() - event->y());
        posCam.setCoordinates(event->x(), event->y());
    }
}

/*****************************************************************************
 * wheelEvent()
 *      Called on mouse wheel move. Controls this input.
 *****************************************************************************/
void GLWidget::wheelEvent (QWheelEvent * event)
{
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;  // See QWheelEvent documentation
    _numScheduledScalings += numSteps;
    if (_numScheduledScalings * numSteps < 0) // If user moved the wheel in another direction, we reset previously scheduled scalings
        _numScheduledScalings = numSteps;

    if(event->delta() > 0){ //Delta also shows wheel direction. Positive zoom, negative un-zoom
        _isZoomingIn = true;
    }else{
        _isZoomingIn = false;
    }

    QTimeLine *anim = new QTimeLine(350, this); //Create animation of 350ms of duration, updating every 20ms
    anim->setUpdateInterval(20); //Update animation every 20 ms

    connect(anim, SIGNAL(valueChanged(qreal)), SLOT(onZoomChanged(qreal))); //Every 20ms zoom will be called
    connect(anim, SIGNAL(finished()), SLOT(onAnimZoomFinished()));//When zoom finnishes, animZoomFinished is called
    anim->start();
}

/*****************************************************************************
 * onAnimZoomFinished()
 *      Called when the zoom animation finishes
 *****************************************************************************/
void GLWidget::onAnimZoomFinished()
{
    if (_numScheduledScalings > 0)
        _numScheduledScalings--;
    else
        _numScheduledScalings++;

    sender()->~QObject();
}

/*****************************************************************************
 * zoom()
 *      Called when a frame of the zoom animation is called.
 *****************************************************************************/

void GLWidget::onZoomChanged(qreal x)
{
    (void)x; //Delete unused warning
    qreal factor = 1 + qreal(_numScheduledScalings) / 300.0; //Faster zoom if faster wheel movement

    CameraAbs *camera = _cameraManager->getActiveCamera();

    if(_isZoomingIn){//Increment or decrease current zoom
        camera->setZoom(camera->getZoom() + factor);
    }else{
        camera->setZoom(camera->getZoom() - factor);
    }
}

/*****************************************************************************
 * resizeGL()
 *      Called on keystrokes. Controls this input.
 *****************************************************************************/
void GLWidget::keyPressEvent(QKeyEvent* event)
{

    bool update = true;
    Point3D *pos;

    switch(event->key()) {

    case Qt::Key_Right: //Move camera to right
        //qDebug() << "PULSANDO RIGHT";
        _cameraManager->getActiveCamera()->move(1, false);
        _objectManager->checkVisibility(_cameraManager->getActiveCamera()->getPosition(), _maxVisibleDistance);

        break;

    case Qt::Key_Left: //Move camera to left
        //qDebug() << "PULSANDO LEFT";
        _cameraManager->getActiveCamera()->move(-1, false);
        _objectManager->checkVisibility(_cameraManager->getActiveCamera()->getPosition(), _maxVisibleDistance);
        break;
    case Qt::Key_Up: //Move camera to front
        //qDebug() << "PULSANDO UP";
        _cameraManager->getActiveCamera()->move(1, true);
        _objectManager->checkVisibility(_cameraManager->getActiveCamera()->getPosition(), _maxVisibleDistance);
        break;

    case Qt::Key_Down: //Move camera to back
        //qDebug() << "PULSANDO DOWN";
        _cameraManager->getActiveCamera()->move(-1, true);
        _objectManager->checkVisibility(_cameraManager->getActiveCamera()->getPosition(), _maxVisibleDistance);
        break;

    //DEBUG
    case Qt::Key_U:
        _cameraManager->getActiveCamera()->move(10, true);
        _objectManager->checkVisibility(_cameraManager->getActiveCamera()->getPosition(), _maxVisibleDistance);
        break;
    case Qt::Key_J:
        _cameraManager->getActiveCamera()->move(-10, true);
        _objectManager->checkVisibility(_cameraManager->getActiveCamera()->getPosition(), _maxVisibleDistance);
        break;

    case Qt::Key_Plus: //Move camera, more altitude
        break;

    case Qt::Key_Minus: //Move camera, less altitude
        break;

    case Qt::Key_W:
        break;
    case Qt::Key_S:
        {
            Point3D * position = _cameraManager->getCamera("free")->getPosition();

            float yaw, pitch;
            _cameraManager->getCamera("free")->getYawPitch(yaw, pitch);

            float zoom = _cameraManager->getCamera("free")->getZoom();
            QString qStr = QString::number(_indexCamera);
            QString Qname = QString("fixedCamera");
            Qname.append(qStr);
            FixedCamera * newcam = new FixedCamera(Qname);
            newcam->getPosition()->setCoordinates(position->getX(),
                                                  position->getY(),
                                                  position->getZ());
            newcam->setYawPitch(yaw, pitch);
            newcam->setZoom(zoom);
            _cameraManager->addCamera(Qname, newcam);
            ++_indexCamera;
        }
        break;
    case Qt::Key_R:
        break;
    case Qt::Key_A:
        break;
    case Qt::Key_D:
        break;
    case Qt::Key_0:
        pos = _objectManager->getCar(0)->getPosition();
        _cameraManager->setCameraOnCar(pos);
        break;
    case Qt::Key_1:
        pos = _objectManager->getCar(1)->getPosition();
        _cameraManager->setCameraOnCar(pos);
        break;
    case Qt::Key_2:
        pos = _objectManager->getCar(2)->getPosition();
        _cameraManager->setCameraOnCar(pos);
        break;
    case Qt::Key_3:
        pos = _objectManager->getCar(3)->getPosition();
        _cameraManager->setCameraOnCar(pos);
        break;
    case Qt::Key_4:
        pos = _objectManager->getCar(4)->getPosition();
        _cameraManager->setCameraOnCar(pos);
        break;
    case Qt::Key_5:
        pos = _objectManager->getCar(5)->getPosition();
        _cameraManager->setCameraOnCar(pos);
        break;
    case Qt::Key_6:
        pos = _objectManager->getCar(6)->getPosition();
        _cameraManager->setCameraOnCar(pos);
        break;
    case Qt::Key_7:
        pos = _objectManager->getCar(7)->getPosition();
        _cameraManager->setCameraOnCar(pos);
        break;
    case Qt::Key_8:
        pos = _objectManager->getCar(8)->getPosition();
        _cameraManager->setCameraOnCar(pos);
        break;
    case Qt::Key_9:
        pos = _objectManager->getCar(9)->getPosition();
        _cameraManager->setCameraOnCar(pos);
        break;
    default:
        update = false;
    }

    if(update){
        Point3D *pos = _cameraManager->getCamera("free")->getPosition();
        //qDebug() << "CAMERA POSITION " << pos->getX() << " " << pos->getY() << " " << pos->getZ();
    }

}

/*****************************************************************************
 * initializeShaders()
 *      Loads custom shader by specifying filename (expects frag/vert pair)
 *****************************************************************************/
void GLWidget::initializeShaders(QString filename)
{

    bool result;
    result = shader->addShaderFromSourceFile( QGLShader::Vertex, filename + ".vert" );
    if ( !result )
        qDebug() << "Vertex: " << shader->log();
    else
        qDebug() << "Vertex shader works!";
    result = shader->addShaderFromSourceFile( QGLShader::Fragment, filename + ".frag" );
    if ( !result )
        qDebug() << "Fragment: " << shader->log();
    else
        qDebug() << "Fragment shader works!";
    result = shader->link();
    if ( !result )
        qDebug() << "Link: " << shader->log();
    else
        qDebug() << "Shaders link: OK!";
    result = shader->bind();
    if ( !result )
        qDebug() << "Bind: " << shader->log();
    else
        qDebug() << "Shaders bind: OK!";

}

/*****************************************************************************
 * releaseAllShaders()
 *      Unload shaders, return to OpenGL fixed function.
 *****************************************************************************/
void GLWidget::releaseAllShaders()
{

    shader->release();
    shader->removeAllShaders();

}
