#include "Commitment.h"

QDate Commitment::getDateStart() const
{
    return dateStart;
}

void Commitment::setDateStart(const QDate &value)
{
    dateStart = value;
}

QDate Commitment::getDateEnd() const
{
    return dateEnd;
}

void Commitment::setDateEnd(const QDate &value)
{
    dateEnd = value;
}

QVector<Session> Commitment::getSessions() const
{
    return sessions;
}

void Commitment::setSessions(const QVector<Session> &value)
{
    sessions = value;
}

Commitment::Commitment()
{

}
