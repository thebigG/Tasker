#ifndef LISTENER_H
#define LISTENER_H

#include <QDataStream>
#include <QFile>
#include <QObject>
#include <QThread>
#include <cstdint>
namespace Engine {
/**
 * @brief The Engine::Hook class is the base class for all of the hooks on
 * Tasker. It provides a stateful(with productive and unproductive states)
 * interface that any child class may extend and build upon.
 */
class Hook : public QObject {
  Q_OBJECT
public:
  enum class HookState { unproductive, productive };
  /**
   * @brief The HookType enum
   * This enum used for Timer to know which listener it is going to instantiate
   * @note If, for whatever reason, we decide to add HookType values make
   * sure to add them BEFORE none. The none type is used for bounds
   * checking.
   */
  enum class HookType { X_MOUSE_KEYBOARD, X_MOUSE, X_KEYBOARD, audio, none };
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
  static HookType intToHookType(int enumToInt);
  virtual Hook::HookState startHook() = 0;
  virtual void setState(HookState);
  virtual HookState getState() = 0;

protected:
  /**
   * @brief state
   */
  Hook::HookState state;

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
};
} // namespace Engine

QDataStream &operator<<(QDataStream &out,
                        const Engine::Hook::HookType &newHook);
/**
 * @brief operator >> Loads the newHook from disk onto memory.
 * @param in
 * @param newListener
 * @return
 */
QDataStream &operator>>(QDataStream &in, Engine::Hook::HookType &newHook);
#endif // LISTENER_H
