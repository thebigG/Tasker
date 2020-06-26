#include "Hook.h"
#include <QtDebug>
using namespace Engine;

/**
 * @brief Engine::Hook::Hook
 */
Hook::Hook() { state = Hook::HookState::unproductive; }
QDataStream &Engine::operator<<(QDataStream &out,
                                const Hook::HookType &newListener) {
  out << int(newListener);
  return out;
}
QDataStream &Engine::operator>>(QDataStream &in, Hook::HookType &newHook) {
  int enumValue = 0;
  in >> enumValue;
  newHook = Engine::Hook::intToHookType(enumValue);
  return in;
}
/**
 * @brief Hook::intToHookType safely converts an integer into a HookType
 * enum.
 * @param enumInt Integer to convert.
 * @return A HookType enum that was represented by enumInt
 */
Hook::HookType Hook::intToHookType(int enumInt) {
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
