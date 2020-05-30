#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H
#include <Hook.h>
#include <QtCore>
#if defined(Q_OS_LINUX)
#ifdef __TASKER_DEBUG__
#define IOHOOK_SCRIPT_PATH "../libs/linux/iohook/XListenerHook"
#else
#define IOHOOK_SCRIPT_PATH "./XListenerHook"
#endif
#endif
#if defined(Q_OS_OSX)
#define IOHOOK_SCRIPT_PATH "../Resources/XListenerHook"
#endif
#if defined(Q_OS_WIN)
#define IOHOOK_SCRIPT_PATH "../libs/windows/iohook/XListenerHook"
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
