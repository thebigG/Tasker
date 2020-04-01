#ifndef AUDIOLISTENER_H
#define AUDIOLISTENER_H

#include "Listener.h"
#include <AudioMachine.h>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include <memory>
namespace Engine {
class AudioListener;
}

/**
 * @brief The Engine::AudioListener class
 */
class Engine::AudioListener : public Engine::Listener {
  Q_OBJECT

public:
  enum class AudioListenerState { ON, OFF };

  AudioListener();
  //    ~AudioListener() override;
  void setAudioThreshold(qreal audioThreshold);
  qreal &getAudioThreshold();

  Listener::ListenerState listen() override;

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
