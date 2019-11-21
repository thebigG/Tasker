#include "User.h"

udata::User::User() {

}

udata::User::~User() {

}

bool udata::User::isDefaultCommitment(int c) {
    return c ? false : true;
}

int udata::User::getDefaultCommitment() {
    return 0;
}
