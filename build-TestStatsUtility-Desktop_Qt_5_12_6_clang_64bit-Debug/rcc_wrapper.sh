#!/bin/sh
DYLD_IMAGE_SUFFIX=_debug
export DYLD_IMAGE_SUFFIX
exec /Users/gemuelealudino/Qt/5.12.6/clang_64/bin/rcc "$@"
