#include "User.h"
#include "UdataUtils.h"
#include <stdlib.h>
#include <QDebug>
#include <QVector>
using namespace udata;
User* User::thisInstance = new User(QVector<Commitment>{});
User::User(QVector<Commitment> newCommitments) {
    commitments = newCommitments;
}
User::User()
{

}
User::User(QString& newUsername): userName{newUsername}
{
}
User::~User()
{}
const Commitment &udata::User::getDefaultCommitment() {
    return commitments.at(defaultCommitmentIndex);
}
QVector<Commitment>& User:: getCommitments()
{
    return commitments;
}
void User::addCommitment(Commitment& newCommitment)
{
    commitments.push_back(newCommitment);
    UdataUtils::saveUserData(*getInstance());
}

void User::addSession(Session& newSession)
{
    Commitment c = commitments.at(currentCommitment);
    c.getSessions().push_back(newSession);
    UdataUtils::saveUserData(*getInstance());
}

void udata::User::setDefaultCommitment(const Commitment &c) {
    int i = 0;
    bool found = false;
    /*
    for (i = 0; i < commitments.size(); i++) {
        if (c == commitments.at(i)) {
            found = true;
            defaultCommitmentIndex = i;
            break;
        }
    }

    if (found == false) {
        commitments.push_back(c);
        defaultCommitmentIndex = commitments.size() - 1;
    }
    */
}
void User::setUsername(QString& name)
{
    userName = name;
}
QString& User::getUsername(){
    return userName;
}
QDataStream& udata::operator<<(QDataStream &out, User &newUser)
{
    out<<newUser.commitments<<newUser.defaultCommitmentIndex<<newUser.userName;
    return out;
}
QDataStream &udata::operator>>(QDataStream &in, User &newUser)
{
    in>>newUser.commitments>>newUser.defaultCommitmentIndex>>newUser.userName;
    return in;
}
User* User::getInstance()
{
    return thisInstance;
}
