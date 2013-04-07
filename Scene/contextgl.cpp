#include <QtGui/QMouseEvent>
#include "contextgl.h"
#include <QApplication>

#include "Cameras/cameramanager.h"
#include "Cameras/sphericalcamera.h"
#include "Cameras/cameraabs.h"

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


    // 2) Init our own architecture (camera, lights, action!)
    //----------------------------------------------------------
    SphericalCamera * spCam = new SphericalCamera();
    CameraManager::getCameraManager()->setCamera(QString("spherical"), spCam);

    glEnable(GL_TEXTURE_2D);

    // 3) Init shaders
    //----------------------------------------------------------
    //shader =  new QGLShaderProgram();
    //initializeShaders(QString("simple"));


    _scene = new Scene();

}

/*****************************************************************************
 * resizeGL()
 *      Called at context resizing. Controls aspect ratio changes.
 *****************************************************************************/
void GLWidget::resizeGL(int w, int h)
{

    glViewport(0,0,w,h);
    CameraManager::getCameraManager()->getCamera("spherical")
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
    CameraManager::getCameraManager()->getCamera("spherical")->update();

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

    bool update = false;

    if (event->buttons() & Qt::LeftButton)
    {
        CameraManager::getCameraManager()->getCamera("spherical")
                ->addYawPitch(posCam.getX()- event->x(),  posCam.getY() - event->y());
        posCam.setCoordinates(event->x(), event->y());

        update = true;
    }

    if(update)
        updateGL();

}

/*****************************************************************************
 * resizeGL()
 *      Called on keystrokes. Controls this input.
 *****************************************************************************/
void GLWidget::keyPressEvent(QKeyEvent* event)
{
    bool update = true;

    switch(event->key()) {
    case Qt::Key_W:
        break;
    case Qt::Key_S:
        break;
    case Qt::Key_A:
        break;
    case Qt::Key_D:
        break;
    default:
        update = false;
    }

    if(update)
        updateGL();

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
