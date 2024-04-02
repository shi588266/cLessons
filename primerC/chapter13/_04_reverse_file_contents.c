/**
 * 倒序输出文件内容
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
#define CTL_Z '\032'
int main(void)
{
    char name[MAXLEN];
    unsigned long last_pos,count;
    FILE *fp;
    int ch;
    // 读取用户输入的文件名
    puts("Enter the filename to read");
    scanf("%s", name);
    printf("filename is %s\n", name);
    
    /**
     * 以二进制格式打开文件,读取到的内容与文件实际内容一致
     * 如果以文本模式打开文件, C会对不同文件内容做映射, 比如:把MS-DOS系统的文件内容的 '\r\n' 映射为 '\n',
     * 这样会把两个字符变为一个字符, 所以以文本模式打开文件, ftell()获取的文件字节数不准确.
     */
    if ( (fp = fopen(name, "rb"))==NULL ) {
        printf("Open file \"%s\" failed\n", name);
        exit(EXIT_FAILURE);
    }
    //3.倒序输出文件内容
    // 3.1把文件读取位置置于文件末尾, 第二个参数是偏移量, 0L说明偏移量是一个long类型
    last_pos = fseek(fp, 0L, SEEK_END);
    count = ftell(fp);
    printf("count is %lu\n", count);
    // 3.2 从最后一个字节倒序读取
    unsigned long i;
    for (i = 1L; i <= count; i++) {
        fseek(fp, -i, SEEK_END);
        ch = fgetc(fp);
        // 3.3输出内容
        if (ch == '\r' || ch == CTL_Z) {//MS_DOS系统下特殊符号
            continue;
        }
        fputc(ch, stdout);
    }
    putchar('\n');
    
    if ( fclose(fp) != 0 ) {
        puts("close failed");
    }
    return 0;
}