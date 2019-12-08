#include "Task.h"
#include "QString"
#include <QDataStream>
#include <QFile>
#include <QtCore>
using namespace udata;
Task::Task() {
}

Task::Task(QString newName) {
    name = newName;
}

Task::Task(QString newName, QVector<Engine::Listener::ListenerType> listeners) {

    setName(newName);
    setListeners(listeners);
}

QString &Task::getName() {
    return name;
}
/**
   sets the name test
 */
void Task::setName(QString value) {
    this->name = QString(value);
}

QVector<Engine::Listener::ListenerType> &Task::getListeners() {
    return listeners;
}

void Task::setListeners(const QVector<Engine::Listener::ListenerType> newListeners) {
    for (Engine::Listener::ListenerType l : newListeners) {
        listeners.push_back(l);
    }
}
/**
 * @brief operator >> This grabs the task data from the data stream(a file) and writes it to newTask.
 * @param in The data stream where where the data is.
 * @param newTask The task object in memory.
 * @return
 */
QDataStream &udata::operator>>(QDataStream &in, udata::Task &newTask) {
    in >> newTask.name >> newTask.listeners;
    return in;
}
/**
 * @brief udata::operator << This writes the data from task into the data stream out(a file).
 * @param out The file on disk(data stream).
 * @param newTask The in-memory task to be written to file.
 * @return The data stream(this can be very useful for error checking).
 */
QDataStream &udata::operator<<(QDataStream &out, const udata::Task &newTask) {
    out << newTask.name << newTask.listeners;
    return out;
}
