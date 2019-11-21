import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "3DQuickInput"
    Depends { name: "Qt"; submodules: ["core-private","qml-private","3dquick-private","3dcore-private","3dinput-private","3dquickinput"]}

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
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/Qt3DQuickInput.framework/Headers/5.12.5","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/Qt3DQuickInput.framework/Headers/5.12.5/Qt3DQuickInput"]
    cpp.libraryPaths: []
    
}
