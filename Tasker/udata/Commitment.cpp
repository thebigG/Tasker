
#include "Commitment.h"
#include <QDebug>
#include <QtGlobal>
#include <QtMath>
#include <Session.h>

using namespace udata;

/**
 * @brief Commitment::Commitment
 */
Commitment::Commitment() {}
/**
 * @brief Commitment::Commitment Creates a new commitment. This constructor
 * tries its best to solve any date conflicts such as dateStart being greater
 * than dateEnd, which should not happen. It also updates all the TimeWindow
 * objects in commitment so that the data is up to date with the current date of
 * the machine.
 * @param newName The name of this new commitment.
 * @param newStart The date this commitment started. If, for whatever reason,
 * this date happens to be earlier than the current date of the machine, then
 * the current date is fetched from the system and this parameter is
 * overwritten.
 * @param newEnd The date this commitment will end, if it has an end date.
 * @param newFrequency The object that describes the frequency of this
 * commitment(how many times a week the user will commit to this).
 * @param newType The type of commitment this is; WEEKLY, MONTHLY, etc.
 * @param newNoEndDate Decides whether or not this commitment has an enddate.
 */
Commitment::Commitment(QString newName,
                       QDate newStart,
                       QDate newEnd,
                       udata::CommitmentFrequency newFrequency,
                       CommitmentType newType,
                       bool newNoEndDate)
: name{ newName }, dateStart{ newStart }, dateEnd{ newEnd }, frequency{ newFrequency },
  commitmentWindows{}, Type{ newType }, noEndDate{ newNoEndDate } {
    if (dateStart < QDate::currentDate()) {
        dateStart = QDate::currentDate();
    }
    if (dateEnd < dateStart) {
        dateEnd = dateStart;
    }
    update();
    updateCommitmentWindows();
}
void Commitment::setFrequency(long long newTime, int newFrequency, int newTimeWinowSize) {
    frequency.goal = newTime;
    frequency.frequency = newFrequency;
    frequency.timeWindowSize = newTimeWinowSize;
}
void Commitment::setFrequency(CommitmentFrequency newFrequency) {
    frequency = newFrequency;
} /**
   * @brief Commitment::setCommitmentWindows
   * @param newCommitmentWindows
   * @note updates commitment windows if the date between this commitment and
   * the system are out of sync.
   */
void Commitment::setCommitmentWindows(QVector<TimeWindow> &newCommitmentWindows) {
    for (auto windows : newCommitmentWindows) {
        commitmentWindows.append(windows);
    }
}
void Commitment::setType(CommitmentType newType) {
    Type = newType;
}
CommitmentType &Commitment::getType() {
    return Type;
}
void Commitment::setNoEndDate(bool newNoEndDate) {
    noEndDate = newNoEndDate;
}
bool Commitment::hasEndDate() {
    return !noEndDate;
}

