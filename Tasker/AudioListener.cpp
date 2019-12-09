/**
 *  @file       AudioListener.cpp
 *  @brief      Source file for Engine::AudioListener
 *
 *  @author     Gemuele (Gem) Aludino
 *  @date       25 Nov 2019
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

using Engine::AudioListener;
using Engine::Listener;

AudioListener::AudioListener()
    : Listener::Listener() {
    qDebug() << "AudioListener::AudioListener\n";
}

AudioListener::~AudioListener() {
//    Listener::~Listener();
    qDebug() << "AudioListener::~AudioListener\n";
}

void AudioListener::start() {
    qDebug() << "AudioListener::start";
    qDebug() << "Thread ID: " << QThread::currentThreadId() << "\n";
    startListening();
}

void AudioListener::end() {
    qDebug() << "AudioListener::end\n";
}

void AudioListener::pause() {
    qDebug() << "AudioListener::pause\n";
}

void AudioListener::update() {
    qDebug() << "AudioListener::update\n";
}

Listener::ListenerState AudioListener::listen() {
    qDebug() << "AudioListener::listen\n";
    return Listener::getState();
}

int AudioListener::startListening(unsigned long int delay) {
    // see KeyboardListener, while(1) { ... }
    qDebug() << "AudioListener::startListening\n";
    t = new Thread{};
    while (1) {
        qDebug()<<"current level:"<<t->getLevel();
    }

    return EXIT_SUCCESS;
}
