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
#include <QDebug>

using Engine::AudioThread;
using Engine::AudioMachine;

AudioThread::AudioThread() : audioMachine(nullptr), audioLevel(nullptr) {
    connect(&qThread, &QThread::started, this, &AudioThread::updateState);

    this->moveToThread(&qThread);
    qThread.start();
}

AudioThread::~AudioThread() {
    delete audioMachine;
}

QThread& AudioThread::getQThread() {
    return qThread;
}

AudioMachine*& AudioThread::getAudioMachine() {
    return audioMachine;
}

qreal AudioThread::getAudioLevel() {
    return audioLevel == nullptr ? 0.0 : (*audioLevel);
}

void AudioThread::updateState() {
    audioMachine = new AudioMachine();
    audioLevel = &(audioMachine->getAudioDevice()->getDeviceLevel());
}

