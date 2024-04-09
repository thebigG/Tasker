#ifndef UDPHOOK_H
#define UDPHOOK_H
#include <Hook.h>

#include <QtCore>
#include <memory>
#include <QtNetwork/QUdpSocket>

/**
 * @brief The UdpHook class
 */
class UdpHook: public Engine::Hook
{
    Q_OBJECT
    public:

    UdpHook();
    private:
    /**
       * @brief socket
       */
      std::unique_ptr<QUdpSocket> socket;


  public slots:
      /**
       * @brief socketRead
       */
      void socketRead();
};



#endif // UDPHOOK_H
