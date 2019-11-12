<<<<<<< HEAD
#include "Widget_CommStats.h"
#include "createcommitmentqwidget.h"
#include "taskeruimainwindow.h"
=======
#include "CommStatsQWidget.h"
#include "CreateCommitmentQWidget.h"
#include "TaskerUIMainWindowQWidget.h"
>>>>>>> hardware-audio

#include <QApplication>
#include <QDebug>
#include <Qt>
#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
static TaskerUIMainWindow *mainWindow = nullptr;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainWindow = new TaskerUIMainWindow;
    mainWindow->show();
    return a.exec();
}

void TaskerUIMainWindow::on_QPushButton_MakeCommitment_clicked() {
    mainWindow->hide();
    mainWindow->getCreateCommitment()->show();
}

void createCommitmentQWidget::on_pushButton_clicked() {
    this->hide();
    Widget_CommStats *wc = mainWindow->getCommStats();
    wc->show();
}

void createCommitmentQWidget::on_pushButton_2_clicked() {
=======
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
>>>>>>> hardware-audio
    this->hide();
    mainWindow->show();
}

void CommStatsQWidget::on_addCommitmentQCommandLinkButton_clicked() {
    this->hide();
<<<<<<< HEAD
    createCommitmentQWidget *cc = mainWindow->getCreateCommitment();
=======
    CreateCommitmentQWidget *cc = f->getCreateCommitment();
>>>>>>> hardware-audio
    cc->show();
}

void TaskerUIMainWindowQWidget::on_quickSessionQPushButton_clicked() {
    this->hide();
<<<<<<< HEAD
    timerwindow *tw = mainWindow->getTimerWindow();
=======
    TimerWindowQWidget *tw = f->getTimerWindow();
>>>>>>> hardware-audio
    tw->show();
}

void TimerWindowQWidget::on_backQPushButton_clicked() {
    this->hide();
    mainWindow->show();
}
