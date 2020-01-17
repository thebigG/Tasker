#include "livesession.h"
#include "ui_livesession.h"
#include <QDebug>
#include <Timer.h>
using namespace Engine;
LiveSession::LiveSession(QWidget *parent)
: QWidget(parent), ui(new Ui::LiveSession) {
    ui->setupUi(this);
    connect(Engine::Timer::getInstance(), &Timer::Timer::tick, this, &LiveSession::updateTimeUI);
    connect(Engine::Timer::getInstance(), &Timer::Timer::congrats, this,
            &LiveSession::congratsSlot);
    ui->congratsMessageLabel->setText("");
    this->setWindowTitle("Live Session");
    //    this->ui->productiveTime
    qDebug() << "text on label:" + ui->productiveTime->text();
}
/**
 * @brief LiveSession::updateTimeUI
 * This is a time-sensitive function.
 * It MUST return within 1 second.
 * current latency(average)=75,000 nanoseconds
 * I believe this latency can be reduced with some optimizations I'll be
 * making later.
 */
void LiveSession::updateTimeUI() {
    qDebug() << "livession threadid:" << QThread::currentThreadId();
    liveSessionPerfTimer.restart();
    ui->productiveTime->setText(Timer::getInstance()->getProductiveStatus());
    ui->unproductiveTimeValue->setText(Timer::getInstance()->getUnproductiveStatus());
    ui->label->setText(Timer::getInstance()->getTimeElapsedStatus());
    liveSessionPerfTimer.stop();
    qDebug()<<"updateTimeUI latency:"<<liveSessionPerfTimer.duration;
}
void LiveSession::congratsSlot() {
    qDebug() << "congrats on livession++++++";
    ui->congratsMessageLabel->setText(
        "Congrats! You've completed your session!");
}
LiveSession::~LiveSession() {
    delete ui;
}

void LiveSession::on_productiveTimeValue_linkActivated(const QString &link) {
}
