#ifndef TIMERTHREAD_H
#define TIMERTHREAD_H
#include <Listener.h>
#include <QThread>
#include <Timer.h>
using namespace Engine;
class TimerThread : public QThread {
public:
    TimerThread(Listener::ListenerType newListener);
    virtual void run();

private:
    Engine::Timer *timerThread;
    Listener::ListenerType listener;
};

#endif // TIMERTHREAD_H
