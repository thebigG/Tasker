#include "Timer.h"
#include "AudioListener.h"
#include "KeyboardListener.h"
#include <StatsUtility.h>
#include <QThread>
#include <QDebug>
#include <QTime>
#include <mainui.h>

using namespace Engine;
using namespace util;
using namespace udata;
Timer *Timer::thisInstance;
/**
 * @brief Timer::Timer
 */
Timer::Timer(int newNiceness) {
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

    connect(timer, &QTimer::timeout, this, &Timer::startBackgroundTimer);
    timer = new QTimer(this);
    connect(this, &Timer::stopTimer, this , &Timer::stopTimerSlot);
    qDebug() << "Timer() constructor#2 ";
    qDebug() << "Timer() constructor#3";
    qDebug() << "Timer() constructor#4";
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
    qDebug()<<"startTimer#2";
    clock.start();
    qDebug()<<"startTimer#3";
    qDebug()<<"startTimer#4";
}
/**
 * @brief Timer::startBackgroundTimer
 * This is a time-sensitive function. Whatever it executes, it MUST return
 * within 1 second.
 */
void Timer::startBackgroundTimer()
{
    qDebug()<<"background timer thread id:"<<QThread::currentThreadId();
    qDebug()<<"checking state";
    Listener::ListenerState currentState;
    long long int elapsedSeconds  = StatsUtility::milliToSeconds(clock.restart());
    qDebug()<<"current clock:"<<clock.elapsed();
    qDebug()<<"elapsedSeconds:"<<elapsedSeconds;
    int tickDelta;
    if(listener->getState() == Listener::ListenerState::productive)
    {

        tickDelta = tickCount - producitveTickCount;
        currentProductiveTime += 1;
        currentState = Listener::ListenerState::productive;
        qDebug()<<"state: productive";
        qDebug()<<"elapsed time:"<<elapsedSeconds<<" seconds";
        producitveTickCount += 1;
        lastProductiveTick = tickCount;
    }
    else
    {
        currentUnproductiveTime += unproductiveTimeSurplus;
        currentState = Listener::ListenerState::unproductive;
        unProducitveTickCount += 1;
        lastUnproductiveTick = tickCount;
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
    tickCount++;
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
    startTimeStamp = clock.elapsed();
    timer->start(TIMER_TICK);
    this->start();

}
/**
 * @brief Timer::productiveSlot
 *
 * Called every time the listener emits the prductive signal.
 * This function can be used to crunch more stats on hardware interaction.
 * For example; we could keep internal productive counters on timer
 * and give the user data such as "you were most productive
 * on the first 10 minutes of the session" because there was a constant increment
 * on your productive signal count. I think the possibility are endless, in terms of data,
 * depending on the context, whether they're writing or practicing music.
 *
 */
void Timer::productiveSlot()
{
//    startBackgroundTimer();
    productiveSignalCount++;
    qDebug()<<"<<<<<<<productive signal>>>>>>";
    qDebug()<<"productive signal count:"<<this->productiveSignalCount;
}
/**
 * @brief Timer::unProductiveSlot
 *Called every time the listener emits the unProductive signal.
 * This function can be used to crunch more stats on hardware interaction.
 * For example; we could keep internal unProductive counters on Timer
 * and give the user data such as "you were least productive
 * on the first 10 minutes of the session" because there was a constant increment
 * on your productive signal count. That's just a silly example, but I think the possibility are endless,
 * in terms of data,
 * depending on the context, whether they're writing or practicing music.
 *
 */
void Timer::unProductiveSlot()
{
    unProductiveSignalCount++;
//    startBackgroundTimer();
    qDebug()<<"*****Unproductive signal*******";
    qDebug()<<"unProductive signal count:"<<this->unProductiveSignalCount;
}
void Timer::stopTimerSlot()
{
    emit congrats();
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
    if(resultProductive>MINUTE)
    {
        resultProductive = currentProductiveTime -  (productiveMinutes * MINUTE);
    }
    else if(resultProductive %  MINUTE == 0)
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
    if(currentUnproductiveTime>MINUTE)
    {
        resultProductive = currentUnproductiveTime -  (productiveMinutes * MINUTE);
    }
    else if(resultProductive %  MINUTE == 0)
    {
        resultProductive = 0;

    }

    result = QString::number( productiveMinutes)+ ":" + QString::number(resultProductive);
    qDebug()<<"result unproductive time:"<<result;
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
    if(resultProductive>MINUTE)
    {
        resultProductive = getTotalTimeElapsed() -  (productiveMinutes * MINUTE);
    }
    else if(resultProductive %  MINUTE == 0)
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
