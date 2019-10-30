#include "createcommitment.h"
#include "taskeruimainwindow.h"
#include "Widget_CommStats.h"

#include <QApplication>
#include <Qt>
#include <stdio.h>
#include <stdlib.h>

static TaskerUIMainWindow* f = nullptr;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    f = new TaskerUIMainWindow;

    f->show();
    return a.exec();
}

void TaskerUIMainWindow::on_QPushButton_MakeCommitment_clicked() {
   f->hide();
   f->getCreateCommitment()->show();

   emit hello_clicked();
}

void createcommitment::on_pushButton_2_clicked() {
    this->hide();
    f->show();
}
