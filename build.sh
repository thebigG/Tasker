#!/bin/bash
mkdir TravisCIBuild
cd TravisCIBuild
qmake ../Tasker/Tasker.pro
make -j4
cd ..
