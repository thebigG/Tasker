#include <QApplication>
#include <QGuiApplication>
#include <QRegularExpression>
#include <QThread>
#include <QtCore>
#include <XListener.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
using namespace Engine;

XListener::XListener(Engine::XListenerMode newXMode) {
    XMode = newXMode;
    xHook.setParent(this);
    switch (XMode) {
    case XListenerMode::MOUSE_AND_KEYBOARD:
        qDebug()<<"X#1";
        xHookArguments << IOHOOK_KEYBOARD_AND_MOUSE_MODE;
        break;
    case XListenerMode::MOUSE:
        xHookArguments << IOHOOK_MOUSE_MODE;
        qDebug()<<"X#2";
        break;
    case XListenerMode::KEYBOARD:
        xHookArguments << IOHOOK_KEYBOARD_MODE;
        qDebug()<<"X#3";
        break;
    }
    connect(&xHook, &QProcess::readyReadStandardOutput, this, &XListener::update);

}
/**
 * @brief XListener::XListener
 */
XListener::XListener() {
    XMode = XListenerMode::MOUSE_AND_KEYBOARD;
    xHook.setParent(this);
    xHookArguments << IOHOOK_KEYBOARD_AND_MOUSE_MODE;
    connect(&xHook, &QProcess::readyReadStandardOutput, this, &XListener::update);
#ifdef Q_OS_LINUX

#endif // setKeyboardPathsOnLinux
}

/**
 * @brief KeyboardListener::start
 */
void XListener::start() {
    qDebug() << "start function :)";
    qDebug() << "current thread id keyBoardListner class:" << QThread::currentThreadId();
    startListening();
}

/**
 * @brief KeyboardListener::end
 */
void XListener::end() {
    xHook.kill();
}

/**
 * @brief KeyboardListener::pause
 */
void XListener::pause() {

}

/**
 * @brief KeyboardListener::update
 */
void XListener::update() {
    QByteArray Xdata = xHook.readAllStandardOutput();
    qDebug()<<"update XHook";
    Xdata.chop(Xdata.length()-1);
    QString iohookState{Xdata};

    qDebug()<<"X state="<<iohookState;
    if(XMode == XListenerMode::MOUSE_AND_KEYBOARD &&  iohookState == IOHOOK_KEYBOARD_AND_MOUSE_MODE)
    {
    setState(ListenerState::productive);
    }
    else if(XMode == XListenerMode::MOUSE &&  iohookState == IOHOOK_MOUSE_MODE)
    {
        setState(ListenerState::productive);
    }
    else if(XMode == XListenerMode::KEYBOARD &&  iohookState == IOHOOK_KEYBOARD_MODE)
    {
            setState(ListenerState::productive);
    }
    else
    {
        qDebug()<<"INVALID MODE from IOHOOK***";
    }
}

/**
 * @brief KeyboardListener::listen
 * @return
 */
Listener::ListenerState XListener::listen() {

    return getState();
}
void XListener::resetState() {
    setState(ListenerState::unproductive);
}

int XListener::startListening() {
    setState(ListenerState::unproductive);
    connect(qApp, &QGuiApplication::lastWindowClosed, this, &XListener::end);
    xHook.start(IOHOOK_SCRIPT_PATH, xHookArguments);
    qDebug() << "startListening{yes}-->threadid" << QThread::currentThreadId();
    return EXIT_FAILURE;
}
/**

*/
