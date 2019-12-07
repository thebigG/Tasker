#include "testaudio.h"

testAudio::testAudio()
{
    QAudioInput* audio; // Class member
    {
        destinationFile.setFileName("/tmp/test.raw");
        destinationFile.open( QIODevice::WriteOnly | QIODevice::Truncate );

        QAudioFormat format;
        // Set up the desired format, for example:
        format.setSampleRate(8000);
        format.setChannelCount(1);
        format.setSampleSize(8);
        format.setCodec("audio/pcm");
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setSampleType(QAudioFormat::UnSignedInt);

        QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
        if (!info.isFormatSupported(format)) {
            qWarning() << "Default format not supported, trying to use the nearest.";
            format = info.nearestFormat(format);
        }

        audio = new QAudioInput(format, this);
        connect(audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));
        QTimer::singleShot(3000, this, SLOT(stopRecording()));
        audio->start(&destinationFile);
        // Records audio for 3000ms
    }
}
