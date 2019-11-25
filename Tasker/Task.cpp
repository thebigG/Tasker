#include "Task.h"
#include "QString"
#include <QtCore>
using namespace udata;
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

QString& Task::getName()
{
    return name;
}
/**
   sets the name test
 */
void Task::setName(QString value)
{
    this->name = QString(value);
}

QVector<QString>& Task::getListeners()
{
    return listeners;
}

void Task::setListeners(const QVector<QString> newListeners)
{
    for (QString l : newListeners) {
        listeners.push_back(l);
    }
}
