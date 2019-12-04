#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "TaskerUIMainWindowQWidget.h"
#include "Task.h"
#include <KeyboardListener.h>
#include "Interval.h"
#include "StatsUtility.h"
#include "User.h"
#include <QThreadPool>
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <Qt>
#include <Timer.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
static TaskerUIMainWindowQWidget* f = nullptr;
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <QtCore>
#include <QObject>
#include <iostream>
#include <UdataUtils.h>
using std::cout;
using std::endl;
using namespace Engine;
using namespace udata;
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    f = new TaskerUIMainWindowQWidget;
    f->show();
//    qDebug()<<"thread id for main GUI thread:" <<QThread::currentThreadId();

//Timer myTimer;
//myTimer.start(); //calls the run() method
    QProcess getUsername;
    QString output;
    getUsername.start("whoami");
    getUsername.waitForFinished();
    output = QString(getUsername.readAllStandardOutput());
    qDebug()<<"ls output:" + output;
return a.exec();
//    UdataUtils::saveTask();
//    Task newTask{};
//    UdataUtils::loadTask(newTask);
//    qDebug()<<"name for task from disk:" + newTask.getName();
}


void TaskerUIMainWindowQWidget::on_makeCommitmentQPushButton_clicked()
{
    f->hide();
    f->getCreateCommitment()->show();
}

void CreateCommitmentQWidget::on_createCommitmentQPushButton_clicked()
{
    this->hide();
    CommStatsQWidget* wc = f->getCommStats();
    wc->show();
}

void CreateCommitmentQWidget::on_backQPushButton_clicked()
{

    this->hide();
    f->show();
}

void CommStatsQWidget::on_addCommitmentQCommandLinkButton_clicked()
{
    this->hide();
    CreateCommitmentQWidget* cc = f->getCreateCommitment();
    cc->show();
}

void TaskerUIMainWindowQWidget::on_quickSessionQPushButton_clicked()
{
    this->hide();
    TimerWindowQWidget* tw = f->getTimerWindow();
    tw->show();
}

void TimerWindowQWidget::on_backQPushButton_clicked()
{
    this->hide();
    f->show();
}
