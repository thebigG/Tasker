#include "taskeruimainwindow.h"
#include "ui_taskeruimainwindow.h"

#include <stdio.h>
#include <stdlib.h>

TaskerUIMainWindow::TaskerUIMainWindow(QWidget *parent)
: QWidget(parent), ui(new Ui::TaskerUIMainWindow) {
    ui->setupUi(this);

    x = new createcommitment();
    this->setWindowTitle("Tasker");

    wc = new Widget_CommStats();
}

QPushButton *TaskerUIMainWindow::getButton() {
    return ui->QPushButton_MakeCommitment;
}

createcommitment *TaskerUIMainWindow::getCreateCommitment() {
    return x;
}

QFrame *TaskerUIMainWindow::getWelcomeFrame() {
    return ui->QFrame_Welcome;
}

Widget_CommStats *TaskerUIMainWindow::getCommStats() {
    return wc;
}

TaskerUIMainWindow::~TaskerUIMainWindow() {
    delete ui;
}
