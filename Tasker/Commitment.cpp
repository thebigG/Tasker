#include "Commitment.h"
#include <QDebug>
#include <Session.h>

using namespace udata;

/**
 * @brief Commitment::Commitment
 */
Commitment::Commitment() {
}

Commitment::Commitment(QString newName,
                       QDate newStart,
                       QDate newEnd,
                       util::CommitmentFrequency newInterval,
                       QVector<Session> newSessions,
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

    commitmentWindows.push_back(util::TimeWindow{.startDate=dateStart,.endDate = dateEnd , .sessions=newSessions});
}

/**
 * @brief Commitment::Commitment
 * @param newName
 * @param newStart
 * @param newEnd
 * @param newInterval
 */
Commitment::Commitment(QString newName, QDate newStart, QDate newEnd, util::CommitmentFrequency newInterval, CommitmentType newType)
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
 * @brief udata::operator << This writes an interval to a data stream(file).
 * @param out The data stream to write to, the file.
 * @param newInterval
 * @return out(data stream). This can be very useful to catch errors.
 */
QDataStream &udata::operator<<(QDataStream &out, const util::CommitmentFrequency &newInterval) {
    out << newInterval.time << newInterval.Frequency;
    return out;
}

/**
 * @brief udata::operator >> This gathers all data from the data stream
 * and wirites it to the in-memory Interval.
 * @param in The data stream to read from.
 * @param newInterval An interval to write to.
 * @return The in data stream. Useful for error-checking.
 */
QDataStream &udata::operator>>(QDataStream &in, util::CommitmentFrequency &newInterval) {
    in >> newInterval.time >> newInterval.Frequency;
    return in;
}

/**
 * @brief udata::operator <<This writes a commitment(and all of its fields) to a data stream(a file).
 * @param out The data stream to write to.
 * @param newCommitment The in-memory commitment to write to data stream.
 * @return The data stream. Very useful for error checking.
 */
QDataStream &udata::operator<<(QDataStream &out, const udata::Commitment &newCommitment) {
    unsigned long long int size, frequency;
    size = newCommitment.interval.time;
    frequency = newCommitment.interval.Frequency;
    out << newCommitment.name << newCommitment.dateStart << newCommitment.dateEnd
        << newCommitment.interval ;//<< newCommitment.commitmentWindows;
    return out;
}

/**
 * @brief udata::operator >> Writes all data from data stream into newCommitment.
 * @param in data stream to read from, a file.
 * @param newCommitment The in-memory commitment to be written to.
 * @return The data stream out. Very useful for error-checking.
 */
QDataStream &udata::operator>>(QDataStream &in, udata::Commitment &newCommitment) {
    util::CommitmentFrequency commitmentInterval;
    QString commitmentName;
    QDate commitmentDateStart;
    QDate commitmentDateEnd;
    QVector<util::TimeWindow> commitmentSessions;
    in >> commitmentName >> commitmentDateStart >> commitmentDateEnd >>
        commitmentInterval; //>> commitmentSessions; Commented out because it's not working yet
    newCommitment.name = commitmentName;
    newCommitment.dateStart = commitmentDateStart;
    newCommitment.dateEnd = commitmentDateEnd;
    newCommitment.interval = commitmentInterval;
//    newCommitment.commitmentWindows = commitmentSessions;
    return in;
}
QDataStream& udata::operator<<(QDataStream &out, const util::TimeWindow &newTimeWindow)
{
    return out;
}
QDataStream & udata::operator>>(QDataStream &in, util::TimeWindow &newTimeWindow)
{
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

/**
 * @brief Commitment::setSessions
 * @param value
 */
void Commitment::setSessions(QVector<Session> value) {

}
