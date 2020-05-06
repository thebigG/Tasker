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
#include <NewSessionQWidget.h>

#include "User.h"
#include <QMenu>
#include <QMenuBar>
#include <QTreeWidget>
#include <QWidget>
#include <livesession.h>
#include <map>
#include <memory>
namespace Ui {
class CommStatsQWidget;
}

/**
 * @brief The CommStatsQWidget class is the main hub where the data for
 * Commitments is displayed. Whether that be charts, averages, current
 * commitments and their sessions, it is all displayed by CommStatsQWidget.
 * This class just displays data, it doesn't really "manipulate" it
 * except for the cases where one might need to convert minutes to seconds,
 * seconds to hours, etc. All data "manipulation" is done for the sake of UI
 * design, not data management. All data management should be left to Classes
 * such as Commitment, Session, UdataUtils, etc. This class is a hybrid of a
 * Controller and Viewer. It is a viewer in the sense that it dispplays all data
 * about commitments and a controller in the sense that it controls much of data
 * navigation and parsing for human readibility. This data navigation includes
 * things like navigating through different snapshots of time windows, secleting
 * different commitments and sessions that belong to those commitments.
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
  NewSessionQWidget &getNewSessionQWidget();
  CreateCommitmentQWidget &getCreateCommitment();
  void addCommitmentItem(udata::Commitment &newCommitment);
  ~CommStatsQWidget();
  void show();
  void func();
  void update();
  void updateCommitmentInfoStatsQWidget();
  void updateCurrentCommitment();
  void updateBeginDateQLabel();
  void updateEndDateQLabel();
  QPalette getSnapshotPalette();

public slots:
  void saveCurrentSession();
  void newCommitmentSlot(bool);
  void editCommitmentSlot(bool);
  void deleteCommitmentSlot(bool);
  void newSessionSlot(bool);
  void currentCommitmentChangedSlot(QTreeWidgetItem *, QTreeWidgetItem *);
  void itemDoubleClickedSlot(QTreeWidgetItem *item, int column);
  void newLiveSessionSlot();
  void on_statsQFrame_destroyed();
private slots:
  void previousSnapshot();
  void nextSnapshot();
  void updateLiveSessionStateSlot();

private:
  Ui::CommStatsQWidget *ui;
  bool isDelete = false;
  /**
   * @brief isSelectable if true, this means that the commitments are
   * selectable; the user may select different commitments in the UI and look
   * at data such as snapshot, commitment metadata, etc.
   * If false, this means the commitments are NOT selectable and the user may
   * not look at any data related to any commitments, except the one that is
   * currently selected; the one that was selected previously. This is
   * particularly useful for when the user is in the middle of a live session
   * and we want to disable selection.
   */
  bool isSelectable = true;
  /**
   * @brief currentLiveSessionCommitment Used for re-focusing/re-selecting
   * the current commitment a LiveSession belongs to when resuming a
   * LiveSession.
   */
  int currentLiveSessionCommitment;
  void updateCurrentLiveSessionCommitment();
  void setSelectable(bool);
  QString commitmentMetaDataText{};
  QString beginDateText{"Commitment began on "};
  QString endDateText{"Ends on "};
  LiveSession currentLiveSessionWidget{};
  QPalette p;
  //    TempChartQWidget mw{};
  int selectedCommitmentIndex = 0;
  int currentTimeWindow = 0;
  std::map<QString, udata::Commitment &> commitmentMap;
  //    QVBoxLayout layout{};
  CreateCommitmentQWidget createCommimentWindow;
  NewSessionQWidget newSessionQWidget;
  udata::CommitmentSnaphot snapshot;
  void updateSnapshot();
  Perf::PerfTimer newPerfTimer{};
};

#endif // WIDGET_COMMSTATS_H
