#ifndef MAINUI_H
#define MAINUI_H

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <memory>

#include "CommStatsQWidget.h"
#include "Timer.h"
#define ICONPATH ":/resources/clock-256.png"

/**
Status strings for what is happening with the current live session.
*/
#define LIVESESSION_PENDING "Pending"
#define LIVESSION_IN_PROGRESS "In Progress"
#define LIVESSION_COMPLETE "Completed"
#define LIVESESSION_PAUSED "Paused"

/**
 * @brief The MainUI class is the one responsible
 * for the meta UI/front-end state of Tasker as a whole.
 * One can think of this class as the one represnting the entire winodw
 * displaying Tasker and the one reponsible for shutdown and cleanup procedures
 * such as storing the commitments to disk before shutting down the App.
 * The class is also responsible for managing(as implied before) layout,
 * sizes, context menus and look-and-feel of the entire UI.
 * Another responsability of this class is that it works as the keykeeper of
 * all of the actions that a user may want to do on Tasker. For instance
 * actions( or QActions in QT speak) such as creating new sessions are
 * allowed/disallowed by this class as it is looking at the meta state of the
 * Application as a whole. Any entity that wants to know whether the user can
 * execute an action or not at the moment, such as starting a new Session for a
 * Commitment, should ask this class first.
 */
class MainUI : public QMainWindow {
    Q_OBJECT
private:
  static std::unique_ptr<MainUI> mainHub;
  CommStatsQWidget commitmentHub{};
  QMenuBar mainMenuBar;
  QMenu commitmentMenu{ COMMITMENT_MENU_STRING };
  QMenu sessionMenu{ SESSION_MENU_STRING };
  QMenu trayIconMenu{};
  QAction *getNewSessionAction();
  QAction *getEditCommitmentAction();
  QAction *getDeleteCommitmentAction();
  QSystemTrayIcon trayIcon;
  QAction *liveSessionStatusAction{};
  QString liveSessionStatusText{ "LiveSession:" };
  void updateLiveSessionStatusText();
  void updateLiveSessionStatusAction();
  void closeEvent(QCloseEvent *) override;

  public:
  static MainUI *getInstance();
  void update();
  void updateNewSessionActionState();
  void updateEditCommitmentActionState();
  void updateDeleteCommitmentActionState();
  void updateActionStates();
  bool newSessionActionState();
  bool editCommitmentActionState();
  bool deleteCommitmentActionState();
  CommStatsQWidget &getCommitmentHub();
  MainUI();
public slots:
  static void saveTaskerStateSlot();
  void trayIconShoWindowSlot(QSystemTrayIcon::ActivationReason);
  void toggleShowWindow();
  void quitSlot();
};

#endif // MAINUI_H
