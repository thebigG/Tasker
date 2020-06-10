#include <XHook.h>
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

XHook::XHook(Engine::XHookMode newXMode) {
  XMode = newXMode;
  xChildHook.setParent(this);
  switch (XMode) {
  case XHookMode::MOUSE_AND_KEYBOARD:
    xChildHookArguments << IOHOOK_KEYBOARD_AND_MOUSE_MODE;
    break;
  case XHookMode::MOUSE:
    xChildHookArguments << IOHOOK_MOUSE_MODE;
    break;
  case XHookMode::KEYBOARD:
    xChildHookArguments << IOHOOK_KEYBOARD_MODE;
    break;
  }
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
 * @brief XHook::XHook
 */
XHook::XHook() {
  XMode = XHookMode::MOUSE_AND_KEYBOARD;
  xChildHook.setParent(this);
  xChildHookArguments << IOHOOK_KEYBOARD_AND_MOUSE_MODE;
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
 * @brief XHook::end
 */
void XHook::end() { xChildHook.kill(); }

/**
 * @brief XHook::pause
 */
void XHook::pause() {}

/**
 * @brief  XHook::update
 * This method is called every time xHook process writes to standrd output.
 * It's essentially IPC.
 *
 */
void XHook::update() {
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
 * @brief XHook::listen
 * @return
 */
Hook::HookState XHook::startHook() { return getState(); }
void XHook::resetState() { setState(HookState::unproductive); }

/**
 * @brief XListener::startListening
 * Spawn process which is a hardware hook for mouse, keyboard or both
 * @return
 */
int XHook::startXHook() {
  setState(HookState::unproductive);

  xChildHook.setWorkingDirectory(WORKDIR);
  // Kill xHook process when this process ends
  connect(qApp, &QGuiApplication::lastWindowClosed, this, &XHook::end);
  xChildHook.start(IOHOOK_SCRIPT_PATH, xChildHookArguments);
  qDebug() << "path=" << IOHOOK_SCRIPT_PATH;
  qDebug() << "current path=" << QCoreApplication::applicationDirPath();
  xChildHook.waitForStarted();
  switch (xChildHook.state()) {
  case QProcess::NotRunning:
    qDebug() << "Not running";
    break;
  case QProcess::Running:
    qDebug() << "Running";
    break;
  case QProcess::Starting:
    qDebug() << "Starting";
  }
  qDebug() << "started Xhook??";
  return 0;
}
/**

*/
