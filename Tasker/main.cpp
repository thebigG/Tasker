#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "TaskerUIMainWindowQWidget.h"
#include "Task.h"
#include <KeyboardListener.h>
#include "Interval.h"
#include "StatsUtility.h"
#include "User.h"

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <Qt>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
static TaskerUIMainWindowQWidget* f = nullptr;
using namespace std;
#include <cstdio>
#include <cstdlib>

#include <iostream>

using std::cout;
using std::endl;
using namespace Engine;
// Task test_task;

/*
 * Keyboard's branch main
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    {
        cout << "60 seconds to mins: " << util::StatsUtility::toMinutes(60) << endl;
        cout << "3600 seconds to hours: " << util::StatsUtility::toHours(3600) << endl;
        cout << "86400 seconds to days: " << util::StatsUtility::toDays(86400) << endl;
        cout << "604800 seconds to weeks: " << util::StatsUtility::toWeeks(604800) << endl;
        cout << "2592000 seconds to months: " << util::StatsUtility::toMonths(2592000) << endl;
    }

    f = new TaskerUIMainWindowQWidget;
    f->show();
    return a.exec();
>>>>>>> hardware-audio
 */

int main(int argc, char* argv[])
{
//    QApplication a(argc, argv);
//    f = new TaskerUIMainWindowQWidget;
//    f->show();

//    delete str;
qDebug()<<"calling keyboard listener constructor";
KeyboardListener kL{};
qDebug()<<"after call";
kL.startListening();
qDebug()<<"Did it reach this?";
/*

<<<<<<< HEAD
    auto taskName = getNameFromIn();
    qDebug() << "task Name" + *taskName;
    auto task1 = new Task();
    */

//    return a.exec();
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
