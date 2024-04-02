#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<windows.h>

// windows 遍历C盘下所有.txt文件
// for /r "C:\" %i in (*.txt) do @echo %i

// windows 遍历文件夹下包含某内容的文件
// for /r "C:\" %a in (*.txt) do @findstr /im "关键字" "%a"

// Linux 指定目录下搜索指定文件名  
// find /etc --name char.c
// find / -name *c*     搜索文件名带c的

// 从根目录查找所有扩展名为 .log 的文件, 并找出包含 "ERROR" 的行
// find / -type f -name "*.log" | xargs grep "ERROR"

void main(int argc, char const *argv[])
{
    // 定义查找路径
    char findPath[50] = "C:\\Users\\shi\\AppData\\Local";
    char findstr[15] = "windows";   // 要查找的关键字
    char findCmd[100];
    sprintf(findCmd, "for /r \"%s\" %%a in (*.txt) do @findstr /im \"%s\" \"%%a\"", findPath, findstr);
    //system(findCmd);

    // 把查找结果写入到输出文件
    char writeOutCmd[100];
    char outPutFile[50] = "C:\\Users\\shi\\Desktop\\outPut.txt";
    sprintf(writeOutCmd, "%s  >> %s", findCmd, outPutFile);
    system(writeOutCmd);

    // 读取文件输出内容
    char showCmd[100];
    sprintf(showCmd, "type %s", outPutFile);
    system(showCmd);
}