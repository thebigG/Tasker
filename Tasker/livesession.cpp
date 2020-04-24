#include "livesession.h"
#include "ui_livesession.h"
#include <QDebug>
#include <StatsUtility.h>
#include <Timer.h>
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
                   util::toMinutes(Timer::getInstance()->getProductiveTime()),
                   contextText);
  util::formatTime(unproductiveTimeValueText,
                   util::toMinutes(Timer::getInstance()->getUnproductiveTime()),
                   contextText);
  util::formatTime(totalTimeValueText,
                   util::toMinutes(Timer::getInstance()->getTotalTimeElapsed()),
                   contextText);
  ui->productiveTimeValue->setText(productiveTimeValueText);
  ui->unproductiveTimeValue->setText(unproductiveTimeValueText);
  ui->label->setText(totalTimeValueText);
  liveSessionPerfTimer.stop();
  qDebug() << "updateTimeUI latency#4:" << liveSessionPerfTimer.duration;
}
void LiveSession::congratsSlot() {
  qDebug() << "congrats on livession++++++";
  ui->congratsMessageLabel->setText("Congrats! You've completed your session!");
}
QLabel &LiveSession::getcongratsMessageLabel() {
  return *ui->congratsMessageLabel;
}
LiveSession::~LiveSession() { delete ui; }
