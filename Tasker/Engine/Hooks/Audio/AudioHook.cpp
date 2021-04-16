#include "AudioHook.h"
#include "TaskerPerf/perftimer.h"
#include <QDebug>
#include <cstdio>

using Engine::AudioHook;
using Engine::Hook;

/**
 * @brief AudioHook::AudioListener
 * @todo At the moment the audioThreshold is set on AudioHook, but it really
 * should not be.
 */
AudioHook::AudioHook()
    : Hook::Hook{}, audioListenerState{AudioListenerState::OFF} {

  audioThreshold = 0.01;
}

/**
 * @brief AudioHook::setAudioThreshold
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
 * @brief AudioHook::start initializes the state of AudioMachine,
 *AudioDevice(the actual audio I/O device). This function also connects and
 *signals and slots necessary to start the hook.
 */
void AudioHook::start() {
  audioSource = std::make_unique<AudioMachine>();
  audioListenerState = AudioListenerState::ON;
  if (audioSource == nullptr) {
    // error-handling
  }
  connect(audioSource->getAudioDevice(), &AudioDevice::audioRead, this,
          &AudioHook::update);
}

/**
 * @brief AudioHook::end
 */
void AudioHook::end() { audioListenerState = AudioListenerState::OFF; }

/**
 * @brief AudioHook::pause
 */
void AudioHook::pause() {
  // TODO pause
  // suspend listening, but don't quit
}

/**
 * @brief AudioHook::update updates the state of AudioHook to productive if the
 * audio volume(level) is above audioThreshold, otherwise it sets the state to
 * unproductive. It also profiles the audio device's if it hasn't been profiled
 * yet.
 * @note Note that this function is called every time the AudioDevice::audioRead
 * signal is sent.
 */
void AudioHook::update() {
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
}

Hook::HookState AudioHook::startHook() { return getState(); }

/**
 * @brief AudioHook::listen resets state to "unproductive"
 */
void AudioHook::resetState() { setState(HookState::unproductive); }

Hook::HookState AudioHook::getState() { return state; }
