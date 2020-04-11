#include "TimerWindowQWidget.h"
#include "ui_TimerWindowQWidget.h"
#include <Hook.h>
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
TimerWindowQWidget::TimerWindowQWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::TimerWindowQWidget) {
  ui->setupUi(this);
  connect(this->ui->backQPushButton, &QPushButton::clicked, this,
          &TimerWindowQWidget::backButtonSlot);
  connect(this->ui->startTimerQPushButton, &QPushButton::clicked, this,
          &TimerWindowQWidget::startTimerButtonSlot);
  connect(this->ui->taskQComboBox, SIGNAL(activated(const QString &)), this,
          SLOT(dropDownTaskSlot(const QString &)));
  this->ui->keyboardQCheckBox->setCheckState(Qt::CheckState{Qt::Checked});
  goalText.reserve(100);
  goalText.resize(100);
}

/**
 * @brief TimerWindowQWidget::backButtonSlot
 */
void TimerWindowQWidget::backButtonSlot() {
  this->hide();
  MainUI::getInstance()->show();
}
void TimerWindowQWidget::startTimerButtonSlot() {
  QVector<Engine::Hook::HookType> newListsners;
  /**
    TODO: While the UI supports multiple listeners at the same time, the backend
    DOES NOT. So make sure, for now at least, to NOT allow the user to select
    more than one listener for the session.
    Will be adding support for multiple listeners ASAP.
    */
  if (this->ui->keyboardQCheckBox->checkState() ==
      Qt::CheckState{Qt::Checked}) {
    newListsners.push_back(Engine::Hook::HookType::X_KEYBOARD);
  }
  if (this->ui->audioQCheckBox->checkState() == Qt::CheckState{Qt::Checked}) {
    newListsners.push_back(Engine::Hook::HookType::audio);
  }
  if (this->ui->mouseQCheckBox->checkState() == Qt::CheckState{Qt::Checked}) {
    newListsners.push_back(Engine::Hook::HookType::X_MOUSE);
  }
  int goal = 0;
  //            this->ui->productionTimeHoursQSpinBox->value() *
  //            SECONDS_IN_HOUR;
  //    goal += this->ui->productionTimeMinutesQSpinBox->value() *
  //    SECONDS_IN_MINUTE;
  qDebug() << "new goal" << goal;
  Task newTask{getTaskName(), newListsners};
  Session newSession{newTask, goal, QDate::currentDate()};
  Engine::Timer::getInstance()->initTimer(newListsners.at(0), newSession);
  liveTimer = std::make_unique<LiveSession>();
  liveTimer->show();

  //    Engine::Timer::getInstance()->start();
}
QString TimerWindowQWidget::getTaskName() {
  return this->ui->taskQComboBox->currentText();
}
/**
 * @brief TimerWindowQWidget::~TimerWindowQWidget
 */
TimerWindowQWidget::~TimerWindowQWidget() {
  qDebug() << "TimerWindowQWidget destructor#1";
  delete ui;
  qDebug() << "TimerWindowQWidget destructor#2";
}

/**
 * @brief TimerWindowQWidget::on_timerWindowQFrame_destroyed
 */
void TimerWindowQWidget::on_timerWindowQFrame_destroyed() {
  qDebug()
      << " udata::User::getInstance() on on_timerWindowQFrame_destroyed()#1";
  delete udata::User::getInstance();
  qDebug()
      << " udata::User::getInstance() on on_timerWindowQFrame_destroyed()#2";
}

void TimerWindowQWidget::dropDownTaskSlot(const QString &arg1) {
  if (arg1 == QString(WRITING_STRING)) {
    this->ui->keyboardQCheckBox->setCheckState(Qt::CheckState{Qt::Checked});
    this->ui->audioQCheckBox->setCheckState(Qt::CheckState{Qt::Unchecked});
  } else if (arg1 == QString(MUSIC_STRING)) {
    this->ui->audioQCheckBox->setCheckState(Qt::CheckState{Qt::Checked});
    this->ui->keyboardQCheckBox->setCheckState(Qt::CheckState{Qt::Unchecked});
  } else if (arg1 == QString(CUSTOM_STRING)) {
    this->ui->audioQCheckBox->setCheckState(Qt::CheckState{Qt::Unchecked});
    this->ui->keyboardQCheckBox->setCheckState(Qt::CheckState{Qt::Unchecked});
  }
}
/**
 * @brief TimerWindowQWidget::updateGoalText
 * @todo This is broken. Make sure to fix it. The time format shows
 * backwards on the UI.
 */
void TimerWindowQWidget::updateGoalText() {
  goalText.fill(' ');
  const QString &commitmentName =
      " " + QString{User::getInstance()->getCurrentCommitment().getName()} +
      " for ";
  goalText.replace(0, 5, "Goal:");
  goalText.replace(5, commitmentName.length(), commitmentName);
  util::formatTime(
      goalText, User::getInstance()->getCurrentCommitment().getFrequency().goal,
      goalContext, 5 + commitmentName.length());
  this->ui->goalQLabel->setText(goalText);
}

void TimerWindowQWidget::show() {
  updateGoalText();
  QWidget::show();
}
