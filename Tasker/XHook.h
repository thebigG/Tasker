#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H
#include <Hook.h>
#include <QtCore>
#include <memory>
#ifdef __TASKER_DEBUG__
#if defined(Q_OS_LINUX)
#define IOHOOK_SCRIPT_PATH "./XListenerHook"
#define WORKDIR "../libs/linux/iohook"
#elif defined(Q_OS_OSX)
#define IOHOOK_SCRIPT_PATH "./run_hook.sh"
#define WORKDIR "./Contents/iohook"
#elif defined(Q_OS_WIN)
#define IOHOOK_SCRIPT_PATH "./run_hook.sh"
#define WORKDIR "./Contents/iohook"
#endif
#else
#if defined(Q_OS_LINUX)
#define IOHOOK_SCRIPT_PATH "./XListenerHook"
#define WORKDIR QCoreApplication::applicationDirPath()
#elif defined(Q_OS_OSX)
#define IOHOOK_SCRIPT_PATH "./XListenerHook"
#define WORKDIR QCoreApplication::applicationDirPath() + "/../Frameworks/iohook"
#elif defined(Q_OS_WIN)
#define IOHOOK_SCRIPT_PATH "./XListenerHook"
#define WORKDIR QCoreApplication::applicationDirPath()
#endif
#endif
#define IOHOOK_MOUSE_MODE "0"
#define IOHOOK_KEYBOARD_MODE "1"
#define IOHOOK_KEYBOARD_AND_MOUSE_MODE "2"
#define IOHOOK_MOUSE_DRAGGED "3"
namespace Engine {
class XHook;
enum class XHookMode;
} // namespace Engine

enum class Engine::XHookMode { MOUSE, KEYBOARD, MOUSE_AND_KEYBOARD };
/**
 * @brief The Engine::XListener class
 * This class has the capiblity of detecting mouse and keyboard interaction.
 */
class Engine::XHook : public Hook {
  Q_OBJECT

public:
  XHook();
  XHook(Engine::XHookMode);
  int startXHook();
  Hook::HookState startHook() override;

public slots:
  virtual void start() override;
  virtual void end() override;
  virtual void pause() override;
  virtual void update() override;
  virtual void resetState() override;

private:
  QProcess xChildHook;
  QStringList xChildHookArguments;
  XHookMode XMode;
signals:
  void signalThread();
};

void hook();
#endif // KEYBOARDLISTENER_H
