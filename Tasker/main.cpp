#include "createcommitment.h"
#include "taskeruimainwindow.h"
#include "Widget_CommStats.h"

#include <QApplication>
#include <Qt>
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>

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

   /*emit hello_clicked();*/
}

void createcommitment::on_pushButton_clicked() {

    this->hide();
    Widget_CommStats *wc = f->getCommStats();
    wc->show();
}

void createcommitment::on_pushButton_2_clicked() {
    this->hide();
    f->show();
}

void Widget_CommStats::on_CommandLinkButton_AddNewCommitment_clicked()
{
    this->hide();
    createcommitment *cc = f->getCreateCommitment();
    cc->show();
}
