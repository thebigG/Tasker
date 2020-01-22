#include "Timer.h"
#include "AudioListener.h"
#include "KeyboardListener.h"
#include <QDebug>
#include <QThread>
#include <QTime>
#include <StatsUtility.h>
#include <mainui.h>
#include <TaskerPerf/perftimer.h>
#include <iostream>
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
    connect(timer, &QTimer::timeout, this, &Timer::tickUpdate);
    connect(this, &Timer::stopTimer, this, &Timer::stopTimerSlot);
}
/**
 * @brief Timer::Timer
 * @param newListenerType This tells timer what type of listener to instantiate.
 * It's not the prettiest way of doing this, but at least we're not doing
 * weird/prone-to-bugs type probing at runtime, like dynamic_cast nonsense.
 *
 */
Timer::Timer(Listener::ListenerType newListenerType, Session newSession) {
    qDebug() << "Timer() constructor: " << currentThreadId();
    currentSession = newSession;
    listenerType = newListenerType;
    currentProductiveTime = 0;
    currentUnproductiveTime = 0;

    connect(timer, &QTimer::timeout, this, &Timer::tickUpdate);
    timer = new QTimer(this);
    connect(this, &Timer::stopTimer, this, &Timer::stopTimerSlot);
    qDebug() << "Timer() constructor after start(): " << currentThreadId();
}

/**
 * @brief Timer::~Timer
 */
Timer::~Timer() {
    if (timer != nullptr)
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
void Timer::run() {
    qDebug() << "run method on Timer:" << QThread::currentThreadId();

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
    /**
        This block of code  WORKS!
        DO NOT DELETE THIS BLOCK OF CODE. IT IS PERFECT!
        Specifically the statements regarding the listener and
        listenerThread. I'm talking about the next 3 lines of code.
     */
    connect(&listenerThread, &QThread::started, listener, &Listener::start);
    listener->moveToThread(&listenerThread);
    listenerThread.start();
}
/**
 * @brief Timer::tickUpdate
 * This is a time-sensitive function. Whatever it executes, it MUST return
 * within 1 second.
 * Current latency(average)= 14000 nanoseconds
 */
void Timer::tickUpdate() {
    newPerfTimer.restart();
    int tickDelta;
    if (listener->getState() == Listener::ListenerState::productive) {

        tickDelta = tickCount - producitveTickCount;
        currentProductiveTime += 1;
        producitveTickCount += 1;
        lastProductiveTick = tickCount;
    } else {
        currentUnproductiveTime += unproductiveTimeSurplus;
        unProducitveTickCount += 1;
        lastUnproductiveTick = tickCount;
    }
    totalTimeElapsed = currentProductiveTime + currentUnproductiveTime;
    if (currentProductiveTime == productiveTimeGoal) {
        timer->stop();
        emit stopTimer();
    }
    updateProductiveStatus();
    updateUnproductiveStatus();
    updateTimeElapsedStatus();
    tickCount++;
    newPerfTimer.stop();
    qDebug()<<"tick update on Timer took this long(nanoseconds):"<<newPerfTimer.duration;
    emit tick();
}


int Timer::getTotalTimeElapsed() {
    return currentUnproductiveTime + currentProductiveTime;
}
Timer *Timer::getInstance() {
    if (thisInstance == nullptr) {
        thisInstance = new Timer();
    }
    return thisInstance;
}
void Timer::setCurrentSession(Session newSession) {
    currentSession = newSession;
    productiveTimeGoal = currentSession.getGoal();
}
void Timer::setListener(Listener::ListenerType newListenerType) {
    listenerType = newListenerType;
}
void Timer::initTimer(Listener::ListenerType newListener, udata::Session newSession) {
    thisInstance->setCurrentSession(newSession);
    thisInstance->setListener(newListener);
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
 * on your productive signal count. I think the possibilities are endless, in terms of data,
 * depending on the context, whether they're writing or practicing music.
 *
 */
void Timer::productiveSlot() {
    productiveSignalCount++;
}
/**
 * @brief Timer::unProductiveSlot
 *Called every time the listener emits the unProductive signal.
 * This function can be used to crunch more stats on hardware interaction.
 * For example; we could keep internal unProductive counters on Timer
 * and give the user data such as "you were least productive
 * on the first 10 minutes of the session" because there was a constant decrement
 * on your productive signal count. That's just a silly example, but I think the possibilities are endless,
 * in terms of data,
 * depending on the context, whether they're writing or practicing music.
 *
 */
void Timer::unProductiveSlot() {
    unProductiveSignalCount++;
}
void Timer::stopTimerSlot() {
    emit congrats();
    timer->stop();
}
void Timer::updateProductiveStatus()
{
    long long int productiveMinutes = StatsUtility::toMinutes(currentProductiveTime);
    int resultProductive = currentProductiveTime;
    if (resultProductive > MINUTE) {
        resultProductive = currentProductiveTime - (productiveMinutes * MINUTE);
    } else if (resultProductive % MINUTE == 0) {
        resultProductive = 0;
    }

    productiveStatus = QString::number(productiveMinutes) + ":" + QString::number(resultProductive);
    if (productiveMinutes == ZERO) {

    } else {
    }
}
/**
 * @brief Timer::getProductiveStatus
 * @return the productime time status(the string representation)
 * of the current productive time count.
 */
QString& Timer::getProductiveStatus() {
    return productiveStatus;
}
void Timer::updateUnproductiveStatus()
{

    long long int productiveMinutes = StatsUtility::toMinutes(currentUnproductiveTime);
    int resultProductive = currentUnproductiveTime;
    if (currentUnproductiveTime > MINUTE) {
        resultProductive = currentUnproductiveTime - (productiveMinutes * MINUTE);
    } else if (resultProductive % MINUTE == 0) {
        resultProductive = 0;
    }

    UnproductiveStatus = QString::number(productiveMinutes) + ":" + QString::number(resultProductive);
}
QString& Timer::getUnproductiveStatus() {
    return UnproductiveStatus;
}


void Timer::updateTimeElapsedStatus()
{
    long long int productiveMinutes = StatsUtility::toMinutes(totalTimeElapsed);
    int resultProductive = totalTimeElapsed;
    if (resultProductive > MINUTE) {
        resultProductive = totalTimeElapsed - (productiveMinutes * MINUTE);
    } else if (resultProductive % MINUTE == 0) {
        resultProductive = 0;
    }

    TimeElapsedStatus = QString::number(productiveMinutes) + ":" + QString::number(resultProductive);
}
QString& Timer::getTimeElapsedStatus() {
    return TimeElapsedStatus;
}
