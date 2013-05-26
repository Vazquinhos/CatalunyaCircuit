#include "timemanager.h"

TimeManager * TimeManager::_p_timeManager = NULL;

TimeManager::TimeManager() : QObject()
{
    _timerUpdate = new QTimer(this);
    connect(_timerUpdate, SIGNAL(timeout()), this, SLOT(updateTimers()));
    _timerUpdate->start(1);

    _timerCount.start();
}

TimeManager::~TimeManager(){

}

TimeManager* TimeManager::getTimeManager(){
    if(!_p_timeManager){
        _p_timeManager = new TimeManager();
    }
    return _p_timeManager;
}
int TimeManager::getCurrentTimeMilis(){
    return _timerCount.elapsed();
}
int TimeManager::getCurrentTimeSeconds(){
    return _timerCount.elapsed()/1000;
}

void TimeManager::addUpdateable(Updatable *updatable){
    _vUpdatables.push_back(updatable);
}

void TimeManager::updateTimers(){
    for(unsigned int i = 0; i < _vUpdatables.size(); ++i){
        _vUpdatables[i]->updateTimer();
    }
}

void TimeManager::setElapsedTime(float time){
    _elapsedTime = time;
}
float TimeManager::getElapsedTime(){
    return _elapsedTime;
}
