/**
 *  @file       AudioListener.cpp
 *  @brief      Source file for Engine::AudioListener
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
#include "AudioListener.h"
#include <QDebug>
#include <cstdio>



using Engine::AudioListener;
using Engine::Listener;

/**
 * @brief AudioListener::AudioListener
 */
AudioListener::AudioListener()
: Listener::Listener(), audioListenerState(AudioListenerState::OFF),
  audioThread(nullptr), audioThreshold(0.0) {
    audioThreshold = 0.01;
}

/**
 * @brief AudioListener::~AudioListener
 */
AudioListener::~AudioListener() {
//    ~Listener();
qDebug()<<"AudioListener destructor";
}

/**
 * @brief AudioListener::setAudioThreshold
 * @param audioThreshold
 */
void AudioListener::setAudioThreshold(qreal audioThreshold) {
    this->audioThreshold = audioThreshold;
}

/**
 * @brief AudioListener::getAudioThreshold
 * @return
 */
qreal &AudioListener::getAudioThreshold() {
    return audioThreshold;
}

/**
 * @brief AudioListener::start
 */
void AudioListener::start() {
    // start listening
    startListening();
}

/**
 * @brief AudioListener::end
 */
void AudioListener::end() {
    // stop listening, for end of session
    audioThread->getQThread().exit();
    audioListenerState = AudioListenerState::OFF;
}

/**
 * @brief AudioListener::pause
 */
void AudioListener::pause() {
    // TODO pause
    // suspend listening, but don't quit
}

/**
 * @brief AudioListener::update
 */
void AudioListener::update() {
    // TODO update
    // change input device
}

/**
 * @brief AudioListener::cleanup
 */
void AudioListener::cleanup() {
    delete audioThread;
}

/**
 * @brief AudioListener::listen
 * @return
 */
Listener::ListenerState AudioListener::listen() {
    return Listener::getState();
}

/**
 * @brief AudioListener::startListening
 * @param delay
 * @return
 */
int AudioListener::startListening(unsigned long int delay) {
    audioThread = new AudioThread;
    // must pass in audio device type at some point to thread.

    // connect(address of thread object, &thisThread,
    // signal want to run, &QThread::finished,
    // object that contains slot, this
    // function i want to run, &AudioListener::cleanup);

    connect(&audioThread->getQThread(), &QThread::finished, this, &AudioListener::cleanup);
//    connect();
    qDebug() << "From startListening on Listener.cpp: " << QThread::currentThreadId();
    audioThread->moveToThread(&audioThread->getQThread());
    qDebug() << "From startListening on Listener.cpp: after connect" << QThread::currentThreadId();
    audioListenerState = AudioListenerState::ON;
    audioThread->getQThread().start();
    while (true) {
        if (audioThread->getAudioMachine()) {
            if (audioThread->getAudioMachine()->getAudioDevice()) {
                audioThread->getAudioMachine()->getQAudioInput()->setVolume(0.0);
                while (audioThread->getAudioMachine()->getAudioDevice()->getDeviceLevel() == 0.0) {
                }
                audioThread->getAudioMachine()->getAudioDevice()->setMinAmplitude(
                    audioThread->getAudioMachine()->getAudioDevice()->getDeviceLevel());
                audioThread->getAudioMachine()->getQAudioInput()->setVolume(1.0);
                break;
            }
        }
    }
    qDebug() << "AudioListener updateState() thread id: << " << QThread::currentThreadId();
    while (true) {
        ListenerState state;

        state = audioThread->getAudioLevel() > audioThreshold ?
                    ListenerState::productive :
                    ListenerState::unproductive;
        setState(state);

//        qDebug() << "listener level: " << audioThread->getAudioLevel();

        if (state == ListenerState::productive) {
            qDebug() << "status: productive";
        } else {
            qDebug() << "status: unproductive";
        }

        QThread::sleep(BASE_DELAY + delay);
    }

    return EXIT_SUCCESS;
}
