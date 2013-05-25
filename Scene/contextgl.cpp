#include <QtGui/QMouseEvent>
#include "contextgl.h"
#include <QApplication>
#include <QTimeLine>
#include <QStringList>
#include <Ui/loaderqt.h>
#include <QThread>
#include "Cameras/cameramanager.h"
#include "Cameras/fixedcamera.h"
#include "GL/glut.h"
#include <QThread>
#include <QSet>



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
    loader = new LoaderQt();
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

    glShadeModel(GL_SMOOTH);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    // default components for global illumination
    LightManager::getLightManager()->setupDefault();
    LightManager::getLightManager()->setActiveLight(QString("Light0"));
}


/*****************************************************************************
 * initializeWorld()
 *      Makes all needed inicialization that is not part of openGL config
 *****************************************************************************/
void GLWidget::initializeWorld(){
    _soundManager = SoundManager::getSoundManager();
    _soundManager->CleanUP();
    _soundManager->getSoundManager()->LoadSounds( "Media/XML/sounds.xml" );
    _soundManager->getSoundManager()->PlayAction("intro");

    // 1) Load and initialize managers

    _objectManager = ObjectManager::getObjectManager();
    _cameraManager = CameraManager::getCameraManager();
    _modelManager  =  ModelManager::getModelManager();

    // 2) Init our own architecture (camera, lights, action!)
    //----------------------------------------------------------
    _isInDriveMode = false;
    _fps = 0;
    _indexCamera = 0;
    _maxVisibleDistance = 200;

    glEnable(GL_TEXTURE_2D);

    // 3) Init shaders
    //----------------------------------------------------------
    shader =  new QGLShaderProgram();
    initializeShaders(QString("./Shader/simple"));


    QThread *p_thread = new QThread();
    _modelManager->moveToThread( p_thread );
    //QObject::connect(modelManager, error(QString),this,SLOT(er));
    QObject::connect(p_thread, SIGNAL(started()),_modelManager,SLOT(loadModels()));
    QObject::connect(_modelManager,SIGNAL(finish()),p_thread,SLOT(quit()));
    QObject::connect(_modelManager,SIGNAL(NewModel(QString,int)),this,SLOT(PrintModel(QString,int)));
    p_thread->start();
    QObject::connect(_modelManager,SIGNAL(finish()),this,SLOT(startTimers()));
}

void GLWidget::changeCarModel()
{
    _carViewer->changeToViewerMode();
}

void GLWidget::simulatePhysics()
{
    _scene->simulatePhisics(_physicsTimer.restart()/1000.0f);
    processKeys();
}

void GLWidget::PrintModel(QString a,int val)
{
    loader->PrintModelLoaded(a,val);
}

void
GLWidget::startTimers()
{
    ModelManager *modelManager = ModelManager::getModelManager();

    modelManager->loadMaterials();
    modelManager->render();
    loader->hide();
    _scene = new Scene();
    _objectManager->checkVisibility();
    // This slot will be called when the signal finish of loading models is emited
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

    emit LoadingFinished();

    _carViewer = new CarViewer();
    _timeManager = TimeManager::getTimeManager();
    _bSplineManager = BSplineManager::getBSplineManager();
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

    if(_carViewer->isActive())
        ((SwivelLight*)LightManager::getLightManager()->getActiveLight())->update(d_elapsedTime, GL_LIGHT0);
    else
        LightManager::getLightManager()->update();

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
        _objectManager->checkVisibility();
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
    _pressedKeys.insert(event->key());

    /*
      qDebug() << "*****************TECLAS PULSADAS********************** " ;
            QString teclas = "";
    int size = pressedKeys.size();
    for(int i = 0; i < size ;++i){
        teclas += " " + QString::number(pressedKeys.toList()[i]);
    }
    qDebug() << teclas;
    */
}

