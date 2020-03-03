#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H
#include <Listener.h>
#include <QtCore>
#if defined(Q_OS_LINUX)
#define IOHOOK_SCRIPT_PATH "../libs/linux/iohook/XListenerHook"
#endif
#if defined(Q_OS_OSX)
#define IOHOOK_SCRIPT_PATH "../libs/macOS/iohook/XListenerHook"
#endif
#if defined(Q_OS_WIN)
#define IOHOOK_SCRIPT_PATH "../libs/windows/iohook/XListenerHook"
#endif
#define IOHOOK_MOUSE_MODE "0"
#define IOHOOK_KEYBOARD_MODE "1"
#define IOHOOK_KEYBOARD_AND_MOUSE_MODE "2"
#define IOHOOK_MOUSE_DRAGGED "3"
namespace Engine {
class XListener;
enum class XListenerMode;
} // namespace Engine

enum class Engine::XListenerMode { MOUSE, KEYBOARD, MOUSE_AND_KEYBOARD };
/**
 * @brief The Engine::XListener class
 * This class has the capiblity of detecting mouse and keyboard interaction.
 */
class Engine::XListener : public Listener {
    Q_OBJECT

public:
    XListener();
    XListener(Engine::XListenerMode);
    int startListening();
    Listener::ListenerState listen() override;

public slots:
    virtual void start() override;
    virtual void end() override;
    virtual void pause() override;
    virtual void update() override;
    virtual void resetState() override;

private:
    QProcess xHook;
    QStringList xHookArguments;
    XListenerMode XMode;

signals:
    void signalThread();
};

void hook();
#endif // KEYBOARDLISTENER_H
