#ifndef UDPHOOK_H
#define UDPHOOK_H
#include <Hook.h>

#include <QtCore>
#include <memory>
#include <QtNetwork/QUdpSocket>

/**
 * @brief The UdpHook class.
 * This is a very simple hook that is
 * listening to a UDP socket.
 * It all does is read the first byte of the datagram and if it is greater than 0,
 * then it sets the state of the hookn to productive.
 */
class UdpHook: public Engine::Hook
{
    Q_OBJECT
    public:

    UdpHook();

    Hook::HookState startHook() override;
    virtual Hook::HookState getState() override;
    virtual void setState(HookState) override;

    private:
    /**
       * @brief socket
       */
      std::unique_ptr<QUdpSocket> socket;




  public slots:
      virtual void start() override;
      virtual void end() override;
      virtual void pause() override;
      virtual void update() override;
      virtual void resetState() override;
      /**
       * @brief socketRead
       */
      void socketRead();
};



#endif // UDPHOOK_H
