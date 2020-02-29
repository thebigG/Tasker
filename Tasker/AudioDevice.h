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

#include <QIODevice>
#include <QtMultimedia>
/**
 *@brief The Engine namespace has all of the
 *Hardware Listeners and classes that make up the "Engine" of Tasker
 * When it comes to detecting user interaction with hardware
 * such as KeyboardListener, AudioListener, Timer and any other class that directly
 * aid these entities such as AudioDevice.
 * Listener classes are platform-dependent. Given that they work
 * very close to hardware, you will probably find a lot of macros
 * that test whether the OS is Linux, MacOS, Windows, etc.
 *
 * Right now these listeners have been developed mostly with Linux in mind.
 * The only one that is "cross-platform" is the AudioListener, however, I haven't tested it
 * thoroughly on other platforms such MacOS or Windows.
 * I would love(and plan) to have these listeners work well(specially the KeyboardListener)
 * on Windows and MacOS, but that's not going to happen in a while, given that my priority is
 * Linux right now.
 *
 * If you have any ideas/want to make hardware listeners for this app, PR and issues are super welcome!
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
