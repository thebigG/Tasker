#include <QtNetwork/QUdpSocket>
#include <QNetworkDatagram>
#include "UdpHook.h"
#include <iostream>


/**
 * @brief UdpHook::UdpHook
 * @todo Really would like move the socket init code to start function...I think I need to do a move
 * of the parent thread inside the start(), I think. Wonderful Qt OOP rules...
 */
UdpHook::UdpHook()
{

    socket = std::make_unique<QUdpSocket>(this);
    socket->bind(QHostAddress::Any, 7755);

    connect(socket.get(), &QUdpSocket::readyRead,
            this, &UdpHook::socketRead);
}

/**
 * @brief XHook::start
 * @todo Ideally we initialize the socket here...
 */
void UdpHook::start() {
//    startXHook();
}

/**
 * @brief Closes the UDP socket
 */
void UdpHook::end() {
    socket->close();
}

/**
 * @brief  Does nothing.
 */
void UdpHook::pause() {
}

/**
 * @brief  Does nothing
 *
 */
void UdpHook::update() {
}


void UdpHook::setState(HookState newState) {
    Hook::setState(newState);
}
/**
 * @brief Engine::Engine::Hook::getState
 *        Returns current state of the Hook, unproductive or productive
 *
 * @return Engine::Engine::Hook::HookState::unproductive,
 *         or
 *         Engine::Engine::Hook::Engine::Hook::productive
 */
Engine::Hook::HookState UdpHook::getState() {
    return state;
}

/**
 * @brief XHook::startHook
 * @return
 */
Engine::Hook::HookState UdpHook::startHook() {
    return getState();
}

void UdpHook::resetState() {
    setState(HookState::unproductive);
}

/**
 * @brief UdpHook::socketRead
 */
void UdpHook::socketRead()
{
    while (socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = socket->receiveDatagram();
        auto dataArray = datagram.data();
        auto data = (unsigned int)dataArray.at(0);
        if(data > 0)
        {
            setState(HookState::productive);
        }

    }
}

