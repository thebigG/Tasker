#ifndef LIVESESSION_H
#define LIVESESSION_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <TaskerPerf/perftimer.h>
#if defined(Q_OS_OSX)
#define LIVESESSIONFONTPATH "some/macOS/path"
#elif defined(Q_OS_LINUX)
#define LIVESESSIONFONTPATH "../resources/fonts/unifont-13.0.02.ttf"
#endif

#define PLAYBUTTON "\u25B6"
#define PAUSEBUTTON "\u23F8"
/**
 * @brief The LiveSessionState enum repesents the current state when there is a
 * live session happening.
 * Paused: When the current session is paused; all hooks are deactivated;
 * and the Timer engine is stopped. Note that while "Stopped" the Timer Engine
 * is not collecting about the current session.
 * Started: The timer engine and hooks are currently active. This means that the
 * Timer Engine is currently collecting data about the current live session.
 * Stopped: This state is when the LiveSession has been stopped prematurely by
 * the user. This feature is not supported yet; will support as soon as I can.
 *
 */
enum class LiveSessionState { Paused, Started, Stopped };
namespace Ui {
class LiveSession;
}

class LiveSession : public QWidget {
  Q_OBJECT

public:
  explicit LiveSession(QWidget *parent = nullptr);
  QLabel &getcongratsMessageLabel();
  QPushButton *getPlayButton();
  void pause();
  void resume();
  ~LiveSession();
  LiveSessionState getCurrentState() const;

private slots:
  void updateTimeUI();
  void congratsSlot();
  void playButtonSlot();
  void updateHookState();
  void start();

signals:
  void liveStateChanged();

private:
  Ui::LiveSession *ui;
  QString productiveTimeValueText;
  QString unproductiveTimeValueText;
  QString totalTimeValueText;
  QString contextText{""};
  QString sessionGoalText;
  QString hookStateText{};
  QString congratsMessage{"Congrats! You've completed your session!"};
  QString activeText{"(active)"};
  QString inactiveText{"(inactive)"};
  QString taskState{};
  void initTaskState();
  void initHookState();
  LiveSessionState currentState;
  Perf::PerfTimer liveSessionPerfTimer{};
  Perf::PerfTimer liveSessionPerfTimer1{};
  Perf::PerfTimer liveSessionPerfTimer2{};
  Perf::PerfTimer liveSessionPerfTimer3{};
};

#endif // LIVESESSION_H
