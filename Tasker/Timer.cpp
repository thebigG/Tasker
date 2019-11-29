#include "Timer.h"
#include <QTime>
#include <QDebug>
#include <KeyboardListener.h>
using namespace Engine;
Timer::Timer()
{
    thisK = new KeyboardListener();
}
Timer::~Timer()
{
    delete thisK;
}
void Timer::startConnect()
{
    qDebug()<<"startConnect func...";
//    connect(&thisK, &KeyboardListener::signalThread, this, &Timer::timeSlot );
    ((QThread*)thisK)->start();
}
void Timer::timeSlot()
{
    qDebug()<<"Time slot func :)";
}
QTime Timer::getRealTime(){ //not implemented
    return QTime::currentTime();
}


