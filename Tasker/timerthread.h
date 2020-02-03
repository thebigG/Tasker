#ifndef TIMERTHREAD_H
#define TIMERTHREAD_H
#include <Listener.h>
#include <QThread>
#include <Timer.h>
class TimerThread : public QThread {
public:
    TimerThread(Engine::Listener::ListenerType newListener);
    virtual void run();

private:
    Engine::Timer *timerThread;
    Engine::Listener::ListenerType listener;
};

#endif // TIMERTHREAD_H
