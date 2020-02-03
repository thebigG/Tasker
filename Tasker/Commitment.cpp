#include "Commitment.h"
#include <QDebug>
#include <Session.h>
#include <QtMath>

using namespace udata;

/**
 * @brief Commitment::Commitment
 */
Commitment::Commitment() {
}

Commitment::Commitment(QString newName,
                       QDate newStart,
                       QDate newEnd,
                       udata::CommitmentFrequency newInterval,
                       CommitmentType newType,
                       bool newNoEndDate)
: name{ newName }, dateStart{ newStart }, dateEnd{ newEnd },
  interval{ newInterval }, commitmentWindows{}, Type{newType},
  noEndDate{newNoEndDate}
{
    if (dateStart < QDate::currentDate()) {
        dateStart = QDate::currentDate();
    }
    if (dateEnd < dateStart) {
        dateEnd = dateStart;
    }
    updateCommitmentWindows();

}

/**
 * @brief Commitment::Commitment
 * @param newName
 * @param newStart
 * @param newEnd
 * @param newInterval
 */
Commitment::Commitment(QString newName, QDate newStart, QDate newEnd, udata::CommitmentFrequency newInterval, CommitmentType newType)
: name{ newName }, dateStart{ newStart }, dateEnd{ newEnd }, interval{ newInterval },
Type{newType}
{
    if (dateStart < QDate::currentDate()) {
        dateStart = QDate::currentDate();
    }
    if (dateEnd < dateStart) {
        dateEnd = dateStart;
    }
}
void Commitment::setType(CommitmentType newType)
{
Type = newType;
}
CommitmentType Commitment::getType()
const
{
    return Type;
}
/**
 * @brief Commitment::getName
 * @return
 */
const QString &Commitment::getName() const {
    return name;
}
/**
 * @brief Commitment::updateCommitmentWindows
 * I don't think this method makes a lot of sense.
 * I think the functionality of this can be replaced with something like
 * addSession(Session newSession) and have that method
 * check the validity of commitmentWindows with updateCommitmentWindows
 * @param newSession
 */
void Commitment::updateCommitmentWindows(Session newSession)
{
 if(commitmentWindows.isEmpty())
 {
commitmentWindows.push_back(util::TimeWindow{.startDate=dateStart,.endDate = dateStart.addDays(interval.frequency) , .sessions=QVector<Session>{newSession}});
 }
}
/**
 * @brief Commitment::updateCommitmentWindows
 * Updates the current Commitment Time Windows by adding necessary ones
 * to the internal QVector, if needed.
 * For example; Imagine Alice sets a commitment to write 30 minutes four times a week.
 * Also assum that she goes missing for three weeks on vacation and comes back to Tasker.
 * This method, which is called when Tasker starts on loadUser(), will
 * update all of those three missing CommitmentWindows, which is 3 in this case(three weeks).
 *This would of course be also very useful when a Commitment Window is closed;
 * in the beginning of a new week, a new Commitment TimeWindow is added that will be closed in seven more days.
 */
void Commitment::updateCommitmentWindows()
{
    QDate currentDate = QDate::currentDate();
    if(commitmentWindows.isEmpty())
    {
      commitmentWindows.push_back(util::TimeWindow{});
      util::TimeWindow& newWindow = commitmentWindows.last();
      newWindow.startDate.setDate(currentDate.year(), currentDate.month(),
                                  currentDate.day());
      currentDate = currentDate.addDays(interval.timeWindowSize);
      newWindow.endDate.setDate(currentDate.year(),currentDate.month(),
                                currentDate.day());
    }
    else
    {
        util::TimeWindow& lastWindow = commitmentWindows.last();
        if(currentDate<=lastWindow.endDate)
        {
            return;
        }
        currentDate.setDate(lastWindow.endDate.year(),lastWindow.endDate.month(),
                            lastWindow.endDate.day());
        currentDate = currentDate.addDays(1);
        float NumberOfTimeWindows =qCeil((currentDate.day() - lastWindow.endDate.day())/(interval.timeWindowSize));
        for(int i =0 ;i<NumberOfTimeWindows;i++)
        {
            commitmentWindows.push_back(util::TimeWindow{});
            util::TimeWindow& newWindow = commitmentWindows.last();
            newWindow.startDate.setDate(currentDate.year(), currentDate.month(),
                                        currentDate.day());
            currentDate = currentDate.addDays(interval.timeWindowSize);
            newWindow.endDate.setDate(currentDate.year(),currentDate.month(),
                                      currentDate.day());
        }

    }

}
QVector<util::TimeWindow>& Commitment::getCommitmentWindows()
const
{
    return commitmentWindows;
}
/**
 * @brief udata::operator << This writes an interval to a data stream(file).
 * @param out The data stream to write to, the file.
 * @param newInterval
 * @return out(data stream). This can be very useful to catch errors.
 */
QDataStream &udata::operator<<(QDataStream &out, const udata::CommitmentFrequency &newInterval) {
    out << newInterval.time << newInterval.frequency<<newInterval.timeWindowSize;
    return out;
}

