#include "livesession.h"
#include "ui_livesession.h"
#include <Timer.h>
#include <QDebug>
using namespace Engine;
LiveSession::LiveSession(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::LiveSession)
{
    ui->setupUi(this);
    connect(Engine::Timer::getInstance(), &Timer::Timer::tick,
            this, &LiveSession::updateTimeUI);
    connect(Engine::Timer::getInstance(), &Timer::Timer::congrats,
            this, &LiveSession::congratsSlot);
    ui->congratsMessageLabel->setText("");
    this->setWindowTitle("Live Session");
//    this->ui->productiveTime
    qDebug()<<"text on label:" + ui->productiveTime->text();
}
void LiveSession::updateTimeUI()
{
    qDebug()<<"livession thread id:"<<QThread::currentThreadId();
    ui->productiveTime->setText( Timer::getInstance()->getProductiveStatus());
    ui->unproductiveTimeValue->setText(Timer::getInstance()->getUnproductiveStatus());
    ui->label->setText(Timer::getInstance()->getTimeElapsedStatus());

}
void LiveSession::congratsSlot()
{
    qDebug()<<"congrats on livession++++++";
    ui->congratsMessageLabel->setText("Congrats! You've completed your session!");
}
LiveSession::~LiveSession()
{
    delete ui;
}

void LiveSession::on_productiveTimeValue_linkActivated(const QString &link)
{

}
