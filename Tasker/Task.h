#ifndef TASK_H
#define TASK_H
#include "QObject"
#include "QVector"
#include <Listener.h>
#include <QDataStream>
#include <QFile>
#include <QString>
/**
 *
 */
namespace udata {
class Task;
}

/**
 * @brief The udata::Task class
 * This class repsents a task. It is used as part of a Session.
 */
class udata::Task {

private:
    QVector<Engine::Listener::ListenerType> listeners;
    QString name;

public:
    Task();
    Task(QString newName);
    Task(QString newName, QVector<Engine::Listener::ListenerType> listeners);
    QString &getName();
    void setName(QString value);
    QVector<Engine::Listener::ListenerType> &getListeners();
    void setListeners(QVector<Engine::Listener::ListenerType> value);

    friend QDataStream &operator<<(QDataStream &out, const udata::Task &newTask);
    /**
     * @brief operator >> I'm really sorry about this ugiliness. Apparently,
     * as far as I know, C++ wants me to do it this way in order to access private members.
     * @param in
     * @param newTask
     * @return
     */
    friend QDataStream &operator>>(QDataStream &in, udata::Task &newTask);
};

#endif // TASK_H
