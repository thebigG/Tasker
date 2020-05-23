#!/usr/bin/env python3
from yaml import safe_load, dump
from yaml import YAMLError
from subprocess import run
ubuntu_sources = [{'sourceline': 'deb http://archive.ubuntu.com/ubuntu/ bionic main restricted universe multiverse',
                   'key_url': 'http://keyserver.ubuntu.com/pks/lookup?op=get&search=0x3b4fe6acc0b21f32'},
                  {'sourceline': 'deb http://archive.ubuntu.com/ubuntu/ bionic-updates main restricted universe multiverse'},
                  {'sourceline': 'deb http://archive.ubuntu.com/ubuntu/ bionic-backports main restricted universe multiverse'},
                  {'sourceline': 'deb http://archive.ubuntu.com/ubuntu/ bionic-security main restricted universe multiverse'}
                  ]
run(["mkdir", "build"])

run(["qmake", "../Tasker.pro"],  cwd="./build")
run(["make", "-j4", ],  cwd="./build")
run(["make", "install", "INSTALL_ROOT=AppDir"], cwd="./build")
# Build directory structure for AppDir
run(["mkdir", "-p", "usr/bin"], cwd="./build/AppDir")
run(["mkdir", "-p", "usr/share/applications"], cwd="./build/AppDir")
run(["mkdir", "-p", "usr/share/icons/hicolor/256x256/apps"],
    cwd="./build/AppDir")

# Copy/move necessary files to AppDir
run(["mv", "opt/Tasker/bin/Tasker", "usr/bin"],
    cwd="./build/AppDir")
run(["cp", "./clock-256.png", "build/AppDir/usr/share/icons/hicolor/256x256/apps"])
run(["cp", "./Tasker.desktop", "build/AppDir/usr/share/applications"])

run(["appimage-builder", "--generate"], cwd="./build")
#
with open('./build/AppImageBuilder.yml') as recipe_file:
    try:
        AppImage_config = safe_load(recipe_file)
    except YAMLError as exc:
        if hasattr(exc, 'problem_mark'):
            mark = exc.problem_mark
            print("Error position: (%s:%s)" % (mark.line + 1, mark.column + 1))
        print('An Error happened loading the yml recipe')
with open('./build/AppImageBuilder.yml', mode='w') as recipe_file:
    AppImage_config['AppDir']['apt']['sources'] = ubuntu_sources
    dump(AppImage_config, recipe_file)


# Build the AppImage
run(["appimage-builder", "--skip-test", "--skip-appimage"], cwd="./build")
run(["appimage-builder", "--skip-test"], cwd="./build")
