#ifndef COMMITMENT_H
#define COMMITMENT_H
#include <QDate>
#include <Session.h>
#include <Interval.h>
#include <QString>
#include <QDataStream>
namespace udata
{
class Commitment;
QDataStream& operator<<(QDataStream &out, const util::Interval&);
QDataStream& operator>>(QDataStream &in,  util::Interval&);
}
class udata::Commitment

{
private:
    QString name;
    QDate dateStart;
    QDate dateEnd;
    util::Interval interval;
    QVector<udata::Session> sessions;
public:
    Commitment();
    Commitment(QString newName,QDate newStart, QDate newEnd, QVector<udata::Session> newSessions);
    Commitment(QString newName,QDate newStart, QDate newEnd);
    QDate& getDateStart();
    void setDateStart(QDate value);
    QDate& getDateEnd();
    void setDateEnd(QDate value);
    QVector<Session>& getSessions();
    void setSessions(QVector<udata::Session> value);
    QString& getName();


friend QDataStream& operator<<(QDataStream &out, const udata::Commitment &newCommitment);
friend QDataStream & operator>>(QDataStream &in, udata::Commitment &newCommitment);
};

#endif // COMMITMENT_H
