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
 * @brief The Engine::Timer class is a clock that hooks to specified Hooks such
 * as XHook or AudioHook and keeps track of whether the hook's state is
 * productive or unproductive.
 */
class Engine::Timer : public QThread {
  Q_OBJECT
private:
  int currentProductiveTime = 0;   // in seconds
  int currentUnproductiveTime = 0; // in seconds
  int totalTimeElapsed = 0;
  long long int productiveTimeGoal; // in seconds
  udata::Session currentSession;
  static std::unique_ptr<Timer> thisInstance;
  Perf::PerfTimer newPerfTimer{};
  int productiveSignalCount = 0;
  int unProductiveSignalCount = 0;
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
  std::unique_ptr<Hook> hook;
  QThread hookThread;
  QThread thisThread;
  std::unique_ptr<QTimer> timer;
  int gracePeriod = 30; // How many seconds to keep the Timer in a "productive"
                        // state for before for new state of the hook(s)
  virtual void run();
signals:
  void tick();

public:
  Timer();
  static Timer *getInstance();
  void initTimer(Hook::HookType, udata::Session);
  void stop();
  void reset();
  void pause();
  void resume();
  void setCurrentSession(udata::Session);
  void setHook(Hook::HookType);
  int getProductiveTime();
  int getUnproductiveTime();
  void startTimer();
  int getTotalTimeElapsed();
  Hook::HookState timerHookState;
  Hook::HookType hookType;
  QTimer *getClock();
  udata::Session &getCurrentSession();

public slots:
  void stopTimerSlot();
  void tickUpdate();
  void productiveSlot();
  void unProductiveSlot();
signals:
  void timerStarted();
  void stopTimer();
  void congrats();
};

#endif // TIMER_H
