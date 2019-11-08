#include "taskeruimainwindow.h"
#include "ui_taskeruimainwindow.h"

#include <stdio.h>
#include <stdlib.h>

TaskerUIMainWindow::TaskerUIMainWindow(QWidget *parent)
: QWidget(parent), ui(new Ui::TaskerUIMainWindow) {
    ui->setupUi(this);

    createCommitmentWindow = new createCommitmentQWidget();
    this->setWindowTitle("Tasker");

    wc = new Widget_CommStats();

    tw = new timerwindow();
}

QPushButton *TaskerUIMainWindow::getButton() {
    return ui->QPushButton_MakeCommitment;
}

createCommitmentQWidget *TaskerUIMainWindow::getCreateCommitment() {
    return createCommitmentWindow;
}

QFrame *TaskerUIMainWindow::getWelcomeFrame() {
    return ui->QFrame_Welcome;
}

Widget_CommStats *TaskerUIMainWindow::getCommStats() {
    return wc;
}

timerwindow *TaskerUIMainWindow::getTimerWindow() {
    return tw;
}

TaskerUIMainWindow::~TaskerUIMainWindow() {
    delete tw;
    delete wc;
    delete createCommitmentWindow;

    delete ui;
}
