import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Scxml"
    Depends { name: "Qt"; submodules: ["core-private","qml-private","scxml"]}

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
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtScxml.framework/Headers/5.12.5","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtScxml.framework/Headers/5.12.5/QtScxml"]
    cpp.libraryPaths: []
    
}
