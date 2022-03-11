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

    AudioHook();
    void setAudioThreshold(qreal audioThreshold);
    qreal &getAudioThreshold();

    Hook::HookState startHook() override;

    Hook::HookState getState() override;

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
    std::vector<ma_device_info> getDevices();
    ma_result initContext(ma_context_config *pConfig,
                          ma_context *pContext,
                          ma_uint32 backendCount,
                          ma_backend *backends);

    ma_context context;
    std::unique_ptr<ma_context_config> contextConfig;
};

#endif // AUDIOHOOK_H
