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
    xHookArguments << IOHOOK_KEYBOARD_AND_MOUSE_MODE;
    break;
  case XListenerMode::MOUSE:
    xHookArguments << IOHOOK_MOUSE_MODE;
    break;
  case XListenerMode::KEYBOARD:
    xHookArguments << IOHOOK_KEYBOARD_MODE;
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
}

/**
 * @brief KeyboardListener::start
 */
void XListener::start() { startListening(); }

/**
 * @brief KeyboardListener::end
 */
void XListener::end() { xHook.kill(); }

/**
 * @brief KeyboardListener::pause
 *
 */
void XListener::pause() {}

/**
 * @brief KeyboardListener::update
 * This method is called every time xHook process writes to standrd output.
 * It's essentially IPC.
 *
 */
void XListener::update() {
  QByteArray Xdata = xHook.readAllStandardOutput();
  Xdata.chop(Xdata.length() - 1);
  QString iohookState{Xdata};
  if (XMode == XListenerMode::MOUSE_AND_KEYBOARD &&
      iohookState == IOHOOK_KEYBOARD_AND_MOUSE_MODE) {
    setState(ListenerState::productive);
  } else if (XMode == XListenerMode::MOUSE &&
             iohookState == IOHOOK_MOUSE_MODE) {
    setState(ListenerState::productive);
  } else if (XMode == XListenerMode::KEYBOARD &&
             iohookState == IOHOOK_KEYBOARD_MODE) {
    setState(ListenerState::productive);
  } else {
  }
}

/**
 * @brief KeyboardListener::listen
 * @return
 */
Listener::ListenerState XListener::listen() { return getState(); }
void XListener::resetState() { setState(ListenerState::unproductive); }

/**
 * @brief XListener::startListening
 * Spawn process which is a hardware hook for mouse, keyboard or both
 * @return
 */
int XListener::startListening() {
  setState(ListenerState::unproductive);
  // Kill xHook process when this process ends
  connect(qApp, &QGuiApplication::lastWindowClosed, this, &XListener::end);
  xHook.start(IOHOOK_SCRIPT_PATH, xHookArguments);
  return 0;
}
/**

*/
