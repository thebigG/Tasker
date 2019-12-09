#ifndef AUDIOMACHINE_H
#define AUDIOMACHINE_H
#include <QFile>
#include <QAudioInput>
#include <qaudiodevice.h>
class audioMachine: public QObject
{
    Q_OBJECT
public:
    audioMachine();
    QAudioDevice* destinationFile;   // Class member
    QAudioInput* audio;
public slots:
    void handleStateChanged(QAudio::State);
    void stopRecording();
};

#endif // AUDIOMACHINE_H

