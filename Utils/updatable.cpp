#include "updatable.h"
#include "Utils/timemanager.h"

Updatable::Updatable(int updateInterval)
{
    _updateInterval = updateInterval;
    _currentTime = 0;

    TimeManager::getTimeManager()->addUpdateable(this);
}

Updatable::~Updatable(){

}

void Updatable::updateTimer(){
    ++_currentTime;
    if(_currentTime < _updateInterval){
        update();
    }else{
        _currentTime = 0;
    }
}

void Updatable::update(){}
