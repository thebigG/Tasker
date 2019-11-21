import qbs.FileInfo
import qbs.Utilities
import "../QtModule.qbs" as QtModule

QtModule {
    qtModuleName: "Scxml"

    property string qscxmlcName: "qscxmlc"
    property string className
    property string namespace
    property bool generateStateMethods
    property stringList additionalCompilerFlags

    Rule {
        inputs: ["qt.scxml.compilable"]

        Artifact {
            filePath: FileInfo.joinPaths(input.moduleProperty("Qt.core", "generatedHeadersDir"),
                                         input.baseName + ".h")
            fileTags: ["hpp", "unmocable"]
        }
        Artifact {
            filePath: input.baseName + ".cpp"
            fileTags: ["cpp", "unmocable"]
        }

        prepare: {
            var compilerName = product.moduleProperty("Qt.scxml", "qscxmlcName");
            var compilerPath = FileInfo.joinPaths(input.moduleProperty("Qt.core", "binPath"),
                                                  compilerName);
            var args = ["--header", outputs["hpp"][0].filePath,
                        "--impl", outputs["cpp"][0].filePath];
            var cxx98 = input.moduleProperty("cpp", "cxxLanguageVersion") === "c++98";
            if (cxx98)
                args.push("-no-c++11");
            var className = input.moduleProperty("Qt.scxml", "className");
            if (className)
                args.push("--classname", className);
            var namespace = input.moduleProperty("Qt.scxml", "namespace");
            if (namespace)
                args.push("--namespace", namespace);
            if (input.Qt.scxml.generateStateMethods
                    && Utilities.versionCompare(product.Qt.scxml.version, "5.9") >= 0) {
                args.push("--statemethods");
            }
            if (input.Qt.scxml.additionalCompilerFlags)
                args = args.concat(input.Qt.scxml.additionalCompilerFlags);
            args.push(input.filePath);
            var cmd = new Command(compilerPath, args);
            cmd.description = "compiling " + input.fileName;
            cmd.highlight = "codegen";
            return [cmd];
        }
    }

    architectures: ["x86_64"]
    targetPlatform: "macos"
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: ["QtQml","QtNetwork","QtCore","DiskArbitration","IOKit"]
    frameworksRelease: ["QtQml","QtNetwork","QtCore","DiskArbitration","IOKit"]
    frameworkPathsDebug: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib"]
    frameworkPathsRelease: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib"]
    libNameForLinkerDebug: "QtScxml"
    libNameForLinkerRelease: "QtScxml"
    libFilePathDebug: "/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtScxml.framework/QtScxml"
    libFilePathRelease: "/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtScxml.framework/QtScxml"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_plugins","import_qpa_plugin","asset_catalogs","rez","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","app_bundle","incremental","global_init_link_order","lib_version_first","sdk","clang_pch_style","shared","qt_framework","release","macos","osx","macx","mac","darwin","unix","posix","gcc","clang","llvm","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","f16c","largefile","precompile_header","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","explicitlib","testcase_no_bundle","qt_example_installs","warning_clean","release","ReleaseBuild","Release","build_pass","release","ReleaseBuild","Release","build_pass","c++11","qscxmlc","generated_privates","module_frameworks","lib_bundle","relative_qt_rpath","app_extension_api_only","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c99","c11","hide_symbols","separate_debug_info","need_fwd_pri","qt_install_module","debug_and_release","build_all","create_cmake","sliced_bundle","compiler_supports_fpmath","create_pc","release","ReleaseBuild","Release","build_pass","have_target","dll","exclusive_builds","objective_c","no_autoqmake","any_bundle","thread","moc","resources"]

    cpp.defines: ["QT_SCXML_LIB"]
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtScxml.framework/Headers"]
    cpp.libraryPaths: []

    
}
