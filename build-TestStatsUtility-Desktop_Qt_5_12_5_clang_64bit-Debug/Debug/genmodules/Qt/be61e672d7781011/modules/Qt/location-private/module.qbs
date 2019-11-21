import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Location"
    Depends { name: "Qt"; submodules: ["core-private","positioning-private","quick-private","positioning-private","positioningquick-private","qml-private","core-private","gui-private","positioningquick-private","location"]}

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
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtLocation.framework/Headers/5.12.5","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtLocation.framework/Headers/5.12.5/QtLocation"]
    cpp.libraryPaths: []
    
}
