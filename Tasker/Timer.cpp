#include "Timer.h"
#include "AudioListener.h"
#include "KeyboardListener.h"
#include <StatsUtility.h>
#include <QThread>
#include <QDebug>
#include <QTime>


using namespace Engine;
using namespace util;
using namespace udata;
Timer *Timer::thisInstance = new Timer();
/**
 * @brief Timer::Timer
 */
Timer::Timer() {
    currentProductiveTime = 0;
    currentUnproductiveTime = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Timer::startBackgroundTimer);
    connect(this, &Timer::stopTimer, this , &Timer::stopTimerSlot);
    qDebug()<<"productive time from constructor:"<<currentProductiveTime;
}
/**
 * @brief Timer::Timer
 * @param newListenerType This tells timer what type of listener to instantiate.
 * It's not prettiest way of doing this, but at least we're not doing
 * weird/prone-to-bugs type probing at runtime, like dynamic_cast nonsense.
 *
 */
Timer::Timer(Listener::ListenerType newListenerType,Session newSession ) {
    qDebug() << "Timer() constructor: " << currentThreadId();
    currentSession = newSession;
    listenerType = newListenerType;
    currentProductiveTime = 0;
    currentUnproductiveTime = 0;
//    timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, &Timer::startBackgroundTimer);
    timer = new QTimer(this);
    connect(this, &Timer::stopTimer, this , &Timer::stopTimerSlot);
//    timer->start(1000);
    qDebug() << "Timer() constructor#2 ";
//    connect(&listenerThread, &QThread::started, listener, &Listener::start);
    qDebug() << "Timer() constructor#3";
//    listener->moveToThread(&listenerThread);
    qDebug() << "Timer() constructor#4";
//    listenerThread.start();
//    connect(&listenerThread, &QThread::started, this, &Timer::startTimer);
//    listener->moveToThread(&listenerThread);
//    listenerThread.start();
//    listenerThread.start();
    qDebug()<< "Timer() constructor after start(): "<<currentThreadId();
}

/**
 * @brief Timer::~Timer
 */
Timer::~Timer() {
    if(timer != nullptr)
        delete timer;
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
    /**
        This block of code  WORKS!
        DO NOT DELETE THIS BLOCK OF CODE. IT IS PERFECT!
        Specifically the statements regarding the listener and
        listenerThread. I'm talking about the next 3 lines of code.
     */
    connect(&listenerThread, &QThread::started, listener, &Listener::start);
    listener->moveToThread(&listenerThread);
    listenerThread.start();
    qDebug()<<"startTimer#1";
    connect(timer, &QTimer::timeout, this, &Timer::startBackgroundTimer);
    qDebug()<<"startTimer#2";
    clock.start();
    qDebug()<<"startTimer#3";
    qDebug()<<"startTimer#4";
}

void Timer::startBackgroundTimer()
{
//    int goal = 20;
    qDebug()<<"checking state";
    Listener::ListenerState currentState;
    long long int elapsedSeconds  = StatsUtility::milliToSeconds(clock.restart());
    qDebug()<<"current clock:"<<clock.elapsed();
    if(listener->getState() == Listener::ListenerState::productive)
    {

        currentProductiveTime += elapsedSeconds;
        currentState = Listener::ListenerState::productive;
        qDebug()<<"state: productive";
        qDebug()<<"elapsed time:"<<elapsedSeconds<<" seconds";
    }
    else
    {
        currentUnproductiveTime += elapsedSeconds;
        currentState = Listener::ListenerState::unproductive;
        qDebug()<<"state:unproductive";
    }

    qDebug()<<"productive time:"<<currentProductiveTime;
    qDebug()<<"unproductive time:"<<currentUnproductiveTime;
    qDebug()<<"Total Elapsed time:"<<getTotalTimeElapsed();
    qDebug()<<"current goal"<<productiveTimeGoal;
    if(currentProductiveTime==productiveTimeGoal)
    {
        qDebug()<<">>>>>>>>>>>>>>>>>>goal was reached";
//        timer->stop();
        emit stopTimer();
    }
    emit tick();
}

/**
 * @brief Timer::timeSlot
 */

void Timer::timeSlot() {
    qDebug() << "Time slot func :)";
    qDebug() << "current thread id Timer timeSlot:" << QThread::currentThreadId();
}


int Timer::getTotalTimeElapsed()
{
    return currentUnproductiveTime + currentProductiveTime;
}
Timer* Timer::getInstance()
{
    if(thisInstance == nullptr)
    {
        thisInstance = new Timer();
    }
    return thisInstance;
}
void Timer::setCurrentSession(Session newSession)
{
    currentSession = newSession;
    productiveTimeGoal = currentSession.getGoal();
}
void Timer::setListener(Listener::ListenerType newListenerType)
{
    listenerType = newListenerType;
}
void Timer::initTimer(Listener::ListenerType newListener, udata::Session newSession)
{
    thisInstance->setCurrentSession(newSession);
    thisInstance->setListener(newListener);
    timer->start(TIMER_TICK);
    this->start();

}
void Timer::stopTimerSlot()
{
    timer->stop();
}
QTime Timer::getClock()
{
    return clock;
}
QString Timer::getProductiveStatus()
{
    long long int productiveMinutes = StatsUtility::toMinutes(currentProductiveTime);
    qDebug()<<"productive time on UI:"<<currentProductiveTime;
    QString result;
    int resultProductive =  currentProductiveTime;
    if(resultProductive>HOUR)
    {
        resultProductive += currentProductiveTime -  (productiveMinutes * HOUR);
    }
    else if(resultProductive %  HOUR == 0)
    {
        resultProductive = 0;

    }

    result = QString::number( productiveMinutes)+ ":" + QString::number(resultProductive);
    if(productiveMinutes==ZERO)
    {

    }
    else
    {

    }
    return  result;
}



QString Timer::getUnproductiveStatus()
{
    long long int productiveMinutes = StatsUtility::toMinutes(currentUnproductiveTime);
    qDebug()<<"productive time on UI:"<<currentUnproductiveTime;
    QString result;
    int resultProductive =  currentUnproductiveTime;
    if(resultProductive>HOUR)
    {
        resultProductive += currentUnproductiveTime -  (productiveMinutes * HOUR);
    }
    else if(resultProductive %  HOUR == 0)
    {
        resultProductive = 0;

    }

    result = QString::number( productiveMinutes)+ ":" + QString::number(resultProductive);
    if(productiveMinutes==ZERO)
    {

    }
    else
    {

    }
    return  result;
}


QString Timer::getTimeElapsedStatus()
{
    long long int productiveMinutes = StatsUtility::toMinutes(getTotalTimeElapsed());
    qDebug()<<"productive time on UI:"<<getTotalTimeElapsed();
    QString result;
    int resultProductive =  getTotalTimeElapsed();
    if(resultProductive>HOUR)
    {
        resultProductive += getTotalTimeElapsed() -  (productiveMinutes * HOUR);
    }
    else if(resultProductive %  HOUR == 0)
    {
        resultProductive = 0;

    }

    result = QString::number( productiveMinutes)+ ":" + QString::number(resultProductive);
    if(productiveMinutes==ZERO)
    {

    }
    else
    {

    }
    return  result;
}
