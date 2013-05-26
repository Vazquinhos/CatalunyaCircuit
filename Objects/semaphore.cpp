#include "semaphore.h"
#include "Objects/objectManager.h"
#include <QDebug>

Semaphore::Semaphore()
{
    _soundManager = SoundManager::getSoundManager();
    _modelManager = ModelManager::getModelManager();
    _state = 0;

    _semNormal = _modelManager->getModel("Semaphore/SemaphoreNormal/semaphoreNormal.3ds");
    _semRed1 = _modelManager->getModel("Semaphore/SemaphoreRed1/semaphoreRed1.3ds");
    _semRed2 = _modelManager->getModel("Semaphore/SemaphoreRed2/semaphoreRed2.3ds");
    _semYellow = _modelManager->getModel("Semaphore/SemaphoreYellow/semaphoreYellow.3ds");
    _semGreen = _modelManager->getModel("Semaphore/SemaphoreGreen/semaphoreGreen.3ds");

    _model = _semNormal;

    _semNormal->setVisibility(true);
    _semRed1->setVisibility(false);
    _semRed2->setVisibility(false);
    _semYellow->setVisibility(false);
    _semGreen->setVisibility(false);
}

Model3D * Semaphore::getModel(){
    return _model;
}

Semaphore::~Semaphore(){

}

void Semaphore::update(){
    if(_state == 0){
        qDebug() << "ESTADO APAGADO1";
        _model = _semNormal;
        ++_state;
    }else if(_state == 1){
        qDebug() << "ESTADO ROJO 1";
        _model = _semRed1;

        ++_state;
    }else if(_state == 2){
        qDebug() << "ESTADO ROJO 2";
        _model = _semRed2;
        ++_state;
    }
    else if(_state == 3){
        qDebug() << "ESTADO VERDE";
        _model = _semGreen;
        ++_state;

    }else{
        qDebug() << "ESTADO APAGADO2";
        _model = _semNormal;

        endSemaphore();
        _state = 0;
    }
    ObjectManager::getObjectManager()->checkVisibility();
}

void Semaphore::startSemaphore(){
    _timerUpdate = new QTimer(this);
    connect(_timerUpdate, SIGNAL(timeout()), this, SLOT(update()));
    _timerUpdate->start(700);
    _soundManager->PlayAction("startRace");
}
void Semaphore::endSemaphore(){
    _timerUpdate->stop();
}
