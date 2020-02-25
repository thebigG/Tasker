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

/**
 * @brief KeyboardListener::KeyboardListener
 */
KeyboardListener::KeyboardListener() {
#ifdef Q_OS_LINUX

//    setKeyboardPathsOnLinux();
#endif // setKeyboardPathsOnLinux
//    setObjectName(KeyboardListener::objectName);
}

// void KeyboardListener::signalThread()
//{
//    qDebug()<<"signaling thread...";
//}

/**
 * @brief KeyboardListener::start
 */
void KeyboardListener::start() {
    qDebug() << "start function :)";
    qDebug() << "current thread id keyBoardListner class:" << QThread::currentThreadId();
    // connect(this, &KeyboardListener::signalThread, &myTimer, &Timer::timeSlot);
    startListening();
}

/**
 * @brief KeyboardListener::end
 */
void KeyboardListener::end() {
}

/**
 * @brief KeyboardListener::pause
 */
void KeyboardListener::pause() {
}

/**
 * @brief KeyboardListener::update
 */
void KeyboardListener::update() {
}

/**
 * @brief KeyboardListener::listen
 * @return
 */
Listener::ListenerState KeyboardListener::listen() {

    return getState();
}
void KeyboardListener::resetState()
{
    setState(ListenerState::unproductive);

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
    // Set the event callback for uiohook events.

    // Start the hook and block.
    // NOTE If EVENT_HOOK_ENABLED was delivered, the status will always succeed.
//    int status = hook_run();
//    const char *dev = activeKeyboardPath.toLocal8Bit().data();
    struct input_event ev;
    ssize_t n;
    int fd = 0;
    //      emit unProductive();
//    fd = open(dev, O_RDONLY);
    setState(ListenerState::unproductive);
    while (1) {

        //        state = ListenerState::unproductive;
        qDebug() << "waitting on keyboard...:unproductive state\n";
        n = read(fd, &ev, sizeof ev);
        qDebug() << "returning from read() call";
        if (n == -1) {
            if (errno == EINTR)
                continue;
            else
                break;
        } else if (n != sizeof ev) {
            errno = EIO;
            break;
        }
        if (ev.type == EV_KEY && ev.value >= 0) {
            int val = ev.value;
            setState(ListenerState::productive);
            //            state=  ListenerState::productive;
            //            emit productive();
            //            printf("%s 0x%04x (%d)\n", evval[ev.value], (int)ev.code, (int)ev.code);
            qDebug() << "key pressed: productive state\n";
            /**
              block until signal is sent
              */
//            while(getState() == ListenerState::productive)
//            {
////                qDebug()<<"Waitting for tick on listener|+|";
//            }
            qDebug()<<"State has been reset************************************";
//            QThread::sleep(BASE_DELAY);

        } else {
            //            emit unProductive();
        }
    }
    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
#endif // startListening
    return EXIT_FAILURE;
}
/**

*/
