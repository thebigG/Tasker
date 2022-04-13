#ifndef TASK_H
#define TASK_H

#include "QObject"
#include "QVector"
#include <Hook.h>
#include <QDataStream>
#include <QFile>
#include <QString>

namespace udata {
class Task;
QDataStream &operator<<(QDataStream &out, const udata::Task &newTask);
QDataStream &operator>>(QDataStream &in, udata::Task &newTask);
} // namespace udata

/**
 * @brief The udata::Task class
 * This class repsents a task. It is used as part of a Session.
 */
class udata::Task {

private:
    QVector<Engine::Hook::HookType> listeners;
    QString name;

public:
    Task();
    Task(QString newName);
    Task(QString newName, QVector<Engine::Hook::HookType> listeners);
    Task(QString newName, std::vector<Engine::Hook::HookType> listeners);
    QString &getName();
    void setName(QString value);
    QVector<Engine::Hook::HookType> &getListeners();
    void setListeners(QVector<Engine::Hook::HookType> value);

    void setListeners(std::vector<Engine::Hook::HookType> newListeners);

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
