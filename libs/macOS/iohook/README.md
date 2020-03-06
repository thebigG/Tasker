Don't forget to set the shared library path for macOS:
`export DYLD_LIBRARY_PATH=.:$DYLD_LIBRARY_PATH`

Or for a more permanent solution(highly recommended):
`install_name_tool -change /usr/local/lib/libuiohook.0.dylib  ./libuiohook.0.dylib ./XListenerHook`

- tested on macODS 10.15.3
