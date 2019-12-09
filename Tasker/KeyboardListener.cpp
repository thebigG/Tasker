#include <KeyboardListener.h>
#include <QRegularExpression>
#include <QThread>
#include <QtCore>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef Q_OS_LINUX
#include <linux/input.h>
#endif
using namespace Engine;

KeyboardListener::KeyboardListener() {
#ifdef Q_OS_LINUX
    setKeyboardPathsOnLinux();
#endif // setKeyboardPathsOnLinux
    setObjectName(KeyboardListener::objectName);
}

// void KeyboardListener::signalThread()
//{
//    qDebug()<<"signaling thread...";
//}

void KeyboardListener::start() {
    qDebug() << "start function :)";
    qDebug() << "current thread id keyBoardListner class:" << QThread::currentThreadId();
    //connect(this, &KeyboardListener::signalThread, &myTimer, &Timer::timeSlot);
    startListening();
}
void KeyboardListener::end() {
}
void KeyboardListener::pause() {
}
void KeyboardListener::update() {
}

Listener::ListenerState KeyboardListener::listen() {


    return getState();
}

/**
 * @brief KeyboardListener::setKeyboardPathsOnLinux
 * This function iterates over /dev/input and finds the paths that point
 * to a keyboard device. This has been tested on Ubuntu-based distros.
 * These paths will be stored as QStrings in keyboardPaths.
 */
void KeyboardListener::setKeyboardPathsOnLinux(int deviceIndex) {
#ifdef Q_OS_LINUX
    QDir linuxDir(LNUX_DEV_PATH);
    QStringList devices = linuxDir.entryList();
    QRegularExpression re(LINUX_KEYBOARD_PATH_KEYWORD);
    for (int i = 0; i < devices.length(); i++) {
        QRegularExpressionMatch myMatch = re.match(devices.at(i));
        if (myMatch.hasMatch()) {
            keyboardPaths.append(devices.at(i));
        }
    }
    activeKeyboardPath = LNUX_DEV_PATH + keyboardPaths.at(deviceIndex);
#endif // setKeyboardPathsOnLinux
}

/**
 * @brief KeyboardListener::startListening holds the core logic of this listener.
 * This is a routine on an infinite loop that waits for keyboard input to come in.
 * Once it receives(detects) keyboard input, it will hold an active state
 * for the listener for the number of sconds that is delay.
 * @param delay For how long do we keep the active state. The default value is 30 seconds.
 * @return
 */
int KeyboardListener::startListening(unsigned long int delay) {
#ifdef Q_OS_LINUX
    const char *dev = activeKeyboardPath.toLocal8Bit().data();
    struct input_event ev;
    ssize_t n;
    int fd;
    fd = open(dev, O_RDONLY);
    while (1) {
        setState(ListenerState::unproductive);
        qDebug() << "waitting on keyboard...:unproductive state\n";
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
            qDebug() << "key pressed: productive state\n";
            QThread::sleep(delay);
        }
    }
    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
#endif // startListening
    return EXIT_FAILURE;
}
/**

*/
