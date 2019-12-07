#ifndef USERQOBJECT_H
#define USERQOBJECT_H

#include <QVector>

#include "Commitment.h"

namespace udata {
class User;
}

class udata::User {
public:
    User(QVector<Commitment>&);
    ~User();

    const Commitment &getDefaultCommitment();
    void setDefaultCommitment(const Commitment &c);

private:
    QVector<Commitment> commitments;
    int defaultCommitmentIndex;
    QString userName;
    // user preferences?

friend QDataStream &operator>>(QDataStream &in, User &newUser);
friend QDataStream &operator<<(QDataStream &out, User &newUser);
};

#endif // USER_H
