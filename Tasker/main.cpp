#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "TaskerUIMainWindowQWidget.h"
<<<<<<< HEAD
#include "Task.h"
#include "TestUtils.h"
=======

#include "Interval.h"
#include "StatsUtility.h"
#include "User.h"

>>>>>>> hardware-audio
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <Qt>
<<<<<<< HEAD
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
static TaskerUIMainWindowQWidget* f = nullptr;
using namespace std;
using namespace testUtils;
// Task test_task;
int main(int argc, char* argv[])
{
//    QApplication a(argc, argv);
//    f = new TaskerUIMainWindowQWidget;
//    f->show();
    /*
    auto str = getNameFromIn();
    Task myTask(str);
    qDebug()<< "Task name:" + myTask.getName();
    */
    QVector<QString> listenerList =  getNameListFromIn();
    qDebug()<<"size of vector:" + QString::number(listenerList.size());
    for(int i =0 ;i<listenerList.size();i++)
    {
        qDebug()<< "item #" + QString::number(i+1) + ":" + listenerList.at(i);
    }
    qDebug()<< "Enter the name for this task:";
    QString taskName  = getNameFromIn();
    Task myTask{taskName, listenerList};
    taskName = QString("");
    qDebug()<<"Task name:" + myTask.getName();
    qDebug()<<"Task name(old var):" + taskName;
//    delete str;
=======
#include <cstdio>
#include <cstdlib>

#include <iostream>

using std::cout;
using std::endl;
>>>>>>> hardware-audio

/*

<<<<<<< HEAD
    auto taskName = getNameFromIn();
    qDebug() << "task Name" + *taskName;
    auto task1 = new Task();
    */

//    return a.exec();
}

QString testUtils::getNameFromIn()
{
    QString yourText;
    QFile file;
    file.open(stdin, QIODevice::ReadOnly);
    QTextStream qtin(&file);
    qDebug() << "Input name:";
    qtin >> yourText;
    file.close();
    return yourText;
=======
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
}

QVector<QString> testUtils::getNameListFromIn()
{
    QString yourText;
    QFile file;
    file.open(stdin, QIODevice::ReadOnly);
    QTextStream qtin(&file);
    qDebug()<< "Enter the size of list:";
    qtin>>yourText;
    int size = yourText.toInt();
    QString temp;
    QVector<QString> list{};
    for(int i =0;i<size;i++)
    {
        qDebug()<< "Enter item#" +  QString::number(i+1);
        qtin >>temp;
        list.push_back(temp);
    }
    return list;
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
