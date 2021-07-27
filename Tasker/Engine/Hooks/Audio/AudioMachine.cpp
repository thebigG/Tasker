/**
 *  @file       AudioMachine.cpp
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
#include "AudioMachine.h"
#include <QThread>
#include <QTimer>
#include <TaskerPerf/perftimer.h>

using Engine::AudioDevice;
using Engine::AudioMachine;

/**
 * @brief AudioMachine::AudioMachine initializes the AudioDevice and all other
 * state(such as audio formats) to enable the AudioDevice to function properly.
 */
AudioMachine::AudioMachine() : audioDevice(nullptr), qAudioInput(nullptr) {
  // TODO: Move some of this code to an init function. Shouldn't be opening a
  // device
  // inside a constructor.
  QAudioFormat format;

  // Set up the desired format, for example:
  format.setSampleRate(8000);
  format.setChannelCount(1);
  format.setSampleSize(8);
  format.setCodec("audio/pcm");
  format.setByteOrder(QAudioFormat::LittleEndian);
  format.setSampleType(QAudioFormat::UnSignedInt);
  audioDevice = std::make_unique<AudioDevice>(format);
  bool success = audioDevice->open(QIODevice::WriteOnly);
  qDebug() << "device:" << success;

  // assign audio device here
  QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
  QList<QAudioDeviceInfo> devices =
      QAudioDeviceInfo::availableDevices(QAudio::Mode::AudioInput);

  for (QAudioDeviceInfo i : devices) {

    if (i.isFormatSupported(format)) {
      qDebug() << "valid device info name:" << i.deviceName();
    }
  }
  if (!info.isFormatSupported(format)) {
    qDebug("Default format not supported, trying to use the nearest.");
    format = info.nearestFormat(format);
  }

  qAudioInput = std::make_unique<QAudioInput>(format, this);

  qAudioInput->start(audioDevice.get());

  qDebug() << "default audio device name:" << info.deviceName();

  qDebug() << "audio state-->" << qAudioInput->state();
  qAudioInput->setVolume(0.0);
  audioDevice->setMinAmplitude(audioDevice->getDeviceLevel());
  qAudioInput->setVolume(1.0);
}

/**
 * @brief AudioMachine::getAudioDevice
 * @return
 */
AudioDevice *AudioMachine::getAudioDevice() { return audioDevice.get(); }

/**
 * @brief AudioMachine::getQAudioInput
 * @return
 */
QAudioInput &AudioMachine::getQAudioInput() { return *(qAudioInput.get()); }

/**
 * @brief AudioMachine::handleStateChanged
 * @param newState
 */
void AudioMachine::handleStateChanged(QAudio::State newState) {
  switch (newState) {
  case QAudio::StoppedState:
    if (qAudioInput->error() != QAudio::NoError) {
      // Error handling
    } else {
      // Finished recording
      qDebug("stopped state");
    }

    break;

  case QAudio::ActiveState:
    // Started recording - read from IO device
    qDebug("active state");

  default:
    // ... other cases as appropriate
    break;
  }
}

/**
 * @brief AudioMachine::stopRecording
 */
void AudioMachine::stopRecording() {
  qAudioInput->stop();
  audioDevice->close();
}
/**
 * @brief AudioMachine::isAudioDeviceValid if the AudioDevice is open, then this
 * function returns true. Otherwise, it returns false.
 * @return
 */
bool AudioMachine::isAudioDeviceValid() { return audioDevice->isOpen(); }
