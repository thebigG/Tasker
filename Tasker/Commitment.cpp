#include "Commitment.h"
#include <QDebug>
#include <Session.h>
using namespace udata;

Commitment::Commitment() {
}
Commitment::Commitment(QString newName, QDate newStart, QDate newEnd, QVector<Session> newSessions)
: name{ newName }, dateStart{ newStart }, dateEnd{ newEnd }, sessions{ newSessions } {
    if (dateStart < QDate::currentDate()) {
        dateStart = QDate::currentDate();
    }
    if (dateEnd < dateStart) {
        dateEnd = dateStart;
    }
}
Commitment::Commitment(QString newName, QDate newStart, QDate newEnd)
: name{ newName }, dateStart{ newStart }, dateEnd{ newEnd } {
    if (dateStart < QDate::currentDate()) {
        dateStart = QDate::currentDate();
    }
    if (dateEnd < dateStart) {
        dateEnd = dateStart;
    }
}
QString &Commitment::getName() {
    return name;
}
/**
 * @brief udata::operator << This writes an interval to a data stream(file).
 * @param out The data stream to write to, the file.
 * @param newInterval
 * @return out(data stream). This can be very useful to catch errors.
 */
QDataStream &udata::operator<<(QDataStream &out, const util::Interval &newInterval) {
    out << newInterval.size << newInterval.frequency;
    return out;
}
/**
 * @brief udata::operator >> This gathers all data from the data stream
 * and wirites it to the in-memory Interval.
 * @param in The data stream to read from.
 * @param newInterval An interval to write to.
 * @return The in data strea. Useful for error-checking.
 */
QDataStream &udata::operator>>(QDataStream &in, util::Interval &newInterval) {
    in >> newInterval.size >> newInterval.frequency;
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
    size = newCommitment.interval.size;
    frequency = newCommitment.interval.frequency;
    out << newCommitment.name << newCommitment.dateStart << newCommitment.dateEnd
        << newCommitment.interval << newCommitment.sessions;
    return out;
}
/**
 * @brief udata::operator >> Writes all data from data stream into newCommitment.
 * @param in data stream to read from, a file.
 * @param newCommitment The in-memory commitment to be written to.
 * @return The data stream out. Very useful for error-checking.
 */
QDataStream &udata::operator>>(QDataStream &in, udata::Commitment &newCommitment) {
    util::Interval commitmentInterval;
    QString commitmentName;
    QDate commitmentDateStart;
    QDate commitmentDateEnd;
    QVector<Session> commitmentSessions;
    in >> commitmentName >> commitmentDateStart >> commitmentDateEnd >>
        commitmentInterval >> commitmentSessions;
    newCommitment.name = commitmentName;
    newCommitment.dateStart = commitmentDateStart;
    newCommitment.dateEnd = commitmentDateEnd;
    newCommitment.interval = commitmentInterval;
    newCommitment.sessions = commitmentSessions;
    return in;
}
QDate &Commitment::getDateStart() {
    return dateStart;
}

void Commitment::setDateStart(QDate value) {
    dateStart = value;
}

QDate &Commitment::getDateEnd() {
    return dateEnd;
}

void Commitment::setDateEnd(QDate value) {
    dateEnd = value;
}

QVector<Session> &Commitment::getSessions() {
    return sessions;
}

void Commitment::setSessions(QVector<Session> value) {
    sessions = value;
}
