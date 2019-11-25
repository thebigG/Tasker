#ifndef TASK_H
#define TASK_H
#include "QString"
#include "QVector"
#include "QObject"
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
    Task(QString newName);
    Task(QString newName, QVector<QString> listeners);
    QString& getName() ;
    void setName(QString value);
    QVector<QString>& getListeners() ;
    void setListeners(QVector<QString> value);

private:
    QString name;
    //The QString is just a placeholder. Will replace in future with actual listener class
    QVector<QString> listeners;

};

#endif // TASK_H
