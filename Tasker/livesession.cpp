#include "livesession.h"

#include <StatsUtility.h>
#include <Timer.h>
#include <mainui.h>

#include <QDebug>
#include <QFontDatabase>

#include "ui_livesession.h"
using namespace Engine;
LiveSession::LiveSession(QWidget *parent)
    : QWidget(parent), ui(new Ui::LiveSession) {
  ui->setupUi(this);
  connect(Engine::Timer::getInstance(), &Timer::Timer::tick, this,
          &LiveSession::updateTimeUI);
  connect(Engine::Timer::getInstance(), &Timer::Timer::tick, this,
          &LiveSession::updateHookState);

  connect(Engine::Timer::getInstance(), &Timer::Timer::congrats, this,
          &LiveSession::congratsSlot);
  connect(this->ui->playButton, &QPushButton::clicked, this,
          &LiveSession::playButtonSlot);
  connect(Timer::getInstance(), &QThread::started, this, &LiveSession::start);
  currentState = LiveSessionState::Stopped;
  //    qDebug() << "font value="
  /**
   * @brief QFontDatabase::addApplicationFont We need a supported font for the
   * play/pause unicode icons.
   * It currently works on macOS and linux.
   * Has not been tested on Windows.
   *
   */
  if (QFontDatabase::addApplicationFont(LIVESESSIONFONTPATH) == 0) {
    qDebug() << "successfully loaded font for play/pause buttons";
    QString family = QFontDatabase::applicationFontFamilies(0).at(0);
    QFont newFont(family, 16, true);
    this->ui->playButton->setFont(newFont);
  }

  this->ui->taskStateMessageLabel->setText("");
  this->ui->playButton->setText(PAUSEBUTTON);
  //  this->ui->playButton->setAutoFillBackground(true);
  productiveTimeValueText.reserve(10);
  productiveTimeValueText.resize(10);
  unproductiveTimeValueText.reserve(10);
  unproductiveTimeValueText.resize(10);
  totalTimeValueText.reserve(10);
  totalTimeValueText.resize(10);
  taskState.reserve(100);
  taskState.resize(100);
  sessionGoalText.reserve(10);
  sessionGoalText.resize(10);
  hookStateText.reserve(20);
  hookStateText.resize(20);
  //  hookStatusText()
  this->ui->playButton->setVisible(false);
  this->ui->hookStateQLabel->setVisible(false);
  qDebug() << "text on label:" + ui->productiveTimeValue->text();
}
/**
 * @brief LiveSession::updateTimeUI
 * This is a time-sensitive function.
 * It MUST return within 1 second.
 * current latency(average)=140000 nanoseconds
 * I believe this latency can be reduced with some optimizations I'll be
 * making later.
 */
void LiveSession::updateTimeUI() {
  liveSessionPerfTimer.restart();
  util::formatTime(productiveTimeValueText,
                   Timer::getInstance()->getProductiveTime(), contextText, 0,
                   util::TimeFormat::HMS);
  util::formatTime(unproductiveTimeValueText,
                   Timer::getInstance()->getUnproductiveTime(), contextText, 0,
                   util::TimeFormat::HMS);
  util::formatTime(totalTimeValueText,
                   Timer::getInstance()->getTotalTimeElapsed(), contextText, 0,
                   util::TimeFormat::HMS);
  ui->productiveTimeValue->setText(productiveTimeValueText);
  ui->unproductiveTimeValue->setText(unproductiveTimeValueText);
  ui->totalTimeValue->setText(totalTimeValueText);
  liveSessionPerfTimer.stop();
  qDebug() << "updateTimeUI latency#4:" << liveSessionPerfTimer.duration;
}
void LiveSession::congratsSlot() {
  qDebug() << "congrats on livession++++++";
  //  if()
  ui->productiveTimeValue->setText("0h0m0s");
  ui->unproductiveTimeValue->setText("0h0m0s");
  ui->totalTimeValue->setText("0h0m0s");
  //  ui->
  // reset the rest of the UI
  this->ui->hookStateQLabel->setVisible(false);
  ui->taskStateMessageLabel->setText(congratsMessage);
}
QLabel &LiveSession::getcongratsMessageLabel() {
  return *ui->taskStateMessageLabel;
}
/**
 * @brief LiveSession::resume resumes the Timer Engine.
 * If the Timer Engine is already running this function does nothing.
 */
void LiveSession::resume() {
  if (currentState == LiveSessionState::Started) {
    return;
  }
  Timer::getInstance()->resume();
  currentState = LiveSessionState::Started;
}
/**
 * @brief LiveSession::pause pauses the Timer Engine.
 * Beware that while the Timer Engine is in this Paused state, there is not data
 * being collected about this current live session. If the Timer is already
 * paused, this function does nothing.
 */
