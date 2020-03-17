#ifndef USERQOBJECT_H
#define USERQOBJECT_H

#include "Commitment.h"
#include <QVector>
#include <memory>

namespace udata {
class User;
}

/**
 * @brief The udata::User class A singleton user for the whole system.
 */
class udata::User {
    // friend std::unique_ptr<User> std::make_unique<User>(QVector<udata::Commitment>&&);
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
    void updateCurrentCommitment(int newCommitmentIndex);
    Commitment& getCurrentCommitment();

private:
    User(QVector<Commitment>);
    User();
    User(QString &username);
    QVector<Commitment> commitments;
    int defaultCommitmentIndex;
    QString userName;
    static std::unique_ptr<User> thisInstance;
    int currentCommitment = 0;
    // user preferences?
    //    static std::unique_ptr<User> make_unique(QVector<udata::Commitment>&&);
    friend std::unique_ptr<User> std::make_unique<User>(QVector<udata::Commitment> &&);
    friend QDataStream &operator>>(QDataStream &in, User &newUser);
    friend QDataStream &operator<<(QDataStream &out, User &newUser);
};

#endif // USER_H
