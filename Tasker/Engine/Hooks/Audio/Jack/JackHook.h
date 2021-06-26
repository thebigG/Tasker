#include "Hook.h"

int initJackClient(std::string clientName);
namespace Engine {
class JackHook;
} // namespace Engine

/**
 * @brief The Engine::JackHook class allows users to connect Tasker to Jack.
 * To learn more about Jack:https://jackaudio.org/
 * Meaning one could have software such as Audacity(or anything else that
 * supports Jack) and Tasker running at the same time.
 */
class Engine::JackHook : public Engine::Hook {
  Q_OBJECT

  enum class AudioListenerState { ON, OFF };

public:
  JackHook();
  void setAudioThreshold(qreal audioThreshold);
  qreal &getAudioThreshold();

  Hook::HookState startHook() override;

  Hook::HookState getState() override;

public slots:
  virtual void start() override;
  virtual void end() override;
  virtual void pause() override;
  virtual void update() override;
  virtual void resetState() override;

signals:
  void signalThread();

private:
  AudioListenerState audioListenerState;
  // TODO: Maybe this should be configurable by the user...
  // At the moment is a fixed value set on the constructor.
  float audioThreshold;

signals:
  void jackUpdate();
};