#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include "Objects/model3D.h"
#include "Objects/modelManager.h"
#include "Sound/SoundManager.h"
#include <QTimer>
#include <QObject>

class Semaphore: public QObject
{
    Q_OBJECT
public:
    Semaphore();
    ~Semaphore();

    void startSemaphore();
    void endSemaphore();
    Model3D * getModel();

    //=================== Inherited =================
public slots:
    void update();

private:
    int _state;
    SoundManager *_soundManager;
    ModelManager *_modelManager;
    Model3D *_semNormal;
    Model3D *_semRed1;
    Model3D *_semRed2;
    Model3D *_semYellow;
    Model3D *_semGreen;

    Model3D *_model;
    QTimer *_timerUpdate;
};

#endif // SEMAPHORE_H
