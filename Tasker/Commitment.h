#ifndef COMMITMENT_H
#define COMMITMENT_H
#include <QDate>
#include <Session.h>
class Commitment
{
private:
    QDate dateStart;
    QDate dateEnd;
    //Interval goes here
    QVector<Session> sessions;
public:
    Commitment();

};

#endif // COMMITMENT_H
