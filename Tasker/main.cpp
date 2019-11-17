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
using namespace testUtil;
int main(int argc, char* argv[])
{

    QApplication a(argc, argv);
    /*
    f = new TaskerUIMainWindowQWidget;
    f->show();

    */
    auto taskName = getNameFromIn();
    qDebug() << "task Name" + *taskName;
    auto task1 = new Task();
    return a.exec();
}

QString* testUtil::getNameFromIn()
{
    auto yourText = new QString();
    QFile file;
    file.open(stdin, QIODevice::ReadOnly);
    QTextStream qtin(&file);
    qDebug() << "Input name:";
    qtin >> *yourText;
    return yourText;
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
