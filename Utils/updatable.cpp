#include "updatable.h"
#include "Utils/timemanager.h"

Updatable::Updatable(int updateInterval, bool start)
{
    _updateInterval = updateInterval;
    _currentTime = 0;
    _isActive = start;

    TimeManager::getTimeManager()->addUpdateable(this);
}

Updatable::~Updatable(){

}

void Updatable::updateTimer(){
    if(_isActive){
        if(_currentTime < _updateInterval){
            update();
            ++_currentTime;
        }else{
            _currentTime = 0;
        }
    }
}

void Updatable::update(){}

void Updatable::startAllTimers(){
    _isActive = true;
}

void Updatable::stopAllTimers(){
    _isActive = false;
    _currentTime = 0;
}
