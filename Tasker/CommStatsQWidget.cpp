#include "CommStatsQWidget.h"
#include "ui_CommStatsQWidget.h"
#include <CreateCommitmentQWidget.h>
#include <QAbstractItemView>
#include <UdataUtils.h>
#include <mainui.h>
#define TRAVIS_CI 1
#include "Timer.h"
#include <QDebug>
#include <iostream>

using Engine::Hook;
using udata::Commitment;
using udata::Session;
using udata::User;

/**
 * @brief CommStatsQWidget::CommStatsQWidget
 * @param parent
 */
CommStatsQWidget::CommStatsQWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::CommStatsQWidget) {
  ui->setupUi(this);
  /*
   * Set up all necessary signals and slots for this class.
   */
  connect(ui->commitmentsQTreeWidget, &QTreeWidget::currentItemChanged, this,
          &CommStatsQWidget::currentCommitmentChangedSlot);
  connect(ui->prevSnaphot, &QPushButton::clicked, this,
          &CommStatsQWidget::previousSnapshot);
  connect(ui->nextSnapshot, &QPushButton::clicked, this,
          &CommStatsQWidget::nextSnapshot);
  this->ui->commitmentsQTreeWidget->setColumnWidth(
      0, this->ui->commitmentsQTreeWidget->size().width() - 100);
  connect(Engine::Timer::getInstance(), &Engine::Timer::stopTimer, this,
          &CommStatsQWidget::saveCurrentSession);
  connect(ui->commitmentsQTreeWidget, &QTreeWidget::itemDoubleClicked, this,
          &CommStatsQWidget::newSessionSlot);
  connect(&currentLiveSessionWidget, &LiveSession::liveStateChanged, this,
          &CommStatsQWidget::updateLiveSessionStateSlot);
  connect(&currentLiveSessionWidget, &LiveSession::sessionStarted, this, [&]() {
    setSelectable(false);
    updateCurrentLiveSessionCommitment();
    MainUI::getInstance()->updateActionStates();
  });
  /*
   * Allocate space in this string to avoid realocation on when updating
   */
  commitmentMetaDataText.reserve(100);
  commitmentMetaDataText.resize(100);
  beginDateText.resize(100);
  setSelectable(true);
  /*
   * Arrenge navigating buttons for our commitment snaphots.
   */
  static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
      ->addWidget(this->ui->prevSnaphot, 0, 0);
  static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
      ->addWidget(&snapshot, 0, 1);
  static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
      ->addWidget(&currentLiveSessionWidget, 2, 1);

  static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
      ->addWidget(this->ui->CommitmentInfoStatsQWidget, 1, 1);

  /*
   * Assign the same color to our CommitmentInfoStats widget as the
   * CommitmentSnaphot chart to make things look uniform.
   */
  QPalette p = this->ui->CommitmentInfoStatsQWidget->palette();

  p.setColor(this->ui->CommitmentInfoStatsQWidget->backgroundRole(),
             snapshot.palette().color(QPalette::ColorRole::Background));
  this->ui->CommitmentInfoStatsQWidget->setAutoFillBackground(true);
  this->ui->CommitmentInfoStatsQWidget->setPalette(p);
  currentLiveSessionWidget.setAutoFillBackground(true);
  currentLiveSessionWidget.setPalette(p);
}

void CommStatsQWidget::newCommitmentSlot(bool checked) {
  this->createCommimentWindow.show();
}
void CommStatsQWidget::editCommitmentSlot(bool) {
  createCommimentWindow.editCommitment(selectedCommitmentIndex);
}
/**
 * @brief CommStatsQWidget::addCommitmentItem Adds a new commitment to the
 * backing store and to the QTreetView.
 * @param newCommitment
 */
void CommStatsQWidget::addCommitmentItem(udata::Commitment &newCommitment) {
  udata::User::getInstance()->addCommitment(newCommitment);
  ui->commitmentsQTreeWidget->addTopLevelItem(
      new QTreeWidgetItem(QStringList() << newCommitment.getName() << ""));
}
/**
 * @brief CommStatsQWidget::~CommStatsQWidget
 */
CommStatsQWidget::~CommStatsQWidget() { delete ui; }

