#ifndef SESSION_H
#define SESSION_H
#include "Task.h"
#include <QDataStream>
namespace udata {
class Session;

}
class udata::Session {
public:
    Session();
    Session(Task newTask, long long goalLength);
    Task &getTask();
    void setTask(Task value);

    long long getProductiveTime() const;
    void setProductiveTime(long long value);

    long long getUnproductiveTime() const;
    void setUnproductiveTime(long long int value);

    QString &getNotes();
    void setNotes(QString value);

    QVector<QString> &getMedia();
    void setMedia(QVector<QString> value);

    long long getLength() const;
    void setLength(long long int value);

private:
    Task task;
    long long int productiveTime;
    long long int unproductiveTime;
    QString notes;
    QVector<QString> media;
    long long int length;

    friend QDataStream &operator<<(QDataStream &out, const udata::Session &newSession);
    friend QDataStream &operator>>(QDataStream &in, udata::Session &newSession);
};

#endif // SESSION_H
