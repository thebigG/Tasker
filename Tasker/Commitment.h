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
    /**
 * @brief operator << I'm really sorry about this ugiliness. Apparently,
 * as far as I know, C++ wants me to do it this way in order to access private members.
 * @param out
 * @param newCommitment
 * @return
 */
friend QDataStream& operator<<(QDataStream &out, const udata::Commitment &newCommitment)
{
    unsigned long long int size, frequency;
    size = newCommitment.interval.size;
    frequency = newCommitment.interval.frequency;
    out<<newCommitment.name
      <<newCommitment.dateStart
      <<newCommitment.dateEnd
      <<size
     <<frequency
    <<newCommitment.sessions;
    return out;
}
/**
* @brief operator >> I'm really sorry about this ugiliness. Apparently,
* as far as I know, C++ wants me to do it this way in order to access private members.
* @param in
* @param newCommitment
* @return
*/
friend QDataStream & operator>>(QDataStream &in, udata::Commitment &newCommitment)
{
    unsigned long long int intervalSize, intervalFrequency;
    QString commitmentName;
    QDate commitmentDateStart;
    QDate commitmentDateEnd;
    QVector<Session> commitmentSessions;
    in>>commitmentName
       >>commitmentDateStart
       >>commitmentDateEnd
       >>intervalSize
       >>intervalFrequency
       >>commitmentSessions;
    util::Interval commitmentInterval;
    commitmentInterval.size = intervalSize;
    commitmentInterval.frequency = intervalFrequency;
    newCommitment.name = commitmentName;
    newCommitment.dateStart = commitmentDateStart;
    newCommitment.dateEnd = commitmentDateEnd;
    newCommitment.interval = commitmentInterval;
    newCommitment.sessions = commitmentSessions;
    return in;
}
};

#endif // COMMITMENT_H
