#include "User.h"
#include "UdataUtils.h"
#include <QDebug>
#include <QVector>
#include <stdlib.h>
using namespace udata;
std::unique_ptr<User> User::thisInstance;
/**
 * @brief User::User
 * @param newCommitments
 */
User::User(QVector<Commitment> newCommitments) {
    commitments = newCommitments;
}

/**
 * @brief User::User
 */
User::User() {
}
void User::updateCurrentCommitment(int newCommitmentIndex) {
    currentCommitment = newCommitmentIndex;
}
Commitment &User::getCurrentCommitment() {
    return commitments[currentCommitment];
}

/**

 * @brief User::User
 * @param newUsername
 */
User::User(QString &newUsername) : userName{ newUsername } {
}

int User::getDefaultCommitmentIndex() const {
    return defaultCommitmentIndex;
}

/**
 * @brief User::~User
 */
User::~User() {
}

/**
 * @brief udata::User::getDefaultCommitment
 * @return
 */
const Commitment &udata::User::getDefaultCommitment() {
    return commitments.at(defaultCommitmentIndex);
}

/**
 * @brief User::getCommitments
 * @return
 */
QVector<Commitment> &User::getCommitments() {
    return commitments;
}

/**
 * @brief User::addCommitment
 * @param newCommitment
 */
void User::addCommitment(Commitment &newCommitment) {
    commitments.push_back(newCommitment);
    UdataUtils::saveUserData(*getInstance());
}

/**
 * @brief User::addSession
 * @param newSession
 */
void User::addSession(Session &newSession) {
    Commitment c = commitments.at(currentCommitment);
    c.getAllSessions().push_back(newSession);
    UdataUtils::saveUserData(*getInstance());
}

/**
 * @brief User::setUsername
 * @param name
 */
void User::setUsername(QString &name) {
    userName = name;
}

/**
 * @brief User::getUsername
 * @return
 */
QString &User::getUsername() {
    return userName;
}

/**
 * @brief udata::operator <<
 * @param out
 * @param newUser
 * @return
 */
QDataStream &udata::operator<<(QDataStream &out, User &newUser) {
    out << newUser.getCommitments() << newUser.getDefaultCommitmentIndex()
        << newUser.getUsername();
    return out;
}

/**
 * @brief udata::operator >>
 * @param in
 * @param newUser
 * @return
 */
QDataStream &udata::operator>>(QDataStream &in, User &newUser) {
    in >> newUser.commitments >> newUser.defaultCommitmentIndex >> newUser.getUsername();
    return in;
}

/**
 * @brief User::getInstance
 * @return
 */
User *User::getInstance() {
    if (thisInstance.get() == nullptr) {
        thisInstance = std::make_unique<User>(QVector<Commitment>());
    }
    return thisInstance.get();
}
