#include "Task.h"
#include "QString"
Task::Task()
{

}

Task::Task( QString newName)
{
name = newName;
}

Task::Task(QString newName, QVector<QString> listeners)
{

    setName(newName);
    setListeners(listeners);
}
//Task::~Task()
//{

//}

QString Task::getName() const
{
    return name;
}

void Task::setName(QString value)
{
    name = value;
}

QVector<QString> Task::getListeners() const
{
    return listeners;
}

void Task::setListeners(const QVector<QString> newListeners)
{
    for (QString l : newListeners) {
        listeners.push_back(l);
    }
}
