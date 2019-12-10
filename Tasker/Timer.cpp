#include "Timer.h"
#include "AudioListener.h"
#include "KeyboardListener.h"
#include <QThread>
#include <QDebug>
#include <QTime>

using namespace Engine;

/**
 * @brief Timer::Timer
 */
Timer::Timer() {
    qDebug() << "Timer() constructor: " << currentThreadId();
    connect(&listenerThread, &QThread::started, this, &Timer::startTimer);
    listener->moveToThread(&listenerThread);
    listenerThread.start();
}
/**
 * @brief Timer::Timer
 * @param newListenerType This tells timer what type of listener to instantiate.
 * It's not prettiest way of doing this, but at least we're not doing
 * weird/prone-to-bugs type probing at runtime, like dynamic_cast nonsense.
 *
 */
Timer::Timer(Listener::ListenerType newListenerType) {
    qDebug() << "Timer() constructor: " << currentThreadId();
    listenerType = newListenerType;
    connect(&listenerThread, &QThread::started, this, &Timer::startTimer);
//    this->moveToThread(&listenerThread);

//    listenerThread.start();
    qDebug()<< "Timer() constructor after start(): "<<currentThreadId();
}

/**
 * @brief Timer::~Timer
 */
Timer::~Timer() {
    delete listener;
}

/**
 * @brief Timer::run
 * This function is called when the thread starts.
 *Any and all QObjects(such as Listener) MUST be instantiated inside this method.
 * Otherwise, QT's thread management will NOT consider that QObject as part of the Timer
 * thread.
 *The code in &Listener::start, which is the ACTUAL code that listents to hardware,
 * does not run until the startListner() signal is sent.
 */
// void Timer::run() {
//    qDebug() << "From work thread: " << currentThreadId();

//    if (listenerType == Listener::ListenerType::keyboard) {
//        listener = new KeyboardListener();
//    } else if (listenerType == Listener::ListenerType::audio) {
//        listener = new AudioListener();
//    }

//    connect(this, &Timer::startListener, listener, &Listener::start);
//    emit startListener();
//    int i =0;
//    exec();
//}
void Timer::run()
{
    qDebug()<<"run method on Timer:"<<QThread::currentThreadId();
    startTimer();
    exec();

}
void Timer::startTimer() {
    qDebug() << "From work thread: " << currentThreadId();

    if (listenerType == Listener::ListenerType::keyboard) {
        listener = new KeyboardListener();
    } else if (listenerType == Listener::ListenerType::audio) {
        listener = new AudioListener();
    }
    qDebug()<<"before listener->start()";

    qDebug()<<"after listener->start()";
//    time = new QTime();
//    qDebug() << "From work thread: " << currentThreadId();
//    listener->moveToThread(&listenerThread);
//    listenerThread.start();
////    ((QThread*)listener)->start();
//    qDebug() << "From work thread after connect after signal: " << currentThreadId();
    int goal = 100;
//    time->start();
//    currentProductiveTime = 0;
//    qDebug() << "productive time" << currentProductiveTime;
    while (currentProductiveTime < goal) {
//        currentProductiveTime += time.elapsed();
        currentProductiveTime++;
        qDebug() << "productive time" << currentProductiveTime;
    }
//    qDebug() << "goal was reached :)";
//    int i = 0;
}

/**
 * @brief Timer::timeSlot
 */
void Timer::timeSlot() {
    qDebug() << "Time slot func :)";
    qDebug() << "current thread id Timer timeSlot:" << QThread::currentThreadId();
}

/**
 * @brief Timer::getRealTime
 * @return
 */
QTime Timer::getRealTime() { // not implemented
    return QTime::currentTime();
}
