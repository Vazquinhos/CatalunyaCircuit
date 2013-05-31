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
#include "Lights/light.h"
#include "Lights/swivellight.h"
#include "Lights/lightmanager.h"
#include "Objects/bsplinemanager.h"
#include "Objects/bspline.h"
#include "Utils/timemanager.h"

class GLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    GLWidget(QWidget *parent = NULL);
    ~GLWidget();

    void StartAnimation();
    void StopAnimation();

    void CarViewerShow();

public slots:
    void onZoomChanged(qreal x);
    void onAnimZoomFinished();
    void simulatePhysics();
    void startTimers();
    void PrintModel( QString, int val );
    void changeCarModel();
    void runCar();

signals:
    void MPushed();
    void LoadingFinished();
    void NewModelToPrint( QString );
    void CarFinishEditing();

protected:
    virtual void initializeGL();
    void initializeWorld();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void wheelEvent (QWheelEvent * event);

    Scene *_scene;
    ObjectManager *_objectManager;
    CameraManager *_cameraManager;
    SoundManager  *_soundManager;
    ModelManager  *_modelManager;
    TimeManager  *_timeManager;

    BSplineManager* _bSplineManager;

    bool isInDebugMode;


private:
    int _maxVisibleDistance;
    QSet<int> _pressedKeys;

    float _fps;
    /*float _countFrames;
    float _maxCountFrames;*/
    unsigned int _indexCamera;
    double _totalTime;

    bool _shaders;
    bool animationEnabled;
    bool carViewerActive;

    CarViewer *_carViewer;
    bool _isInDriveMode;

    QTimer *_physicsEventTimer;
    QTimer *_displayEventTimer;
    QTimer *_semaEventTimer;
    QTime  _displayTimer;
    QTime  _physicsTimer;
    LoaderQt* loader;

    bool menuWasVisible;
    bool menuIsVisible;

    QGLShaderProgram *shader;

    Point2D posCam;


    //************** MOUSE ZOOM ******************
    bool _isZoomingIn;
    int _numScheduledScalings;


    /*void onZoomChanged(qreal x);
    void onAnimZoomFinished();*/
    //********************************************
    void processKeys();
    void initializeShaders(QString filename);
    void releaseAllShaders();
};

#endif  /* _GLWIDGET_H */
