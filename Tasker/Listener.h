#ifndef LISTENER_H
#define LISTENER_H

#include <cstdint>

namespace Engine {
    class Listener;
}

class Engine::Listener {
public:
    enum class ListenerState { unproductive, productive };

protected:
    Listener();
    virtual ~Listener();

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
    virtual void start() = 0;
    virtual void end() = 0;
    virtual void pause() = 0;
    virtual void update() = 0;
    virtual Listener::ListenerState listen() = 0;

public:
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
};

#endif // LISTENER_H
