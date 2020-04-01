#include "Listener.h"
#include <QtDebug>
using namespace Engine;

/**
 * @brief Engine::Listener::Listener
 *        default constructor
 */
Listener::Listener() { state = Listener::ListenerState::unproductive; }
QDataStream &Engine::operator<<(QDataStream &out,
                                const Listener::ListenerType &newListener) {
  out << int(newListener);
  return out;
}
/**
 * @brief Listener::intToListenerType
 * @param enumInt
 * @return
 */
Listener::ListenerType Listener::intToListenerType(int enumInt) {
  if (int(ListenerType::X_MOUSE_KEYBOARD) < enumInt ||
      int(ListenerType::none) > enumInt)
    return ListenerType(enumInt);
  return ListenerType::none;
}

/**
 * @brief Engine::Listener::~Listener
 *        destructor
 */
Listener::~Listener() {}

/**
 * @brief Engine::Listener::setState
 * @param state ListenerState, unproductive or productive
 * This method emits the productive or unProductive signal,
 * depending on the state passed.
 */
void Listener::setState(Listener::ListenerState newState) {
  newState == ListenerState::productive ? emit productive()
                                        : emit
                                          unProductive();
  state = newState;
}

/**
 * @brief Engine::Listener::getState
 *        Returns current state of Listener, unproductive or productive
 *
 * @return Engine::Listener::ListenerState::unproductive,
 *         or
 *         Engine::Listener::ListenerState::productive
 */
Listener::ListenerState Listener::getState() { return state; }
