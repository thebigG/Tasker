#ifndef SESSION_H
#define SESSION_H
#include "Task.h"
#include <QDataStream>
namespace udata {
class Session;

}
class udata::Session
{
public:
    Session();
    Session(Task newTask, long long goalLength);
    Task& getTask();
    void setTask(Task value);

    long long getProductiveTime() const;
    void setProductiveTime(long long value);

    long long getUnproductiveTime() const;
    void setUnproductiveTime(long long int value);

    QString& getNotes() ;
    void setNotes( QString value);

    QVector<QString>& getMedia() ;
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


   /**
* @brief operator << I'm really sorry about this ugiliness. Apparently,
* as far as I know, C++ wants me to do it this way in order to access private members.
* @param out
* @param newSession
* @return
*/
friend QDataStream& operator<<(QDataStream &out, const udata::Session &newSession)
{
   out<<newSession.task<<newSession.productiveTime
     <<newSession.unproductiveTime<<newSession.notes
    <<newSession.media<<newSession.length;
   return out;
}
/**
* @brief operator >> I'm really sorry about this ugiliness. Apparently,
* as far as I know, C++ wants me to do it this way in order to access private members.
* @param in
* @param newSession
* @return
*/
friend QDataStream & operator>>(QDataStream &in, udata::Session &newSession)
{

   in >> newSession.task>>newSession.productiveTime
           >>newSession.unproductiveTime>>newSession.notes>>
           newSession.media>>newSession.length;
   return in;
}
};

#endif // SESSION_H
