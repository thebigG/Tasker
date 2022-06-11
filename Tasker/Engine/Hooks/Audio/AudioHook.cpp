#include "AudioHook.h"
#define MINIAUDIO_IMPLEMENTATION
#include "TaskerPerf/perftimer.h"
#include "miniaudio.h"
#include <QDebug>
#include <cstdio>
#include <exception>
#include <map>

// Please ALWAYS include cmath. Otherwise the Windows build breaks. No freaking
// idea why... It complains abs(float) functions being ambiguous
// This explains why: https://stackoverflow.com/a/5450536
/**
 * Its boils down to this: math.h is from C and was created over 10 years ago.
In math.h, due to its primitive nature, the abs() function is "essentially" just
for integer types and if you wanted to get the absolute value of a double, you
had to use fabs(). When C++ was created it took math.h and made it cmath. cmath
is essentially math.h but improved for C++. It improved things like having to
distinguish between fabs() and abs, and just made abs() for both doubles and
integer types. In summary either: Use  math.h and use abs() for integers, fabs()
for doubles or use cmath and just have abs for everything (easier and
recommended)

Hope this helps anyone who is having the same problem!
 */
#include <cmath>

using Engine::AudioHook;
using Engine::Hook;

/**
 * @brief calc_peak_amplitude
 * @param pOutput
 * @param pInput
 * @param frameCount
 * @return
 */
float calc_peak_amplitude(void *pOutput, const void *pInput, ma_uint32 frameCount) {
    float maxValue = 0;
    float maxAmplitude = 0x7fffffff;
    float captureValue = 0;
    float minAmplitude = 0;
    uint32_t current_sample_value = 0;

    const float *audioInput = static_cast<const float *>(pInput);

    for (unsigned int i = 0; i < frameCount; i++) {
        current_sample_value =
            static_cast<long long>(std::abs((audioInput[i]) * (0x7fffffff)));

        maxValue = current_sample_value > maxValue ? current_sample_value : maxValue;
    }

    // Calculate the volume of the sound coming from the device.

    maxValue = std::min(maxValue, maxAmplitude);
    captureValue = static_cast<uint32_t>(maxValue) / maxAmplitude;

    // When we say "deviceLevel", what we really mean is Peak Amplitude.
    float deviceLevel = captureValue - minAmplitude;

    return deviceLevel;
}

void data_callback(ma_device *pDevice, void *pOutput, const void *pInput, ma_uint32 frameCount) {
    auto deviceLevel = calc_peak_amplitude(pDevice, pInput, frameCount);
}

/**
 * @brief AudioHook::AudioListener
 * @todo At the moment the audioThreshold is set on AudioHook, but it really
 * should not be.
 */
// TODO:Add constructor that that takes the context as a parameter
AudioHook::AudioHook(std::string newDevice)
: Hook::Hook{}, audioListenerState{ AudioHookState::OFF } {
    audioThreshold = 0.001f;
    contextConfig = std::make_unique<ma_context_config>();

    config = std::make_unique<ma_device_config>();
    //	init_audio_device(config.get());

    // Don't love doing this in a constructor. Maybe I should have an
    // "init/configure" method in the Hook interface
    initContext(contextConfig.get(), &context, 1, getBackends().data());
    updateDeviceMap();
    deviceId = &deviceMap.at(newDevice).id;
    type = HookType::AUDIO;
}

// TODO:Temporary for now to create the context(and fetch devices) somewhat easily
AudioHook::AudioHook()
: Hook::Hook{}, audioListenerState{ AudioHookState::OFF } {
    audioThreshold = 0.001f;
    contextConfig = std::make_unique<ma_context_config>();

    std::unique_ptr<ma_device_config> config = std::make_unique<ma_device_config>();
    //	init_audio_device(config.get());

    // Don't love doing this in a constructor. Maybe I should have an
    // "init/configure" method in the Hook interface
    initContext(contextConfig.get(), &context, 1, getBackends().data());
    updateDeviceMap();
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
    initAudioDevice(config.get());
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

std::vector<std::string> AudioHook::getDeviceNames() {

    std::vector<std::string> devices{};
    for (auto &pair : deviceMap) {
        devices.push_back(pair.first);
        qDebug() << "name:" << devices.back().c_str();
    }

    return devices;
}

/**
 * @brief AudioHook::updateDeviceMap
 * update devicemap with the current backend.
 */
void AudioHook::updateDeviceMap() {
    deviceMap.clear();
    ma_uint32 pPlaybackDeviceCount;
    ma_device_info *ppCaptureDeviceInfos;
    ma_uint32 pCaptureDeviceCount;

    ma_result res = ma_context_get_devices(&context, nullptr, &pPlaybackDeviceCount,
                                           &ppCaptureDeviceInfos, &pCaptureDeviceCount);
    if (res == MA_SUCCESS) {
        for (int i = 0; i < pCaptureDeviceCount; i++) {
            deviceMap[ppCaptureDeviceInfos[i].name] = ppCaptureDeviceInfos[i];
        }
    } else {
        // TODO:Replace with MA_Exception
        //			throw std::exception("Something bad happended. ma_context_get_devices failed");
    }
}
ma_result AudioHook::initContext(ma_context_config *pConfig,
                                 ma_context *pContext,
                                 ma_uint32 backendCount,
                                 ma_backend *backends) {
    int res = ma_context_init(backends, backendCount, pConfig, pContext);

    return res;
}

void AudioHook::initAudioDevice(ma_device_config *config) {
    ma_device device;

    *config = ma_device_config_init(ma_device_type_capture);
    config->capture.format = ma_format_f32; // Set to ma_format_unknown to use
                                            // the device's native format.
    config->capture.channels = 2; // Set to 0 to use the device's native channel count.
    config->sampleRate = 0; // Set to 0 to use the device's native sample rate.
    config->dataCallback = data_callback; // This function will be called when
    // miniaudio needs more data.

    config->capture.pDeviceID = deviceId;
    ma_result result = ma_device_init(&context, config, &device);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize capture device.\n");
        //		 return -2;
    }

    result = ma_device_start(&device);
}

const char *Engine::MA_Exception::what() const throw() {
    return "Miniaudio error";
}
