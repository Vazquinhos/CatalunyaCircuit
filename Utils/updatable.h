#ifndef UPDATABLE_H
#define UPDATABLE_H

#include <QTimer>

class Updatable
{
public:
    Updatable(int updateInterval, bool start);
    ~Updatable();
    void update();
    void updateTimer();

    void startAllTimers();
    void stopAllTimers();

protected:
    bool _isActive;
    int _updateInterval;
    int _currentTime;
};

#endif // UPDATABLE_H
