#include "mainwindow.h"
#include <QAudioInput>
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <audiomachine.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    audioMachine x{};
    w.show();
//    while(1)
//    {

//    }
    return a.exec();
}
