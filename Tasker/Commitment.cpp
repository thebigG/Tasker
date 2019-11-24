#include "Commitment.h"
#include <QDebug>


Commitment::Commitment()
{

}
Commitment::Commitment(QString newName,QDate newStart, QDate newEnd, QVector<Session> newSessions)
    :name{newName}, dateStart{newStart}, dateEnd{newEnd}, sessions{newSessions}
{
    if(dateStart<QDate::currentDate())
    {
        dateStart = QDate::currentDate();
    }
    if(dateEnd<dateStart)
    {
        dateEnd = dateStart;
    }
}
Commitment::Commitment(QString newName,QDate newStart, QDate newEnd)
:name{newName}, dateStart{newStart}, dateEnd{newEnd}
{
    if(dateStart<QDate::currentDate())
    {
        dateStart = QDate::currentDate();
    }
    if(dateEnd<dateStart)
    {
        dateEnd = dateStart;
    }
}
QString& Commitment::getName()
{
    return name;
}

QDate& Commitment::getDateStart()
{
    return dateStart;
}

void Commitment::setDateStart(QDate value)
{
    dateStart = value;
}

QDate& Commitment::getDateEnd()
{
    return dateEnd;
}

void Commitment::setDateEnd(QDate value)
{
    dateEnd = value;
}

QVector<Session>& Commitment::getSessions()
{
    return sessions;
}

void Commitment::setSessions(QVector<Session> value)
{
    sessions = value;
}

