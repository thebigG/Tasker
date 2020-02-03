#include "timerthread.h"
#include <Listener.h>

TimerThread::TimerThread(Engine::Listener::ListenerType newListener)
: listener{ newListener } {
}
void TimerThread::run() {
    //    timerThread = new Timer(listener);
    exec();
}
