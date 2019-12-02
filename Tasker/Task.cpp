#include "Task.h"
#include "QString"
#include <QtCore>
#include <QFile>
#include <QDataStream>
using namespace udata;
Task::Task()
{

}
Task::~Task()
{

}

Task::Task(QString newName)
{
name = newName;
}

Task::Task(QString newName, QVector<Engine::Listener::ListenerType> listeners)
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

QVector<Engine::Listener::ListenerType>& Task::getListeners()
{
    return listeners;
}

void Task::setListeners(const QVector<Engine::Listener::ListenerType> newListeners)
{
    for (Engine::Listener::ListenerType l : newListeners) {
        listeners.push_back(l);
    }
}
