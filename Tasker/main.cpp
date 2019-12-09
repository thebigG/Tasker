#include "AudioListener.h"
#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "Interval.h"
#include "StatsUtility.h"
#include "Task.h"
#include "TaskerUIMainWindowQWidget.h"
#include "User.h"
#include <KeyboardListener.h>
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QThreadPool>
#include <Qt>
#include <Timer.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QObject>
#include <QtCore>
#include <UdataUtils.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <mainui.h>
using std::cout;
using std::endl;
using namespace Engine;
using namespace udata;
using namespace std;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    if( UdataUtils::prepFiles() == 0)
    {
        qDebug()<<"files was allocated successfully";
    }
    else
    {
        qDebug()<<"prepFiles failed";
    }
    MainUI::getInstance()->show();
    qDebug()<<"user name:"<<User::getInstance()->getUsername();
    Commitment c = User::getInstance()->getCommitments().at(0);
    c.getName();
    qDebug()<<"commitment on disk:"<<c.getName();
    MainUI::getInstance()->show();
//    Timer myTimer(Listener::ListenerType::audio);
//    myTimer.start();

    return a.exec();
}

void TaskerUIMainWindowQWidget::on_makeCommitmentQPushButton_clicked() {
    MainUI::getInstance()->hide();
    MainUI::getInstance()->getCreateCommitment()->show();
}

void CreateCommitmentQWidget::on_createCommitmentQPushButton_clicked() {
    this->hide();
//    QVector<Commitment> commitments =  udata::User::getInstance()->getCommitments();

    Commitment temp{this->getCommitmentName(), this->getStartDate(),  this->getEndDate(), this->getInterval()};
    udata::User::getInstance()->addCommitment(temp);
    CommStatsQWidget *wc = MainUI::getInstance()->getCommStats();
    wc->show();
}

void CreateCommitmentQWidget::on_backQPushButton_clicked() {

    this->hide();


    MainUI::getInstance()->show();
}

void CommStatsQWidget::on_addCommitmentQCommandLinkButton_clicked() {
    this->hide();
    CreateCommitmentQWidget *cc = MainUI::getInstance()->getCreateCommitment();
    cc->show();
}

void TaskerUIMainWindowQWidget::on_quickSessionQPushButton_clicked() {
    this->hide();
    TimerWindowQWidget *tw = MainUI::getInstance()->getTimerWindow();
    tw->show();
}

void TimerWindowQWidget::on_backQPushButton_clicked() {
    this->hide();
    MainUI::getInstance()->show();
}
