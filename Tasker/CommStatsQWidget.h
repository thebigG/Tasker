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

#include <CommitmentSnapshot.h>
#include <CreateCommitmentQWidget.h>
#include <TimerWindowQWidget.h>

#include <QMenu>
#include <QMenuBar>
#include <QTreeWidget>
#include <QWidget>
#include <memory>

#include "User.h"
namespace Ui {
class CommStatsQWidget;
}

/**
 * @brief The CommStatsQWidget class is the main hub where the data for
 * Commitments is displayed. Whether that be charts, averages, current
 * commitments and their sessions, it is all displayed by CommStatsQWidget.
 * This clas just displays data, it doesn't really "manipulate" it
 * except for the cases where one might need to convert minutes to seconds,
 * seconds to hours, etc. All data "manipulation" is done for the sake of UI
 * design, not data management. All data management should be left to Classes
 * such as Commitment, Session, Task, etc.
 *
 * @note Beware of manipulating palettes on Qt Designer.
 * It can cause backwards comptability problems(specifically might break the
 * build for Ubuntu 14.04) when changing the palette manually on Qt Designer. It
 * lookes like it is ok to manipulate palettes via code by calling methods like
 * QWidget.setPalette(), but not through the Qt Designer editor.
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

public slots:
  void newCommitmentSlot(bool);
  void deleteCommitmentSlot(bool);
  void newSessionSlot(bool);
  void currentCommitmentChangedSlot(QTreeWidgetItem *, QTreeWidgetItem *);
  void newLiveSessionSlot();
  void on_statsQFrame_destroyed();
  void on_commitmentsQTreeWidget_itemDoubleClicked(QTreeWidgetItem *item,
                                                   int column);
private slots:
  void previousSnapshot();
  void nextSnapshot();

private:
  Ui::CommStatsQWidget *ui;
  bool isDelete = false;
  QPalette p;
  //    TempChartQWidget mw{};
  int selectedCommitmentIndex = 0;
  int currentTimeWindow = 0;

  //    QVBoxLayout layout{};
  CreateCommitmentQWidget createCommimentWindow;
  TimerWindowQWidget timerWindow;
  udata::CommitmentSnaphot snapshot;
  Perf::PerfTimer newPerfTimer{};
};

#endif // WIDGET_COMMSTATS_H
