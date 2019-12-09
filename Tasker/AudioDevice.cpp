/**
 *  @file       AudioDevice.h
 *  @brief      Header file for Engine::AudioDevice
 *
 *  @author     Gemuele (Gem) Aludino
 *  @date       09 Dec 2019
 */
/**
 *  Copyright © 2019 Gemuele Aludino
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 *  THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include "AudioDevice.h"

#include <QAudioFormat>
#include <QDebug>
#include <QtCore>
#include <QtGlobal>

using Engine::QAudioDevice;

QAudioDevice::QAudioDevice(const QAudioFormat newFormat)
: qAudioFormat(newFormat), deviceLevel(0.0), minAmplitude(0.0), maxAmplitude(0) {
    switch (qAudioFormat.sampleSize()) {
    case 8:
        switch (qAudioFormat.sampleType()) {
        case QAudioFormat::UnSignedInt:
            maxAmplitude = 255;
            break;
        case QAudioFormat::SignedInt:
            maxAmplitude = 127;
            break;
        default:
            break;
        }

        break;

    case 16:
        switch (qAudioFormat.sampleType()) {
        case QAudioFormat::UnSignedInt:
            maxAmplitude = 65535;
            break;
        case QAudioFormat::SignedInt:
            maxAmplitude = 32767;
            break;
        default:
            break;
        }

        break;

    case 32:
        switch (qAudioFormat.sampleType()) {
        case QAudioFormat::UnSignedInt:
            maxAmplitude = 0xffffffff;
            break;
        case QAudioFormat::SignedInt:
            maxAmplitude = 0x7fffffff;
            break;
        case QAudioFormat::Float:
            maxAmplitude = 0x7fffffff; // Kind of
            break;
        default:
            break;
        }

        break;

    default:
        break;
    }
}

QAudioDevice::~QAudioDevice() {
    deviceLevel = 0.0;
    minAmplitude = 0.0;
    maxAmplitude = 0.0;
}

void QAudioDevice::setMinAmplitude(qreal minAmplitude) {
    this->minAmplitude = minAmplitude;
}

QAudioFormat& QAudioDevice::getQAudioFormat() {
    return qAudioFormat;
}

qreal& QAudioDevice::getDeviceLevel() {
    return deviceLevel;
}

qreal& QAudioDevice::getMinAmplitude() {
    return minAmplitude;
}

quint32& QAudioDevice::getMaxAmplitude() {
    return maxAmplitude;
}

qint64 QAudioDevice::readData(char *data, qint64 maxlen) {
    // just to get warning to disappear
    return data ? maxlen : 0;
}

qint64 QAudioDevice::writeData(const char *data, qint64 len) {
    qreal captureValue = 0.0;

    if (maxAmplitude) {
        Q_ASSERT(qAudioFormat.sampleSize() % 8 == 0);

        const qint64 channelBytes = (qAudioFormat.sampleSize() / 8);
        const qint64 sampleBytes = (qAudioFormat.channelCount() * channelBytes);

        Q_ASSERT(len % sampleBytes == 0);

        const qint64 numSamples = (len / sampleBytes);

        quint32 maxValue = 0;
        const unsigned char *ptr = reinterpret_cast<const unsigned char *>(data);

        for (int i = 0; i < numSamples; ++i) {
            for (int j = 0; j < qAudioFormat.channelCount(); ++j) {
                quint32 value = 0;

                if (qAudioFormat.sampleSize() == 8 && qAudioFormat.sampleType() == QAudioFormat::UnSignedInt) {
                    value = *reinterpret_cast<const quint8 *>(ptr);
                } else if (qAudioFormat.sampleSize() == 8 &&
                           qAudioFormat.sampleType() == QAudioFormat::SignedInt) {
                    value = static_cast<quint32>(
                        qAbs(*reinterpret_cast<const qint8 *>(ptr)));
                } else if (qAudioFormat.sampleSize() == 16 &&
                           qAudioFormat.sampleType() == QAudioFormat::UnSignedInt) {
                    if (qAudioFormat.byteOrder() == QAudioFormat::LittleEndian) {
                        value = qFromLittleEndian<quint16>(ptr);
                    } else {
                        value = qFromBigEndian<quint16>(ptr);
                    }
                } else if (qAudioFormat.sampleSize() == 16 &&
                           qAudioFormat.sampleType() == QAudioFormat::SignedInt) {
                    if (qAudioFormat.byteOrder() == QAudioFormat::LittleEndian) {
                        value = static_cast<quint32>(qAbs(qFromLittleEndian<qint16>(ptr)));
                    } else {
                        value = static_cast<quint32>(qAbs(qFromBigEndian<qint16>(ptr)));
                    }
                } else if (qAudioFormat.sampleSize() == 32 &&
                           qAudioFormat.sampleType() == QAudioFormat::UnSignedInt) {
                    if (qAudioFormat.byteOrder() == QAudioFormat::LittleEndian) {
                        value = qFromLittleEndian<quint32>(ptr);
                    } else {
                        value = qFromBigEndian<quint32>(ptr);
                    }
                } else if (qAudioFormat.sampleSize() == 32 &&
                           qAudioFormat.sampleType() == QAudioFormat::SignedInt) {
                    if (qAudioFormat.byteOrder() == QAudioFormat::LittleEndian) {
                        value = static_cast<quint32>(qAbs(qFromLittleEndian<qint32>(ptr)));
                    } else {
                        value = static_cast<quint32>(qAbs(qFromBigEndian<qint32>(ptr)));
                    }
                } else if (qAudioFormat.sampleSize() == 32 &&
                           qAudioFormat.sampleType() == QAudioFormat::Float) {
                    value = static_cast<quint32>(
                        qAbs(*reinterpret_cast<const float *>(ptr) * 0x7fffffff)); // assumes 0-1.0
                }

                maxValue = qMax(value, maxValue);
                ptr += channelBytes;
            }
        }

        maxValue = getMin(maxValue, maxAmplitude);
        captureValue = (qreal(maxValue) / maxAmplitude);
        deviceLevel = captureValue - minAmplitude;
    }

    return len;
}

quint32 QAudioDevice::getMin(quint32 a, quint32 b) {
    return a < b ? a : b;
}
