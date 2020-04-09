#include "CommStatsQWidget.h"

#include <CreateCommitmentQWidget.h>
#include <mainui.h>

#include "ui_CommStatsQWidget.h"
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
      0, this->ui->commitmentsQTreeWidget->columnWidth(0) + 50);
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
  this->getTimerWindow().show();
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

void CommStatsQWidget::on_commitmentsQTreeWidget_itemDoubleClicked(
    QTreeWidgetItem *item, int column) {
  QString commitmentName = item->text(column);

  auto c_vec = User::getInstance()->getCommitments();
  auto c_it = c_vec.begin();

  while (c_it != c_vec.end()) {
    Commitment c = (*c_it);

    if (c.getName() == commitmentName) {
      qDebug() << c.getName();

      TimerWindowQWidget &t =
          MainUI::getInstance()->getCommitmentHub().getTimerWindow();
      t.show();
    }

    ++c_it;
  }
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
TimerWindowQWidget &CommStatsQWidget::getTimerWindow() { return timerWindow; }
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
