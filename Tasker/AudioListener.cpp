#include "AudioListener.h"
#include "TaskerPerf/perftimer.h"
#include <QDebug>
#include <cstdio>

using Engine::AudioListener;
using Engine::Listener;

/**
 * @brief AudioListener::AudioListener
 */
AudioListener::AudioListener()
    : Listener::Listener{}, audioListenerState{AudioListenerState::OFF} {
  audioThreshold = 0.01;
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
qreal &AudioListener::getAudioThreshold() { return audioThreshold; }

/**
 * @brief AudioListener::start
 */
void AudioListener::start() { startListening(); }

/**
 * @brief AudioListener::end
 */
void AudioListener::end() {
  // stop listening, for end of session
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
  if (!profiled) {
    /**
      Profile device's volume if it hasn't been profiled yet
      */
    audioSource->getQAudioInput().setVolume(0.0);
    audioSource->getAudioDevice()->setMinAmplitude(
        audioSource->getAudioDevice()->getDeviceLevel());
    audioSource->getQAudioInput().setVolume(1.0);
    profiled = true;
  }
  ListenerState state;

  state = audioSource->getAudioDevice()->getDeviceLevel() > audioThreshold
              ? ListenerState::productive
              : ListenerState::unproductive;
  setState(state);

  qDebug() << "listener level: "
           << audioSource->getAudioDevice()->getDeviceLevel();

  if (state == ListenerState::productive) {
    qDebug("audio status: productive");
  } else {
    qDebug("audio status: unproductive");
  }
}

/**
 * @brief AudioListener::listen
 * @return
 */
Listener::ListenerState AudioListener::listen() { return Listener::getState(); }
void AudioListener::resetState() {
  // reset state to "unproductive"
  setState(ListenerState::unproductive);
}

/**
 * @brief AudioListener::startListening
 * @param
 * @return
 */
int AudioListener::startListening() {
  audioSource = std::make_unique<AudioMachine>();
  qDebug() << "From startListening on Listener.cpp: "
           << QThread::currentThreadId();
  qDebug() << "From startListening on Listener.cpp: after connect:%d"
           << QThread::currentThreadId();
  audioListenerState = AudioListenerState::ON;
  qDebug() << "AudioListener#1";
  if (audioSource == nullptr) {
    qDebug("NULL++++");
  }
  qDebug() << "AudioListener#2";
  connect(audioSource->getAudioDevice(), &AudioDevice::audioRead, this,
          &AudioListener::update);
  qDebug() << "AudioListener updateState() thread id: %d"
           << QThread::currentThreadId();

  return EXIT_SUCCESS;
}
