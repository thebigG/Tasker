/**
 *  @file       AudioThread.cpp
 *  @brief      Source file for Engine::AudioThread
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
#include "AudioThread.h"
#include "TaskerPerf/perftimer.h"
#include <QDebug>

using Engine::AudioMachine;
using Engine::AudioThread;

/**
 * @brief AudioThread::AudioThread
 */
AudioThread::AudioThread() : audioMachine(nullptr), audioLevel(nullptr) {
    connect(&qThread, &QThread::start, this, &AudioThread::updateState);
    qDebug("AudioThread constructor thread id: %d", QThread::currentThreadId());
    audioMachine =  std::make_unique<AudioMachine>();
    this->moveToThread(&qThread);
    qThread.start();
}

/**
 * @brief AudioThread::~AudioThread
 */
AudioThread::~AudioThread() {
//    delete audioMachine;
}

/**
 * @brief AudioThread::getQThread
 * @return
 */
QThread &AudioThread::getQThread() {
    return qThread;
}

/**
 * @brief AudioThread::getAudioMachine
 * @return
 */
AudioMachine* AudioThread::getAudioMachine() {
    qDebug()<<"getAudioMachine#1";

    return audioMachine.get();
}

/**
 * @brief AudioThread::getAudioLevel
 * @return
 */
qreal AudioThread::getAudioLevel() {
    return audioLevel == nullptr ? 0.0 : (*audioLevel);
}

/**
 * @brief AudioThread::updateState
 */
void AudioThread::updateState() {
//    audioMachine =  std::make_unique<AudioMachine>();
    qDebug("AudioThread updateState() thread id: %d", QThread::currentThreadId());
    audioLevel = &(audioMachine->getAudioDevice()->getDeviceLevel());
}
