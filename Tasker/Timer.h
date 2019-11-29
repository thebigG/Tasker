#ifndef TIMER_H
#define TIMER_H
#include <QTime>
#include <QThread>
#include "Session.h"
#include <QObject>
#include <KeyboardListener.h>
namespace Engine {
class Timer;
}

class Engine::Timer: public QThread
{
Q_OBJECT
private:
    QTime currentProductiveTime;
    QTime currentUnproductiveTime;
    udata::Session currentSession;
    QTime startTime;
    Listener* thisK;

public:
    Timer();
    ~Timer();
    void start();
    void stop();
    void pause();
    void startConnect();
    QTime getProductiveTime();
    QTime getUnproductiveTime();
    QTime getRealTime();

    QTime getProductiveTimeLeft();
    QTime getRealTimeLeft();

    QTime setProductiveTime(QTime*);
    QTime setRealTime(QTime*);
public slots:
void timeSlot();

};

#endif // TIMER_H
