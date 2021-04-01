#ifndef XHOOK_ENGINE_H
#define XHOOK_ENGINE_H

#define IOHOOK_MOUSE_MODE 0
#define IOHOOK_KEYBOARD_MODE 1
#define IOHOOK_KEYBOARD_AND_MOUSE_MODE 2
#define IOHOOK_MOUSE_DRAGGED 3

#include <stdint.h>
#include <uiohook.h>

namespace Engine {
// I don't think making this class will work because I don't think emit signals
// from C free functions.
// class XhookEngine {
//  int run();
//  XhookEngine(uint32_t mode);
//  uint32_t current_mode = 0;
//};
int run_xhook_engine(int mode);
} // namespace Engine

#endif // XHOOK_ENGINE_H
