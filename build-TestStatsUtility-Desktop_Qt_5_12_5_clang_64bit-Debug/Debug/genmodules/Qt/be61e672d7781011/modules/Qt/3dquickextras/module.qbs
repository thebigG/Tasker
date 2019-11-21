import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "3DQuickExtras"
    Depends { name: "Qt"; submodules: ["core","gui","qml","3dcore","3dinput","3dquick","3drender","3dlogic","3dextras"]}

    architectures: ["x86_64"]
    targetPlatform: "macos"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: ["Qt3DExtras","Qt3DInput","Qt3DQuick","Qt3DRender","Qt3DLogic","Qt3DCore","QtGamepad","QtQuick","QtGui","QtQml","QtNetwork","QtConcurrent","QtCore","DiskArbitration","IOKit"]
    frameworksRelease: ["Qt3DExtras","Qt3DInput","Qt3DQuick","Qt3DRender","Qt3DLogic","Qt3DCore","QtGamepad","QtQuick","QtGui","QtQml","QtNetwork","QtConcurrent","QtCore","DiskArbitration","IOKit"]
    frameworkPathsDebug: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib"]
    frameworkPathsRelease: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib"]
    libNameForLinkerDebug: "Qt3DQuickExtras"
    libNameForLinkerRelease: "Qt3DQuickExtras"
    libFilePathDebug: "/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/Qt3DQuickExtras.framework/Qt3DQuickExtras"
    libFilePathRelease: "/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/Qt3DQuickExtras.framework/Qt3DQuickExtras"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_plugins","import_qpa_plugin","asset_catalogs","rez","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","app_bundle","incremental","global_init_link_order","lib_version_first","sdk","clang_pch_style","shared","qt_framework","release","macos","osx","macx","mac","darwin","unix","posix","gcc","clang","llvm","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","f16c","largefile","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","explicitlib","testcase_no_bundle","release","ReleaseBuild","Release","build_pass","release","ReleaseBuild","Release","build_pass","module_frameworks","lib_bundle","relative_qt_rpath","app_extension_api_only","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c99","c11","hide_symbols","separate_debug_info","need_fwd_pri","qt_install_module","debug_and_release","build_all","create_cmake","sliced_bundle","compiler_supports_fpmath","create_pc","release","ReleaseBuild","Release","build_pass","have_target","dll","exclusive_builds","objective_c","no_autoqmake","any_bundle","thread","opengl","moc","resources"]
    cpp.defines: ["QT_3DQUICKEXTRAS_LIB"]
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/Qt3DQuickExtras.framework/Headers"]
    cpp.libraryPaths: []
    
}