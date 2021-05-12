#include "Hook.h"

int initJackClient(std::string clientName);
namespace Jack {
class JackHook;
} // namespace Jack

class Jack::JackHook : public Engine::Hook {};
