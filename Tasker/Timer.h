#ifndef TIMER_H
#define TIMER_H
#include <QTime>
#include "Session.h"

namespace Engine {
class Timer;
}

class Engine::Timer
{
private:
    QTime currentProductiveTime;
    QTime currentUnproductiveTime;
    udata::Session currentSession;
    QTime startTime;

public:
    Timer();
    void start();
    void stop();
    void pause();
    QTime getProductiveTime();
    QTime getUnproductiveTime();
    QTime getRealTime();

    QTime getProductiveTimeLeft();
    QTime getRealTimeLeft();

    QTime setProductiveTime(QTime*);
    QTime setRealTime(QTime*);

};

#endif // TIMER_H
