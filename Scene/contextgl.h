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
#include <QTimer>
#include "Ui/loaderqt.h"
#include "Objects/carviewer.h"
#include "Sound/SoundManager.h"
#include "Objects/modelManager.h"


class GLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    GLWidget(QWidget *parent = NULL);
    ~GLWidget();

public slots:
    void onZoomChanged(qreal x);
    void onAnimZoomFinished();
    void simulatePhysics();
    void startTimers();
    void PrintModel( QString, int val );
    void changeCarModel();

signals:
    void MPushed();
    void LoadingFinished();
    void NewModelToPrint( QString );


protected:
    virtual void initializeGL();
    void initializeWorld();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent (QWheelEvent * event);

    Scene *_scene;
    ObjectManager *_objectManager;
    CameraManager *_cameraManager;
    SoundManager  *_soundManager;
    ModelManager  *_modelManager;

private:
    int _maxVisibleDistance;

    float _fps;
    /*float _countFrames;
    float _maxCountFrames;*/
    unsigned int _indexCamera;
    double _totalTime;

    CarViewer *_carViewer;
    bool _isInDriveMode;

    QTimer *_physicsEventTimer;
    QTimer *_displayEventTimer;
    QTime  _displayTimer;
    QTime  _physicsTimer;
    LoaderQt* loader;

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
