#!/usr/bin/env python3

#I should make this a shell script at this point...
from yaml import safe_load, dump
from yaml import YAMLError
from subprocess import run

#NOTE: Install Qt with the regular online installer from the Qt company to make your life easier
CMAKE="/usr/local/bin/cmake"
CMAKE_PREFIX_PATH="-DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake/"
APPDIR_DIR="AppDir"
LINUX_DEPLOY_QT="/opt/squashfs-root/AppRun"
QMAKE="/usr/lib/qt5/bin/qmake"

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
run(["cp", "./Tasker/Tasker", "./AppDir/usr/bin"],
    cwd="./build")
run(["cp", "./Tasker/clock-256.png", "build/AppDir/usr/share/icons/hicolor/256x256/apps"])
run(["cp", "./Tasker/Tasker.desktop", "build/AppDir/usr/share/applications"])

run([LINUX_DEPLOY_QT,"AppDir/usr/share/applications/Tasker.desktop", "-appimage" ,"-bundle-non-qt-libs", "-qmake="+QMAKE ], cwd="./build")
