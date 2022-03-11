#ifndef XHOOK_H
#define XHOOK_H
#include <Hook.h>

#include <QtCore>
#include <memory>
namespace Engine {
enum class XHookMode { MOUSE, KEYBOARD, MOUSE_AND_KEYBOARD };
int run_xhook_engine(XHookMode mode);
class XHook;
enum class XHookMode;
} // namespace Engine

/**
 * @brief The Engine::XListener class
 *  This class has the capiblity of detecting mouse and keyboard
 * interaction.
 * @note Note that the detecion of mouse and keyboard input(globally
 * throughout the system) is made possible by the amazing libuiiohook library.
 * You can check out the library here https://github.com/kwhat/libuiohook
 */
class Engine::XHook : public Hook {
    Q_OBJECT

public:
    XHook();
    XHook(Engine::XHookMode);
    int startXHook();
    Hook::HookState startHook() override;
    virtual Hook::HookState getState() override;
    virtual void setState(HookState) override;

public slots:
    virtual void start() override;
    virtual void end() override;
    virtual void pause() override;
    virtual void update() override;
    virtual void resetState() override;

private:
    XHookMode XMode;
signals:
    void signalThread();
};

void hook();
#endif // XHOOK_H
