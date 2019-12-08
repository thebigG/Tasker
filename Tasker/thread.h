#ifndef THREAD_H
#define THREAD_H
#include <audiomachine.h>
#include <QObject>
#include <QThread>
class Thread : public QObject
{
    Q_OBJECT
public:
     Thread();
//     virtual ~Thread();
     audioMachine* x;
//     qreal level;
     QThread thisThread;
    void virtual run();
    qreal getLevel();
    double *level;
signals:
    void go();
public slots:
     void updateState();
};

#endif // THREAD_H
