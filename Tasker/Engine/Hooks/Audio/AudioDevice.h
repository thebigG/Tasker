#ifndef AUDIODEVICE_H
#define AUDIODEVICE_H

#include <QIODevice>
#include <QtMultimedia>
/**
 *@brief The Engine namespace has all of the
 *Hardware Hooks and classes that make up the "Engine" of Tasker
 * When it comes to detecting user interaction with hardware
 * such as XHook, AudioHook, Timer and any other class that
 *directly aids these entities such as AudioDevice. Hook classes are
 *platform-dependent.
 * If you have any ideas/want to make hardware Hook for this app, PR and
 *issues are always welcome!
 */
namespace Engine {
class AudioDevice;
};

/**
 * @brief The Engine::AudioDevice class represents the audio hardware device of
 * this machine. It aids to capture the audio(asynchronously) that AudioMachine
 * manages and captures.
 */
class Engine::AudioDevice : public QIODevice {
  Q_OBJECT
public:
  AudioDevice(const QAudioFormat newFormat);

  void setMinAmplitude(qreal minAmplitude);

  QAudioFormat &getQAudioFormat();
  qreal &getDeviceLevel();
  qreal &getMinAmplitude();
  quint32 &getMaxAmplitude();

  static quint32 getMin(quint32 a, quint32 b);

public slots:
  qint64 readData(char *data, qint64 maxlen) override;
  qint64 writeData(const char *data, qint64 len) override;

signals:
  void audioRead();

private:
  QAudioFormat qAudioFormat;

  qreal deviceLevel;
  qreal minAmplitude;

  quint32 maxAmplitude;
};

#endif // AUDIODEVICE_H
