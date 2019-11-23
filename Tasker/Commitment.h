#ifndef COMMITMENT_H
#define COMMITMENT_H
#include <QDate>
#include <Session.h>
#include <Interval.h>
#include <QString>
namespace UData
{
class Commitment;
}
class Commitment
{
private:
    QString name;
    QDate dateStart;
    QDate dateEnd;
    util::Interval interval;
    QVector<Session> sessions;
public:
    Commitment();
    Commitment(QString newName,QDate newStart, QDate newEnd, QVector<Session> newSessions);
    QDate& getDateStart();
    void setDateStart(QDate value);
    QDate& getDateEnd();
    void setDateEnd(QDate value);
    QVector<Session>& getSessions();
    void setSessions(QVector<Session> value);
    QString& getName();
};

#endif // COMMITMENT_H
