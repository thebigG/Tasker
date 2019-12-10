#ifndef TIMER_H
#define TIMER_H
#include "Session.h"
#include <QObject>
#include <QThread>
#include <QTime>

#include <KeyboardListener.h>
namespace Engine {

class Timer;
}
/**
 * @brief The Engine::Timer class
 * @note I had to remove the start() method from Timer.
 * It was conflicting with QThread's start() method.
 */
class Engine::Timer : public QThread {
    Q_OBJECT
private:
    int currentProductiveTime;
    int currentUnproductiveTime;
    udata::Session currentSession;
//    QTime time;
    Listener *listener;
    const QString objectName = "Timer";
    QThread listenerThread;
    virtual void run();

public:
    Timer();
    Timer(Listener::ListenerType);
    ~Timer();
    void stop();
    void pause();
    void startConnect();
    QTime getProductiveTime();
    QTime getUnproductiveTime();
    QTime getRealTime();
    QTime getProductiveTimeLeft();
    QTime getRealTimeLeft();
    Listener::ListenerType listenerType;
    QTime setProductiveTime(QTime *);
    QTime setRealTime(QTime *);
    void startTimer();
    QTime* time;

public slots:
    void timeSlot();
signals:
    void startListener();
};

#endif // TIMER_H
