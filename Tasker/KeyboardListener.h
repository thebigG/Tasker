#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H
#define LNUX_DEV_PATH "/dev/input/by-id"
#include <QtCore>
static const char *const evval[3] = {
    "RELEASED",
    "PRESSED ",
    "REPEATED"
};
namespace Engine
{
class KeyboardListener;
int startListening();

}

class Engine::KeyboardListener
{
public:
    KeyboardListener();
    static int startListening();
private:
    QString getKeyboardPathOnLinux();

};

#endif // KEYBOARDLISTENER_H
