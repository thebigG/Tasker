#ifndef TASK_H
#define TASK_H
#include "QString"
#include "QVector"

class Task
{
public:
    Task();
    ~Task();
    Task(const QString &newName);
    Task(const QString &newName, QVector<QString> &listeners);
    QString getName() const;
    void setName(const QString &value);
    QVector<QString> getListeners() const;
    void setListeners(const QVector<QString> &value);

private:
    QString name;
    //The QString is just a placeholder. Will replace in future with actual listener class
    QVector<QString> listeners;
};

#endif // TASK_H
