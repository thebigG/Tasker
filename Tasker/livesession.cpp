#include "livesession.h"
#include "ui_livesession.h"
#include <QDebug>
#include <QFontDatabase>
#include <StatsUtility.h>
#include <Timer.h>
#include <mainui.h>
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
  this->ui->playButton->setVisible(false);
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
void LiveSession::updateHookState() {}
void LiveSession::initHookState() {
  hookStateText.fill(' ');
  hookStateText.insert(0, "Hook(s):");
}
LiveSession::~LiveSession() { delete ui; }
