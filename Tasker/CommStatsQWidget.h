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
/**
 *@brief The Ui namespace is a namespace generated by Qt where it places
 *anything UI related.
 */
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
  void updateCurrentCommitment();
  /**
   * @brief currentLiveSessionCommitment Used for re-focusing/re-selecting
   * the current commitment a LiveSession belongs to when resuming a
   * LiveSession.
   */
  int currentLiveSessionCommitment;
  /**
   * @brief selectedCommitmentIndex currently selected(highlited) commitment in
   * commitmentsQTreeWidget.
   * @note I think for the future keeping a reference to current commitment
   * might be a lot better, instead of an index that has to be updated in
   * hacky/ugly ways.
   */
  int selectedCommitmentIndex = 0;
  LiveSession const &getcurrentLiveSessionWidget() const;

public slots:
  void saveCurrentSession();
  void newCommitmentSlot(bool);
  void editCommitmentSlot(bool);
  void deleteCommitmentSlot(bool);
  void newSessionSlot();
  void currentCommitmentChangedSlot(QTreeWidgetItem *, QTreeWidgetItem *);
  void itemDoubleClickedSlot(QTreeWidgetItem *item, int column);
private slots:
  void previousSnapshot();
  void nextSnapshot();
  void updateLiveSessionStateSlot();

private:
  Ui::CommStatsQWidget *ui;
  /**
   * @brief isDelete if true, it means that we have just deleted a commitment
   * from the Tree View of commitments. This is particularly useful for
   * preventing issues(such as off-by-one errors) when deleting a commitment and
   * the currentItemChanged gets fired.
   */
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
  void initCommitmentsQTreeWidget();
  void updateCurrentLiveSessionCommitment();
  void setSelectable(bool);
  QString commitmentMetaDataText{};
  QString beginDateText{"Commitment began on "};
  QString endDateText{"Ends on "};
  LiveSession currentLiveSessionWidget{};
  QPalette p;
  int currentTimeWindow = 0;
  std::map<QString, udata::Commitment &> commitmentMap;
  CreateCommitmentQWidget createCommimentWindow;
  NewSessionQWidget newSessionQWidget;
  CommitmentSnaphot snapshot;
  void updateSnapshot();
  void updateCommitmentInfoStatsQWidget();
  void updateBeginDateQLabel();
  void updateEndDateQLabel();
  Perf::PerfTimer newPerfTimer{};
};

#endif // WIDGET_COMMSTATS_H
