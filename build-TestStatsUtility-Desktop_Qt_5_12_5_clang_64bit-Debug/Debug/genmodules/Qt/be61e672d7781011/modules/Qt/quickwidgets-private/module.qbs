import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QuickWidgets"
    Depends { name: "Qt"; submodules: ["core-private","gui-private","qml-private","quick-private","widgets-private","quickwidgets"]}

    architectures: []
    targetPlatform: "macos"
    hasLibrary: false
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: undefined
    libNameForLinkerRelease: undefined
    libFilePathDebug: undefined
    libFilePathRelease: undefined
    pluginTypes: []
    moduleConfig: []
    cpp.defines: []
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtQuickWidgets.framework/Headers/5.12.5","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtQuickWidgets.framework/Headers/5.12.5/QtQuickWidgets"]
    cpp.libraryPaths: []
    
}
