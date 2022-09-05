#include "Timer.h"

#include <MainUi.h>
#include <StatsUtility.h>
#include <TaskerPerf/PerfTimer.h>

#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include <QTime>
#include <iostream>

#include "AudioHook.h"
#include "XHook.h"
using namespace Engine;
using namespace util;
using namespace udata;
std::unique_ptr<Timer> Timer::thisInstance = std::make_unique<Timer>();
/**
 * @brief Timer::Timer initializes this Timer instance. It also initializes the
 * QTimer's timeout and Timer's stopTimer signals.
 */
Timer::Timer() {
    currentProductiveTime = 0;
    currentUnproductiveTime = 0;
    timer = std::make_unique<QTimer>(this);
    connect(timer.get(), &QTimer::timeout, this, &Timer::tickUpdate);
    connect(this, &Timer::stopTimer, this, &Timer::stopTimerSlot);
}

/**
 * @brief Timer::run
 * This function is called when the thread starts.
 *Any and all QObjects(such as Hook) MUST be instantiated inside this
 *method. Otherwise, QT's thread management will NOT consider that QObject as
 *part of the Timer thread. The code in &Hook::start, which is the ACTUAL
 *code that hooks to hardware, does not run until the startHook() signal
 *is sent.
 */
void Timer::run() {
    startTimer();
    int val = exec();
    if (val == 0) {
    }
}
/**
 * @brief Timer::startTimer initializes the hook and its thread.
 */
void Timer::startTimer() {
    // TODO:Iterate through both; hookMap and hookThreads. Maybe have both in the same map(?)
    for (auto &config : hookConfigMap) {
        // Not neede since all hooks implemented at the moment intantiate their own threads
        //        connect(&config.second.hookThread, &QThread::started,
        //                config.second.hook.get(), &Hook::start);
        ////        config.second.hook->moveToThread(&config.second.hookThread);
        ////        config.second.hookThread.start();
        config.second.hook->start();
    }
}
/**
 * @brief Timer::tickUpdate Updates Timer's state. This state includes data such
 * as current productive/unproductive ticks. It is also responsible for loading
 * that state into the current session. This is a time-sensitive function.
 * Whatever it executes, it MUST return within 250 milliseconds, which is human
 * perception threshold. Current latency(average)= 0.025 nanoseconds
 */
void Timer::tickUpdate() {
    newPerfTimer.restart();
    /**
     * @brief productiveTickDelta
     * This is the real-time amoumt of seconds that the user has gone
     * unproductive. The maximum grace period is defined by gracePeriod.
     */
    int productiveTickDelta = tickCount - lastProductiveTick;

    Hook::HookState hookState{ Hook::HookState::unproductive };

    for (auto &hook : hookConfigMap) {
        if (hook.second.hook->getState() == Hook::HookState::productive) {
            hookState = Hook::HookState::productive;
            hook.second.hook->setState(Hook::HookState::unproductive);
        }
    }

    if (hookState == Hook::HookState::productive) {
        currentProductiveTime += 1;
        producitveTickCount += 1;
        lastProductiveTick = tickCount;
        timerHookState = Hook::HookState::productive;
        // Not sure if this is the best way of handling this.
        //		hookConfigMap[Hook::HookType::AUDIO].hook->setState(Hook::HookState::unproductive);
        //		hookConfigMap[Hook::HookType::]->setState(Hook::HookState::unproductive);
    } else if (productiveTickDelta < gracePeriod) {
        currentProductiveTime += 1;
        producitveTickCount += 1;
        timerHookState = Hook::HookState::productive;
    } else {
        currentUnproductiveTime += unproductiveTimeSurplus;
        timerHookState = Hook::HookState::unproductive;
        unProducitveTickCount += 1;
        lastUnproductiveTick = tickCount;
    }
    totalTimeElapsed = currentProductiveTime + currentUnproductiveTime;
    currentSession.setProductiveTime(currentProductiveTime);
    currentSession.setUnproductiveTime(currentUnproductiveTime);
    if (currentProductiveTime == productiveTimeGoal) {
        timer->stop();
        newPerfTimer.stop();
        tickCount++;
        emit stopTimer();
        this->quit();
        return;
    }
    tickCount++;
    newPerfTimer.stop();
    emit tick();
}

int Timer::getTotalTimeElapsed() {
    return totalTimeElapsed;
}
Timer *Timer::getInstance() {
    return thisInstance.get();
}
void Timer::setCurrentSession(Session newSession) {
    currentSession = newSession;
    productiveTimeGoal = currentSession.getGoal();
}
void Timer::setHooks(std::vector<Hook::HookType> newListenerType) {
    hookTypes = newListenerType;
}
/**
 * @brief Timer::initTimer starts the Timer's internal QTimer object
 * @param newHook The type of hardware hook that will be part of this session.
 * @param newSession a new session that will contain the data of Timer once the
 * Timer's goal is reached.
 */
