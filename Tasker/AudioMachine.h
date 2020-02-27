/**
 *  @file       AudioMachine.h
 *  @brief      Header file for Engine::AudioMachine
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
