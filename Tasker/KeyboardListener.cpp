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

    setKeyboardPathsOnLinux();
#endif // setKeyboardPathsOnLinux
    setObjectName(KeyboardListener::objectName);
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
    qDebug() << "active path for keyboard:" << activeKeyboardPath;
#endif // setKeyboardPathsOnLinux
}
void KeyboardListener::resetState()
{
    setState(ListenerState::unproductive);

}


// NOTE: The following callback executes on the same thread that hook_run() is called
// from.  This is important because hook_run() attaches to the operating systems
// event dispatcher and may delay event delivery to the target application.
// Furthermore, some operating systems may choose to disable your hook if it
// takes to long to process.  If you need to do any extended processing, please
// do so by copying the event to your own queued dispatch thread.
void dispatch_iohook_process(uiohook_event * const event) {
    char buffer[256] = { 0 };
    qDebug()<<"thread id for hook:"<<QThread::currentThreadId();
    size_t length = snprintf(buffer, sizeof(buffer),
            "id=%i,when=%" PRIu64 ",mask=0x%X",
            event->type, event->time, event->mask);

    switch (event->type) {
//    emit KeyboardListener::productive();
        case EVENT_KEY_PRESSED:
            // If the escape key is pressed, naturally terminate the program.
//        setState(ListenerState::productive);
        qDebug()<<"iohook magic";
            if (event->data.keyboard.keycode == VC_ESCAPE) {
                qDebug()<<"escape key pressed$$$$$";
                int status = hook_stop();
                switch (status) {
                    // System level errors.
                    case UIOHOOK_ERROR_OUT_OF_MEMORY:
//                        logger_proc(LOG_LEVEL_ERROR, "Failed to allocate memory. (%#X)", status);
                        break;

                    case UIOHOOK_ERROR_X_RECORD_GET_CONTEXT:
                        // NOTE This is the only platform specific error that occurs on hook_stop().
//                        logger_proc(LOG_LEVEL_ERROR, "Failed to get XRecord context. (%#X)", status);
                        break;
                case UIOHOOK_SUCCESS:
                    qDebug()<<"hook_stop success!!!!";
//                    status = hook_run();
                    // Default error.
                    case UIOHOOK_FAILURE:
                    default:
//                        logger_proc(LOG_LEVEL_ERROR, "An unknown hook error occurred. (%#X)", status);
                        break;
                }
            }
        case EVENT_KEY_RELEASED:
            snprintf(buffer + length, sizeof(buffer) - length,
                ",keycode=%u,rawcode=0x%X",
                event->data.keyboard.keycode, event->data.keyboard.rawcode);
            break;

        case EVENT_KEY_TYPED:
            snprintf(buffer + length, sizeof(buffer) - length,
                ",keychar=%lc,rawcode=%u",
                (wint_t) event->data.keyboard.keychar,
                event->data.keyboard.rawcode);
            break;

//        case EVENT_MOUSE_PRESSED:
//        case EVENT_MOUSE_RELEASED:
//        case EVENT_MOUSE_CLICKED:
//        case EVENT_MOUSE_MOVED:
//        case EVENT_MOUSE_DRAGGED:
//            snprintf(buffer + length, sizeof(buffer) - length,
//                ",x=%i,y=%i,button=%i,clicks=%i",
//                event->data.mouse.x, event->data.mouse.y,
//                event->data.mouse.button, event->data.mouse.clicks);
//            break;

//        case EVENT_MOUSE_WHEEL:
//            snprintf(buffer + length, sizeof(buffer) - length,
//                ",type=%i,amount=%i,rotation=%i",
//                event->data.wheel.type, event->data.wheel.amount,
//                event->data.wheel.rotation);
//            break;

        default:
            break;
    }

    fprintf(stdout, "%s\n",	 buffer);
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
    hook_set_dispatch_proc(dispatch_iohook_process);

    // Start the hook and block.
    // NOTE If EVENT_HOOK_ENABLED was delivered, the status will always succeed.
    int status = hook_run();
    const char *dev = activeKeyboardPath.toLocal8Bit().data();
    struct input_event ev;
    ssize_t n;
    int fd;
    //      emit unProductive();
    fd = open(dev, O_RDONLY);
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
