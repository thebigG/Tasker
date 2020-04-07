#ifndef TIMER_H
#define TIMER_H

#include "Session.h"
#include <QObject>
#include <QThread>
#include <QTime>
#define TIMER_TICK 1000 // in milliseconds
#define MINUTE 60       // in seconds
#include <TaskerPerf/perftimer.h>
#include <XHook.h>
#include <memory>
namespace Engine {
class Timer;
}

/**
 * @brief The Engine::Timer class
 * @note I had to remove the start() method from Timer.
 * It was conflicting with QThread's start() method.
 */
class Engine::Timer : public QThread {
  Q_OBJECT
private:
  int currentProductiveTime = 0;
  int currentUnproductiveTime = 0;
  int totalTimeElapsed = 0;
  long long int productiveTimeGoal;
  udata::Session currentSession;
  static std::unique_ptr<Timer> thisInstance;
  Perf::PerfTimer newPerfTimer{};
  int productiveSignalCount = 0;
  int unProductiveSignalCount = 0;
  long startTimeStamp;
  int niceness;
  long long tickCount = 0; // Every "tick" is usually a second, or whatever the
                           // value of TIMER_TICK is in milliseconds
  long long producitveTickCount = 0;
  long long unProducitveTickCount = 0;
  int lastProductiveTick =
      0; // The last point in time(on which tick) where the Timer was productive
  int lastUnproductiveTick = 0;
  int productiveTimeSurplus = 1; // For how many EXTRA ticks does productiveTime
                                 // get incremented. Depends on niceness
  int unproductiveTimeSurplus = 1;
  std::unique_ptr<Hook> listener;
  Hook::HookType listenerType;
  QThread listenerThread;
  QThread thisThread;
  std::unique_ptr<QTimer> timer;
  void updateProductiveStatus();
  QString productiveStatus;
  void updateUnproductiveStatus();
  QString UnproductiveStatus;
  void updateTimeElapsedStatus();
  QString TimeElapsedStatus;
  virtual void run();

public:
  Timer(int newNiceness = 5);
  static Timer *getInstance();
  void initTimer(Hook::HookType, udata::Session);
  void stop();
  void pause();
  void setCurrentSession(udata::Session);
  void setListener(Hook::HookType);
  void startConnect();
  int getProductiveTime();
  int getUnproductiveTime();
  void startTimer();
  int getTotalTimeElapsed();
  QTime getClock();
  QString &getProductiveStatus();
  QString &getUnproductiveStatus();
  QString &getTimeElapsedStatus();

public slots:
  void stopTimerSlot();
  void tickUpdate();
  void productiveSlot();
  void unProductiveSlot();
signals:
  void startHook();
  void stopTimer();
  void tick();
  void congrats();
};

#endif // TIMER_H
