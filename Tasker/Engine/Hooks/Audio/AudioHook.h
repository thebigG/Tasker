#ifndef AUDIOHOOK_H
#define AUDIOHOOK_H

#include "Hook.h"
#include "miniaudio.h"
#include <memory>
namespace Engine {
class AudioHook;
class MA_Exception;
} // namespace Engine
class Engine::MA_Exception : public std::exception {
public:
    virtual ~MA_Exception(){};
    const char *what() const throw();
};
/**
 * @brief Engine::AudioHook class This class uses the AudioDvice and
 * AudioMachine classes to make a self-sustained asynchronous and stateful audio
 * Hook that hooks to an audio device.
 *
 */
class Engine::AudioHook : public Engine::Hook {
    Q_OBJECT

public:
    enum class AudioHookState { ON, OFF };
    AudioHook(std::string deviceName);
    void setAudioThreshold(qreal audioThreshold);
    qreal &getAudioThreshold();
    Hook::HookState startHook() override;
    Hook::HookState getState() override;
    std::vector<std::string> getDeviceNames();
    static std::vector<std::string> queryDeviceNames();

public slots:
    virtual void start() override;
    virtual void end() override;
    virtual void pause() override;
    virtual void update() override;
    virtual void resetState() override;

signals:
    void signalThread();

private:
    AudioHookState audioListenerState;
    //  std::unique_ptr<AudioMachine> audioSource;
    qreal audioThreshold;
    bool profiled = false;
    static std::vector<ma_backend> getBackends();
    ma_result initContext(ma_context_config *pConfig,
                          ma_context *pContext,
                          ma_uint32 backendCount,
                          ma_backend *backends);

    ma_context context;
    std::unique_ptr<ma_context_config> contextConfig;
    const ma_device_id *deviceId; // Managed by miniaudio
    void initAudioDevice(ma_device_config *config);
    std::map<std::string, ma_device_info> deviceMap{};
    void updateDeviceMap();
    std::unique_ptr<ma_device_config> config;
};

#endif // AUDIOHOOK_H
