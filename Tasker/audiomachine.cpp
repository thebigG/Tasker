#include "audiomachine.h"
#include <QTimer>
#include <QDebug>
#include <QThread>
audioMachine::audioMachine()
{
    QAudioFormat format;
    // Set up the desired format, for example:
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);
//    destinationFile.setFileName("/tmp/test.raw");
//    destinationFile.open( QIODevice::WriteOnly | QIODevice::Truncate );
destinationFile = new QAudioDevice(format);
destinationFile->open( QIODevice::WriteOnly);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = info.nearestFormat(format);
    }
    audio = new QAudioInput(format, this);
    //connect(audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));

//    QTimer::singleShot(3000, this, SLOT(stopRecording()));
    qDebug()<<"calling start on destinationFile ";
    qDebug()<<"audiomachine thread:"<<QThread::currentThreadId();
    qDebug() << info.deviceName();
    audio->start(destinationFile);

    // Records audio for 3000ms
}



void audioMachine::handleStateChanged(QAudio::State newState)
{
    switch (newState) {
    case QAudio::StoppedState:
        if (audio->error() != QAudio::NoError) {
            // Error handling
        } else {
            // Finished recording
            qDebug()<<"stopped state";
        }
        break;

    case QAudio::ActiveState:
        // Started recording - read from IO device
        qDebug()<<"active state";
        break;

    default:
        // ... other cases as appropriate
        break;
    }
}









void audioMachine::stopRecording()
{
    audio->stop();
    destinationFile->close();
    delete audio;
}




