#!/usr/bin/env bash
gcc -no-pie -o XListenerHook  ./XListenerHook.c    ./libuiohook.a ./libXtst.a ./libX11.a /usr/lib/x86_64-linux-gnu/libXt.a ./libxkbcommon.a ./libxkbcommon-x11.a ./libxkbfile.a ./libXinerama.a ./libX11-xcb.a   -lX11   ./libxcb.a  ./libXau.a ./libXdmcp.a  -lICE -lSM ./libXext.a -lxcb-xkb

