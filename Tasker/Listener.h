#ifndef LISTENER_H
#define LISTENER_H

#include <cstdint>
#include <QThread>
#include <QObject>
#include <QFile>
#include <QDataStream>
namespace Engine {
    class Listener;
}

class Engine::Listener : public QObject {
    Q_OBJECT
public:
    enum class ListenerState { unproductive, productive };
    /**
     * @brief The ListenerType enum
     * This enum used for Timer to know which listener it is going to instantiate
     * @note If, for whatever reason, we decide to add ListenerType values make
     * sure that to add them BEFORE none. The none type is used for bounds checking.
     */
    enum class ListenerType{keyboard,audio, none};    //I had to do this to make QThreads work

protected:
    Listener();
    virtual ~Listener();
<<<<<<< HEAD

protected:
    double getCheckStateDelay();

    void setCheckStateDelay(double checkStateDelay);
    void setState(Listener::ListenerState state);

    // probably not needed...timer keeps track of live session time,
    // when session ends, session will grab this data from timer
    // to store permanently in Commitment
    void setProductiveTime(uint64_t productiveTime);
    void setUnproductiveTime(uint64_t unproductiveTime);

public:
=======
>>>>>>> master
    virtual void start() = 0;
    virtual void end() = 0;
    virtual void pause() = 0;
    virtual void update() = 0;
<<<<<<< HEAD
    virtual Listener::ListenerState listen() = 0;

public:
=======
    static ListenerType intToListenerType(int enumToInt);
    virtual Listener::ListenerState listen() = 0;
    ListenerState currentState;
    double getSlack();
    void setState(ListenerState);
    ListenerState getState();

>>>>>>> master
    // probably not needed...timer keeps track of live session time,
    // when session ends, session will grab this data from timer
    // to store permanently in Commitment
    uint64_t getProductiveTime();
    uint64_t getUnproductiveTime();

    double getSlack();
    void setSlack(double slack);

    Listener::ListenerState getState();

protected:
    double checkStateDelay;
    double slack;

    // probably not needed...timer keeps track of live session time,
    // when session ends, session will grab this data from timer
    // to store permanently in Commitment
    uint64_t productiveTime;
    uint64_t unproductiveTime;

    Listener::ListenerState state;
<<<<<<< HEAD
=======

    void setCheckStateDelay(double checkStateDelay);

    // probably not needed...timer keeps track of live session time,
    // when session ends, session will grab this data from timer
    // to store permanently in Commitment
    void setProductiveTime(uint64_t productiveTime);
    void setUnproductiveTime(uint64_t unproductiveTime);
    /**
 * @brief operator << I'm really sorry about this ugiliness. Apparently,
 * as far as I know, C++ wants me to do it this way in order to access private members.
 * @param out
 * @param newTask
 * @return
 */
friend QDataStream& operator<<(QDataStream &out, const ListenerType &newListener)
{
    out<<int(newListener);
    return out;
}
/**
* @brief operator >> I'm really sorry about this ugiliness. Apparently,
* as far as I know, C++ wants me to do it this way in order to access private members.
* @param in
* @param newTask
* @return
*/
friend QDataStream& operator>>(QDataStream &in, ListenerType &newListener)
{
    int enumValue = 0;
    in >> enumValue;
    newListener = intToListenerType(enumValue);
    return in;
}
>>>>>>> master
};

#endif // LISTENER_H
