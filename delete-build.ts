import * as process from "process";
import * as path from "path";
import * as fs from "fs";

const script = process.argv[1];
const dir = path.dirname(script);
const buildDir = path.join(dir, "Build");

if (fs.existsSync(buildDir)) {
  // 递归删除目录及其内容的函数
  const deleteFolderRecursive = function (path, d) {
    if (fs.existsSync(path)) {
      fs.readdirSync(path).forEach(function (file) {
        const curPath = path + "/" + file;
        if (fs.lstatSync(curPath).isDirectory()) { // recurse
          deleteFolderRecursive(curPath, true);
        } else { // delete file
          fs.unlinkSync(curPath);
        }
      });

      if (d)
        fs.rmdirSync(path);
    }
  };

  // 调用递归删除函数删除目录及其内容
  deleteFolderRecursive(buildDir, false);
}
