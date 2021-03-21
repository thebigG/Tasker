#!/usr/bin/env python3

#I should make this a shell script at this point...
from yaml import safe_load, dump
from yaml import YAMLError
from subprocess import run
CMAKE="/home/lorenzo/cmake-3.16.0-Linux-x86_64/bin/cmake"
CMAKE_PREFIX_PATH="-DCMAKE_PREFIX_PATH=/opt/qt59/lib/cmake"
APPDIR_DIR="AppDir"
LINUX_DEPLOY_QT="/home/lorenzo/Downloads/linuxdeployqt-7-x86_64.AppImage"
QMAKE="/opt/qt59/bin/qmake"

ubuntu_sources = [{'sourceline': 'deb http://archive.ubuntu.com/ubuntu/ bionic main restricted universe multiverse',
                   'key_url': 'http://keyserver.ubuntu.com/pks/lookup?op=get&search=0x3b4fe6acc0b21f32'},
                  {'sourceline': 'deb http://archive.ubuntu.com/ubuntu/ bionic-updates main restricted universe multiverse'},
                  {'sourceline': 'deb http://archive.ubuntu.com/ubuntu/ bionic-backports main restricted universe multiverse'},
                  {'sourceline': 'deb http://archive.ubuntu.com/ubuntu/ bionic-security main restricted universe multiverse'}
                  ]


run(["mkdir", "build"])

run([CMAKE, "..", CMAKE_PREFIX_PATH],  cwd="./build")
run(["make", "-j4", "-C", "./build" ])

run(["mkdir", "AppDir"], cwd="./build")
run(["make", "INSTALL_ROOT=AppDir"], cwd="./build")
# Build directory structure for AppDir
run(["mkdir", "-p", "usr/bin"], cwd="./build/AppDir")
run(["mkdir", "-p", "usr/share/applications"], cwd="./build/AppDir")
run(["mkdir", "-p", "usr/share/icons/hicolor/256x256/apps"],
    cwd="./build/AppDir")

# Copy/move necessary files to AppDir
run(["cp", "./Tasker", "./AppDir/usr/bin"],
    cwd="./build")
run(["cp", "../libs/linux/iohook/XListenerHook",
     "./build/AppDir/usr/bin"])
run(["cp", "./clock-256.png", "build/AppDir/usr/share/icons/hicolor/256x256/apps"])
run(["cp", "./Tasker.desktop", "build/AppDir/usr/share/applications"])

run([LINUX_DEPLOY_QT,"AppDir/usr/share/applications/Tasker.desktop", "-appimage" ,"-bundle-non-qt-libs", "-qmake="+QMAKE ], cwd="./build")
