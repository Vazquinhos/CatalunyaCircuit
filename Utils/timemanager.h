#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <vector>
#include <QTimer>
#include <QTime>
#include <QObject>


class TimeManager : public QObject
{
    Q_OBJECT
public:
    TimeManager();
    static TimeManager	* getTimeManager();

    int getCurrentTimeMilis();
    int getCurrentTimeSeconds();
    void setElapsedTime(float time);
    float getElapsedTime();
    ~TimeManager();

private:
    static TimeManager * _p_timeManager;
    QTimer *_timerUpdate;
    QTime _timerCount;
    float _elapsedTime;

};

#endif // TIMEMANAGER_H
