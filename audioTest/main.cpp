#include "mainwindow.h"
#include <QAudioInput>
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <audiomachine.h>
#include <thread.h>
//static Thread* t;
static MainWindow*  w;
Thread* t;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<"run#1";
    t = new Thread();
    qDebug()<<"run#2";
    w = new MainWindow;
//    w.centralWidget()->layout()
//    audioMachine x{};
//    t.start();
    w->show();
    while(1)
    {
        qDebug()<<"level:"<<t->getLevel();
        QThread::sleep(2);
    }
//    {
//        qDebug()<<"level:" <<t.level;
//    }
//    t = new Thread();
    qDebug()<<"thread id on main:"<<QThread::currentThreadId();
    return a.exec();
}
void MainWindow::on_pushButton_clicked()
{
    //    ui->
    //t.getLevel()
//    this->ui->label_level->setText("testing");

    w->getLabel()->setText(QString::number(t->x->destinationFile->deviceLevel));
}