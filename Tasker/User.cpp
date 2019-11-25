#include "User.h"
using namespace udata;
User::User() {

}

User::~User() {

}


const Commitment& udata::User::getDefaultCommitment() {
    return commitments.at(defaultCommitmentIndex);
}

void udata::User::setDefaultCommitment(const Commitment& c) {
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