void CommStatsQWidget::deleteCommitmentSlot(bool checked) {
  /*
   * If there are no commitments to delete, then there is nothing to delete.
   */
  if (User::getInstance()->getCommitments().isEmpty()) {
    return;
  }
  int tempIndex = selectedCommitmentIndex;
  /*
   * If we are deleting the last commitment, make sure we don't have an
   * off-by-one error :)
   */
  if (selectedCommitmentIndex ==
      (User::getInstance()->getCommitments().size() - 1)) {
    selectedCommitmentIndex--;
  }
  User::getInstance()->getCommitments().removeAt(tempIndex);
  isDelete = true; // This is for the currentItemChanged signal, which gets
                   // emitted by delete keyword
  // I don't want to use delete, but it seems to be the only way to delete these
  // TreeWidget items
  delete ui->commitmentsQTreeWidget->takeTopLevelItem(tempIndex);
}
void CommStatsQWidget::newSessionSlot(bool checked) {
  if (!User::getInstance()
           ->getCurrentCommitment()
           .getCommitmentWindows()
           .last()
           .sessions.isEmpty()) {
    if (QDate::currentDate() == User::getInstance()
                                    ->getCurrentCommitment()
                                    .getCommitmentWindows()
                                    .last()
                                    .sessions.last()
                                    .getDate()) {
      //      /**
      //       * Maybe show the user in the UI that they have added this session
      //       already to this commitment today. It might be worth it to
      //       consider a case where maybe a session was terminated prematurely
      //       for whatever reason and the user might want to resume that
      //       session even after closing Tasker, this is assuming that they
      //       open Tasker the very same day again. Give this a lot of thought
      //       as this could add clutter to the UI, which I don't want.
      //      */
      return;
    }
  }
  if (MainUI::getInstance()->newSessionActionState()) {
    this->getNewSessionQWidget().show();
  }
}
/**
 * @brief CommStatsQWidget::on_statsQFrame_destroyed
 */
void CommStatsQWidget::on_statsQFrame_destroyed() {
  qDebug() << "delete udata::User::getInstance() on on_statsQFrame_destroyed#1";
  //    delete udata::User::getInstance();
  qDebug() << "delete udata::User::getInstance() on on_statsQFrame_destroyed2";
}

void CommStatsQWidget::update() {
  QVector<Commitment> &commitments = User::getInstance()->getCommitments();
  ui->commitmentsQTreeWidget->clear();
  selectedCommitmentIndex = 0;
  auto commitmentIt = commitments.begin();
  qDebug() << "calling update on commstats++++++++++++_";
  while (commitmentIt != commitments.end()) {
    Commitment c = (*commitmentIt);

    auto s_vec = c.getAllSessions();
    auto s_it = s_vec.begin();

    QTreeWidget *w = ui->commitmentsQTreeWidget;
    qDebug() << "size of tree widget$$$:" << w->size();
    // Removing this new() call will require more thinking
    // and considering a redesign of commStatsQwidget as a whole
    QTreeWidgetItem *item = new QTreeWidgetItem(
        QStringList() << c.getName() << ": " << c.getDateStart().toString());

    while (s_it != s_vec.end()) {
      Session s = (*s_it);

      ++s_it;
    }

    ++commitmentIt;

    w->addTopLevelItem(item);
  }
}
void CommStatsQWidget::itemDoubleClickedSlot(QTreeWidgetItem *item,
                                             int column) {
  ui->commitmentsQTreeWidget->indexOfTopLevelItem(item);
  newSessionSlot(false);
}

