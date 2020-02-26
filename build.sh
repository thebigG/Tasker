#!/bin/bash
cd Tasker
clang-format -i -style=file *.cpp *.h
cd ..
mkdir TravisCIBuild
cd TravisCIBuild
qmake ../Tasker/Tasker.pro
make -j4
