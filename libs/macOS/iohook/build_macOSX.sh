clang -no-pie -Iinclude/ XListenerHook.c  -shared -v  -framework IOKit -framework CoreFoundation  -framework CoreServices  -framework Carbon    ./libuiohook.a
