import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "WebEngineCore"
    Depends { name: "Qt"; submodules: []}

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
    cpp.defines: ["QT_WEBENGINECOREHEADERS_LIB"]
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtWebEngineCore.framework/Headers","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtWebEngineCore.framework/Headers/5.12.5","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtWebEngineCore.framework/Headers/5.12.5/QtWebEngineCore"]
    cpp.libraryPaths: []
    
}
