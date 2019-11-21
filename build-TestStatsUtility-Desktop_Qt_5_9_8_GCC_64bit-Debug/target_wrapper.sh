#!/bin/sh
LD_LIBRARY_PATH=/home/fast-alchemist/Qt/5.9.8/gcc_64/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
QT_PLUGIN_PATH=/home/fast-alchemist/Qt/5.9.8/gcc_64/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
