#include "Hook.h"
#include <QtDebug>

/**
 * @brief Engine::Engine::Hook::Hook
 */
Engine::Hook::Hook() { state = Engine::Hook::HookState::unproductive; }

QDataStream &operator<<(QDataStream &out,
                        const Engine::Hook::HookType &newListener) {
  out << int(newListener);
  return out;
}

QDataStream &operator>>(QDataStream &in, Engine::Hook::HookType &newHook) {
  int enumValue = 0;
  in >> enumValue;
  newHook = Engine::Hook::intToHookType(enumValue);
  return in;
}

/**
 * @brief Engine::Hook::intToHookType safely converts an integer into a HookType
 * enum.
 * @param enumInt Integer to convert.
 * @return A HookType enum that was represented by enumInt
 */
Engine::Hook::HookType Engine::Hook::intToHookType(int enumInt) {
  if (int(HookType::X_MOUSE_KEYBOARD) < enumInt ||
      int(HookType::none) > enumInt)
    return HookType(enumInt);
  return HookType::none;
}

/**
 * @brief Engine::Hook::~Hook
 */
Engine::Hook::~Hook() {}

/**
 * @brief Engine::Engine::Hook::setState
 * @param state HookState, unproductive or productive
 * This method emits the productive or unProductive signal,
 * depending on the state passed.
 */
void Engine::Hook::setState(Engine::Hook::HookState newState) {
  newState == HookState::productive ? emit productive() : emit unProductive();
  state = newState;
}

Engine::Hook::HookType Engine::Hook::getType() { return type; }
/**
 * @brief Engine::Engine::Hook::getState
 *        Returns current state of the Hook, unproductive or productive
 *
 * @return Engine::Engine::Hook::HookState::unproductive,
 *         or
 *         Engine::Engine::Hook::Engine::Hook::productive
 */
// Engine::Hook::HookState Engine::Hook::getState() { return state; }
