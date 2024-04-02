#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<windows.h>


void read(char *file_path){
    FILE *pfile = fopen(file_path, "rb"); //以二进制方式读取内容原封不动
    char ch;
    fread(&ch, 1, 1, pfile); //读取文件内容,每次读取1个元素,读一次, 并把内容赋值给ch
    while ( !eof(pfile) )  //没有到文件末尾就一直读取
    {
        printf("%d\n", ch);     //打印字符的ascii码
        fread(&ch, 1, 1, pfile);
    }
    fclose(pfile);
}

void main(int argc, char const *argv[])
{
    // 初始化字符数组
    char buffer[5] = {10,10,10,10,10};

    FILE *pfile_ascii ;// 定义文本文件指针
    FILE *pfile_bin ;// 定义二进制文件指针

    char path_ascii[15] = "E:\\ascii.c"
    pfile_ascii = fopen(path_ascii, "w");   //按照文本写入的方式打开文件
    if (pfile_ascii == NULL)
    {
        printf("文本文件打开失败\n");
    } else {
        // 把数组写入到文本文件
        fwrite(buffer, 1, 5, pfile_ascii);  // 把buffer中的元素写入到文本文件指针,每次写1个字符, 写5次
        fclose(pfile_ascii);    // 关闭文件指针
    }
    printf("开始读取文本文件内容\n");
    read(path_ascii);


    char path_bin[15] = "E:\\binary.c";
    pfile_bin = fopen(path_bin, "wb");   //按照二进制写入的方式打开文件
    if (pfile_bin == NULL)
    {
        printf("二进制文件打开失败\n");
    } else {
        // 把数组写入到二进制文件
        fwrite(buffer, 1, 5, pfile_bin);  // 把buffer中的元素写入到文件指针,每次写1个字符, 写5次
        fclose(pfile_bin);    // 关闭文件指针
    }
    printf("开始读取二进制文件内容\n");
    read(path_bin);
}


