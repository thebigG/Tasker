#ifndef USERQOBJECT_H
#define USERQOBJECT_H

#include <QVector>

//#include "Commitment.h"

namespace udata {
    class User;
}

class udata::User {
public:
    User();
    ~User();

    bool isDefaultCommitment(int c);
    int getDefaultCommitment();
private:
    QVector<int> commmitments;
    int defaultCommitment;

    // username?
    // user preferences?
};

#endif // USER_H
