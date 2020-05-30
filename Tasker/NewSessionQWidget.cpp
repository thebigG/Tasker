#include "NewSessionQWidget.h"
#include "ui_NewSessionQWidget.h"
#include <Hook.h>
#include <NewSessionQWidget.h>
#include <QString>
#include <Session.h>
#include <StatsUtility.h>
#include <Task.h>
#include <Timer.h>
#include <User.h>
#include <livesession.h>
#include <mainui.h>
using namespace udata;
using namespace Engine;
/**
 * @brief TimerWindowQWidget::TimerWindowQWidget
 * @param parent
 */
NewSessionQWidget::NewSessionQWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::NewSessionQWidget) {
  ui->setupUi(this);
  connect(this->ui->backQPushButton, &QPushButton::clicked, this,
          &NewSessionQWidget::backButtonSlot);
  connect(this->ui->startTimerQPushButton, &QPushButton::clicked, this,
          &NewSessionQWidget::startTimerButtonSlot);
  this->addAction(new QAction());
  this->actions().at(0)->setShortcut(QKeySequence::Cancel);
  connect(this->actions().at(0), &QAction::triggered, this, &QWidget::hide);
  this->ui->keyboardQRadioButton->isChecked();
  goalText.reserve(100);
  goalText.resize(100);
}

/**
 * @brief TimerWindowQWidget::backButtonSlot
 */
void NewSessionQWidget::backButtonSlot() {
  this->hide();
  MainUI::getInstance()->show();
}
void NewSessionQWidget::startTimerButtonSlot() {
  QVector<Engine::Hook::HookType> newListsners;
  /**
    TODO: While the UI supports multiple listeners at the same time, the backend
    DOES NOT. So make sure, for now at least, to NOT allow the user to select
    more than one listener for the session.
    Will be adding support for multiple listeners ASAP.
    */
  if (this->ui->keyboardQRadioButton->isChecked()) {
    newListsners.push_back(Engine::Hook::HookType::X_KEYBOARD);
  } else if (this->ui->audioQRadioButton->isChecked()) {
    newListsners.push_back(Engine::Hook::HookType::audio);
  } else if (this->ui->mouseQRadioButton->isChecked()) {
    newListsners.push_back(Engine::Hook::HookType::X_MOUSE);
  }
  Task newTask{getTaskName(), newListsners};
  Session newSession{
      newTask, User::getInstance()->getCurrentCommitment().getFrequency().goal,
      QDate::currentDate()};
  Engine::Timer::getInstance()->initTimer(newListsners.at(0), newSession);
  this->hide();
}
QString NewSessionQWidget::getTaskName() {
  return this->ui->taskLineEdit->text();
}
/**
 * @brief TimerWindowQWidget::~TimerWindowQWidget
 */
NewSessionQWidget::~NewSessionQWidget() {
  qDebug() << "TimerWindowQWidget destructor#1";
  delete ui;
  qDebug() << "TimerWindowQWidget destructor#2";
}

/**
 * @brief TimerWindowQWidget::on_timerWindowQFrame_destroyed
 */
void NewSessionQWidget::on_timerWindowQFrame_destroyed() {
  qDebug()
      << " udata::User::getInstance() on on_timerWindowQFrame_destroyed()#1";
  delete udata::User::getInstance();
  qDebug()
      << " udata::User::getInstance() on on_timerWindowQFrame_destroyed()#2";
}

/**
 * @brief TimerWindowQWidget::updateGoalText
 */
void NewSessionQWidget::updateGoalText() {
  goalText.fill(' ');
  const QString &commitmentName =
      " " + QString{User::getInstance()->getCurrentCommitment().getName()} +
      " for ";
  goalText.replace(0, 5, "Goal:");
  goalText.replace(5, commitmentName.length(), commitmentName);
  //  qDebug()<<""
  util::formatTime(
      goalText, User::getInstance()->getCurrentCommitment().getFrequency().goal,
      goalContext, 5 + commitmentName.length());
  this->ui->goalQLabel->setText(goalText);
}

void NewSessionQWidget::show() {
  updateGoalText();
  this->setWindowTitle("New session for \"" +
                       User::getInstance()->getCurrentCommitment().getName() +
                       "\"");
  QWidget::show();
}
