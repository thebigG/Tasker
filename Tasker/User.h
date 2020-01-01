#ifndef USERQOBJECT_H
#define USERQOBJECT_H

#include <QVector>

#include "Commitment.h"

namespace udata {
class User;
}
/**
 * @brief The udata::User class A singleton user for the whole system.
 */
class udata::User {
public:
    ~User();
    static User *getInstance();
    const Commitment &getDefaultCommitment();
    void setDefaultCommitment(const Commitment &c);
    QVector<Commitment> &getCommitments();
    void addCommitment(Commitment &);
    void setUsername(QString &);
    QString &getUsername();
    void addSession(Session &);

private:
    User(QVector<Commitment>);
    User();
    User(QString &username);
    QVector<Commitment> commitments;
    int defaultCommitmentIndex;
    QString userName;
    static User *thisInstance;
    int currentCommitment;
    // user preferences?

    friend QDataStream &operator>>(QDataStream &in, User &newUser);
    friend QDataStream &operator<<(QDataStream &out, User &newUser);
};

#endif // USER_H
