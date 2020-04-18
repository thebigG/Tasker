#include "CommStatsQWidget.h"

#include "ui_CommStatsQWidget.h"
#include <CreateCommitmentQWidget.h>
#include <UdataUtils.h>
#include <mainui.h>
#define TRAVIS_CI 1
#include "Timer.h"
#include <QDebug>
#include <iostream>

//#include <QtCharts/QBarSeries>

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
  // allocate space in this string to avoid realocation on when updating
  // CommitmentInfoStatsQWidget
  commitmentMetaDataText.reserve(100);
  commitmentMetaDataText.resize(100);
  beginDateText.resize(100);
  //  this->ui->GoalQLabel->setAlignment(Qt::AlignCenter);
  //  this->la
  //  qDebug()<<""
  //  snapshot.setMaximumSize(600, 600);
  qDebug() << "size of snapshot=" << snapshot.size();
  qDebug() << "size polocy of snapshot" << snapshot.sizePolicy();
  //  snapshot.setMaximumHeight(400);
  static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
      ->addWidget(this->ui->prevSnaphot, 0, 0);
  static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
      ->addWidget(&snapshot, 0, 1);
  static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
      ->addWidget(&currentLiveSessionWidget, 2, 1);

  static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
      ->addWidget(this->ui->CommitmentInfoStatsQWidget, 1, 1);
//          (this->ui->prev,0,0);
//  static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
//      ->setSpacing(0);
//  static_cast<QGridLayout *>(this->ui->commStatsHubQWidget->layout())
//      ->setContentsMargins(0, 0, 0, 0);
#ifdef TRAVIS_CI
  QPalette p = this->ui->CommitmentInfoStatsQWidget->palette();
  p.setColor(this->ui->CommitmentInfoStatsQWidget->backgroundRole(),
             snapshot.palette().color(QPalette::ColorRole::Background));
  this->ui->CommitmentInfoStatsQWidget->setAutoFillBackground(true);
  this->ui->CommitmentInfoStatsQWidget->setPalette(p);
  currentLiveSessionWidget.setAutoFillBackground(true);
  currentLiveSessionWidget.setPalette(p);

#endif
  this->layout()->setSpacing(0);
  this->layout()->setContentsMargins(0, 0, 0, 0);
}

void CommStatsQWidget::newCommitmentSlot(bool checked) {
  this->createCommimentWindow.show();
}
void CommStatsQWidget::addCommitmentItem(udata::Commitment &newCommitment) {

  ui->commitmentsQTreeWidget->addTopLevelItem(
      new QTreeWidgetItem(QStringList() << newCommitment.getName() << "0%"));
}
/**
 * @brief CommStatsQWidget::~CommStatsQWidget
 */
CommStatsQWidget::~CommStatsQWidget() {
  qDebug("CommStatsQWidget destructor#1");
  delete ui;
  qDebug("CommStatsQWidget destructor#2");
}

