#ifndef USER_H
#define USER_H

#include "Commitment.h"
#include <QVector>
#include <memory>

namespace udata {
class User;
QDataStream &operator>>(QDataStream &in, udata::User &newUser);
QDataStream &operator<<(QDataStream &out, udata::User &newUser);
} // namespace udata

/**
 * @brief The udata::User class A singleton user for the user's data(all of
 * their commitments) as a whole.
 */
class udata::User {
public:
    ~User();
    static User *getInstance();
    const Commitment &getDefaultCommitment();
    QVector<Commitment> &getCommitments();
    void addCommitment(Commitment &);
    void setUsername(QString &);
    QString &getUsername();
    void addSession(Session &);
    void updateCurrentCommitment(int newCommitmentIndex);
    Commitment &getCurrentCommitment();

    int getDefaultCommitmentIndex() const;

private:
    User(QVector<Commitment>);
    User();
    User(QString &username);
    QVector<Commitment> commitments;
    int defaultCommitmentIndex;
    QString userName;
    static std::unique_ptr<User> thisInstance;
    int currentCommitment = 0;
    friend std::unique_ptr<User> std::make_unique<User>(QVector<udata::Commitment> &&);
    friend QDataStream &operator>>(QDataStream &in, User &newUser);
    friend QDataStream &operator<<(QDataStream &out, User &newUser);
};

#endif // USER_H
