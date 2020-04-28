#include "livesession.h"
#include "ui_livesession.h"
#include <QDebug>
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
  ui->congratsMessageLabel->setText("");
  this->setWindowTitle("Live Session");
  this->ui->playButton->setText("\u25B6");
  //  QPalette p = this->ui->playButton->palette();
  //  p.setColor(this->ui->playButton->backgroundRole(), );
  this->ui->playButton->setAutoFillBackground(true);
  //  this->ui->playButton->setPalette(
  //      MainUI::getInstance()->getCommitmentHub().getSnapshotPalette());
  productiveTimeValueText.reserve(10);
  productiveTimeValueText.resize(10);
  unproductiveTimeValueText.reserve(10);
  unproductiveTimeValueText.resize(10);
  totalTimeValueText.reserve(10);
  totalTimeValueText.resize(10);
  //    this->ui->productiveTime
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
QPushButton *LiveSession::getPlayButton() { return ui->playButton; }
LiveSession::~LiveSession() { delete ui; }
