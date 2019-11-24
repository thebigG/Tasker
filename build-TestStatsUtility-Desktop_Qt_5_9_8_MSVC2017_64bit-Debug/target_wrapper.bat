@echo off
SetLocal EnableDelayedExpansion
(set PATH=D:\Qt\5.9.8\msvc2017_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=D:\Qt\5.9.8\msvc2017_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=D:\Qt\5.9.8\msvc2017_64\plugins
)
%*
EndLocal
