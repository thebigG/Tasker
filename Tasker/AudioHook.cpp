#include "AudioHook.h"
#include "TaskerPerf/perftimer.h"
#include <QDebug>
#include <cstdio>

using Engine::AudioHook;
using Engine::Hook;

/**
 * @brief AudioListener::AudioListener
 */
AudioHook::AudioHook()
    : Hook::Hook{}, audioListenerState{AudioListenerState::OFF} {
  audioThreshold = 0.01;
}

/**
 * @brief AudioListener::setAudioThreshold
 * @param audioThreshold
 */
void AudioHook::setAudioThreshold(qreal audioThreshold) {
  this->audioThreshold = audioThreshold;
}
/**
 * @brief AudioListener::getAudioThreshold
 * @return
 */
qreal &AudioHook::getAudioThreshold() { return audioThreshold; }

/**
 * @brief AudioListener::start
 */
void AudioHook::start() { startListening(); }

/**
 * @brief AudioListener::end
 */
void AudioHook::end() {
  // stop listening, for end of session
  audioListenerState = AudioListenerState::OFF;
}

/**
 * @brief AudioListener::pause
 */
void AudioHook::pause() {
  // TODO pause
  // suspend listening, but don't quit
}

/**
 * @brief AudioListener::update
 */
void AudioHook::update() {
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
  HookState state;

  state = audioSource->getAudioDevice()->getDeviceLevel() > audioThreshold
              ? HookState::productive
              : HookState::unproductive;
  setState(state);

  qDebug() << "listener level: "
           << audioSource->getAudioDevice()->getDeviceLevel();

  if (state == HookState::productive) {
    qDebug("audio status: productive");
  } else {
    qDebug("audio status: unproductive");
  }
}

/**
 * @brief AudioListener::listen
 * @return
 */
Hook::HookState AudioHook::startHook() { return Hook::getState(); }
void AudioHook::resetState() {
  // reset state to "unproductive"
  setState(HookState::unproductive);
}

/**
 * @brief AudioListener::startListening
 * @param
 * @return
 */
int AudioHook::startListening() {
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
          &AudioHook::update);
  qDebug() << "AudioListener updateState() thread id: %d"
           << QThread::currentThreadId();

  return EXIT_SUCCESS;
}
