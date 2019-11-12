#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "TaskerUIMainWindowQWidget.h"

#include <QApplication>
#include <QDebug>
#include <Qt>
#include <stdio.h>
#include <stdlib.h>

static TaskerUIMainWindowQWidget *f = nullptr;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    f = new TaskerUIMainWindowQWidget;
    f->show();

    return a.exec();
}

void TaskerUIMainWindowQWidget::on_makeCommitmentQPushButton_clicked() {
    f->hide();
    f->getCreateCommitment()->show();
}

void CreateCommitmentQWidget::on_createCommitmentQPushButton_clicked() {
    this->hide();
    CommStatsQWidget *wc = f->getCommStats();
    wc->show();
}

void CreateCommitmentQWidget::on_backQPushButton_clicked() {
    this->hide();
    f->show();
}

void CommStatsQWidget::on_addCommitmentQCommandLinkButton_clicked() {
    this->hide();
    CreateCommitmentQWidget *cc = f->getCreateCommitment();
    cc->show();
}

void TaskerUIMainWindowQWidget::on_quickSessionQPushButton_clicked() {
    this->hide();
    TimerWindowQWidget *tw = f->getTimerWindow();
    tw->show();
}

void TimerWindowQWidget::on_backQPushButton_clicked() {
    this->hide();
    f->show();
}