Hook::HookError Timer::initTimer(EngineConfig &newConfig, udata::Session newSession) {
    // TODO:Revisit this logic. It is horrendous how I'm handling configs here...
    Hook::HookError error = configTimer(newConfig, newSession);
    if (error.getStatus() == Hook::HookError::HookErrorStatus::FAIL) {
        return error;
    }
    timer->start(TIMER_TICK);
    this->start();
    emit timerStarted();

    return error;
}
Hook::HookError Timer::configTimer(EngineConfig &newConfig, udata::Session newSession) {
    config.activeHooks = newConfig.activeHooks;
    config.audioDevice = newConfig.audioDevice;
    for (auto hook : config.activeHooks) {
        switch (hook) {
        case Engine::Hook::HookType::AUDIO: {
            // TODO:Revisit this logic. It is horrendous how I'm handling configs here...
            hookConfigMap[hook].audioDevice = config.audioDevice;
            hookConfigMap[hook].hook =
                std::make_unique<AudioHook>(hookConfigMap[hook].audioDevice);
            Hook::HookError error = hookConfigMap[hook].hook->configure();
            if (error.getStatus() == Hook::HookError::HookErrorStatus::FAIL)
                return error;

            connect(hookConfigMap[hook].hook.get(), &Hook::hookError, this,
                    &Timer::hookErrorSlot);
            break;
        }
        case Engine::Hook::HookType::X_KEYBOARD: {
            hookConfigMap[hook].hook = std::make_unique<XHook>(XHookMode::KEYBOARD);
            break;
        }
        case Engine::Hook::HookType::X_MOUSE: {
            hookConfigMap[hook].hook = std::make_unique<XHook>(XHookMode::MOUSE);
            break;
        }
        case Engine::Hook::HookType::X_MOUSE_KEYBOARD: {
            // Any config needed for the XHook goes here
            hookConfigMap[hook].hook =
                std::make_unique<XHook>(XHookMode::MOUSE_AND_KEYBOARD);
            break;
        }

        default: {
            qDebug() << "Hook not supported.";
            break;
        }
        }
    }
    setCurrentSession(newSession);
    currentSession.setDate(QDate::currentDate());
    setHooks(config.activeHooks);

    return Hook::HookError{ "Succeess", Hook::HookError::HookErrorStatus::SUCCESS };
}
/**
 * @brief Timer::productiveSlot
 *
 * Called every time the listener emits the prductive signal.
 * This function can be used to crunch more stats on hardware interaction.
 * For example; we could keep internal productive counters on timer
 * and give the user data such as "you were most productive
 * on the first 10 minutes of the session" because there was a constant
 * increment on your productive signal count. I think the possibilities are
 * endless, in terms of data, depending on the context, whether they're writing
 * or practicing music.
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
 * on the first 10 minutes of the session" because there was a constant
 *decrement on your productive signal count. That's just a silly example, but I
 *think the possibilities are endless, in terms of data, depending on the
 *context, whether they're writing or practicing music.
 *
 */
void Timer::unProductiveSlot() {
    unProductiveSignalCount++;
}
/**
 * @brief Timer::stopTimerSlot
 * This stops the timer.
 * Note that it resets Timer's state by calling the reset function.
 */
void Timer::stopTimerSlot() {
    emit congrats();
    reset();
    timer->stop();
}
/**
 * @brief Timer::reset resets all state of the Timer to zero.
 * This function also kills the hook thread.
 *
 */
void Timer::reset() {
    currentProductiveTime = 0;
    currentUnproductiveTime = 0;
    totalTimeElapsed = 0;
    tickCount = 0;
    productiveSignalCount = 0;
    unProductiveSignalCount = 0;
    producitveTickCount = 0;
    unProducitveTickCount = 0;
    lastProductiveTick = 0;
    lastUnproductiveTick = 0;
    productiveTimeSurplus = 1;
    unproductiveTimeSurplus = 1;
    for (auto &config : hookConfigMap) {
        config.second.hookThread.quit();
    }
}
QTimer *Timer::getClock() {
    return timer.get();
}
udata::Session &Timer::getCurrentSession() {
    return currentSession;
}
int Timer::getProductiveTime() {
    return currentProductiveTime;
}
int Timer::getUnproductiveTime() {
    return currentUnproductiveTime;
}
void Timer::pause() {
    timer->stop();
}
void Timer::resume() {
    timer->start(TIMER_TICK);
    this->start();
}

std::map<Hook::HookType, EngineConfig> &Timer::getHookMap() {
    return hookConfigMap;
}

/**
 * This could be useful for upstreaming a HookError that happens during
 * the start() function of any of the hooks.
 * I'm still thinking about this since the code could get messy...
 * ONe could make the argument that the configure() function of the hook API
 * is the only one that should return any kind of HookError...
 */
void Timer::hookErrorSlot(Hook::HookError e) {
    // If I decide to do this, then congrats signal would have pass along the
    // HookError Message/signal. emit stopTimer();
}
