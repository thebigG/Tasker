#ifndef LISTENER_H
#define LISTENER_H

#include <cstdint>

namespace Engine {
    class Listener;
}

class Engine::Listener {
public:
    enum class ListenerState { unproductive, productive };

public:
    Listener();
    virtual ~Listener();

    virtual void start() = 0;
    virtual void end() = 0;
    virtual void pause() = 0;
    virtual void update() = 0;

    virtual Listener::ListenerState listen() = 0;
    ListenerState currentState;
    double getSlack();
    void setState(ListenerState);
    ListenerState getState();

    // probably not needed...timer keeps track of live session time,
    // when session ends, session will grab this data from timer
    // to store permanently in Commitment
    uint64_t getProductiveTime();
    uint64_t getUnproductiveTime();

    void setSlack(double slack);
private:
    double checkStateDelay;
    double slack;

    // probably not needed...timer keeps track of live session time,
    // when session ends, session will grab this data from timer
    // to store permanently in Commitment
    uint64_t productiveTime;
    uint64_t unproductiveTime;

    double getCheckStateDelay();

    Listener::ListenerState state;

    void setCheckStateDelay(double checkStateDelay);

    // probably not needed...timer keeps track of live session time,
    // when session ends, session will grab this data from timer
    // to store permanently in Commitment
    void setProductiveTime(uint64_t productiveTime);
    void setUnproductiveTime(uint64_t unproductiveTime);
};

#endif // LISTENER_H
