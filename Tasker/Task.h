#ifndef TASK_H
#define TASK_H
#include <QString>
#include "QVector"
#include "QObject"
#include <QFile>
#include <QDataStream>
#include <Listener.h>
/**
 *
 */
namespace udata
{
class Task;

}


/**
 * @brief The udata::Task class
 * This class repsents a task. It is used as part of a Session.
 */
class udata::Task
{

public:
    Task();
    ~Task();
    Task(QString newName);
    Task(QString newName, QVector<Engine::Listener::ListenerType> listeners);
    QString& getName();
    void setName(QString value);
    QVector<Engine::Listener::ListenerType>& getListeners();
    void setListeners(QVector<Engine::Listener::ListenerType> value);

    /**
 * @brief operator << I'm really sorry about this ugiliness. Apparently,
 * as far as I know, C++ wants me to do it this wayin order to access private members.
 * @param out
 * @param newTask
 * @return
 */
friend QDataStream& operator<<(QDataStream &out, const udata::Task &newTask)
{
    out<< newTask.name;
    return out;
}
/**
* @brief operator >> I'm really sorry about this ugiliness. Apparently,
* as far as I know, C++ wants me to do it this way in order to access private members.
* @param in
* @param newTask
* @return
*/
friend QDataStream & operator>>(QDataStream &in, udata::Task &newTask)
{
    newTask = Task();
    in >> newTask.name;
    return in;
}

private:
    QVector<Engine::Listener::ListenerType> listeners;
    QString name;

};


#endif // TASK_H
