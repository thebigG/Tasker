#include "CommStatsQWidget.h"
#include "ui_CommStatsQWidget.h"
#include <CreateCommitmentQWidget.h>
#include <mainui.h>

#include "Timer.h"
#include <QDebug>

//#include <QtCharts/QBarSeries>

using Engine::Listener;
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
  connect(commitmentMenu.addAction(NEW_COMMITMENT_STRING), &QAction::triggered,
          this, &CommStatsQWidget::newCommitmentSlot);
  connect(commitmentMenu.addAction(DELETE_COMMITMENT_STRING),
          &QAction::triggered, this, &CommStatsQWidget::deleteCommitmentSlot);
  commitmentMenu.addAction(EDIT_COMMITMENT_STRING);
  connect(sessionMenu.addAction(NEW_SESSION_STRING), &QAction::triggered, this,
          &CommStatsQWidget::newSessionSlot);
  sessionMenu.addAction(EDIT_SESSION_STRING);
  sessionMenu.addAction(DELETE_SESSION_STRING);
  mainMenuBar.addMenu(&commitmentMenu);
  mainMenuBar.addMenu(&sessionMenu);
  this->layout()->setMenuBar(&mainMenuBar);
  this->ui->CommitmentSnaphotQWidget->setLayout(new QGridLayout());
  snapshot = new udata::CommitmentSnaphot{};

  this->ui->CommitmentSnaphotQWidget->layout()->addWidget(&snapshot->getView());
  //  this->ui->CommitmentSnaphotQWidget->layout()->setSpacing(0);
  //  this->layout()->setSpacing(0);
  //  this->layout()->setMargin(0);
  //  p = this->ui->avg->palette();
  //  QLabel prodLabel =
  QPalette p = this->ui->AvgProductiveTime->palette();
  p.setColor(this->ui->AvgProductiveTime->backgroundRole(),
             snapshot->getProductiveQBarSet().color());
  //  this->ui->CommitmentInfoStatsQWidget->findChild<QLabel>("AvgProductiveTime")
  //      .setPalette(p);
  //  this->ui->CommitmentInfoStatsQWidget->setAutoFillBackground(true);
  //  this->ui->CommitmentInfoStatsQWidget->setPalette(p);
  this->ui->AvgProductiveTime->setAutoFillBackground(true);
  this->ui->AvgProductiveTime->setPalette(p);
  this->layout()->setContentsMargins(0, 0, 0, 0);
  //  this->ui->commStatsHubQWidget->layout()->setContentsMargins(0, 0, 0, 0);
}

void CommStatsQWidget::newCommitmentSlot(bool checked) {
  this->createCommimentWindow.show();
}
/**
 * @brief CommStatsQWidget::~CommStatsQWidget
 */
CommStatsQWidget::~CommStatsQWidget() {
  qDebug("CommStatsQWidget destructor#1");
  delete snapshot;
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

  ui->commitmentsQTreeWidget->removeItemWidget(
      ui->commitmentsQTreeWidget->topLevelItem(tempIndex), 0);
  MainUI::getInstance()->update();
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
  QVector<Commitment> &c_vec = User::getInstance()->getCommitments();
  int oldCurrentIndex = selectedCommitmentIndex;
  ui->commitmentsQTreeWidget->clear();
  selectedCommitmentIndex = 0;
  auto commitmentIt = c_vec.begin();
  while (commitmentIt != c_vec.end()) {
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

      TimerWindowQWidget &t = MainUI::getInstance()->getTimerWindow();
      t.show();
    }

    ++c_it;
  }
}
void CommStatsQWidget::currentCommitmentChangedSlot(QTreeWidgetItem *current,
                                                    QTreeWidgetItem *previous) {
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
    snapshot->update(User::getInstance()->getCurrentCommitment(), 0);
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
