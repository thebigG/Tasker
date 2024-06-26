#ifndef HOOK_H
#define HOOK_H

#include <QDataStream>
#include <QFile>
#include <QObject>
#include <QThread>
#include <cstdint>
#include <exception>
namespace Engine {
/**
 * @brief The Engine::Hook class is the base class for all of the hooks on
 * Tasker. It provides a stateful(with productive and unproductive states)
 * interface that any child class may extend and build upon.
 */
class Hook : public QObject {
    Q_OBJECT
public:
    class HookError {
    public:
        enum class HookErrorStatus { FAIL, SUCCESS };
        HookError(std::string msg, HookErrorStatus newStatus) {
            newMsg = msg;
            status = newStatus;
        }
        virtual const std::string what() const {
            return newMsg;
        }

        virtual const HookErrorStatus getStatus() {
            return status;
        }

    private:
        std::string newMsg;
        HookErrorStatus status;
    };
    enum class HookState { unproductive, productive, started, paused, ended };
    /**
     * @brief The HookType enum
     * This enum used for Timer to know which hook it is going to instantiate
     * @note If, for whatever reason, we decide to add HookType values make
     * sure to add them BEFORE none. The none type is used for bounds
     * checking.
     */
    enum class HookType { UDP_HOOOK, X_MOUSE_KEYBOARD, X_MOUSE, X_KEYBOARD, AUDIO, NONE };
    Hook();
    ~Hook();
    /**
     * @brief start Up to the child to define, but it is usually whatever the
     * class considers thet "start" of the hook, whether that'd be mic or
     * keyboard device.
     *
     */
    virtual void start() = 0;
    /**
     * @brief end Up to the child to define, but this method usually cleans up
     * and gives back resources to the system after a hook is done. For example,
     * in Xhook, part of this cleanup process will involve killing the
     * XListenerHook process gracefully.
     */
    virtual void end() = 0;
    /**
     * @brief pause Up to the child to define, but pause could be useful in a
     * situation where the audio hardware device needs to be swapped for another
     * one at runtime without killing the AudioHook completely.
     */
    virtual void pause() = 0;
    /**
     * @brief update This could be used for updating any state(such as a new
     * audio device) when the hook is pause.
     */
    virtual void update() = 0;
    /**
     * @brief resetState Up to the child, but this usually just sets the current
     * state of the hook to Unproductive.
     */
    virtual void resetState() = 0;

    /**
     * @brief configure.
     * @todo This should return some indication about whether
     * the configuration of the hook was sucessful or not.
     */
    virtual HookError configure() {
        return HookError{ "Success", HookError::HookErrorStatus::SUCCESS };
    };
    static HookType intToHookType(int enumToInt);
    virtual Hook::HookState startHook() = 0;
    virtual void setState(HookState);
    virtual HookState getState() = 0;
    virtual HookType getType();

protected:
    /**
     * @brief state
     */
    Hook::HookState state;
    HookType type;

private:
    /**
     * @brief operator << Writes the newHook to disk.
     * @param out
     * @param newHook
     * @return
     */

signals:
    void productive();
    void unProductive();
    void hookUpdate();
    void hookError(HookError e);
};
} // namespace Engine

QDataStream &operator<<(QDataStream &out, const Engine::Hook::HookType &newHook);
/**
 * @brief operator >> Loads the newHook from disk onto memory.
 * @param in
 * @param newListener
 * @return
 */
QDataStream &operator>>(QDataStream &in, Engine::Hook::HookType &newHook);
#endif // HOOK_H
