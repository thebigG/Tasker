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
}

void KeyboardListener::start()
{
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
            QThread::sleep(delay);
            qDebug()<<"key pressed";

        }
    }
    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return EXIT_FAILURE;
}
