#ifndef LISTENER_H
#define LISTENER_H

#include <QDataStream>
#include <QFile>
#include <QObject>
#include <QThread>
#include <cstdint>
namespace Engine {
class Hook;
enum class HookType;
} // namespace Engine
/**
 * @brief The Engine::Hook class is the base class for all of the hooks on
 * Tasker. It provides a stateful(with productive and unproductive states)
 * interface that any child class may extend and build upon.
 */
class Engine::Hook : public QObject {
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

public:
  Hook();
  ~Hook();
  virtual void start() = 0;
  virtual void end() = 0;
  virtual void pause() = 0;
  virtual void update() = 0;
  virtual void resetState() = 0;
  static HookType intToListenerType(int enumToInt);
  virtual Hook::HookState startHook() = 0;
  void setState(HookState);
  HookState getState();

protected:
  Hook::HookState state;

private:
  /**
   * @brief operator <<
   * @param out
   * @param newListener
   * @return
   */
  friend QDataStream &operator<<(QDataStream &out, const HookType &newListener);
  /**
   * @brief operator >>
   * @param in
   * @param newListener
   * @return
   */
  friend QDataStream &operator>>(QDataStream &in, HookType &newListener);

signals:
  void productive();
  void unProductive();
};

#endif // LISTENER_H
