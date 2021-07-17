/**
 * @brief This simple client gets the volume from the input sound device, such
 * as an audio interface. It essentially calculates Peak Amplitue of the Sin
 * Waves(the audio samples).
 */

#include <QDebug>
#include <errno.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <cmath>
#include <vector>
#ifndef WIN32
#include <unistd.h>
#endif
#include <jack/jack.h>

#include <algorithm>

#include "JackHook.h"
#include "Timer.h"

jack_port_t *output_port1;
jack_client_t *client;
float deviceLevel;
/**
 * The process callback for this JACK application is called in a
 * special realtime thread once for each audio cycle.
 *
 * This client follows a simple rule: when the JACK transport is
 * running, copy the input port to the output.  When it stops, exit.
 *
 *
 * @note Make sure you add yourself to the group before trying to connect to
 * jack, "usermod -a -G audio theusername"
 */

static int process_jack_data(jack_nframes_t nframes, void *arg) {
  jack_default_audio_sample_t *out1;
  out1 = (jack_default_audio_sample_t *)jack_port_get_buffer(output_port1,
                                        nframes);
  float maxValue = 0;
  float maxAmplitude = 0x7fffffff;
  float captureValue = 0;
  float minAmplitude = 0;
  uint32_t current_sample_value = 0;

  for (unsigned int i = 0; i < nframes; i++) {
    current_sample_value =
        static_cast<uint32_t>(std::abs((out1[i]) * (0x7fffffff)));
    maxValue =
        current_sample_value > maxValue ? current_sample_value : maxValue;
  }
  // Calculate the volume of the sound coming from the device.
  maxValue = std::min(maxValue, maxAmplitude);
  captureValue = static_cast<uint32_t>(maxValue) / maxAmplitude;

  // When we say "deviceLevel", what we really mean is Peak Amplitude.
  deviceLevel = captureValue - minAmplitude;

  if (Engine::Timer::getInstance()->getHook()->getType() ==
      Engine::Hook::HookType::JACK) {
    Engine::Timer::getInstance()->getHook().get()->update();
  } else {
    // This should never happen.
  }

  return 0;
}

/**
 * JACK calls this shutdown_callback if the server ever shuts down or
 * decides to disconnect the client.
 */
void jack_shutdown(void *arg) { // shutdwon procedure
}

/**
  Initializes a jack client
 * @brief initJackClient
 * @param clientName
 * @return 0 if successful.-1 otherwise.
 */
int Engine::JackHook::initJackClient(std::string clientName) {
  const char **ports;
  const char *client_name;
  const char *server_name = NULL;

  int options = JackNullOption | JackNoStartServer;

  jack_status_t status;

  /* open a client connection to the JACK server */
  qDebug() << "initJackClient1\n";

  client =
      jack_client_open(clientName.c_str(), static_cast<JackOptions>(options),
                       &status, server_name);

  if (client == NULL) {
    return -1;
  }

  if (status & JackServerStarted) {
    fprintf(stderr, "JACK server started\n");
  }
  if (status & JackNameNotUnique) {
    client_name = jack_get_client_name(client);
    fprintf(stderr, "unique name `%s' assigned\n", client_name);
  }

  /* tell the JACK server to call `process_jack_data()' whenever
           there is work to be done.
        */

  jack_set_process_callback(client, process_jack_data, NULL);

  /* tell the JACK server to call `jack_shutdown()' if
           it ever shuts down, either entirely, or if it
           just decides to stop calling us.
        */

  jack_on_shutdown(client, jack_shutdown, 0);

  /* create two ports */

  output_port1 = jack_port_register(client, "output1", JACK_DEFAULT_AUDIO_TYPE,
                                    JackPortIsInput, 0);

  if (output_port1 == NULL) {
    fprintf(stderr, "no more JACK ports available\n");
    return -1;
  }

  /* Tell the JACK server that we are ready to roll.  Our
   * process() callback will start running now. */

  if (jack_activate(client)) {
    fprintf(stderr, "cannot activate client");
    return -1;
  }

  /* Connect the ports.  You can't do this before the client is
   * activated, because we can't make connections to clients
   * that aren't running.  Note the confusing (but necessary)
   * orientation of the driver backend ports: playback ports are
   * "input" to the backend, and capture ports are "output" from
   * it.
   */

  ports =
      jack_get_ports(client, NULL, NULL, JackPortIsPhysical | JackPortIsOutput);
  if (ports == NULL) {
    fprintf(stderr, "no physical playback ports\n");
    return -1;
  }

  if (jack_connect(client, ports[0], jack_port_name(output_port1))) {
    fprintf(stderr, "cannot connect output ports\n");
  }

  jack_free(ports);
  return 0;
}

/**
 * @brief Checks if there is a Jack Server running at the moment.
 * @return true if the Jack Server is running. Otherwise, returns false.
 */
bool Engine::JackHook::probeJackServer() {
  const char *client_name;
  const char *server_name = NULL;

  jack_client_t *probeClient;
  int options = JackNullOption | JackNoStartServer;

  jack_status_t status;

  /* open a client connection to the JACK server */
  probeClient = jack_client_open("Tasker", static_cast<JackOptions>(options),
                                 &status, server_name);

  if (probeClient == NULL) {
    return false;
  }
  if (status & JackServerStarted) {
    // This should be never happen
    fprintf(stderr, "JACK server started -- probeJackServer \n");
  }
  if (status & JackNameNotUnique) {
    client_name = jack_get_client_name(probeClient);
    fprintf(stderr, "unique name `%s' assigned\n", client_name);
  }
  return true;
}

/**
 * @brief Engine::JackHook::JackHook
 * Sets the audio threshhold to 0.001f. Obviously this is something that
 * needs to be investigated further since this is a fixed threshold and users
 * have no way of configuring it. At the moment this was tested on Pop!_OS 20.04
 * LTS with default settings of the Jack server. Using Moukey Moukey USB 3.0
 * Audio Interface; model#: MK0155-PAN-UK.
 */
Engine::JackHook::JackHook() {
  connect(this, &Engine::JackHook::hookUpdate, this, &JackHook::update);
  type = HookType::JACK;
  audioThreshold = 0.001f;
}
/**
 * @brief JackHook::start Initializes the jack client.
 * @todo In the future have a way of checking if the Jack Server
 * is even running.
 */
void Engine::JackHook::start() { initJackClient("Tasker"); }

/**
 * @brief AudioHook::end
 */
void Engine::JackHook::end() { audioListenerState = AudioListenerState::OFF; }

/**
 * @brief AudioHook::pause
 */
void Engine::JackHook::pause() {
  // TODO pause
  // suspend listening, but don't quit
}

/**
 * @brief AudioHook::update updates the state of AudioHook to productive if
 * the audio volume(level) is above audioThreshold, otherwise it sets the
 * state to unproductive. It also profiles the audio device's if it hasn't
 * been profiled yet.
 * @note Note that this function is called every time the
 * AudioDevice::audioRead signal is sent.
 */
void Engine::JackHook::update() {
  HookState state;
  state = deviceLevel > audioThreshold ? HookState::productive
                                       : HookState::unproductive;
  setState(state);
}

Engine::JackHook::HookState Engine::JackHook::startHook() { return getState(); }

/**
 * @brief AudioHook::listen resets state to "unproductive"
 */
void Engine::JackHook::resetState() { setState(HookState::unproductive); }

Engine::JackHook::Hook::HookState Engine::JackHook::getState() { return state; }
