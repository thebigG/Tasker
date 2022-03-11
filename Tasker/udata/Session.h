#ifndef SESSION_H
#define SESSION_H
#include "Task.h"
#include <QDataStream>
#include <QDate>

namespace udata {
class Session;
QDataStream &operator<<(QDataStream &out, const udata::Session &newSession);
QDataStream &operator>>(QDataStream &in, udata::Session &newSession);
} // namespace udata

/**
 * @brief The udata::Session class
 * A session is what is created when the user starts a certain task on Tasker
 * that is part of the a commitment. For example; imagine a user named Alice
 * creates a commitment called "Alice in Wonderland"  and they define the
 * frequency of that commitment to "Five times a week". Every single time they
 * attempt a new task for that commitment, that will be a session that becomes
 * part of that commitment as a whole.
 */
class udata::Session {
public:
    Session();
    Session(Task newTask, long long goalLength, QDate date);
    Session(Task);
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

    void setGoal(int);
    long long int getGoal();
    void setDate(QDate newDate);
    QDate &getDate();

private:
    Task task;
    long long int goal;
    long long int productiveTime;
    long long int unproductiveTime;
    QString notes;
    QVector<QString> media;
    long long int length;
    QDate date;
    friend QDataStream &operator<<(QDataStream &out, const udata::Session &newSession);
    friend QDataStream &operator>>(QDataStream &in, udata::Session &newSession);
};

#endif // SESSION_H
