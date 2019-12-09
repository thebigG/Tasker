#include "thread.h"
#include <QDebug>
Thread::Thread()
{
    connect(&thisThread, &QThread::started,this, &Thread::updateState );
    this->moveToThread(&thisThread);
    thisThread.start();
}

void Thread::run()
{

//    connect(this, &Thread::go,this, &Thread::updateState);
    emit go();
//    exec();
}
void Thread::updateState()
{
x = new audioMachine();
level = &(x->destinationFile->deviceLevel);

//QThread::sleep(3);
//    while(1)
    {
//        qDebug()<<"Is it running??";
        qDebug()<<"thread id on updateState:"<<QThread::currentThreadId();
//        level = x->destinationFile->deviceLevel;
//        qDebug()<<"current level:"<<level;
    }
}
qreal Thread::getLevel()
{
    if(level == NULL)
    {
        return 0.0;
    }
    return (*level);
}