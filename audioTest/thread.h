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
    double* double_level;
    qreal getLevel();
signals:
    void go();
public slots:
     void updateState();
};

#endif // THREAD_H
