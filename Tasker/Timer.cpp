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
 * @brief Timer::Timer
 */
Timer::Timer(int newNiceness) {
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
 *code that hook to hardware, does not run until the startHook() signal
 *is sent.
 */
void Timer::run() {
  qDebug() << "run method on Timer:" << QThread::currentThreadId();

  startTimer();
  exec();
}
void Timer::startTimer() {
  qDebug() << "From work thread: " << currentThreadId();

  if (listenerType == Hook::HookType::X_MOUSE_KEYBOARD) {
    listener = std::make_unique<XHook>();
  } else if (listenerType == Hook::HookType::X_MOUSE) {
    listener = std::make_unique<XHook>(XHookMode::MOUSE);
  } else if (listenerType == Hook::HookType::X_KEYBOARD) {
    listener = std::make_unique<XHook>(XHookMode::KEYBOARD);
  } else if (listenerType == Hook::HookType::audio) {
    listener = std::make_unique<AudioHook>();
  }
  /**
      This block of code  WORKS!
      DO NOT DELETE THIS BLOCK OF CODE. IT IS PERFECT!
      Specifically the statements regarding the listener and
      listenerThread. I'm talking about the next 3 lines of code.
   */
  connect(&listenerThread, &QThread::started, listener.get(), &Hook::start);
  listener->moveToThread(&listenerThread);
  listenerThread.start();
}
/**
 * @brief Timer::tickUpdate
 * This is a time-sensitive function. Whatever it executes, it MUST return
 * within 250 milliseconds, which is human perception threshold.
 * Current latency(average)= 14000 nanoseconds
 */
void Timer::tickUpdate() {
  newPerfTimer.restart();
  /**
   * @brief productiveTickDelta
   * This is kind of like a "grace" peroid for
   * how long the user can go unproductive.
   * This is 60 seconds for now. Will adjust as I test things out.
   */
  int productiveTickDelta = tickCount - lastProductiveTick;
  if (listener->getState() == Hook::HookState::productive) {
    currentProductiveTime += 1;
    producitveTickCount += 1;
    lastProductiveTick = tickCount;
    listener->setState(Hook::HookState::unproductive);
  } else if (productiveTickDelta < 60) {
    currentProductiveTime += 1;
    producitveTickCount += 1;
  } else {
    currentUnproductiveTime += unproductiveTimeSurplus;
    unProducitveTickCount += 1;
    lastUnproductiveTick = tickCount;
  }
  totalTimeElapsed = currentProductiveTime + currentUnproductiveTime;
  if (currentProductiveTime == productiveTimeGoal) {
    timer->stop();
    currentSession.setGoal(productiveTimeGoal);
    currentSession.setProductiveTime(currentProductiveTime);
    currentSession.setUnproductiveTime(currentUnproductiveTime);
    currentSession.setDate(QDate::currentDate());
    emit stopTimer();
  }
  updateProductiveStatus();
  updateUnproductiveStatus();
  updateTimeElapsedStatus();
  tickCount++;
  newPerfTimer.stop();
  qDebug() << "tick update on Timer took this long(milliseconds):"
           << newPerfTimer.duration;
  emit tick();
}

int Timer::getTotalTimeElapsed() {
  return currentUnproductiveTime + currentProductiveTime;
}
Timer *Timer::getInstance() { return thisInstance.get(); }
void Timer::setCurrentSession(Session newSession) {
  currentSession = newSession;
  productiveTimeGoal = currentSession.getGoal();
}
void Timer::setListener(Hook::HookType newListenerType) {
  listenerType = newListenerType;
}
void Timer::initTimer(Hook::HookType newListener, udata::Session newSession) {
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
void Timer::stopTimerSlot() {
  emit congrats();
  timer->stop();
}
void Timer::updateProductiveStatus() {
  long long int productiveMinutes = toMinutes(currentProductiveTime);
  int resultProductive = currentProductiveTime;
  if (resultProductive > MINUTE) {
    resultProductive = currentProductiveTime - (productiveMinutes * MINUTE);
  } else if (resultProductive % MINUTE == 0) {
    resultProductive = 0;
  }

  productiveStatus = QString::number(productiveMinutes) + ":" +
                     QString::number(resultProductive);
  if (productiveMinutes == ZERO) {

  } else {
  }
}
/**
 * @brief Timer::getProductiveStatus
 * @return the productime time status(the string representation)
 * of the current productive time count.
 */
QString &Timer::getProductiveStatus() { return productiveStatus; }
void Timer::updateUnproductiveStatus() {
  long long int productiveMinutes = toMinutes(currentUnproductiveTime);
  int resultProductive = currentUnproductiveTime;
  if (currentUnproductiveTime > MINUTE) {
    resultProductive = currentUnproductiveTime - (productiveMinutes * MINUTE);
  } else if (resultProductive % MINUTE == 0) {
    resultProductive = 0;
  }

  UnproductiveStatus = QString::number(productiveMinutes) + ":" +
                       QString::number(resultProductive);
}
QString &Timer::getUnproductiveStatus() { return UnproductiveStatus; }

void Timer::updateTimeElapsedStatus() {
  long long int productiveMinutes = toMinutes(totalTimeElapsed);
  int resultProductive = totalTimeElapsed;
  if (resultProductive > MINUTE) {
    resultProductive = totalTimeElapsed - (productiveMinutes * MINUTE);
  } else if (resultProductive % MINUTE == 0) {
    resultProductive = 0;
  }

  TimeElapsedStatus = QString::number(productiveMinutes) + ":" +
                      QString::number(resultProductive);
}
QString &Timer::getTimeElapsedStatus() { return TimeElapsedStatus; }
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
}
udata::Session &Timer::getCurrentSession() { return currentSession; }
