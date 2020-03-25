#ifndef WIDGET_COMMSTATS_H
#define WIDGET_COMMSTATS_H
#define COMMITMENT_MENU_STRING "Commitment"
#define NEW_COMMITMENT_STRING "New Commitment"
#define EDIT_COMMITMENT_STRING "Edit Commitment"
#define DELETE_COMMITMENT_STRING "Delete Commitment"
#define SESSION_MENU_STRING "Session"
#define NEW_SESSION_STRING "New Session"
#define EDIT_SESSION_STRING "Edit Session"
#define DELETE_SESSION_STRING "Delete Session"

#include "User.h"
#include <CommitmentSnapshot.h>
#include <CreateCommitmentQWidget.h>
#include <QMenu>
#include <QMenuBar>
#include <QTreeWidget>
#include <QWidget>
#include <TimerWindowQWidget.h>
#include <memory>
namespace Ui {
class CommStatsQWidget;
}

/**
 * @brief The CommStatsQWidget class
 */
class CommStatsQWidget : public QWidget {
  Q_OBJECT

public:
  explicit CommStatsQWidget(QWidget *parent = nullptr);
  TimerWindowQWidget &getTimerWindow();
  CreateCommitmentQWidget &getCreateCommitment();
  ~CommStatsQWidget();
  void func();
  void update();

private slots:
  void newCommitmentSlot(bool);
  void deleteCommitmentSlot(bool);
  void newSessionSlot(bool);
  void currentCommitmentChangedSlot(QTreeWidgetItem *, QTreeWidgetItem *);
  void newLiveSessionSlot();
  void on_statsQFrame_destroyed();
  void on_commitmentsQTreeWidget_itemDoubleClicked(QTreeWidgetItem *item,
                                                   int column);

private:
  Ui::CommStatsQWidget *ui;
  bool isDelete = false;
  QPalette p;
  //    TempChartQWidget mw{};
  int selectedCommitmentIndex = 0;
  //    QVBoxLayout layout{};
  CreateCommitmentQWidget createCommimentWindow;
  TimerWindowQWidget timerWindow;
  QMenuBar mainMenuBar;
  udata::CommitmentSnaphot *snapshot;
  QMenu commitmentMenu{COMMITMENT_MENU_STRING};
  QMenu sessionMenu{SESSION_MENU_STRING};
};

#endif // WIDGET_COMMSTATS_H
