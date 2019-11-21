import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "XmlPatterns"
    Depends { name: "Qt"; submodules: ["core-private","xmlpatterns"]}

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
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtXmlPatterns.framework/Headers/5.12.5","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtXmlPatterns.framework/Headers/5.12.5/QtXmlPatterns"]
    cpp.libraryPaths: []
    
}
