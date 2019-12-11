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
    QTime clock{0,0,0};
    static Timer *thisInstance;
    Listener *listener;
    Listener::ListenerType listenerType;
    QThread listenerThread;
    QThread thisThread;
    QTimer* timer;
    virtual void run();

public:
    Timer();
    Timer(Listener::ListenerType, udata::Session);
    static Timer* getInstance();
    void initTimer(Listener::ListenerType, udata::Session);
    ~Timer();
    void stop();
    void pause();
    void setCurrentSession(udata::Session);
    void setListener(Listener::ListenerType);
    void startConnect();
    QTime getProductiveTime();
    QTime getUnproductiveTime();
    QTime getRealTime();
    QTime getProductiveTimeLeft();
    QTime getRealTimeLeft();
    QTime setProductiveTime(QTime *);
    QTime setRealTime(QTime *);
    void startTimer();
    QTime* time;
    int getTotalTimeElapsed();

public slots:
    void timeSlot();
    void startBackgroundTimer();
signals:
    void startListener();
};

#endif // TIMER_H
