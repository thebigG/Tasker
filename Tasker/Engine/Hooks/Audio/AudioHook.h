#ifndef AUDIOHOOK_H
#define AUDIOHOOK_H

#include "Hook.h"
#include "miniaudio.h"
#include <memory>
namespace Engine {
class AudioHook;
}

/**
 * @brief Engine::AudioHook class This class uses the AudioDvice and
 * AudioMachine classes to make a self-sustained asynchronous and stateful audio
 * Hook that hooks to an audio device.
 *
 */
class Engine::AudioHook : public Engine::Hook {
  Q_OBJECT

public:
  enum class AudioHookState { ON, OFF };

  AudioHook();
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
  AudioHookState audioListenerState;
//  std::unique_ptr<AudioMachine> audioSource;
  qreal audioThreshold;
  bool profiled = false;
  static std::array<ma_backend, MA_BACKEND_COUNT> getBackends();
};

#endif // AUDIOHOOK_H
