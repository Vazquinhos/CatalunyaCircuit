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
    _semYellow = _modelManager->getModel("Semaphore/SemaphoreYellow/semaphoreYellow.3ds");
    _semGreen = _modelManager->getModel("Semaphore/SemaphoreGreen/semaphoreGreen.3ds");

    _model = _semNormal;

    _isActive = false;
}

Model3D * Semaphore::getModel(){
    return _model;
}

Semaphore::~Semaphore(){

}

bool Semaphore:: isActive(){
    return _isActive;
}

void Semaphore::updateSemaphoreState(){
        if(_state == 0){
            qDebug() << "ESTADO APAGADO1";
            _soundManager->PlayAction("ready");
            _model = _semYellow;
            ++_state;
        }else if(_state == 1){
            _soundManager->PlayAction("ready");
            qDebug() << "ESTADO ROJO 1";
            _model = _semRed1;

            ++_state;
        }else if(_state == 2){
            _soundManager->PlayAction("go");
            qDebug() << "ESTADO ROJO 2";
            _model = _semGreen;
            ++_state;
        }
        else if(_state < 10){
            qDebug() << "ESTADO VERDE";
            ++_state;
        }else{
            _state = 0;
            _model = _semNormal;
            endSemaphore();

        }
        ObjectManager::getObjectManager()->checkVisibility();

}

void Semaphore::startSemaphore(){
    _timerUpdate = new QTimer(this);
    connect(_timerUpdate, SIGNAL(timeout()), this, SLOT(updateSemaphoreState()));
    _timerUpdate->start(1000);
    //_soundManager->PlayAction("startRace");
    _isActive = true;
}
void Semaphore::endSemaphore(){
    _timerUpdate->stop();
    _isActive = false;
}