void CommStatsQWidget::currentCommitmentChangedSlot(QTreeWidgetItem *current,
                                                    QTreeWidgetItem *previous) {
  qDebug() << "currentCommitmentChangedSlot#1";
  //  ui->commitmentsQTreeWidget->selectedItems()
  //  return;
  if (!isSelectable) {
    //    previous->setSelected(true);
    //    current->setSelected(false);
    //    selectedCommitmentIndex = 0;
    qDebug() << "";
    //      !isSelectable
    return;
  }

  if (isDelete) {
    isDelete = false;
    return;
  }
  if (current == previous) {
    qDebug() << "SAME OBJECT";
  }
  int currentIndex = 0;
  currentIndex = ui->commitmentsQTreeWidget->indexOfTopLevelItem(current);
  qDebug() << "currentIndex#1" << currentIndex;
  if (currentIndex == -1) {
    qDebug() << "NEGATIVE on TreeWidgetItem";
    if (current == nullptr) {
      return;
    }

    currentIndex =
        ui->commitmentsQTreeWidget->indexOfTopLevelItem(current->parent());
    qDebug() << "currentIndex#2" << currentIndex;
    qDebug() << "NEGATIVE#2";
    //        return;
  }

  selectedCommitmentIndex = currentIndex;
  qDebug() << "changed commitment index:" << currentIndex;
  qDebug() << "changed commitment name:"
           << User::getInstance()->getCommitments().at(currentIndex).getName();
  //
  User::getInstance()->updateCurrentCommitment(selectedCommitmentIndex);
  qDebug() << "currentCommitmentChangedSlot#10";

  // update meta data on meta data widget
  updateCommitmentInfoStatsQWidget();
  qDebug() << "currentCommitmentChangedSlot#11";
  updateBeginDateQLabel();
  updateEndDateQLabel();
  qDebug() << "currentCommitmentChangedSlot#12";
  QVector<Commitment> &commitments = User::getInstance()->getCommitments();
  qDebug() << "currentCommitmentChangedSlot#13";
  //  qDebug()
  MainUI::getInstance()->updateActionStates();
  qDebug() << "currentCommitmentChangedSlot#14";
  if (!User::getInstance()->getCommitments().isEmpty() &&
      !commitments[0].getCommitmentWindows().isEmpty()) {
    qDebug() << "Running???";
    newPerfTimer.restart();
    /*reset the value of currentTimeWindow to the current time window
     * Since the currently selected commitment has changed
     *This usually means whatever TimeWindow(such as week) includes the current
     *date
     */
    currentTimeWindow = User::getInstance()
                            ->getCurrentCommitment()
                            .getCommitmentWindows()
                            .length() -
                        1;
    updateSnapshot();
    newPerfTimer.stop();
    qDebug() << "duration of chart update=" << newPerfTimer.duration
             << "milli/nanoseconds";
  }
}
void CommStatsQWidget::newLiveSessionSlot() {
  //    this->hide();
  //    this->getTimerWindow().show();
}
NewSessionQWidget &CommStatsQWidget::getNewSessionQWidget() {
  return newSessionQWidget;
}
CreateCommitmentQWidget &CommStatsQWidget::getCreateCommitment() {
  return createCommimentWindow;
}
void CommStatsQWidget::previousSnapshot() {
  if (currentTimeWindow - 1 >= 0) {
    currentTimeWindow = currentTimeWindow - 1;
  } else {
    return;
  }
  updateSnapshot();
}

void CommStatsQWidget::nextSnapshot() {
  if (currentTimeWindow + 1 < User::getInstance()
                                  ->getCurrentCommitment()
                                  .getCommitmentWindows()
                                  .length()) {
    currentTimeWindow = currentTimeWindow + 1;
  } else {
    return;
  }
  updateSnapshot();
}
void CommStatsQWidget::updateSnapshot() {
  qDebug() << "updateSnapshot#1";
  snapshot.update(
      User::getInstance()
          ->getCurrentCommitment()
          .getCommitmentWindows()[currentTimeWindow],
      User::getInstance()->getCurrentCommitment().getType(),
      User::getInstance()->getCurrentCommitment().getFrequency().goal);
}

void CommStatsQWidget::show() { QWidget::show(); }
/**
 * @brief CommStatsQWidget::saveCurrentSession
 * This function assumes that the currently selected session
 * is the same one that this new live session belongs to. As such it stores this
 * new live session to the commitment that is currently selected.
 * @note Any state regarding commitment snaphots and MainUI QActions are updated
 * on this function since the data changes those changes should reflected in the
 * UI.
 */
