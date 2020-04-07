#ifndef LISTENER_H
#define LISTENER_H

#include <QDataStream>
#include <QFile>
#include <QObject>
#include <QThread>
#include <cstdint>
#define BASE_DELAY 2
namespace Engine {
class Hook;
enum class ListenerType;
QDataStream &operator<<(QDataStream &out, const ListenerType &newListener);
QDataStream &operator>>(QDataStream &in, ListenerType &newListener);
} // namespace Engine

/**
 * @brief Engine::Hook class
 */
class Engine::Hook : public QObject {
  Q_OBJECT
public:
  enum class HookState { unproductive, productive };
  /**
   * @brief The HookType enum
   * This enum used for Timer to know which listener it is going to instantiate
   * @note If, for whatever reason, we decide to add HookType values make
   * sure that to add them BEFORE none. The none type is used for bounds
   * checking.
   */
  enum class HookType {
    X_MOUSE_KEYBOARD,
    X_MOUSE,
    X_KEYBOARD,
    audio,
    none
  }; // I had to do this to make QThreads work

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

  // probably not needed...timer keeps track of live session time,
  // when session ends, session will grab this data from timer
  // to store permanently in Commitment
  uint64_t getProductiveTime();
  uint64_t getUnproductiveTime();

protected:
  Hook::HookState state;

private:
  double getCheckStateDelay();

  void setCheckStateDelay(double checkStateDelay);

  /**
   * @brief operator << I'm really sorry about this ugiliness. Apparently,
   * as far as I know, C++ wants me to do it this way in order to access private
   * members.
   * @param out
   * @param newTask
   * @return
   */
  friend QDataStream &operator<<(QDataStream &out, const HookType &newListener);
  /**
   * @brief operator >> I'm really sorry about this ugiliness. Apparently,
   * as far as I know, C++ wants me to do it this way in order to access private
   * members.
   * @param in
   * @param newTask
   * @return
   */
  friend QDataStream &operator>>(QDataStream &in, HookType &newListener) {
    int enumValue = 0;
    in >> enumValue;
    newListener = intToListenerType(enumValue);
    return in;
  }
  // public slots:
  //    void tickSlot();

signals:
  void productive();
  void unProductive();
};

#endif // LISTENER_H