/**
 * @brief udata::operator >> This gathers all data from the data stream
 * and wirites it to the in-memory Interval.
 * @param in The data stream to read from.
 * @param newInterval An interval to write to.
 * @return The in data stream. Useful for error-checking.
 */
QDataStream &udata::operator>>(QDataStream &in, udata::CommitmentFrequency &newInterval) {
    in >> newInterval.time >> newInterval.frequency>>newInterval.timeWindowSize;
    return in;
}

/**
 * @brief udata::operator <<This writes a commitment(and all of its fields) to a data stream(a file).
 * @param out The data stream to write to.
 * @param newCommitment The in-memory commitment to write to data stream.
 * @return The data stream. Very useful for error checking.
 */
QDataStream &udata::operator<<(QDataStream &out, const udata::Commitment &newCommitment) {
    out << newCommitment.name << newCommitment.dateStart << newCommitment.dateEnd
        << newCommitment.interval<<newCommitment.Type<<newCommitment.noEndDate<< newCommitment.commitmentWindows;
    return out;
}

/**
 * @brief udata::operator >> Writes all data from data stream into newCommitment.
 * @param in data stream to read from, a file.
 * @param newCommitment The in-memory commitment to be written to.
 * @return The data stream out. Very useful for error-checking.
 */
QDataStream &udata::operator>>(QDataStream &in, udata::Commitment &newCommitment) {
    udata::CommitmentFrequency commitmentInterval;
    QString commitmentName;
    QDate commitmentDateStart;
    QDate commitmentDateEnd;
    QVector<util::TimeWindow> newTimeWindows;
    CommitmentType newType;
    bool newNoEndDate;
    in >> commitmentName >> commitmentDateStart >> commitmentDateEnd >>
        commitmentInterval>>newType>>newNoEndDate>>newTimeWindows;
    newCommitment.name = commitmentName;
    newCommitment.dateStart = commitmentDateStart;
    newCommitment.dateEnd = commitmentDateEnd;
    newCommitment.interval = commitmentInterval;
    newCommitment.Type = newType;
    newCommitment.commitmentWindows = newTimeWindows;
    return in;
}
QDataStream& udata::operator<<(QDataStream &out, const util::TimeWindow &newTimeWindow)
{
    out<<newTimeWindow.startDate<<newTimeWindow.endDate<<newTimeWindow.sessions;
    return out;
}
QDataStream & udata::operator>>(QDataStream &in, util::TimeWindow &newTimeWindow)
{
    QDate newStartDate, newEndDate;
    QVector<Session> newSessions;
    in>>newStartDate>>newEndDate>>newSessions;
    newTimeWindow.startDate = newStartDate;
    newTimeWindow.endDate = newEndDate;
    newTimeWindow.sessions = newSessions;
    return in;
}
QDataStream &udata::operator<<(QDataStream &out, const CommitmentType& newCommitmentType)
{
    out<<(int)newCommitmentType;
    return out;
}
QDataStream &udata::operator>>(QDataStream &in, CommitmentType& newCommitmentType)
{
    int Type;
    in>>Type;
    newCommitmentType = (CommitmentType)Type;
    return in;
}
/**
 * @brief Commitment::getDateStart
 * @return
 */
QDate &Commitment::getDateStart() {
    return dateStart;
}

/**
 * @brief Commitment::setDateStart
 * @param value
 */
void Commitment::setDateStart(QDate value) {
    dateStart = value;
}

/**
 * @brief Commitment::getDateEnd
 * @return
 */
QDate &Commitment::getDateEnd() {
    return dateEnd;
}

/**
 * @brief Commitment::setDateEnd
 * @param value
 */
void Commitment::setDateEnd(QDate value) {
    dateEnd = value;
}

/**
 * @brief Commitment::getSessions
 * Get All of the sessions, across all of the
 * commitmment TimeWindow objects.
 * @return
 */
QVector<Session> Commitment::getAllSessions() {
    QVector<Session> allSessions{};
    for(util::TimeWindow t: commitmentWindows )
    {
        for(Session s: t.sessions)
        {
            allSessions.push_back(s);
        }
    }
    return allSessions;
}
QString Commitment::summary() const
{
    QString summary;
    summary += "Name:" + name + "\n";
    summary += "Start Date:" + dateStart.toString();
    if(!noEndDate)
    {
        summary += "End Date:" + dateEnd.toString();
    }
    else
    {
        summary += "End Date:None" ;
    }
    summary += "Goal time:"+ QString::number(interval.time) + "\n";
    summary += "Frequency"+ QString::number(interval.frequency)+ "\n";
    summary += "current Time Window:\nBegin:" +
                commitmentWindows.last().startDate.toString()
                +"\nEnd:"
                +  commitmentWindows.last().endDate.toString() +"\n";
    return summary;
}
/**
 * @brief Commitment::setSessions
 * @param value
 */
void Commitment::setSessions(QVector<Session> value) {

}
