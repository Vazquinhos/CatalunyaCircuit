#ifndef _GLWIDGET_H
#define _GLWIDGET_H

#include "Utils/util.h"
#include <QtOpenGL/QGLWidget>
#include <QGLShaderProgram>
#include "camera.h"

#include "Scene/scene.h"
#include "Cameras/cameramanager.h"
#include "Cameras/sphericalcamera.h"
#include "Cameras/cameraabs.h"
#include "Cameras/freecamera.h"

class GLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    GLWidget(QWidget *parent = NULL);
    ~GLWidget();

public slots:
    void onZoomChanged(qreal x);
    void onAnimZoomFinished();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent (QWheelEvent * event);

private:
    Scene *_scene;
    ObjectManager *_objectManager;
    CameraManager *_cameraManager;

    QGLShaderProgram *shader;

    Point2D posCam;

    //************** MOUSE ZOOM ******************
    bool _isZoomingIn;
    int _numScheduledScalings;


    /*void onZoomChanged(qreal x);
    void onAnimZoomFinished();*/
    //********************************************

    void initializeShaders(QString filename);
    void releaseAllShaders();



};

#endif  /* _GLWIDGET_H */
