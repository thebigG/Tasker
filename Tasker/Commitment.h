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

    QDate getDateStart() const;
    void setDateStart(const QDate &value);
    QDate getDateEnd() const;
    void setDateEnd(const QDate &value);
    QVector<Session> getSessions() const;
    void setSessions(const QVector<Session> &value);
};

#endif // COMMITMENT_H
