import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlDevTools"
    Depends { name: "Qt"; submodules: ["core-private"]}

    architectures: ["x86_64"]
    targetPlatform: "macos"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: ["QtCore","DiskArbitration","IOKit"]
    frameworkPathsDebug: []
    frameworkPathsRelease: ["$$[QT_HOST_LIBS]"]
    libNameForLinkerDebug: "Qt5QmlDevTools_debug"
    libNameForLinkerRelease: "Qt5QmlDevTools"
    libFilePathDebug: undefined
    libFilePathRelease: "/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/libQt5QmlDevTools.a"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_qpa_plugin","asset_catalogs","rez","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","app_bundle","incremental","global_init_link_order","lib_version_first","sdk","clang_pch_style","qt_framework","release","macos","osx","macx","mac","darwin","unix","posix","gcc","clang","llvm","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","f16c","largefile","precompile_header","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","explicitlib","testcase_no_bundle","warning_clean","python_available","minimal_syncqt","internal_module","qmldevtools_build","generated_privates","qlalr","static","release","module_frameworks","relative_qt_rpath","app_extension_api_only","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c99","c11","hide_symbols","separate_debug_info","need_fwd_pri","qt_install_module","compiler_supports_fpmath","create_libtool","have_target","staticlib","objective_c","thread","moc","resources"]
    cpp.defines: ["QT_QMLDEVTOOLS_LIB"]
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtQml.framework/Headers","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtQml.framework/Headers/5.12.5","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtQml.framework/Headers/5.12.5/QtQml"]
    cpp.libraryPaths: []
    isStaticLibrary: true
Group {
        files: [Qt["qmldevtools-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
