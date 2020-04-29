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
  connect(Engine::Timer::getInstance(), &Timer::Timer::congrats, this,
          &LiveSession::congratsSlot);
  connect(this->ui->playButton, &QPushButton::clicked, this,
          &LiveSession::playButtonSlot);
  connect(Timer::getInstance(), &QThread::started, this, &LiveSession::start);
  //  qDebug() << "font value="
  //           << QFontDatabase::addApplicationFont(
  //                  "/home/fast-alchemist/Downloads/unifont-13.0.02.ttf");
  //  QString family = QFontDatabase::applicationFontFamilies(0).at(0);
  //  QFont newFont(family, 16, true);
  this->ui->congratsMessageLabel->setText("");
  //  this->ui->playButton->setFont(newFont);
  this->ui->playButton->setText(PAUSEBUTTON);
  //  this->ui->playButton->setAutoFillBackground(true);
  productiveTimeValueText.reserve(10);
  productiveTimeValueText.resize(10);
  unproductiveTimeValueText.reserve(10);
  unproductiveTimeValueText.resize(10);
  totalTimeValueText.reserve(10);
  totalTimeValueText.resize(10);
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

  ui->congratsMessageLabel->setText("Congrats! You've completed your session!");
}
QLabel &LiveSession::getcongratsMessageLabel() {
  return *ui->congratsMessageLabel;
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
void LiveSession::start() { this->ui->playButton->setVisible(true); }
LiveSession::~LiveSession() { delete ui; }
