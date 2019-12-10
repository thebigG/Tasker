/**
 *  @file       AudioDevice.h
 *  @brief      Header file for Engine::AudioDevice
 *
 *  @author     Gemuele (Gem) Aludino
 *  @date       09 Dec 2019
 */
/**
 *  Copyright © 2019 Gemuele Aludino
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 *  THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef AUDIODEVICE_H
#define AUDIODEVICE_H

#include <QAudioFormat>
#include <QIODevice>

namespace Engine {
class AudioDevice;
};

/**
 * @brief The Engine::AudioDevice class
 */
class Engine::AudioDevice : public QIODevice {
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

private:
    QAudioFormat qAudioFormat;

    qreal deviceLevel;
    qreal minAmplitude;

    quint32 maxAmplitude;
};

#endif // AUDIODEVICE_H