void Commitment::setName(QString newName) {
    name = newName;
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
void Commitment::updateCommitmentWindows(Session newSession) {
    if (commitmentWindows.isEmpty()) {
        commitmentWindows.push_back(
            TimeWindow{ .startDate = dateStart,
                        .endDate = dateStart.addDays(frequency.frequency),
                        .sessions = QVector<Session>{ newSession },
                        .frequency = frequency.frequency });
    }
}
/**
 * @brief Commitment::updateCommitmentWindows
 * Updates the current Commitment Time Windows by adding necessary ones
 * to the internal QVector, if needed.
 * For example; Imagine Alice sets a commitment to write 30 minutes four times a
 *week. Also assume that she goes missing for three weeks on vacation and comes
 *back to Tasker. This method, which is called when Tasker starts on loadUser(),
 *will update all of those three missing CommitmentWindows, which is 3 in this
 *case(three weeks). This would of course also be very useful when a Commitment
 *Window is closed; in the beginning of a new week, a new Commitment TimeWindow
 *is added that will be closed in seven more days, assuming that this is a
 *weekly commitment of course.
 */
void Commitment::updateCommitmentWindows() {
    QDate currentDate = QDate::currentDate();
    // If the user is done with this commitment, our work is done. There is no
    // update needed.
    if (isDone()) {
        return;

    }
    // If there are no TimeWindow objects that are part of the commitment then
    // we are constructing this Commitment for the first time and only need a
    // single TimeWindow.
    else if (commitmentWindows.isEmpty()) {
        commitmentWindows.push_back(TimeWindow{});
        TimeWindow &newWindow = commitmentWindows.last();
        newWindow.startDate.setDate(currentDate.year(), currentDate.month(),
                                    currentDate.day());
        currentDate = currentDate.addDays(frequency.timeWindowSize - 1);
        newWindow.endDate.setDate(currentDate.year(), currentDate.month(),
                                  currentDate.day());
        newWindow.frequency = frequency.frequency;
    } else {
        // If our TimeWindow objects are up to date, then we don't need to
        // update them :)
        TimeWindow &lastWindow = commitmentWindows.last();
        int daysSinceLastCommitmentWindow =
            lastWindow.startDate.daysTo(QDate::currentDate());
        if (daysSinceLastCommitmentWindow <= 0) {
            return;
        }

        else if (daysSinceLastCommitmentWindow < frequency.timeWindowSize) {
            return;
        }
        // Imagine we had a weekly commitment
        // If it has been more than week since the last time we added a TimeWindow,
        // then we might need to add 1 or more TimeWindow objects to this commitment
        else if (daysSinceLastCommitmentWindow >= frequency.timeWindowSize) {
            int NumberOfTimeWindows = daysSinceLastCommitmentWindow / frequency.timeWindowSize;
            currentDate = lastWindow.endDate.addDays(1);
            for (int i = 0; i < NumberOfTimeWindows; i++) {
                commitmentWindows.push_back(TimeWindow{});
                TimeWindow &newWindow = commitmentWindows.last();
                newWindow.startDate = currentDate;
                currentDate = currentDate.addDays(frequency.timeWindowSize - 1);
                newWindow.endDate = currentDate;
                currentDate = newWindow.endDate.addDays(1);
                newWindow.frequency = frequency.frequency;
            }
        }
    }
}
/**
 * @brief Commitment::update updates the state of this commitment.
 * Any state regarding whether this Commitment is considered "done" or not is
 * updated by this function.
 */
void Commitment::update() {
    if (noEndDate) {
        done = false;
        return;
    }
    if (QDate::currentDate() > dateEnd) {
        done = true;
    }
    return;
}
void Commitment::setDone(bool newDone) {
    done = newDone;
}
/**
 * @brief Commitment::isDone
 * A commitment is considered "done" when all
 * of its TimeWindows are "closed", whether the user completed
 * all of the tasks/sessions they commmited to or not.
 * For example; suppose that Alice  made a commitment called "Alice in
 * Wonderland" and she set out to write four times week for a whole month.
 * Suppose her start date is "January 1st, 2020"
 * and her end date is "January 30th, 2020".
 *
 * Also suppose she only wrote for two of those weeks.
 * Whe she comes back to use Tasker on January 31st, the
 * Commitment "Alice in Wonderland" will be considered "done".
 * Meaning this function, in that case, will return true.
 *
 * @note Commitments that have noEndDate set to "true" are never considered
 * "done". In such case, this function will always return false.
 * @return true if this commitment is "done". Otherwise, it returns false.
 */
bool Commitment::isDone() {
    update();
    return done;
}
QVector<TimeWindow> &Commitment::getCommitmentWindows() {
    return commitmentWindows;
}
TimeWindow &Commitment::getCurrentTimeWindow() {
    return commitmentWindows[commitmentWindows.size() - 1];
}
/**
 * @brief udata::operator << This writes an interval to a data stream(file).
 * @param out The data stream to write to, the file.
 * @param newInterval
 * @return out(data stream). This can be very useful to catch errors.
 */
QDataStream &udata::operator<<(QDataStream &out, const udata::CommitmentFrequency &newInterval) {
    out << newInterval.goal << newInterval.frequency << newInterval.timeWindowSize;
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
    in >> newInterval.goal >> newInterval.frequency >> newInterval.timeWindowSize;
    return in;
}

/**
 * @brief udata::operator <<This writes a commitment(and all of its fields) to a
 * data stream(a file).
 * @param out The data stream to write to.
 * @param newCommitment The in-memory commitment to write to data stream.
 * @return The data stream. Very useful for error checking.
 */
QDataStream &udata::operator<<(QDataStream &out, const udata::Commitment &newCommitment) {
    out << newCommitment.name << newCommitment.dateStart << newCommitment.dateEnd
        << newCommitment.frequency << newCommitment.Type << newCommitment.noEndDate;
    out << newCommitment.commitmentWindows.size();
    for (const auto w : newCommitment.commitmentWindows) {
        out << w;
    }
    out << newCommitment.done;
    qDebug() << "commitment window when saiving size="
             << newCommitment.commitmentWindows.size();

    return out;
}

/**
 * @brief udata::operator >> Writes all data from data stream into
 * newCommitment.
 * @param in data stream to read from, a file.
 * @param newCommitment The in-memory commitment to be written to.
 * @return The data stream out. Very useful for error-checking.
 */
QDataStream &udata::operator>>(QDataStream &in, udata::Commitment &newCommitment) {
    udata::CommitmentFrequency commitmentInterval;
    QString commitmentName;
    QDate commitmentDateStart;
    QDate commitmentDateEnd;
    QVector<TimeWindow> newTimeWindows;
    qDebug() << "QDataStream &udata::operator>>(QDataStream &in, "
                "udata::Commitment &newCommitment) ";
    CommitmentType newType;
    bool newNoEndDate;
    bool newDone;
    in >> commitmentName >> commitmentDateStart >> commitmentDateEnd >>
        commitmentInterval >> newType >> newNoEndDate;
    int count = 0;
    in >> count;
    for (int i = 0; i < count; i++) {
        TimeWindow temp{};
        in >> temp;
        newTimeWindows.append(temp);
    }

    in >> newDone;

    newCommitment.name = commitmentName;
    newCommitment.dateStart = commitmentDateStart;
    newCommitment.dateEnd = commitmentDateEnd;
    newCommitment.noEndDate = newNoEndDate;
    newCommitment.frequency = commitmentInterval;
    newCommitment.Type = newType;
    newCommitment.commitmentWindows = newTimeWindows;
    newCommitment.done = newDone;
    newCommitment.update();
    // Update commitment windows for this commitment
    newCommitment.updateCommitmentWindows();
    return in;
}
QDataStream &udata::operator<<(QDataStream &out, const TimeWindow &newTimeWindow) {
    out << newTimeWindow.startDate << newTimeWindow.endDate;
    out << newTimeWindow.sessions.length();
    for (const auto s : newTimeWindow.sessions) {
        out << s;
    };
    out << newTimeWindow.frequency;
    return out;
}
QDataStream &udata::operator>>(QDataStream &in, TimeWindow &newTimeWindow) {
    QDate newStartDate, newEndDate;
    QVector<Session> newSessions;
    int TimeWindowFrequency = 0;
    in >> newStartDate >> newEndDate;
    newTimeWindow.startDate = newStartDate;
    newTimeWindow.endDate = newEndDate;
    int sessionCount = 0;
    in >> sessionCount;
    for (int i = 0; i < sessionCount; i++) {
        Session s{};
        in >> s;
        newTimeWindow.sessions.append(s);
    }
    in >> TimeWindowFrequency;
    newTimeWindow.frequency = TimeWindowFrequency;
    return in;
}
QDataStream &udata::operator<<(QDataStream &out, const CommitmentType &newCommitmentType) {
    out << (int)newCommitmentType;
    return out;
}
QDataStream &udata::operator>>(QDataStream &in, CommitmentType &newCommitmentType) {
    int Type;
    in >> Type;
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
    for (TimeWindow t : commitmentWindows) {
        for (Session s : t.sessions) {
            allSessions.push_back(s);
        }
    }
    return allSessions;
}
QString Commitment::summary() const {
    QString summary;
    qDebug() << "summary#1";
    summary += "Name:" + name + "\n";
    qDebug() << "summary#2";
    summary += "Start Date:" + dateStart.toString();
    qDebug() << "summary#3";
    if (!noEndDate) {
        summary += "End Date:" + dateEnd.toString();
    } else {
        summary += "End Date:None";
    }
    qDebug() << "summary#4";
    summary += "Goal time:" + QString::number(frequency.goal) + "\n";
    qDebug() << "summary#5";
    summary += "Frequency" + QString::number(frequency.frequency) + "\n";
    qDebug() << "summary#6";
    if (!commitmentWindows.isEmpty()) {
        summary += "current Time Window:\nBegin:" +
                   commitmentWindows.last().startDate.toString() +

                   "\nEnd:" + commitmentWindows.last().endDate.toString() +
                   "\n" + "Done:" + done;
    }
    qDebug() << "commitmentWindows size=" << commitmentWindows.size();
    return summary;
}
CommitmentFrequency &Commitment::getFrequency() {
    return frequency;
}
