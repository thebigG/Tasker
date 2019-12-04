#include "Listener.h"

using namespace Engine;
/**
 * @brief Engine::Listener::Listener
 *        default constructor
 */
<<<<<<< HEAD
Engine::Listener::Listener() : checkStateDelay(0.0),
                               slack(0.0),
                               productiveTime(0.0),
                               unproductiveTime(0.0) {

=======
Listener::Listener() {
    checkStateDelay = 0.0;
    slack = 0.0;
    currentState = Listener::ListenerState::unproductive;
    productiveTime = 0;
    unproductiveTime = 0;
>>>>>>> master
}
Listener::ListenerType  Listener::intToListenerType(int enumInt)
{
 if(int(ListenerType::keyboard)<enumInt || int(ListenerType::none)>enumInt)
     return ListenerType(enumInt);
 return ListenerType::none;
}
/**
 * @brief Engine::Listener::~Listener
 *        destructor
 */
Listener::~Listener() {
    checkStateDelay = 0.0;
    slack = 0.0;

    productiveTime = 0;
    unproductiveTime = 0;
}

/**
<<<<<<< HEAD
 * @brief Engine::Listener::getCheckStateDelay
 *        determines how long between one invocation of listen() and the next
=======
 * @brief Engine::Listener::setState
 *
 * @param state ListenerState, unproductive or productive
 */

void Listener::setState(Listener::ListenerState newState)
{
    currentState = newState;
}
/**
 * @brief Engine::Listener::getSlack
 *        returns slack value,
 *        user-defined grace "padding" between checkStateDelay
>>>>>>> master
 *
 * @return checkStateDelay, in seconds
 */
<<<<<<< HEAD
double Engine::Listener::getCheckStateDelay() {
    return checkStateDelay;
=======
double Listener::getSlack() {
    return slack;
>>>>>>> master
}

/**
 * @brief Engine::Listener::setCheckStateDelay
 *        set how long between one invocation of listen() and the next
 *
 * @param checkStateDelay   checkStateDelay value, in seconds
 */
<<<<<<< HEAD
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
=======
Listener::ListenerState Listener::getState() {
    return Listener::ListenerState::unproductive;
>>>>>>> master
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
uint64_t Listener::getProductiveTime() {
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
uint64_t Listener::getUnproductiveTime() {
    return unproductiveTime;
}

/**
 * @brief Engine::Listener::getSlack
 *        returns slack value,
 *        user-defined grace "padding" between checkStateDelay
 *
<<<<<<< HEAD
 * @return  slack value, in seconds
 */
double Engine::Listener::getSlack() {
    return slack;
}
=======
 * @param slack     slack value, in seconds
 */
void Listener::setSlack(double slack) {
    this->slack = (slack < 0.0) ? this->slack : slack;
}

/**
 * @brief Engine::Listener::getCheckStateDelay
 *        determines how long between one invocation of listen() and the next
 *
 * @return checkStateDelay, in seconds
 */
double Listener::getCheckStateDelay() {
    return checkStateDelay;
}

/**
 * @brief Engine::Listener::setCheckStateDelay
 *        set how long between one invocation of listen() and the next
 *
 * @param checkStateDelay   checkStateDelay value, in seconds
 */
void Listener::setCheckStateDelay(double checkStateDelay) {
    this->checkStateDelay = (checkStateDelay < 0.0)
            ? this->checkStateDelay : checkStateDelay;
}


>>>>>>> master

/**
 * @brief Engine::Listener::setSlack
 *        sets slack value,
 *        user-defined grace "padding" between checkStateDelay
 *
 * @param slack     slack value, in seconds
 */
<<<<<<< HEAD
void Engine::Listener::setSlack(double slack) {
    this->slack = (slack < 0.0) ? this->slack : slack;
=======
void Listener::setProductiveTime(uint64_t productiveTime) {
    this->productiveTime = productiveTime;
>>>>>>> master
}

/**
 * @brief Engine::Listener::getState
 *        Returns current state of Listener, unproductive or productive
 *
 * @return Engine::Listener::ListenerState::unproductive,
 *         or
 *         Engine::Listener::ListenerState::productive
 */
<<<<<<< HEAD
Engine::Listener::ListenerState Engine::Listener::getState() {
    return Engine::Listener::ListenerState::unproductive;
=======
void Listener::setUnproductiveTime(uint64_t unproductiveTime) {
    this->unproductiveTime = unproductiveTime;
>>>>>>> master
}
