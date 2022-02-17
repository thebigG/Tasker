#include "Timer.h"

#include <StatsUtility.h>
#include <TaskerPerf/perftimer.h>
#include <mainui.h>

#include <QDebug>
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
  if (hookType == Hook::HookType::X_MOUSE_KEYBOARD) {
    hook = std::make_unique<XHook>();

  } else if (hookType == Hook::HookType::X_MOUSE) {
    std::cout << "mouse type..";
    hook = std::make_unique<XHook>(XHookMode::MOUSE);
  } else if (hookType == Hook::HookType::X_KEYBOARD) {
    hook = std::make_unique<XHook>(XHookMode::KEYBOARD);
  } else if (hookType == Hook::HookType::AUDIO) {
    hook = std::make_unique<AudioHook>();
  }
  connect(&hookThread, &QThread::started, hook.get(), &Hook::start);
  hook->moveToThread(&hookThread);
  hookThread.start();
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
  if (hook->getState() == Hook::HookState::productive) {
    currentProductiveTime += 1;
    producitveTickCount += 1;
    lastProductiveTick = tickCount;
    timerHookState = Hook::HookState::productive;
    hook->setState(Hook::HookState::unproductive);
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
  currentSession.setGoal(productiveTimeGoal);
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

int Timer::getTotalTimeElapsed() { return totalTimeElapsed; }
Timer *Timer::getInstance() { return thisInstance.get(); }
void Timer::setCurrentSession(Session newSession) {
  currentSession = newSession;
  productiveTimeGoal = currentSession.getGoal();
}
void Timer::setHook(Hook::HookType newListenerType) {
  hookType = newListenerType;
}
/**
 * @brief Timer::initTimer starts the Timer's internal QTimer object
 * @param newHook The type of hardware hook that will be part of this session.
 * @param newSession a new session that will contain the data of Timer once the
 * Timer's goal is reached.
 */
void Timer::initTimer(Hook::HookType newHook, udata::Session newSession) {
  thisInstance->setCurrentSession(newSession);
  currentSession.setDate(QDate::currentDate());
  thisInstance->setHook(newHook);
  timer->start(TIMER_TICK);
  this->start();
  emit timerStarted();
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
void Timer::productiveSlot() { productiveSignalCount++; }
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
void Timer::unProductiveSlot() { unProductiveSignalCount++; }
/**
 * @brief Timer::stopTimerSlot
 * This stops the timer.
 * Note that it resets Timer's state by calling the reset function.
 */
void Timer::stopTimerSlot() {
  emit congrats();
  hook->end();
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
  hookThread.quit();
}
QTimer *Timer::getClock() { return timer.get(); }
udata::Session &Timer::getCurrentSession() { return currentSession; }
int Timer::getProductiveTime() { return currentProductiveTime; }
int Timer::getUnproductiveTime() { return currentUnproductiveTime; }
void Timer::pause() { timer->stop(); }
void Timer::resume() {
  timer->start(TIMER_TICK);
  this->start();
}

std::unique_ptr<Hook> &Timer::getHook() { return hook; }
