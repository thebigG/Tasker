#include "Timer.h"
#include <QTime>

Engine::Timer::Timer()
{

}

QTime Engine::Timer::getRealTime(){ //not implemented
    return QTime::currentTime();
}

