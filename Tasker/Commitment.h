/**
 *  @file       Commitment.h
 *  @brief      Header file for udata::Commitment
 *
 *  @author     Lorenzo Gomez
 *  @date       02 Feb 2020
 */
#ifndef COMMITMENT_H
#define COMMITMENT_H
#include <QDataStream>
#include <QDate>
#include <QPair>
#include <QString>
#include <Session.h>
#include <StatsUtility.h>

/**
 *@brief The udata namespace has anything related to
 * data that persistent for users such as Commitment, Task, Session etc.
 */
namespace udata {

class Commitment;
enum class CommitmentType;
struct CommitmentFrequency;
struct TimeWindow {
  QDate startDate;
  QDate endDate;
  QVector<Session> sessions;
  int frequency;
  bool isDone() { return sessions.length() == frequency; }
  bool done = false; // managed by Commitment
  bool closed = false;
};
QDataStream &operator<<(QDataStream &out, const CommitmentFrequency &);
QDataStream &operator>>(QDataStream &in, CommitmentFrequency &);
QDataStream &operator<<(QDataStream &out,
                        const udata::Commitment &newCommitment);
QDataStream &operator>>(QDataStream &in, udata::Commitment &newCommitment);
QDataStream &operator<<(QDataStream &out, const TimeWindow &);
QDataStream &operator>>(QDataStream &in, TimeWindow &);
QDataStream &operator<<(QDataStream &out, const CommitmentType &);
QDataStream &operator>>(QDataStream &in, CommitmentType &);
} // namespace udata

/**
 * @brief The udata::Commitment class
 */
enum class udata::CommitmentType { WEEKLY, MONTHLY, Custom };
/**
 * @brief The util::CommitmentFrequency struct represents \
 * the time the user aims to spend per session(time) on each commitment \
 * AND how often they intend to spend that amount of time on each specific
 *Task/Session of \ the commitment.
 *@note Beware that this struct DOES NOT strictly \
 * "define" whether the user has completed a "session" \
 * withtin a certain TimeWindow. \
 *For example; suppose Alice commits to write 30 minutes everyday.
 * In that case the struct would look like this
 * struct util:CommitmentFrequency
 * {
 * time = 1800 //30 minutes in seconds
 * frequency = 1;
 * timeWindowSize  = 1;
 *  //The frequency variable  represents how many times and the timeWindowSize\
 * variablerepresents the size of the time
 * }
 * In the case of twice a week:
 * frequency = 2
 * timeWindowSize = 7
 *
 * In the case of three times a week:
 * frequency = 3
 * timeWindowSize = 7
 *Just because Alice specified the Frequency to be 7, it DOES NOT mean that
 *there will 7 sessions. It just means that was Alice's optimal goal, and this
 *can be displayed in the
 * viewer(UI) as one sees fit. There could very much be the case where Alice
 *decides \
 * to do 14 sessions of 15 minutes(14x15=30x7). A TimeWindow(in the case of
 *Alice a week) is \
 * is only considered accomplished(or closed if you will) when the total amount
 *of \ time(in this case 210 minutes) is reached. Tasker should encourage the
 *user to commit to Frequency number of sessions per week(TimeWindow), BUT the
 *user may choose to "split" that time during the week into as many sessions as
 *they see fit. Hopefully that makes sense. This struct, being a simple struct,
 * does NOT manage itself. The udata::Commitment class is the manager of this
 *struct.
 */
struct udata::CommitmentFrequency {
  long long goal = 0; // in seconds
  int frequency = 0;
  int timeWindowSize = 0; // in days
};
/**
 * @brief The udata::Commitment class
 * A Commitment is a commitment that the user commits to.
 * A Commitment is composed of TimeWindows called "commitmentWindows". Each
 * one of these describes a time range/span for a list of "sessions".
 * Each one of these sessions is composed of a task the user decides to do as
 * part of the commitment with a frequency that is represented by interval,
 * which is a CommitmentFrequency type.
 *
 * For example;
 * Imagine Alice creates a commitment she calls, "Alice in Wonderland".
 * In this commitment she decides to commit to that Task, which is the task of
 * writing. She decides she wants to do this for 30 minutes
 * five times a week. Let's assume this commitment was started on
 *  1 January, 1864 and Alice knew she would finish her book(commitment)
 * on 26 November, 1865.
 * This case woud look like this:
 * Commitment Name: "Alice in Winderland"
 * Start date: January 1st, 1865,
 * End Date: November 26, 1865,
 * CommitmentFrequency:{
 * time  = 1800 //seconds,
 * frequency = 5 //,
 * timeWindowSize = 7 //in days
 * },
 * commitmentWindows:{
 * 1st week(determined by timeWindowSize in CommitmentFrequency, which is seven
 * days):{ startDate = "January 1st, 1865", endDate = "January 7th, 1865"
 *    [Session1, Session2, SessionN...]
 *    },
 * 2nd week:
 *      {
 *    startDate = "January 8th, 1865",
 *    endDate = "January 14th, 1865"
 *    [Session1, Session2, SessionN...]
 * }
 * ,
 * ...
 * nth Week(last week):
 *      {
 *    startDate = "November 20th, 1865"
 *    endDate = "November 26th, 1865
 *    [Session1, Session2, SessionN...]
 *    }
 * },
 * Type : CommitmentType::Weekly,
 * noEndDate : false
 *
 *
 */
class udata::Commitment {
private:
  QString name;
  QDate dateStart;
  QDate dateEnd;
  CommitmentFrequency frequency;
  QVector<TimeWindow>
      commitmentWindows; /**For now these are just a commitment's lifespan
            divided into weeks.\ But hopefully it's clear that this time
            window can also be something like a month, or an arbitray number
            like 3 days. Each TimeWindow is the frame of time the user has to
            complete their sessions for that time period. For example;a
            commitment that is a once-a-week type will give the user a time
            window of seven days to complete that one session. Same goes for
            twice, thrice, four times a week, etc.
            */
  CommitmentType Type;
  bool noEndDate;
  bool done = false;

public:
  Commitment();
  Commitment(QString newName, QDate newStart, QDate newEnd,
             udata::CommitmentFrequency, CommitmentType type, bool noEndDate);
  QDate &getDateStart();
  void setDateStart(QDate value);
  QDate &getDateEnd();
  void setDateEnd(QDate value);
  QVector<Session> getAllSessions();
  void setSessions(QVector<udata::Session> value);
  void setName(QString);
  const QString &getName() const;
  void setType(CommitmentType);
  CommitmentType &getType();
  QString summary() const;
  void updateCommitmentWindows(Session);
  void updateCommitmentWindows();
  void update();
  bool isDone();
  void setDone(bool);
  void setFrequency(long long newTime, int newFrequency, int newTimeWinowSize);
  void setNoEndDate(bool);
  bool hasEndDate();
  CommitmentFrequency &getFrequency();
  void setCommitmentWindows(QVector<TimeWindow> &newCommitmentWindows);
  QVector<TimeWindow> &getCommitmentWindows();
  TimeWindow &getCurrentTimeWindow();
  friend QDataStream &operator<<(QDataStream &out,
                                 const udata::Commitment &newCommitment);
  friend QDataStream &operator>>(QDataStream &in,
                                 udata::Commitment &newCommitment);
};

#endif // COMMITMENT_H
