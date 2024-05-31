"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var process = require("process");
var path = require("path");
var fs = require("fs");
var script = process.argv[1];
var dir = path.dirname(script);
var buildDir = path.join(dir, "Build");
if (fs.existsSync(buildDir)) {
    // 递归删除目录及其内容的函数
    var deleteFolderRecursive_1 = function (path, d) {
        if (fs.existsSync(path)) {
            fs.readdirSync(path).forEach(function (file) {
                var curPath = path + "/" + file;
                if (fs.lstatSync(curPath).isDirectory()) { // recurse
                    deleteFolderRecursive_1(curPath, true);
                }
                else { // delete file
                    fs.unlinkSync(curPath);
                }
            });
            if (d)
                fs.rmdirSync(path);
        }
    };
    // 调用递归删除函数删除目录及其内容
    deleteFolderRecursive_1(buildDir, false);
}