void LiveSession::pause() {
  if (currentState == LiveSessionState::Paused) {
    return;
  }
  Timer::getInstance()->pause();
  currentState = LiveSessionState::Paused;
}
QPushButton *LiveSession::getPlayButton() { return ui->playButton; }
void LiveSession::playButtonSlot() {
  if (this->ui->playButton->text() == PLAYBUTTON) {
    this->ui->playButton->setText(PAUSEBUTTON);
    resume();
  } else {
    this->ui->playButton->setText(PLAYBUTTON);
    pause();
  }
  emit liveStateChanged();
}
void LiveSession::start() {
  currentState = LiveSessionState::Started;
  initTaskState();
  initHookState();
  this->ui->playButton->setVisible(true);
}
void LiveSession::initTaskState() {
  taskState.fill(' ');
  taskState.insert(0, "Attempting \"");
  taskState.insert(
      12, Timer::getInstance()->getCurrentSession().getTask().getName());
  taskState.insert(12 + Timer::getInstance()
                            ->getCurrentSession()
                            .getTask()
                            .getName()
                            .length(),
                   "\"");
  taskState.insert(13 + Timer::getInstance()
                            ->getCurrentSession()
                            .getTask()
                            .getName()
                            .length(),
                   " for ");
  util::formatTime(sessionGoalText,
                   Timer::getInstance()->getCurrentSession().getGoal(),
                   contextText, 0);
  taskState.insert(19 + Timer::getInstance()
                            ->getCurrentSession()
                            .getTask()
                            .getName()
                            .length(),
                   sessionGoalText);
  this->ui->taskStateMessageLabel->setText(taskState);
}
/**
 * @brief LiveSession::updateHookState updates the hook state of the live
 * session. If the hook is currently productive, this hook(Mouse, Keyboard, etc)
 * is rendered as "active" to the user. If the hook is unproductive, then the
 * hook is rendered as "inactive" to the user.
 * This method is called on every "tick" of the Timer Engine; this is a SLOT
 * method that gets connected in LiveSession's constructor to the "tick" signal.
 * The argument could very well be made that this is, in theory inefficient,
 * as the tick signal is sent out every second. Another approach I have thought
 * about is having a "switched hook state" signal which only gets sent
 * out(emitted) exclusively when the Hook state changes from productive to
 * unproductive, or vice versa. However, this approach could sacrifice
 * readability as it will add more complexity to the Controller-Viewer
 * architecture that exists between LiveSession and Timer.
 * I think for now, having this method triggered every second is negligible as
 * it only takes 5000 nanoseconds(worst case on i5 2.5GHZ Dual-Core processor
 * runnign Ubuntu 18.04) on average to complete. That is not to say that other
 * methods such as UpdateUI should not be taken into consideration, since that
 * is another SLOT method that gets triggered by "tick". However, in the mean
 * time, I don't want to sacrifice readability for mere obsession with
 * optimization, which SOMETIMES may be justified in Timer's delicate
 * second-to-second state as we don't want latency in its internal clock,
 * especially when it is rendered to the user.
 */
void LiveSession::updateHookState() {
  liveSessionPerfTimer1.restart();
  hookStateText.replace(17, hookStateText.length(), ' ');
  if (Timer::getInstance()->timerHookState == Hook::HookState::productive) {
    switch (Timer::getInstance()->hookType) {
    case Hook::HookType::X_KEYBOARD:
      hookStateText.replace(17, 8, activeText);
      break;
    case Hook::HookType::X_MOUSE:
      hookStateText.replace(13, 10, activeText);
      break;
    case Hook::HookType::audio:
      hookStateText.replace(13, 10, activeText);
      break;
    }
  } else {
    switch (Timer::getInstance()->hookType) {
    case Hook::HookType::X_KEYBOARD:
      hookStateText.replace(17, 10, inactiveText);
      break;
    case Hook::HookType::X_MOUSE:
      hookStateText.replace(13, 10, inactiveText);
      break;
    case Hook::HookType::audio:
      hookStateText.replace(13, 10, inactiveText);
      break;
    }
  }
  this->ui->hookStateQLabel->setText(hookStateText);
  liveSessionPerfTimer1.stop();
  qDebug() << "updateHookState:" << liveSessionPerfTimer1.duration;
}

void LiveSession::initHookState() {
  hookStateText.fill(' ');
  hookStateText.replace(0, 8, "Hook(s):");
  switch (Timer::getInstance()->hookType) {
  case Hook::HookType::X_KEYBOARD:
    hookStateText.replace(8, 8, "Keyboard");
    break;
  case Hook::HookType::audio:
    hookStateText.replace(8, 8, "Audio");
    break;
  case Hook::HookType::X_MOUSE:
    hookStateText.replace(8, 8, "Mouse");
    break;
  }
  this->ui->hookStateQLabel->setText(hookStateText);
  this->ui->hookStateQLabel->setVisible(true);
}

LiveSessionState LiveSession::getCurrentState() const { return currentState; }
LiveSession::~LiveSession() { delete ui; }
