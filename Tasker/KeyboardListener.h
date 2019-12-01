#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H
#define LNUX_DEV_PATH "/dev/input/by-id/"
#define LINUX_KEYBOARD_PATH_KEYWORD "-kbd" //This is used for regular expression matching
#include <QtCore>
#include <Listener.h>
static const char *const evval[3] = {
    "RELEASED",
    "PRESSED ",
    "REPEATED"
};
namespace Engine
{
class KeyboardListener;
}

class Engine::KeyboardListener: public Listener
{
    Q_OBJECT
public:
    enum class KeyboardListenerState{ON,OFF};
public:
    KeyboardListener();
    int startListening(unsigned long int delay =30);
    Listener::ListenerState listen();
public slots:
    virtual void start();
    virtual void end();
    virtual void pause();
    virtual void run();
    virtual void update();
private:
    QString activeKeyboardPath;
    KeyboardListenerState engineState;
    void setKeyboardPathsOnLinux(int deviceIndex = 0);
    QVector<QString> keyboardPaths;
    const QString objectName = "KeyboardListener";
signals:
    void signalThread();
};

#endif // KEYBOARDLISTENER_H
