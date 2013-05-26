#include "timemanager.h"

TimeManager * TimeManager::_p_timeManager = NULL;

TimeManager::TimeManager() : QObject()
{
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

void TimeManager::setElapsedTime(float time){
    _elapsedTime = time;
}

float TimeManager::getElapsedTime(){
    return _elapsedTime;
}
