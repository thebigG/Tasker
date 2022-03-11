#include "AudioHook.h"
#define MINIAUDIO_IMPLEMENTATION
#include "TaskerPerf/perftimer.h"
#include "miniaudio.h"
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
: Hook::Hook{}, audioListenerState{ AudioHookState::OFF } {
    audioThreshold = 0.001f;
    contextConfig = std::make_unique<ma_context_config>();

    initContext(contextConfig.get(), &context, 1, getBackends().data());
    getDevices();
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
qreal &AudioHook::getAudioThreshold() {
    return audioThreshold;
}
/**
 * @brief AudioHook::start initializes the state of AudioMachine,
 *AudioDevice(the actual audio I/O device). This function also connects and
 *signals and slots necessary to start the hook.
 */
void AudioHook::start() {
    //  audioSource = std::make_unique<AudioMachine>();
    audioListenerState = AudioHookState::ON;
    //  if (audioSource == nullptr) {
    //    // error-handling
    //  }
    //  connect(audioSource->getAudioDevice(), &AudioDevice::audioRead, this,
    //          &AudioHook::update);
}

/**
 * @brief AudioHook::end
 */
void AudioHook::end() {
    audioListenerState = AudioHookState::OFF;
}

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
        //    audioSource->getQAudioInput().setVolume(0.0);
        //    audioSource->getAudioDevice()->setMinAmplitude(
        //        audioSource->getAudioDevice()->getDeviceLevel());
        //    audioSource->getQAudioInput().setVolume(1.0);
        profiled = true;
    }
    HookState state;
    //  state = audioSource->getAudioDevice()->getDeviceLevel() > audioThreshold
    //              ? HookState::productive
    //              : HookState::unproductive;
    setState(state);
}

Hook::HookState AudioHook::startHook() {
    return getState();
}

/**
 * @brief AudioHook::listen resets state to "unproductive"
 */
void AudioHook::resetState() {
    setState(HookState::unproductive);
}

Hook::HookState AudioHook::getState() {
    return state;
}

std::vector<ma_backend> AudioHook::getBackends() {
    std::array<ma_backend, MA_BACKEND_COUNT> backendArr;
    std::vector<ma_backend> backends{};
    try {
        backends.reserve(MA_BACKEND_COUNT);
    } catch (std::length_error) {
        qCritical() << "reserve()failed to reserve memory for backends vector";
    }

    size_t count = 0;
    ma_get_enabled_backends(backends.data(), MA_BACKEND_COUNT, &count);

    return backends;
}

std::vector<ma_device_info> AudioHook::getDevices() {
    unsigned int a{ 0 };

    std::vector<ma_device_info> devices{};
    // NOTE: I know the API is written in C, but I don't like this pointer busisness here...
    ma_uint32 *pPlaybackDeviceCount;
    pPlaybackDeviceCount = &a;
    ma_device_info *ppCaptureDeviceInfos;
    ma_device_info info{};
    ma_uint32 *pCaptureDeviceCount;
    pCaptureDeviceCount = &a;

    ma_result res = ma_context_get_devices(&context, nullptr, pPlaybackDeviceCount,
                                           &ppCaptureDeviceInfos, pCaptureDeviceCount);
    devices.reserve(*pCaptureDeviceCount);
    if (res == MA_SUCCESS) {
        for (int i = 0; i < *pCaptureDeviceCount; i++) {
            devices.push_back(ppCaptureDeviceInfos[i]);
            qDebug() << "device-->" << ppCaptureDeviceInfos[i].name;
        }
    } else {
        //		std::cout<<"Something bad happended. ma_context_get_devices failed"<<std::endl;
        //		throw std::exception{"Something bad happended. ma_context_get_devices failed"};
    }

    return devices;
}
ma_result AudioHook::initContext(ma_context_config *pConfig,
                                 ma_context *pContext,
                                 ma_uint32 backendCount,
                                 ma_backend *backends) {
    int res = ma_context_init(backends, backendCount, pConfig, pContext);

    return res;
}

const char *Engine::MA_Exception::what() const throw() {
    return "Miniaudio error";
}
