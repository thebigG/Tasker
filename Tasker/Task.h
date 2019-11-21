#ifndef TASK_H
#define TASK_H
#include "QString"
#include "QVector"
#include "QObject"
class Task
{

public:
    Task();
//    ~Task();
    Task(QString newName);
    Task(QString newName, QVector<QString> listeners);
    QString getName() const;
    void setName(QString value);
    QVector<QString> getListeners() const;
    void setListeners(QVector<QString> value);

private:
    QString name;
    //The QString is just a placeholder. Will replace in future with actual listener class
    QVector<QString> listeners;

};

#endif // TASK_H
