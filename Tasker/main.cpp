#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "TaskerUIMainWindowQWidget.h"
#include "Task.h"
#include "TestUtils.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <Qt>
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

/*

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
