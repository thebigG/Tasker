#include "XHook.h"
#include "xhook_engine.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <QApplication>
#include <QGuiApplication>
#include <QRegularExpression>
#include <QThread>
#include <QtCore>
using namespace Engine;
/**
 * @brief XHook::XHook initializes this Xhook instance with the specified
 * XhookMode. It hooks all signals necessary to do IPC with the external Xhook
 * child process.
 * @param newXMode The mode(mouse, keyboard or both) this instance will be on.
 */
XHook::XHook(Engine::XHookMode newXMode) {
  XMode = newXMode;
  xChildHook.setParent(this);
  //  switch (XMode) {
  //  case XHookMode::MOUSE_AND_KEYBOARD:
  //    xChildHookArguments << IOHOOK_KEYBOARD_AND_MOUSE_MODE;
  //    break;
  //  case XHookMode::MOUSE:
  //    xChildHookArguments << IOHOOK_MOUSE_MODE;
  //    break;
  //  case XHookMode::KEYBOARD:
  //    xChildHookArguments << IOHOOK_KEYBOARD_MODE;
  //    break;
  //  }
  connect(&xChildHook, &QProcess::readyReadStandardOutput, this,
          &XHook::update);
  connect(&xChildHook, &QProcess::errorOccurred, this,
          [=](QProcess::ProcessError e) { qDebug() << "error code=" << e; });
  connect(&xChildHook, &QProcess::readyReadStandardError, this, [=]() {
    QByteArray errorData = this->xChildHook.readAllStandardError();
    qDebug() << "Error on Xhook process:" << QString{errorData};
  });
}
/**
 * @brief XHook::XHook initializes this Xhook instance on keyboard_and_mouse
 * mode. It hooks all signals necessary to do IPC with the external Xhook child
 * process.
 * @param newXMode The mode(mouse, keyboard or both) this instance will be on.
 */
XHook::XHook() {
  XMode = XHookMode::MOUSE_AND_KEYBOARD;
  xChildHook.setParent(this);
  //  xChildHookArguments << IOHOOK_KEYBOARD_AND_MOUSE_MODE;
  connect(&xChildHook, &QProcess::readyReadStandardOutput, this,
          &XHook::update);
  connect(&xChildHook, &QProcess::errorOccurred, this,
          [=](QProcess::ProcessError e) { qDebug() << "error code=" << e; });
  connect(&xChildHook, &QProcess::readyReadStandardError, this, [=]() {
    QByteArray errorData = this->xChildHook.readAllStandardError();
    qDebug() << "Error on Xhook process:" << QString{errorData};
  });
}
/**
 * @brief XHook::start
 */
void XHook::start() { startXHook(); }

/**
 * @brief XHook::end kills the XListenerHook process.
 */
void XHook::end() { xChildHook.kill(); }

/**
 * @brief XHook::pause Does nothing.
 */
void XHook::pause() {}

/**
 * @brief  XHook::update
 * This method is called every time xHook process writes to standrd output.
 * It's essentially IPC.
 *
 */
void XHook::update() {
  //    current_mode = 12;
  QByteArray Xdata = xChildHook.readAllStandardOutput();
  qDebug() << "update for Xhook...";
  Xdata.chop(Xdata.length() - 1);
  QString iohookState{Xdata};
  if (XMode == XHookMode::MOUSE_AND_KEYBOARD &&
      iohookState == IOHOOK_KEYBOARD_AND_MOUSE_MODE) {
    setState(HookState::productive);
  } else if (XMode == XHookMode::MOUSE && iohookState == IOHOOK_MOUSE_MODE) {
    setState(HookState::productive);
  } else if (XMode == XHookMode::KEYBOARD &&
             iohookState == IOHOOK_KEYBOARD_MODE) {
    setState(HookState::productive);
  } else {
  }
}

/**
 * @brief XHook::startHook
 * @return
 */
Hook::HookState XHook::startHook() { return getState(); }
void XHook::resetState() { setState(HookState::unproductive); }

/**
 * @brief XListener::startXHook
 * Spawn process which is a hardware hook for mouse, keyboard or both
 * @return 0 on success. Error codes to be implemented.
 */
int XHook::startXHook() {
  setState(HookState::unproductive);

  run_xhook_engine(IOHOOK_KEYBOARD_MODE);

  return 0;
}
