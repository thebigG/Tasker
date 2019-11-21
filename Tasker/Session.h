#ifndef SESSION_H
#define SESSION_H
#include "Task.h"

class Session
{
public:
    Session();
    Session(Task newTask, unsigned long long goalLength);
    Task getTask() const;
    void setTask(Task value);

    unsigned long long getProductiveTime() const;
    void setProductiveTime(unsigned long long value);

    unsigned long long getUnproductiveTime() const;
    void setUnproductiveTime(unsigned long long value);

    QString getNotes() const;
    void setNotes( QString value);

    QVector<QString> getMedia() const;
    void setMedia(QVector<QString> value);

    unsigned long long getLength() const;
    void setLength(unsigned long long value);

private:
    Task task;
    unsigned long long int productiveTime;
    unsigned long long int unproductiveTime;
   QString notes;
   QVector<QString> media;
   unsigned long long int length;

};

#endif // SESSION_H
