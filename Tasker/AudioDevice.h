#ifndef AUDIODEVICE_H
#define AUDIODEVICE_H

#include <QIODevice>
#include <QtMultimedia>
/**
 *@brief The Engine namespace has all of the
 *Hardware Listeners and classes that make up the "Engine" of Tasker
 * When it comes to detecting user interaction with hardware
 * such as KeyboardListener, AudioListener, Timer and any other class that
 *directly aids these entities such as AudioDevice. Listener classes are
 *platform-dependent. Given that they work very close to hardware, you will
 *probably find a lot of macros that test whether the OS is Linux, MacOS,
 *Windows, etc.
 *
 * If you have any ideas/want to make hardware listeners for this app, PR and
 *issues are super welcome!
 */
namespace Engine {
class AudioDevice;
};

/**
 * @brief The Engine::AudioDevice class
 */
class Engine::AudioDevice : public QIODevice {
  Q_OBJECT
public:
  AudioDevice(const QAudioFormat newFormat);
  ~AudioDevice() override;

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
