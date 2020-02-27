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
    nodeJS.setParent(this);
    nodeJSArguments << IOHOOK_SCRIPT_PATH;
    switch (XMode) {
    case XListenerMode::MOUSE_AND_KEYBOARD:
        qDebug()<<"X#1";
        nodeJSArguments << IOHOOK_KEYBOARD_AND_MOUSE_MODE;
        break;
    case XListenerMode::MOUSE:
        nodeJSArguments << IOHOOK_MOUSE_MODE;
        qDebug()<<"X#1";
        break;
    case XListenerMode::KEYBOARD:
        nodeJSArguments << IOHOOK_KEYBOARD_MODE;
        break;
    }
    connect(&nodeJS, &QProcess::readyReadStandardOutput, this, &XListener::checkXState);

}
/**
 * @brief XListener::XListener
 */
XListener::XListener() {
    XMode = XListenerMode::MOUSE_AND_KEYBOARD;
    nodeJS.setParent(this);
    nodeJSArguments << IOHOOK_KEYBOARD_AND_MOUSE_MODE;
    connect(&nodeJS, &QProcess::readyReadStandardOutput, this, &XListener::checkXState);
#ifdef Q_OS_LINUX

#endif // setKeyboardPathsOnLinux
}
void XListener::checkXState() {
    QByteArray Xdata = nodeJS.readAllStandardOutput();
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
    nodeJS.kill();
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
    nodeJS.start("node", nodeJSArguments);
    qDebug() << "startListening{yes}-->threadid" << QThread::currentThreadId();
    return EXIT_FAILURE;
}
/**

*/
