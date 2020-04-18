#ifndef MAINUI_H
#define MAINUI_H
#include <TaskerUIMainWindowQWidget.h>

#include <memory>

/**
 * @brief The MainUI class is the one responsible
 * for the meta UI/front-end state of Tasker as a whole.
 * One can think as this class as the one represnting the entire winodw
 * displaying Tasker and the one reponsible for shutdown and cleanup procedures
 * such as storing the commitments to disk before shutting down the App.
 * The class is also responsible for managing(as implied before) layout,
 * sizes,context menus and look-and-feel of the entire UI.
 */
class MainUI : public QMainWindow {
  Q_OBJECT
private:
  static std::unique_ptr<MainUI> mainHub;
  CommStatsQWidget commitmentHub{};
  QMenuBar mainMenuBar;
  QMenu commitmentMenu{COMMITMENT_MENU_STRING};
  QMenu sessionMenu{SESSION_MENU_STRING};

public:
  static MainUI *getInstance();
  void update();
  void updateNewSessionActionState();
  bool newSessionActionState();
  CommStatsQWidget &getCommitmentHub();
  MainUI();
public slots:
  static void saveTaskerStateSlot();
};

#endif // MAINUI_H
