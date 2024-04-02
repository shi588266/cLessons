/**
 * 编写一个程序，接受两个命令行参数。第1个参数是字符，第2个参数是文件名。要求该程序只打印文件中包含给定字符的那些行
 * 读取整行数据考虑使用 fgets()
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int main (int argc, char *argv[])
{
    FILE *fileio;
    int line_no;
    char line[BUFSIZE];
    unsigned char ch;
    
    if (argc != 3) {
        printf("Invalid arguments,Usage:[%s char file].\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    //打开文件
    if ( (fileio = fopen(argv[2], "r")) == NULL ) {
        printf("Open file %s failed.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    
    ch = *argv[1];
    while ( fgets(line, BUFSIZE, fileio)  ) {
        if (strchr(line, ch)) {
            fputs(line);    // fgets 会读取换行符,使用 fputs 输出内容
            printf("at line: %d.\n", line_no);
        }
        line_no++;
    }
    fclose(fileio);
    return 0;
}