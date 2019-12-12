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

//    this->ui->productiveTime
    qDebug()<<"text on label:" + ui->productiveTime->text();
}
void LiveSession::updateTimeUI()
{
    ui->congratsMessageLabel->hide();
    ui->productiveTime->setText( Timer::getInstance()->getProductiveStatus());
    ui->unproductiveTimeValue->setText(Timer::getInstance()->getUnproductiveStatus());
    ui->label->setText(Timer::getInstance()->getTimeElapsedStatus());
    this->setWindowTitle("Live Session");

}
void LiveSession::congratsSlot()
{
    qDebug()<<"";
    ui->congratsMessageLabel->show();
}
LiveSession::~LiveSession()
{
    delete ui;
}

void LiveSession::on_productiveTimeValue_linkActivated(const QString &link)
{

}
