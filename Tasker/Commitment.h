#ifndef COMMITMENT_H
#define COMMITMENT_H
#include <QDataStream>
#include <QDate>
#include <QString>
#include <Session.h>
#include <StatsUtility.h>
#include <QPair>
namespace udata {
class Commitment;
enum class CommitmentType;
struct CommitmentFrequency;
QDataStream &operator<<(QDataStream &out, const CommitmentFrequency &);
QDataStream &operator>>(QDataStream &in, CommitmentFrequency &);
QDataStream &operator<<(QDataStream &out, const udata::Commitment &newCommitment);
QDataStream &operator>>(QDataStream &in, udata::Commitment &newCommitment);
QDataStream &operator<<(QDataStream &out, const util::TimeWindow&);
QDataStream &operator>>(QDataStream &in, util::TimeWindow &);
QDataStream &operator<<(QDataStream &out, const CommitmentType&);
QDataStream &operator>>(QDataStream &in, CommitmentType&);
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
/**
 * @brief The util::CommitmentFrequency struct represents \
 * the time the user aims to spend per session(time) on each commitment \
 * AND how often they intend to spend that amount of time on each specific Task/Session of \
 * the commitment.
 *@note Beware that this struct DOES NOT strictly \
 * "define" whether the user has completed a "session" \
 * withtin a certain TimeWindow. \
 *For example; suppose Alice commits to write 30 minutes everyday.
 * In that case the struct would look like this
 * struct util:CommitmentFrequency
 * {
 * time = 1800 //30 minutes in seconds
 * Frequency  = 7 // In the case of twice a week, this value would be 2, 1 for once a week, etc.
 * }
 *Just because Alice specified the Frequency to be 7, it DOES NOT mean that there will 7
 * sessions. It just means that was Alice's optimal goal, and this can be displayed in the
 * viewer(UI) as one sees fit. There could very much be the case where Alice decides \
 * to do 14 sessions of 15 minutes(14x15=30x7). A TimeWindow(in the case of Alice a week) is \
 * is only considered accomplished(or closed if you will) when the total amount of \
 * time(in this case 210 minutes) is reached. Tasker should encourage the user to
 * commit to Frequency number of sessions per week(TimeWindow), BUT the user
 * may choose to "split" that time during the week into as many sessions as they see fit.
 * Hopefully that makes sense.
 * This struct, being a simple struct,
 * does NOT manage itself. The udata::Commitment class is the manager of this struct.
 */
struct udata::CommitmentFrequency {
    long long time = 0; // in seconds
    long long Frequency = 0; //This should be part of a QPair(?)
};
class udata::Commitment {
private:
    QString name;
    QDate dateStart;
    QDate dateEnd;
    CommitmentFrequency interval;
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
    Commitment(QString newName, QDate newStart, QDate newEnd, udata::CommitmentFrequency, QVector<Session> newSessions, CommitmentType type,
               bool noEndDate);
    Commitment(QString newName, QDate newStart, QDate newEnd, udata::CommitmentFrequency, CommitmentType type);
    QDate &getDateStart();
    void setDateStart(QDate value);
    QDate &getDateEnd();
    void setDateEnd(QDate value);
    QVector<Session> getAllSessions();
    void setSessions(QVector<udata::Session> value);
    const QString &getName() const;
    void setType(CommitmentType);
    CommitmentType getType();
    QString summary() const;
    void addCommitmentWindow(Session);
    friend QDataStream&operator<<(QDataStream &out, const udata::Commitment &newCommitment);
   friend QDataStream &operator>>(QDataStream &in, udata::Commitment &newCommitment);
//   friend QDataStream&operator<<(QDataStream &out, const util::TimeWindow &newTimeWindow);
//  friend QDataStream &operator>>(QDataStream &in, util::TimeWindow &newTimeWindow);
};

#endif // COMMITMENT_H
