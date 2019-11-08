#include "Widget_CommStats.h"
#include "createcommitmentqwidget.h"
#include "taskeruimainwindow.h"

#include <QApplication>
#include <QDebug>
#include <Qt>
#include <stdio.h>
#include <stdlib.h>

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
    this->hide();
    mainWindow->show();
}

void Widget_CommStats::on_CommandLinkButton_AddNewCommitment_clicked() {
    this->hide();
    createCommitmentQWidget *cc = mainWindow->getCreateCommitment();
    cc->show();
}

void TaskerUIMainWindow::on_QPushButton_QuickSession_clicked() {
    this->hide();
    timerwindow *tw = mainWindow->getTimerWindow();
    tw->show();
}

void timerwindow::on_pushButton_2_clicked() {
    this->hide();
    mainWindow->show();
}
