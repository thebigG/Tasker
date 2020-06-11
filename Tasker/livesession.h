#ifndef LIVESESSION_H
#define LIVESESSION_H

#include <TaskerPerf/perftimer.h>

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#define LIVESESSIONFONTPATH ":/resources/unifont-13.0.02.ttf"

#define PLAYBUTTON "\u25B6"
#define PAUSEBUTTON "\u23F8"
/**
 * @brief The LiveSessionState enum repesents the current state when there is a
 * live session happening.
 * Paused: When the current session is paused; all hooks are deactivated;
 * and the Timer engine is stopped. Note that while paused the Timer Engine
 * is not collecting data about the current session.
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
  //  void stop();
  QString congratsCommitmentMessage{
      "Congrats! You've completed this commitment!"};
  QString activeText{"(active)"};
  QString inactiveText{"(inactive)"};
  void updateDetails();
  ~LiveSession();
  LiveSessionState getCurrentState() const;

private slots:
  void updateTimeUI();
  void stop();
  void playButtonSlot();
  void updateHookState();
  void start();

signals:
  void liveStateChanged();
  void sessionStarted();

private:
  Ui::LiveSession *ui;
  QString productiveTimeValueText;
  QString unproductiveTimeValueText;
  QString totalTimeValueText;
  QString contextText{""};
  QString sessionGoalText;
  QString hookStateText{};
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