void GLWidget::processKeys(){
    QList<int> presedKeys;
    bool update = true;

    int size = _pressedKeys.size();
    presedKeys = _pressedKeys.toList();

    for(int i = 0; i < size ;++i){
        switch(presedKeys[i]) {

        case Qt::Key_E:
            _bSplineManager->saveCapturingSpline();
            break;
        case Qt::Key_C:
            _bSplineManager->captureNewSpline();
            break;

        case Qt::Key_V://Move camera to right
            _scene->turnDebugMode();
            break;

        case Qt::Key_M://Move camera to right
            emit MPushed();
            break;
        case Qt::Key_Escape: //Move camera to right

            if(_carViewer->isActive()){
                _carViewer->exitViewer();
                ((SwivelLight*)LightManager::getLightManager()->getActiveLight())->stopAnimation();
            }

            if(_isInDriveMode){
                _isInDriveMode = false;
                _cameraManager->setActiveCamera("free");
            }
            break;

        case Qt::Key_Return: //Move camera to right
            if(_carViewer->isActive()){
                _carViewer->selectCar();
                _isInDriveMode = true;
                ((SwivelLight*)LightManager::getLightManager()->getActiveLight())->stopAnimation();
            }break;

        case Qt::Key_Right: //Move camera to right
            //qDebug() << "PULSANDO RIGHT";
            if(!_carViewer->isActive())
            {
                _cameraManager->getActiveCamera()->move(1, false);
                _objectManager->checkVisibility();
                _bSplineManager->updateCapturingSpline();
            }else{
                _carViewer->shiftNextCar();
            }
            break;

        case Qt::Key_Left: //Move camera to left
            //qDebug() << "PULSANDO LEFT";
            if(!_carViewer->isActive()){
                _cameraManager->getActiveCamera()->move(-1, false);
                _objectManager->checkVisibility();
                _bSplineManager->updateCapturingSpline();
            } else {
                _carViewer->shiftPreviousCar();
            }
            break;
        case Qt::Key_Up: //Move camera to front
            //qDebug() << "PULSANDO UP";
            _cameraManager->getActiveCamera()->move(1, true);
            _objectManager->checkVisibility();
            _bSplineManager->updateCapturingSpline();
            break;

        case Qt::Key_Down: //Move camera to back
            //qDebug() << "PULSANDO DOWN";
            _cameraManager->getActiveCamera()->move(-1, true);
            _objectManager->checkVisibility();
            _bSplineManager->updateCapturingSpline();
            break;

            //DEBUG
        case Qt::Key_U:
            _cameraManager->getActiveCamera()->move(10, true);
            _objectManager->checkVisibility();
            break;
        case Qt::Key_J:
            _cameraManager->getActiveCamera()->move(-10, true);
            _objectManager->checkVisibility();
            break;

        case Qt::Key_Plus:{
            Light* light = LightManager::getLightManager()->getActiveLight();
            light->setPosition(new Point3D(light->getPosition()->getX(),
                                           light->getPosition()->getY(),
                                           light->getPosition()->getZ()+2));
            break;
        }

        case Qt::Key_Minus:{
            Light* light = LightManager::getLightManager()->getActiveLight();
            light->setPosition(new Point3D(light->getPosition()->getX(),
                                           light->getPosition()->getY(),
                                           light->getPosition()->getZ()-2));
            break;
        }

        case Qt::Key_W:
            if(_isInDriveMode){
                _objectManager->getActiveDriveCar()->accelerate();
            }
            else
            {
                Light* light = LightManager::getLightManager()->getActiveLight();
                light->setPosition(new Point3D(light->getPosition()->getX()+2,
                                               light->getPosition()->getY(),
                                               light->getPosition()->getZ()));
            }
            break;

        case Qt::Key_A:
            if(_isInDriveMode){
                _objectManager->getActiveDriveCar()->turnLeft();
            }
            else
            {
                Light* light = LightManager::getLightManager()->getActiveLight();
                light->setPosition(new Point3D(light->getPosition()->getX(),
                                               light->getPosition()->getY()-2,
                                               light->getPosition()->getZ()));
            }
            break;
        case Qt::Key_S:
            if(_isInDriveMode){
                _objectManager->getActiveDriveCar()->brake();
            }
            else
            {
                Light* light = LightManager::getLightManager()->getActiveLight();
                light->setPosition(new Point3D(light->getPosition()->getX()-2,
                                               light->getPosition()->getY(),
                                               light->getPosition()->getZ()));
            }
            break;

        case Qt::Key_D:
            if(_isInDriveMode){
                _objectManager->getActiveDriveCar()->turnRight();
            }
            else
            {
                Light* light = LightManager::getLightManager()->getActiveLight();
                light->setPosition(new Point3D(light->getPosition()->getX(),
                                               light->getPosition()->getY()+2,
                                               light->getPosition()->getZ()));
            }
            break;

        case Qt::Key_R:
            /*if(_shaders)
            releaseAllShaders();

        else
            initializeShaders(QString("./Shader/simple"));
        _shaders = !_shaders;*/
            //((SwivelLight*)LightManager::getLightManager()->getActiveLight())->startAnimation();
            break;

        case Qt::Key_1:
            if(_isInDriveMode){
                _objectManager->getActiveDriveCar()->viewCamera(Car::FRONTAL_CAMERA);
            }
            break;
        case Qt::Key_2:
            if(_isInDriveMode){
                _objectManager->getActiveDriveCar()->viewCamera(Car::REAR_CAMERA);
            }
            break;
        case Qt::Key_3:
            if(_isInDriveMode){
                _objectManager->getActiveDriveCar()->viewCamera(Car::LEFT_CAMERA);
            }
            break;
        case Qt::Key_4:
            if(_isInDriveMode){
                _objectManager->getActiveDriveCar()->viewCamera(Car::RIGHT_CAMERA);
            }
            break;
        default:
            update = false;
        }

        if(update){
            float yaw, pitch;
            Point3D *pos = _cameraManager->getCamera("free")->getPosition();
            _cameraManager->getCamera("free")->getYawPitch(yaw, pitch);
            qDebug() << "CAMERA POSITION " << pos->getX() << " " << pos->getY() << " " << pos->getZ() << " " << yaw << " " << pitch;
        }
    }
}

void GLWidget::keyReleaseEvent(QKeyEvent *event)
{
    _pressedKeys.remove(event->key());
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
