import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "ClipboardSupport"
    Depends { name: "Qt"; submodules: ["core-private","gui"]}

    architectures: ["x86_64"]
    targetPlatform: "macos"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: ["ImageIO","QtGui","QtCore","DiskArbitration","IOKit","AppKit","OpenGL","AGL"]
    frameworksRelease: ["ImageIO","QtGui","QtCore","DiskArbitration","IOKit","AppKit","OpenGL","AGL"]
    frameworkPathsDebug: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib"]
    frameworkPathsRelease: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib"]
    libNameForLinkerDebug: "Qt5ClipboardSupport_debug"
    libNameForLinkerRelease: "Qt5ClipboardSupport"
    libFilePathDebug: "/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/libQt5ClipboardSupport_debug.a"
    libFilePathRelease: "/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/libQt5ClipboardSupport.a"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_qpa_plugin","asset_catalogs","rez","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","app_bundle","incremental","global_init_link_order","lib_version_first","sdk","clang_pch_style","qt_framework","release","macos","osx","macx","mac","darwin","unix","posix","gcc","clang","llvm","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","f16c","largefile","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","explicitlib","testcase_no_bundle","warning_clean","release","ReleaseBuild","Release","build_pass","static","internal_module","relative_qt_rpath","app_extension_api_only","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c99","c11","hide_symbols","separate_debug_info","qt_install_headers","need_fwd_pri","qt_install_module","debug_and_release","build_all","compiler_supports_fpmath","create_libtool","release","ReleaseBuild","Release","build_pass","have_target","staticlib","exclusive_builds","objective_c","no_autoqmake","thread","opengl","moc","resources"]
    cpp.defines: ["QT_CLIPBOARD_SUPPORT_LIB"]
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/include","/Users/gemuelealudino/Qt/5.12.5/clang_64/include/QtClipboardSupport","/Users/gemuelealudino/Qt/5.12.5/clang_64/include/QtClipboardSupport/5.12.5","/Users/gemuelealudino/Qt/5.12.5/clang_64/include/QtClipboardSupport/5.12.5/QtClipboardSupport"]
    cpp.libraryPaths: []
    isStaticLibrary: true
Group {
        files: [Qt["clipboard_support-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
