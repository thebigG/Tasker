#ifndef AUDIOMACHINE_H
#define AUDIOMACHINE_H

#include <AudioDevice.h>
#include <QAudioInput>
#include <QFile>
#include <memory>
namespace Engine {
class AudioMachine;
}

/**
 * @brief The Engine::AudioMachine class
 */
class Engine::AudioMachine : public QObject {
  Q_OBJECT

public:
  AudioMachine();
  ~AudioMachine();
  bool isAudioDeviceValid();
  AudioDevice *getAudioDevice();
  QAudioInput &getQAudioInput();
public slots:
  void handleStateChanged(QAudio::State);
  void stopRecording();

private:
  std::unique_ptr<AudioDevice> audioDevice; // Class member
  std::unique_ptr<QAudioInput> qAudioInput;
};

#endif // AUDIOMACHINE_H
