#include "Listener.h"

/**
 * @brief Engine::Listener::Listener
 *        default constructor
 */
Engine::Listener::Listener() : checkStateDelay(0.0),
                               slack(0.0),
                               productiveTime(0.0),
                               unproductiveTime(0.0) {

}

/**
 * @brief Engine::Listener::~Listener
 *        destructor
 */
Engine::Listener::~Listener() {
    checkStateDelay = 0.0;
    slack = 0.0;

    productiveTime = 0;
    unproductiveTime = 0;
}

/**
 * @brief Engine::Listener::getCheckStateDelay
 *        determines how long between one invocation of listen() and the next
 *
 * @return checkStateDelay, in seconds
 */
double Engine::Listener::getCheckStateDelay() {
    return checkStateDelay;
}

/**
 * @brief Engine::Listener::setCheckStateDelay
 *        set how long between one invocation of listen() and the next
 *
 * @param checkStateDelay   checkStateDelay value, in seconds
 */
void Engine::Listener::setCheckStateDelay(double checkStateDelay) {
    this->checkStateDelay = (checkStateDelay < 0.0)
            ? this->checkStateDelay : checkStateDelay;
}

/**
 * @brief Engine::Listener::setState
 *
 * @param state ListenerState, unproductive or productive
 */
void Engine::Listener::setState(Engine::Listener::ListenerState state) {
    this->state = state;
}

/**
 * @brief Engine::Listener::setProductiveTime
 *        set productiveTime value
 *
 * @param productiveTime productiveTime value, in seconds
 */
void Engine::Listener::setProductiveTime(uint64_t productiveTime) {
    this->productiveTime = productiveTime;
}

/**
 * @brief Engine::Listener::setUnproductiveTime
 *        set unproductiveTime value
 *
 * @param unproductiveTime unproductiveTime value, in seconds
 */
void Engine::Listener::setUnproductiveTime(uint64_t unproductiveTime) {
    this->unproductiveTime = unproductiveTime;
}

/**
 * @brief Engine::Listener::getProductiveTime
 *        returns productive time of Listener
 *
 * @attention   probably not needed...Timer keeps track of live session
 *              time; when Session ends, Session will grab this data from
 *              Timer, and have this value stored permanently within
 *              Commitment (more specifically, User's Commitment QVector)
 *
 * @return  Listener's productive time, in seconds
 */
uint64_t Engine::Listener::getProductiveTime() {
    return productiveTime;
}

/**
 * @brief Engine::Listener::getunProductiveTime
 *        returns unproductive time of Listener
 *
 * @attention   probably not needed...Timer keeps track of live session
 *              time; when Session ends, Session will grab this data from
 *              Timer, and have this value stored permanently within
 *              Commitment (more specifically, User's Commitment QVector)
 *
 * @return Listener's unproductive time, in seconds
 */
uint64_t Engine::Listener::getUnproductiveTime() {
    return unproductiveTime;
}

/**
 * @brief Engine::Listener::getSlack
 *        returns slack value,
 *        user-defined grace "padding" between checkStateDelay
 *
 * @return  slack value, in seconds
 */
double Engine::Listener::getSlack() {
    return slack;
}

/**
 * @brief Engine::Listener::setSlack
 *        sets slack value,
 *        user-defined grace "padding" between checkStateDelay
 *
 * @param slack     slack value, in seconds
 */
void Engine::Listener::setSlack(double slack) {
    this->slack = (slack < 0.0) ? this->slack : slack;
}

/**
 * @brief Engine::Listener::getState
 *        Returns current state of Listener, unproductive or productive
 *
 * @return Engine::Listener::ListenerState::unproductive,
 *         or
 *         Engine::Listener::ListenerState::productive
 */
Engine::Listener::ListenerState Engine::Listener::getState() {
    return Engine::Listener::ListenerState::unproductive;
}
