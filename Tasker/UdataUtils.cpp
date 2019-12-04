#include "UdataUtils.h"
#include <QDebug>
#include <QFile>
#include <QDir>
using namespace udata;
UdataUtils::UdataUtils()
{
}
void UdataUtils::saveTask()
{
    Task newTask{ "Music" };

    QString filename = "newTask.tasker";
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Could not open " << filename;
        return;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_1);
    out << newTask;
    file.flush();
    file.close();
}
void UdataUtils::loadTask(Task& newTask)
{

    QString filename = "newTask.tasker";
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open " << filename;
        return;
    }
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_1);
    in >> newTask;
    file.close();
}
int UdataUtils::prepFiles()
{
    QDir taskerFolder{};

    return 0;
}
