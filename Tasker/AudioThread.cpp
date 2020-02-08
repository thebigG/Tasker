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
AudioThread::AudioThread() : audioMachine(nullptr) {
    connect(&qThread, &QThread::started, this, &AudioThread::updateState);
    qDebug("AudioThread constructor thread id: %d", QThread::currentThreadId());
    this->moveToThread(&qThread);
    qThread.start();
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
 * The audioMachine entity is concurrency-senstive.
 * This means that it is in the context of qThread.
 * Because of this, use this method with GREAT caution
 * and awereness of the fact that even though when this class is innstantiated
 * audioMachine SHOULD be instantiated by qThread, it is NOT a guarantee.
 * When it comes to threads, we are at the mercy of the OS.
 * While it is unlikely,
 * it is very possible that audioMachine might be have a nullptr value.
 * So please, ALWAYS do a null check BEFORE using it.
 *
 * Since audioMachine a unique_prt(AKA "smart pointer"), you
 * don't have to call delete, or do any kind of memory-management
 * nonsense. And please, just don't, if you do the system will crash.
 * It's why we have smart pointers,
 * let them do the hard work.
 * @return a pointer to the audioMachine.
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
//    qDebug()<<"current audio level:"<<*audioLevel;
    return audioMachine->getAudioDevice()->getDeviceLevel();// == nullptr ? 0.0 : (*audioLevel);
}

/**
 * @brief AudioThread::updateState
 * audioMachine MUST be instantiated HERE on updateState() in order for it to be
 * inside qThread's context. DO NOT move it to the constructor.
 * If it were to be instantiated in the constrcutor, things WILL break.
 * Specifically, if one instantiated audioMachine in the constructor, you'll have
 * the AudioListener while(true) loop blocking this Thread and
 * the we won't be able to detect hardware interaction from AudioMachine.
 */
void AudioThread::updateState() {

    audioMachine =  std::make_unique<AudioMachine>();
    qDebug("AudioThread updateState() thread id: %d", QThread::currentThreadId());
}
