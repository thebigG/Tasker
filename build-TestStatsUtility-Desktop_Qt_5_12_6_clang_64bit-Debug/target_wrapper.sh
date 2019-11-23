#!/bin/sh
DYLD_IMAGE_SUFFIX=_debug
export DYLD_IMAGE_SUFFIX
DYLD_FRAMEWORK_PATH=/Users/gemuelealudino/Qt/5.12.6/clang_64/lib${DYLD_FRAMEWORK_PATH:+:$DYLD_FRAMEWORK_PATH}
export DYLD_FRAMEWORK_PATH
QT_PLUGIN_PATH=/Users/gemuelealudino/Qt/5.12.6/clang_64/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
