/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing
**
** This file is part of Qbs.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms and
** conditions see http://www.qt.io/terms-conditions. For further information
** use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, The Qt Company gives you certain additional
** rights.  These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

import qbs.File
import qbs.FileInfo
import qbs.Process
import qbs.TextFile
import qbs.Utilities
import '../QtModule.qbs' as QtModule
import 'quick.js' as QC

QtModule {
    qtModuleName: "Quick"
    Depends { name: "Qt"; submodules: ["core","gui","qml"].concat("qml-private") }

    hasLibrary: true
    architectures: ["x86_64"]
    targetPlatform: "macos"
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: ["QtQml","QtGui","QtNetwork","QtCore","DiskArbitration","IOKit"]
    frameworksRelease: ["QtQml","QtGui","QtNetwork","QtCore","DiskArbitration","IOKit"]
    frameworkPathsDebug: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib"]
    frameworkPathsRelease: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib","/Users/gemuelealudino/Qt/5.12.5/clang_64/lib"]
    libNameForLinkerDebug: "QtQuick"
    libNameForLinkerRelease: "QtQuick"
    libFilePathDebug: "/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtQuick.framework/QtQuick"
    libFilePathRelease: "/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtQuick.framework/QtQuick"
    pluginTypes: ["accessible","scenegraph"]
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_plugins","import_qpa_plugin","asset_catalogs","rez","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","app_bundle","incremental","global_init_link_order","lib_version_first","sdk","clang_pch_style","shared","qt_framework","release","macos","osx","macx","mac","darwin","unix","posix","gcc","clang","llvm","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","f16c","largefile","precompile_header","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","explicitlib","testcase_no_bundle","warning_clean","python_available","release","ReleaseBuild","Release","build_pass","release","ReleaseBuild","Release","build_pass","generated_privates","module_frameworks","lib_bundle","relative_qt_rpath","app_extension_api_only","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c99","c11","hide_symbols","separate_debug_info","need_fwd_pri","qt_install_module","debug_and_release","build_all","create_cmake","sliced_bundle","compiler_supports_fpmath","create_pc","release","ReleaseBuild","Release","build_pass","have_target","dll","exclusive_builds","objective_c","no_autoqmake","any_bundle","thread","opengl","moc","resources","moc","resources"]
    cpp.defines: {
        var result = ["QT_QUICK_LIB"];
        if (qmlDebugging)
            result.push("QT_QML_DEBUG");
        return result;
    }
    cpp.includePaths: ["/Users/gemuelealudino/Qt/5.12.5/clang_64/lib/QtQuick.framework/Headers"]
    cpp.libraryPaths: []
    property bool qmlDebugging: false
    property string qmlPath: "/Users/gemuelealudino/Qt/5.12.5/clang_64/qml"
    property string qmlImportsPath: "/Users/gemuelealudino/Qt/5.12.5/clang_64/imports"

    readonly property bool _compilerIsQmlCacheGen: Utilities.versionCompare(Qt.core.version,
                                                                            "5.11") >= 0
    readonly property string _generatedLoaderFileName: _compilerIsQmlCacheGen
                                                       ? "qmlcache_loader.cpp"
                                                       : "qtquickcompiler_loader.cpp"
    property string compilerBaseName: (_compilerIsQmlCacheGen ? "qmlcachegen" : "qtquickcompiler")
    property string compilerFilePath: FileInfo.joinPaths(Qt.core.binPath,
                                        compilerBaseName + product.cpp.executableSuffix)
    property bool compilerAvailable: File.exists(compilerFilePath);
    property bool useCompiler: compilerAvailable && !_compilerIsQmlCacheGen

    Scanner {
        condition: useCompiler
        inputs: 'qt.quick.qrc'
        searchPaths: [FileInfo.path(input.filePath)]
        scan: QC.scanQrc(input.filePath)
    }

    FileTagger {
        condition: useCompiler
        patterns: "*.qrc"
        fileTags: ["qt.quick.qrc"]
        priority: 100
    }

    Rule {
        condition: useCompiler
        inputs: ["qt.quick.qrc"]
        Artifact {
            filePath: input.fileName + ".json"
            fileTags: ["qt.quick.qrcinfo"]
        }
        prepare: {
            var cmd = new JavaScriptCommand();
            cmd.silent = true;
            cmd.sourceCode = function() {
                var content = QC.contentFromQrc(input.filePath);
                content.qrcFilePath = input.filePath;

                var tf = new TextFile(output.filePath, TextFile.WriteOnly);
                tf.write(JSON.stringify(content));
                tf.close();
            }
            return cmd;
        }
    }

    Rule {
        condition: useCompiler
        inputs: ["qt.quick.qrcinfo"]
        outputFileTags: ["cpp", "qrc"]
        multiplex: true
        outputArtifacts: {
            var infos = [];
            inputs["qt.quick.qrcinfo"].forEach(function (input) {
                var tf = new TextFile(input.filePath, TextFile.ReadOnly);
                infos.push(JSON.parse(tf.readAll()));
                tf.close();
            });

            var result = [];
            infos.forEach(function (info) {
                if (info.newQrcFileName) {
                    result.push({
                        filePath: info.newQrcFileName,
                        fileTags: ["qrc"]
                    });
                }
                info.qmlJsFiles.forEach(function (qmlJsFile) {
                    result.push({
                        filePath: qmlJsFile.output,
                        fileTags: ["cpp"]
                    });
                });
            });
            result.push({
                filePath: product.Qt.quick._generatedLoaderFileName,
                fileTags: ["cpp"]
            });
            return result;
        }
        prepare: {
            var infos = [];
            inputs["qt.quick.qrcinfo"].forEach(function (input) {
                var tf = new TextFile(input.filePath, TextFile.ReadOnly);
                infos.push(JSON.parse(tf.readAll()));
                tf.close();
            });

            var cmds = [];
            var qmlCompiler = product.Qt.quick.compilerFilePath;
            var useCacheGen = product.Qt.quick._compilerIsQmlCacheGen;
            var cmd;
            var loaderFlags = [];

            function findOutput(fileName) {
                for (var k in outputs) {
                    for (var i in outputs[k]) {
                        if (outputs[k][i].fileName === fileName)
                            return outputs[k][i];
                    }
                }
                throw new Error("Qt Quick compiler rule: Cannot find output artifact "
                                + fileName + ".");
            }

            infos.forEach(function (info) {
                if (info.newQrcFileName) {
                    loaderFlags.push("--resource-file-mapping="
                                     + FileInfo.fileName(info.qrcFilePath)
                                     + ":" + info.newQrcFileName);
                    var args = ["--filter-resource-file",
                                info.qrcFilePath];
                    if (useCacheGen)
                        args.push("-o");
                    args.push(findOutput(info.newQrcFileName).filePath);
                    cmd = new Command(qmlCompiler, args);
                    cmd.description = "generating " + info.newQrcFileName;
                    cmds.push(cmd);
                } else {
                    loaderFlags.push("--resource-file-mapping=" + info.qrcFilePath);
                }
                info.qmlJsFiles.forEach(function (qmlJsFile) {
                    var args = ["--resource=" + info.qrcFilePath, qmlJsFile.input];
                    if (useCacheGen)
                        args.push("-o");
                    args.push(findOutput(qmlJsFile.output).filePath);
                    cmd = new Command(qmlCompiler, args);
                    cmd.description = "generating " + qmlJsFile.output;
                    cmd.workingDirectory = FileInfo.path(info.qrcFilePath);
                    cmds.push(cmd);
                });
            });

            var args = loaderFlags.concat(infos.map(function (info) { return info.qrcFilePath; }));
            if (useCacheGen)
                args.push("-o");
            args.push(findOutput(product.Qt.quick._generatedLoaderFileName).filePath);
            cmd = new Command(qmlCompiler, args);
            cmd.description = "generating loader source";
            cmds.push(cmd);
            return cmds;
        }
    }
}
