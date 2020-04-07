#include "Hook.h"
#include <QtDebug>
using namespace Engine;

/**
 * @brief Engine::Hook::Hook
 *        default constructor
 */
Hook::Hook() { state = Hook::HookState::unproductive; }
QDataStream &Engine::operator<<(QDataStream &out,
                                const Hook::HookType &newListener) {
  out << int(newListener);
  return out;
}
/**
 * @brief Hook::intToListenerType
 * @param enumInt
 * @return
 */
Hook::HookType Hook::intToListenerType(int enumInt) {
  if (int(HookType::X_MOUSE_KEYBOARD) < enumInt ||
      int(HookType::none) > enumInt)
    return HookType(enumInt);
  return HookType::none;
}
/**
 * @brief Hook::~Hook
 */
Hook::~Hook() {}

/**
 * @brief Engine::Hook::setState
 * @param state HookState, unproductive or productive
 * This method emits the productive or unProductive signal,
 * depending on the state passed.
 */
void Hook::setState(Hook::HookState newState) {
  newState == HookState::productive ? emit productive() : emit unProductive();
  state = newState;
}

/**
 * @brief Engine::Hook::getState
 *        Returns current state of the Hook, unproductive or productive
 *
 * @return Engine::Hook::HookState::unproductive,
 *         or
 *         Engine::Hook::Hook::productive
 */
Hook::HookState Hook::getState() { return state; }
