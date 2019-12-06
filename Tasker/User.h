#ifndef USERQOBJECT_H
#define USERQOBJECT_H

#include <QVector>

#include "Commitment.h"

namespace udata {
class User;
}

class udata::User {
public:
    User();
    ~User();

    const Commitment &getDefaultCommitment();
    void setDefaultCommitment(const Commitment &c);

private:
    QVector<Commitment> commitments;
    int defaultCommitmentIndex;

    // username?
    // user preferences?
};

#endif // USER_H
