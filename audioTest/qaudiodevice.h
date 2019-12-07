#ifndef QAUDIODEVICE_H
#define QAUDIODEVICE_H
#include <QIODevice>
#include <QAudioFormat>
class QAudioDevice: public QIODevice
{
public:
    QAudioDevice();
    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;
    QAudioDevice(const QAudioFormat newFormat);
    QAudioFormat format;
    quint32 maxAmplitude;
    qreal deviceLevel;
    quint32 getMin(unsigned int a, unsigned int b);
};

#endif // QAUDIODEVICE_H
