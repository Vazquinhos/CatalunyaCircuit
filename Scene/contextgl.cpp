#include <QtGui/QMouseEvent>
#include "contextgl.h"
#include "Objects/modelManager.h"
#include <QApplication>
#include <QTimeLine>
#include <QStringList>


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

#ifndef __APPLE__

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

#endif


    // 1) Go for a well known initialization state.
    //    (essential stuff only)
    //----------------------------------------------------------

    // 1a) Setting default values to clean buffers
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClearDepth(1.0f); // This is the default OpenGL value, but I'm making it explicit for you

    // 1b) Backface culling enabled
    //     (this will speedup rendering)
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // 1c) Enable depth testing
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);


    //1) Initialize variables

    // *********** LOAD MODELS **************/
    QStringList modelFilters;
    QStringList textureFilters;
    modelFilters << "*.3ds";
    textureFilters <<"*.dds" << "*.tga";
    ModelManager *modelManager = ModelManager::getModelManager();
    modelManager->loadModels("/Media/Models/", modelFilters, textureFilters);
    //**********************************************************

    _scene = new Scene();
    _objectManager = ObjectManager::getObjectManager();
    _cameraManager = CameraManager::getCameraManager();


    // 2) Init our own architecture (camera, lights, action!)
    //----------------------------------------------------------
    SphericalCamera * spCam = new SphericalCamera(QString("spherical"));
    _cameraManager->addCamera(QString("spherical"), spCam);
    _cameraManager->setActiveCamera("spherical");
    FreeCamera * frCam = new FreeCamera();
    _cameraManager->addCamera(QString("free"), frCam);

    _maxVisibleDistance = 200;
    _objectManager->checkVisibility(_cameraManager->getCamera("free")->getPosition(), _maxVisibleDistance);

    glEnable(GL_TEXTURE_2D);

    // 3) Init shaders
    //----------------------------------------------------------
    //shader =  new QGLShaderProgram();
    //initializeShaders(QString("simple"));




}

/*****************************************************************************
 * resizeGL()
 *      Called at context resizing. Controls aspect ratio changes.
 *****************************************************************************/
void GLWidget::resizeGL(int w, int h)
{

    glViewport(0,0,w,h);
    _cameraManager->getCamera("free")
            ->resizeProjection(w, h);

}

/*****************************************************************************
 * resizeGL()
 *      Called automatically after init, on possible clock events,
 *      or after UpdateGL requests. Controls context painting.
 *****************************************************************************/
void GLWidget::paintGL()
{
    // Clean buffers:
    // COLOR to ensure final representation has no waste from previous renders
    // DEPTH to ensure correct representation of objects given the depht testing used
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Update camera to its current position
    _cameraManager->getCamera("free")->update();
    _scene->display();
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
        _cameraManager->getCamera("free")
                ->addYawPitch(posCam.getX()- event->x(),  posCam.getY() - event->y());
        posCam.setCoordinates(event->x(), event->y());

        updateGL();
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

    CameraAbs *camera = _cameraManager->getCamera("free");

    if(_isZoomingIn){//Increment or decrease current zoom
        camera->setZoom(camera->getZoom() + factor);
    }else{
        camera->setZoom(camera->getZoom() - factor);
    }

    updateGL();
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
        _cameraManager->getCamera("free")->move(1, false);
        _objectManager->checkVisibility(_cameraManager->getCamera("free")->getPosition(), _maxVisibleDistance);

        break;

    case Qt::Key_Left: //Move camera to left
        //qDebug() << "PULSANDO LEFT";
        _cameraManager->getCamera("free")->move(-1, false);
        _objectManager->checkVisibility(_cameraManager->getCamera("free")->getPosition(), _maxVisibleDistance);
        break;
    case Qt::Key_Up: //Move camera to front
        //qDebug() << "PULSANDO UP";
        _cameraManager->getCamera("free")->move(1, true);
        _objectManager->checkVisibility(_cameraManager->getCamera("free")->getPosition(), _maxVisibleDistance);
        break;

    case Qt::Key_Down: //Move camera to back
        //qDebug() << "PULSANDO DOWN";
        _cameraManager->getCamera("free")->move(-1, true);
        _objectManager->checkVisibility(_cameraManager->getCamera("free")->getPosition(), _maxVisibleDistance);
        break;
        break;

    case Qt::Key_Plus: //Move camera, more altitude
        break;

    case Qt::Key_Minus: //Move camera, less altitude
        break;

    case Qt::Key_W:
        break;
    case Qt::Key_S:
        pos = _cameraManager->getCamera("free")->getPosition();
        qDebug() << "POSICION CAMERA:";
        qDebug() << "X " << pos->getX() << " Y " << pos->getY() << " Z " << pos->getZ();
        break;
    case Qt::Key_R:
        _cameraManager->getCamera("free")->getPosition()->setCoordinates(0,0,0);
        _cameraManager->getCamera("free")->setYawPitch(0,0);
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
        qDebug() << "CAMERA POSITION " << pos->getX() << " " << pos->getY() << " " << pos->getZ();
        updateGL();
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
