/*
输入缓冲字符复制函数
*/
#include <stdlib.h>
#include <string.h>

char* function strdup(char const *string) {
    char *new_string;
    //请求足够长度的内存, 用于存储字符串和结尾的NUL字节
    new_string = (char*)malloc(strlen(string) + 1);
    
    if (new_string != NULL) {
        strcpy(new_string, string);
    }
    return new_string;
}

