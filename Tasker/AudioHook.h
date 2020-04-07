#ifndef AUDIOLISTENER_H
#define AUDIOLISTENER_H

#include "Hook.h"
#include <AudioMachine.h>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include <memory>
namespace Engine {
class AudioHook;
}

/**
 * @brief Engine::AudioHook class
 */
class Engine::AudioHook : public Engine::Hook {
  Q_OBJECT

public:
  enum class AudioListenerState { ON, OFF };

  AudioHook();
  //    ~AudioListener() override;
  void setAudioThreshold(qreal audioThreshold);
  qreal &getAudioThreshold();

  Hook::HookState startHook() override;

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
  std::unique_ptr<AudioMachine> audioSource;
  qreal audioDelta;

  qreal audioThreshold;
  bool profiled = false;
  int startListening(); // seconds
};

#endif // AUDIOLISTENER_H
