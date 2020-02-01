#ifndef COMMITMENT_H
#define COMMITMENT_H
#include <Interval.h>
#include <QDataStream>
#include <QDate>
#include <QString>
#include <Session.h>
#include <StatsUtility.h>

namespace udata {
class Commitment;
enum class CommitmentType;
QDataStream &operator<<(QDataStream &out, const util::CommitmentFrequency &);
QDataStream &operator>>(QDataStream &in, util::CommitmentFrequency &);
QDataStream &operator<<(QDataStream &out, const udata::Commitment &newCommitment);
QDataStream &operator>>(QDataStream &in, udata::Commitment &newCommitment);
QDataStream &operator<<(QDataStream &out, const util::TimeWindow&);
QDataStream &operator>>(QDataStream &in, util::TimeWindow &);
}

/**
 * @brief The udata::Commitment class
 */
enum class udata::CommitmentType
{
  WEEKLY,
  MONTHLY,
  Custom
};
class udata::Commitment {
private:
    QString name;
    QDate dateStart;
    QDate dateEnd;
    util::CommitmentFrequency interval;
//    QVector<Session> sessions;
    QVector<util::TimeWindow> commitmentWindows; /**For now these are just a commitment's lifespan divided into weeks.\
                                            But hopefully it's clear that this time window can also be something
                                            like a month, or an arbitray number like 3 days.
                                            Each TimeWindow is the frame of time the user has to complete their
                                            sessions for that time period.
                                            For example;a commitment that is a once-a-week type
                                            will give the user a time window of seven days
                                            to complete that one session. Same goes for
                                            twice, thrice, four times a week, etc.
                                            */
    CommitmentType Type;
    bool noEndDate;
public:
    Commitment();
    Commitment(QString newName, QDate newStart, QDate newEnd, util::CommitmentFrequency, QVector<Session> newSessions, CommitmentType type,
               bool noEndDate);
    Commitment(QString newName, QDate newStart, QDate newEnd, util::CommitmentFrequency, CommitmentType type);
    QDate &getDateStart();
    void setDateStart(QDate value);
    QDate &getDateEnd();
    void setDateEnd(QDate value);
    QVector<Session> getAllSessions();
    void setSessions(QVector<udata::Session> value);
    const QString &getName() const;
    void setType(CommitmentType);
    CommitmentType getType();
    friend QDataStream&operator<<(QDataStream &out, const udata::Commitment &newCommitment);
   friend QDataStream &operator>>(QDataStream &in, udata::Commitment &newCommitment);
//   friend QDataStream&operator<<(QDataStream &out, const util::TimeWindow &newTimeWindow);
//  friend QDataStream &operator>>(QDataStream &in, util::TimeWindow &newTimeWindow);
};

#endif // COMMITMENT_H
