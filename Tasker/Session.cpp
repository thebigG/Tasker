#include <Session.h>
#include <QtCore>
#include <StatsUtility.h>
using namespace udata;
Session::Session()
{

}

Session::Session(Task newTask, long long int goalLength)
                :task{newTask}, length{goalLength}
{
    if (length<ZERO)
    {
        length = ZERO;
    }
}

Task& Session::getTask()
{
    return task;
}

void Session::setTask(Task value)
{
    task = value;
}

long long Session::getProductiveTime() const
{
    return productiveTime;
}

void Session::setProductiveTime(long long value)
{
    productiveTime = value;
}

long long Session::getUnproductiveTime() const
{
    return unproductiveTime;
}

void Session::setUnproductiveTime(long long value)
{
    unproductiveTime = value;
}

QString& Session::getNotes()
{
    return notes;
}

void Session::setNotes(QString value)
{
    notes = value;
}

QVector<QString>& Session::getMedia()
{
    return media;
}

void Session::setMedia(QVector<QString> value)
{
    media = value;
}

long long Session::getLength() const
{
    return length;
}

void Session::setLength(long long value)
{
    length = value;
}
