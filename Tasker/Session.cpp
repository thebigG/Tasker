#include "Session.h"

Session::Session()
{

}

Session::Session(Task newTask, unsigned long long goalLength)
                :task{newTask}, length{goalLength}
{

}

Task Session::getTask() const
{
    return task;
}

void Session::setTask(Task value)
{
    task = value;
}

unsigned long long Session::getProductiveTime() const
{
    return productiveTime;
}

void Session::setProductiveTime(unsigned long long value)
{
    productiveTime = value;
}

unsigned long long Session::getUnproductiveTime() const
{
    return unproductiveTime;
}

void Session::setUnproductiveTime(unsigned long long value)
{
    unproductiveTime = value;
}

QString Session::getNotes() const
{
    return notes;
}

void Session::setNotes(QString value)
{
    notes = value;
}

QVector<QString> Session::getMedia() const
{
    return media;
}

void Session::setMedia(QVector<QString> value)
{
    media = value;
}

unsigned long long Session::getLength() const
{
    return length;
}

void Session::setLength(unsigned long long value)
{
    length = value;
}
