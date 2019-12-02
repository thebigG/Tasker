#include <KeyboardListener.h>
#include <QRegularExpression>
#include <QtCore>
#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <QThread>
using namespace Engine;

KeyboardListener::KeyboardListener()
{
    setKeyboardPathsOnLinux();
    setObjectName(KeyboardListener::objectName);
}

/**
 * @brief KeyboardListener::run
 * This function gets called when the QThread::start() function gets called.
 * This starts a background thread that is always listening for keyboard input.
 * No keyboard data is buffered. Th only thing the keyboard input is used for is
 * to change the state of KeyboardListener, these states are Productive or Unproductive.
 *
 */
void KeyboardListener::run()
{
    qDebug()<<"run() func";
//    start();
    for(int i =0 ;i<10;i++)
    {
        qDebug()<<"worker thread:" + QString::number(i);
    }

    emit signalThread();

}
//void KeyboardListener::signalThread()
//{
//    qDebug()<<"signaling thread...";
//}

void KeyboardListener::start()
{
    qDebug()<<"start function :)";
    qDebug()<<"current thread id keyBoardListner class:" << QThread::currentThreadId();
//   connect(this, &KeyboardListener::signalThread, &myTimer, &Timer::timeSlot);
//    startListening();
}
void KeyboardListener::end()
{
}
void KeyboardListener::pause()
{
}
void KeyboardListener::update()
{
}
Listener::ListenerState KeyboardListener::listen()
{

    return Listener::ListenerState::productive;
}
/**
 * @brief KeyboardListener::setKeyboardPathsOnLinux
 * This function iterates over /dev/input and finds the paths that point
 * to a keyboard device. This has been tested on Ubuntu-based distros.
 * These paths will be stored as QStrings in keyboardPaths.
 */
void KeyboardListener::setKeyboardPathsOnLinux(int deviceIndex)
{
    QDir linuxDir(LNUX_DEV_PATH);
    QStringList devices = linuxDir.entryList();
    QRegularExpression re(LINUX_KEYBOARD_PATH_KEYWORD);
    for (int i = 0; i < devices.length(); i++) {
        QRegularExpressionMatch myMatch = re.match(devices.at(i));
        if (myMatch.hasMatch()) {
            keyboardPaths.append( devices.at(i));
        }
    }
    activeKeyboardPath = LNUX_DEV_PATH + keyboardPaths.at(deviceIndex);
}
/**
 * @brief KeyboardListener::startListening holds the core logic of this listener.
 * This is a routine on an infinite loop that waits for keyboard input to come in.
 * Once it receives(detects) keyboard input, it will hold an active state
 * for the listener for the number of sconds that is delay.
 * @param delay For how long do we keep the active state. The default value is 30 seconds.
 * @return
 */
int KeyboardListener::startListening(unsigned long int delay)
{
    const char* dev = activeKeyboardPath.toLocal8Bit().data();
    struct input_event ev;
    ssize_t n;
    int fd;
    fd = open(dev, O_RDONLY);
    while (1) {
        setState(ListenerState::unproductive);
        qDebug()<<"waitting on keyboard...:unproductive state\n";
        n = read(fd, &ev, sizeof ev);
        if (n == -1) {
            if (errno == EINTR)
                continue;
            else
                break;
        } else if (n != sizeof ev) {
            errno = EIO;
            break;
        }
        if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2) {
            setState(ListenerState::productive);
            qDebug()<<"key pressed: productive state\n";
            QThread::sleep(delay);

        }
    }
    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return EXIT_FAILURE;
}
/**

*/