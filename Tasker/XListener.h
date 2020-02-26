#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H
#include <Listener.h>
#include <QtCore>
#define IOHOOK_SCRIPT_PATH "../libs/iohook/iohook.js"
#define IOHOOK_MOUSE_MODE "m"
#define IOHOOK_KEYBOARD_MODE "k"
#define IOHOOK_KEYBOARD_AND_MOUSE_MODE "mk"
namespace Engine {
class XListener;
enum class XListenerMode;
}

enum class Engine::XListenerMode
{
MOUSE, KEYBOARD, MOUSE_AND_KEYBOARD
};
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
    void checkXState();
private:
    QProcess nodeJS;
    QStringList nodeJSArguments;
    XListenerMode XMode;

signals:
    void signalThread();
};

void hook();
#endif // KEYBOARDLISTENER_H