void CommStatsQWidget::deleteCommitmentSlot(bool checked) {
  //    TASKER_LOG("deleting#1:" << selectedCommitmentIndex);
  if (User::getInstance()->getCommitments().isEmpty()) {
    return;
  }
  int tempIndex = selectedCommitmentIndex;
  qDebug() << "removeCommitmentButtonSlot#1";
  if (selectedCommitmentIndex ==
      (User::getInstance()->getCommitments().size() - 1)) {
    selectedCommitmentIndex--;
  }
  User::getInstance()->getCommitments().removeAt(tempIndex);
  isDelete = true; // This is for the currentItemChanged signal, which gets
                   // emitted by delete keyword

  //  ui->commitmentsQTreeWidget->removeItemWidget(
  //        ui->commitmentsQTreeWidget->topLevelItem(tempIndex), 0);
  //          ui->commitmentsQTreeWidget->removeItemWidget(
  //      ui->commitmentsQTreeWidget->currentItem(), 0);
  qDebug() << "selected item="
           << ui->commitmentsQTreeWidget->currentItem()->text(0);
  // I don't want to use delete, but it seems to be the only way to delete these
  // TreeWidget items
  delete ui->commitmentsQTreeWidget->takeTopLevelItem(tempIndex);
  //  takeTopLevelItem

  //  MainUI::getInstance()->update();
  //    delete ui->commitmentsQTreeWidget->topLevelItem(tempIndex);
  qDebug() << "deleting#2:" << tempIndex;
  qDebug() << "deleting#3:" << tempIndex;
}
void CommStatsQWidget::newSessionSlot(bool checked) {
  //  if (User::getInstance()->getCurrentCommitment().isDone()) {
  //    // Maybe show the user in the UI that this Commitment is done
  //    return;
  //  }
  //  if (!User::getInstance()
  //           ->getCurrentCommitment()
  //           .getCommitmentWindows()
  //           .last()
  //           .sessions.isEmpty()) {

  //    if (QDate::currentDate() == User::getInstance()
  //                                    ->getCurrentCommitment()
  //                                    .getCommitmentWindows()
  //                                    .last()
  //                                    .sessions.last()
  //                                    .getDate()) {
  //      /**
  //       * Maybe show the user in the UI that they have added this session
  //       already to this commitment today. It might be worth it to consider a
  //       case where maybe a session was terminated prematurily for whatever
  //       reason and the user might want to resume that session even after
  //       closing Tasker, this is assuming that they open Tasker the very same
  //       day again. Give this a lot of thought as this could add clutter to
  //       the UI, which I don't want.
  //      */
  //      return;
  //    }
  //  }
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
  int oldCurrentIndex = selectedCommitmentIndex;
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
  if (isDelete) {
    isDelete = false;
    return;
  }
  if (current == previous) {
    qDebug() << "SAME OBJECT";
  }
  int currentIndex = 0;
  currentIndex = ui->commitmentsQTreeWidget->indexOfTopLevelItem(current);
  if (currentIndex == -1) {
    qDebug() << "NEGATIVE";
    if (current == nullptr) {
      return;
    }

    currentIndex =
        ui->commitmentsQTreeWidget->indexOfTopLevelItem(current->parent());
    qDebug() << "NEGATIVE#2";
    //        return;
  }

  selectedCommitmentIndex = currentIndex;
  qDebug() << "changed commitment index:" << currentIndex;
  qDebug() << "changed commitment name:"
           << User::getInstance()->getCommitments().at(currentIndex).getName();
  User::getInstance()->updateCurrentCommitment(selectedCommitmentIndex);
  // update meta data on meta data widget
  updateCommitmentInfoStatsQWidget();
  updateBeginDateQLabel();
  updateEndDateQLabel();
  MainUI::getInstance()->updateNewSessionActionState();
  if (User::getInstance()->getCommitments().size() != 0 &&
      User::getInstance()
              ->getCommitments()[0]
              .getCommitmentWindows()
              .length() != 0) {
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
    //            0);
    newPerfTimer.stop();
    qDebug() << "duration of chart update=" << newPerfTimer.duration
             << "milliseconds";
    QTextStream(stdout) << "(cout)duration of chart update="
                        << newPerfTimer.duration << "milliseconds";
    ;
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
 * is the same one that this new live session belongs to.
 */
void CommStatsQWidget::saveCurrentSession() {
  User::getInstance()
      ->getCurrentCommitment()
      .getCurrentTimeWindow()
      .sessions.append(Engine::Timer::getInstance()->getCurrentSession());
  udata::UdataUtils::saveUserData(*User::getInstance());
}
void CommStatsQWidget::updateCommitmentInfoStatsQWidget() {
  commitmentMetaDataText.fill(' ');
  QString frequencyString{};
  //  frequencyString.reserve(20);
  //  frequencyString.resize(20);
  frequencyString.append(", ");
  frequencyString.append(QString::number(
      User::getInstance()->getCurrentCommitment().getFrequency().frequency));
  if (User::getInstance()->getCurrentCommitment().getType() ==
      udata::CommitmentType::WEEKLY) {
    frequencyString.append(" times a week.");
  } else {
    // Not supported at the moment
  }
  qDebug() << "commitmentMetaDataText before format time-->"
           << commitmentMetaDataText;
  util::formatTime(
      commitmentMetaDataText,
      util::toMinutes(
          User::getInstance()->getCurrentCommitment().getFrequency().goal),
      frequencyString, 0);
  qDebug() << "commitmentMetaDataText after format time-->"
           << commitmentMetaDataText;
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