void CommStatsQWidget::saveCurrentSession() {
  User::getInstance()
      ->getCurrentCommitment()
      .getCurrentTimeWindow()
      .sessions.append(Engine::Timer::getInstance()->getCurrentSession());
  udata::UdataUtils::saveUserData(*User::getInstance());
  updateSnapshot();
  MainUI::getInstance()->updateActionStates();
}
void CommStatsQWidget::updateCommitmentInfoStatsQWidget() {
  commitmentMetaDataText.fill(' ');
  QString frequencyString{};
  if (User::getInstance()->getCurrentCommitment().getType() ==
      udata::CommitmentType::WEEKLY) {

    frequencyString.append(", ");
    frequencyString.append(QString::number(
        User::getInstance()->getCurrentCommitment().getFrequency().frequency));
    frequencyString.append(" time(s) a week.");

  } else if (User::getInstance()->getCurrentCommitment().getType() ==
             udata::CommitmentType::EVERDAY) {
    frequencyString.append(", Everyday");

  } else {
    // Not supported at the moment
  }

  util::formatTime(
      commitmentMetaDataText,
      User::getInstance()->getCurrentCommitment().getFrequency().goal,
      frequencyString, 0);
  this->ui->goalQLabel->setText(commitmentMetaDataText);
}
void CommStatsQWidget::updateBeginDateQLabel() {
  beginDateText.replace(20, beginDateText.length() - 20, ' ');
  QString startDateText{
      User::getInstance()->getCurrentCommitment().getDateStart().toString()};
  beginDateText.replace(20, startDateText.length(), startDateText);
  this->ui->beginDateQLabel->setText(beginDateText);
}
void CommStatsQWidget::updateEndDateQLabel() {
  if (!User::getInstance()->getCurrentCommitment().hasEndDate()) {
    this->ui->endDateQLabel->setText("");
    return;
  }
  QString date{
      User::getInstance()->getCurrentCommitment().getDateEnd().toString()};
  endDateText.replace(8, endDateText.length() - 8, ' ');
  endDateText.replace(8, date.length(), date);
  this->ui->endDateQLabel->setText(endDateText);
}
QPalette CommStatsQWidget::getSnapshotPalette() {
  QPalette p = this->ui->CommitmentInfoStatsQWidget->palette();
  p.setColor(this->ui->CommitmentInfoStatsQWidget->backgroundRole(),
             snapshot.palette().color(QPalette::ColorRole::Background));
  return p;
}
void CommStatsQWidget::setSelectable(bool toggle) {
  if (toggle) {
    this->ui->commitmentsQTreeWidget->setSelectionMode(
        QAbstractItemView::SelectionMode::SingleSelection); // single selection
    this->ui->commitmentsQTreeWidget->setFocusPolicy(
        Qt::StrongFocus); // strong focus
  } else {
    this->ui->commitmentsQTreeWidget->setSelectionMode(
        QAbstractItemView::SelectionMode::NoSelection);
    this->ui->commitmentsQTreeWidget->setFocusPolicy(Qt::NoFocus);
  }

  isSelectable = toggle;
}
void CommStatsQWidget::updateLiveSessionStateSlot() {
  if (currentLiveSessionWidget.getCurrentState() == LiveSessionState::Paused) {
    setSelectable(true);
  } else if (currentLiveSessionWidget.getCurrentState() ==
             LiveSessionState::Started) {
    qDebug() << "setSelectable(false);";
    this->ui->commitmentsQTreeWidget->setCurrentItem(
        this->ui->commitmentsQTreeWidget->topLevelItem(
            currentLiveSessionCommitment));
    setSelectable(false);
  } else if (currentLiveSessionWidget.getCurrentState() ==
             LiveSessionState::Stopped) {
    setSelectable(true);
  }
  MainUI::getInstance()->updateActionStates();
}
void CommStatsQWidget::updateCurrentLiveSessionCommitment() {
  currentLiveSessionCommitment = selectedCommitmentIndex;
}
void CommStatsQWidget::updateCurrentCommitment() {
  if (ui->commitmentsQTreeWidget->topLevelItem(selectedCommitmentIndex) !=
      nullptr) {
    ui->commitmentsQTreeWidget->topLevelItem(selectedCommitmentIndex)
        ->setText(0, User::getInstance()->getCurrentCommitment().getName());
    qDebug() << "new text for  updateCurrentCommitment="
             << User::getInstance()->getCurrentCommitment().getName();
  } else {
    qDebug() << "updateCurrentCommitment failed";
    return;
  }
  updateCommitmentInfoStatsQWidget();
  qDebug() << "updateCurrentCommitment#1";
  updateBeginDateQLabel();
  updateEndDateQLabel();
  updateSnapshot();
}
LiveSession const &CommStatsQWidget::getcurrentLiveSessionWidget() const {
  return currentLiveSessionWidget;
}
