#include <KeyboardListener.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <QtCore>
#include <QRegularExpression>
#include <stdio.h>
using namespace Engine;
KeyboardListener::KeyboardListener()
{
    getKeyboardPathOnLinux();
}


    QString KeyboardListener::getKeyboardPathOnLinux()
    {
        QDir linuxDIr(LNUX_DEV_PATH);
       QStringList  devices = linuxDIr.entryList();
       QRegularExpression re("*-kbd");
       for(int i =0;i<devices.length();i++)
        {
           qDebug()<<"runnign through loop";
           QRegularExpressionMatch myMatch =  re.match(devices.at(i));
           if(myMatch.hasMatch())
           {
               qDebug()<<"matched device:" + devices.at(i);
           }
        }
        return QString("");
    }

    int KeyboardListener::startListening()
{
        const char *dev = "/dev/input/by-id/usb-Apple_Inc._Apple_Internal_Keyboard___Trackpad-event-kbd";
        struct input_event ev;
        ssize_t n;
        int fd;
        fd = open(dev, O_RDONLY);
        if (fd == -1) {
            fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
            return EXIT_FAILURE;
        }

        while (1) {
            n = read(fd, &ev, sizeof ev);
            if (n == (ssize_t)-1) {
                if (errno == EINTR)
                    continue;
                else
                    break;
            } else
                if (n != sizeof ev) {
                errno = EIO;
                break;
            }
            if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2)
            {
                printf("%s 0x%04x (%d)\n", evval[ev.value], (int)ev.code, (int)ev.code);
            }

        }

        fflush(stdout);
        fprintf(stderr, "%s.\n", strerror(errno));
        return EXIT_FAILURE;
    }

