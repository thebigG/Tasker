#include <QtCore>
#include <Session.h>
#include <StatsUtility.h>

using namespace udata;

/**
 * @brief Session::Session
 */
Session::Session() {
}

/**
 * @brief Session::Session
 * @param newTask
 * @param goalLength
 */
Session::Session(Task newTask, long long int goalLength, QDate newDate)
    : task{ newTask }, goal{ goalLength }, date{newDate} {
    if (goal < ZERO) {
        goal = ZERO;
    }
}
/**
 * @brief Session::Session This constructor is useful when the user creates a commitment without
 * a session. This situation usually happens when creating a commitment for the very first time.
 * @param newTask The task of this "empty" session.
 * @note Be aware that different sessions have different tasks.
 */
Session::Session(Task newTask) : task{ newTask } {
    goal = -1;
    length = -1;
}

/**
 * @brief Session::getTask
 * @return
 */
const Task &Session::getTask() const {
    return task;
}

/**
 * @brief Session::setTask
 * @param value
 */
void Session::setTask(Task value) {
    task = value;
}

/**
 * @brief Session::getProductiveTime
 * @return
 */
long long Session::getProductiveTime() const {
    return productiveTime;
}

/**
 * @brief Session::setProductiveTime
 * @param value
 */
void Session::setProductiveTime(long long value) {
    productiveTime = value;
}

/**
 * @brief Session::getUnproductiveTime
 * @return
 */
long long Session::getUnproductiveTime() const {
    return unproductiveTime;
}

/**
 * @brief Session::setUnproductiveTime
 * @param value
 */
void Session::setUnproductiveTime(long long value) {
    unproductiveTime = value;
}

/**
 * @brief Session::getNotes
 * @return
 */
QString &Session::getNotes() {
    return notes;
}

/**
 * @brief udata::operator <<
 * @param out
 * @param newSession
 * @return
 */
QDataStream &udata::operator<<(QDataStream &out, const udata::Session &newSession) {
    out << newSession.task << newSession.productiveTime << newSession.unproductiveTime
        << newSession.notes << newSession.media << newSession.length;
    return out;
}

/**
 * @brief udata::operator >>
 * @param in
 * @param newSession
 * @return
 */
QDataStream &udata::operator>>(QDataStream &in, udata::Session &newSession) {

    in >> newSession.task >> newSession.productiveTime >> newSession.unproductiveTime >>
        newSession.notes >> newSession.media >> newSession.length;
    return in;
}

/**
 * @brief Session::setNotes
 * @param value
 */
void Session::setNotes(QString value) {
    notes = value;
}

/**
 * @brief Session::getMedia
 * @return
 */
QVector<QString> &Session::getMedia() {
    return media;
}

/**
 * @brief Session::setMedia
 * @param value
 */
void Session::setMedia(QVector<QString> value) {
    media = value;
}

/**
 * @brief Session::getLength
 * @return
 */
long long Session::getLength() const {
    return length;
}

/**
 * @brief Session::setLength
 * @param value
 */
void Session::setLength(long long value) {
    length = value;
}
long long int Session::getGoal() {
    return goal;
}

void Session::setGoal(int newGoal) {
    goal = newGoal;
}
