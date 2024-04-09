#include <QtNetwork/QUdpSocket>
#include <QNetworkDatagram>
#include "UdpHook.h"
#include <iostream>


/**
 * @brief UdpHook::UdpHook
 */
UdpHook::UdpHook()
{
    socket = std::make_unique<QUdpSocket>(this);
    socket->bind(QHostAddress::Any, 7755);

    connect(socket.get(), &QUdpSocket::readyRead,
            this, &UdpHook::socketRead);
}

/**
 * @brief UdpHook::socketRead
 */
void UdpHook::socketRead()
{
    while (socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = socket->receiveDatagram();
        auto data = datagram.data();
         std::cout <<  "data:" << (uint8_t)data.at(0);
//        processTheDatagram(datagram);
    }
}

