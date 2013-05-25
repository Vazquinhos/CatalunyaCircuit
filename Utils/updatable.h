#ifndef UPDATABLE_H
#define UPDATABLE_H

#include <QTimer>

class Updatable
{
public:
    Updatable(int updateInterval);
    virtual ~Updatable();
    virtual void update();
    void updateTimer();

protected:
    int _updateInterval;
    int _currentTime;
};

#endif // UPDATABLE_H
