#include "Task.h"
#include "QString"
Task::Task()
{
}

Task::Task(const QString& newName, QVector<QString>& listeners)
{
    setName(newName);
    setListeners(listeners);
}
Task::~Task()
{
    delete &name;
    delete &listeners;
}

QString Task::getName() const
{
    return name;
}

void Task::setName(const QString& value)
{
    name = value;
}

QVector<QString> Task::getListeners() const
{
    return listeners;
}

void Task::setListeners(const QVector<QString>& newListeners)
{
    for (QString l : newListeners) {
        listeners.push_back(l);
    }
}
