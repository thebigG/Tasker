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

jack_port_t *output_port1;
jack_client_t *client;

#ifndef M_PI
#define M_PI (3.14159265)
#endif
static void signal_handler(int sig) {
  jack_client_close(client);
  fprintf(stderr, "signal received, exiting ...\n");
  //  exit(0);
}

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

int process(jack_nframes_t nframes, void *arg) {
  jack_default_audio_sample_t *out1;
  out1 = (jack_default_audio_sample_t *)jack_port_get_buffer(output_port1,
                                                             nframes);

  float maxValue = 0;

  float maxAmplitude = 0x7fffffff;

  float captureValue = 0;

  float deviceLevel;

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

  printf("level:%f\n", std::abs(deviceLevel));

  return 0;
}

/**
 * JACK calls this shutdown_callback if the server ever shuts down or
 * decides to disconnect the client.
 */
void jack_shutdown(void *arg) { // shutdwon procedure
}

int initJackClient(std::string clientName) {
  const char **ports;
  const char *client_name;
  const char *server_name = NULL;
  jack_options_t options = JackNullOption;
  jack_status_t status;

  /* open a client connection to the JACK server */
  qDebug() << "initJackClient1\n";

  client = jack_client_open(clientName.c_str(), options, &status, server_name);
  qDebug() << "initJackClient2\n";

  if (client == NULL) {
    //    fprintf(stderr,
    //            "jack_client_open() failed, "
    //            "status = 0x%2.0x\n",
    //            status);
    //    if (status & JackServerFailed) {
    //      fprintf(stderr, "Unable to connect to JACK server\n");
    //    }
    qDebug() << "initJackClient2\n";
    //    exit(1);
  }

  else {

    qDebug() << "initJackClient3\n";

    if (status & JackServerStarted) {
      fprintf(stderr, "JACK server started\n");
    }
    if (status & JackNameNotUnique) {
      client_name = jack_get_client_name(client);
      fprintf(stderr, "unique name `%s' assigned\n", client_name);
    }

    /* tell the JACK server to call `process()' whenever
             there is work to be done.
          */

    jack_set_process_callback(client, process, NULL);

    /* tell the JACK server to call `jack_shutdown()' if
             it ever shuts down, either entirely, or if it
             just decides to stop calling us.
          */

    jack_on_shutdown(client, jack_shutdown, 0);

    /* create two ports */

    output_port1 = jack_port_register(
        client, "output1", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);

    if (output_port1 == NULL) {
      fprintf(stderr, "no more JACK ports available\n");
      //    exit(1);
    }

    /* Tell the JACK server that we are ready to roll.  Our
     * process() callback will start running now. */

    if (jack_activate(client)) {
      fprintf(stderr, "cannot activate client");
      //    exit(1);
    }

    /* Connect the ports.  You can't do this before the client is
     * activated, because we can't make connections to clients
     * that aren't running.  Note the confusing (but necessary)
     * orientation of the driver backend ports: playback ports are
     * "input" to the backend, and capture ports are "output" from
     * it.
     */

    ports = jack_get_ports(client, NULL, NULL,
                           JackPortIsPhysical | JackPortIsOutput);
    if (ports == NULL) {
      fprintf(stderr, "no physical playback ports\n");
      //    exit(1);
    }

    if (jack_connect(client, ports[0], jack_port_name(output_port1))) {
      fprintf(stderr, "cannot connect output ports\n");
    }

    jack_free(ports);

    /* install a signal handler to properly quits jack client */
#ifdef WIN32
    signal(SIGINT, signal_handler);
    signal(SIGABRT, signal_handler);
    signal(SIGTERM, signal_handler);
#else
    signal(SIGQUIT, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGHUP, signal_handler);
    signal(SIGINT, signal_handler);
#endif

    /* keep running until the Ctrl+C */

    while (1) {
#ifdef WIN32
      Sleep(1000);
#else
      sleep(1);
#endif
    }

    //  jack_client_close(client);
    //  exit(0);
  }
  return 0;
}
