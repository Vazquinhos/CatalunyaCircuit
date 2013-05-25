#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <vector>
#include <QTimer>
#include <QTime>
#include <QObject>
#include "Utils/updatable.h"

class TimeManager : public QObject
{
    Q_OBJECT
public:
    TimeManager();
    static TimeManager	* getTimeManager();

    void addUpdateable(Updatable *updatable);
    int getCurrentTimeMilis();
    int getCurrentTimeSeconds();
    ~TimeManager();

private:
    static TimeManager * _p_timeManager;
    std::vector<Updatable*> _vUpdatables;
    QTimer *_timerUpdate;
    QTime _timerCount;

private slots:
    void update();
};

#endif // TIMEMANAGER_H
