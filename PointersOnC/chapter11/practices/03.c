/*
3.编写一个函数，从标准输入读取一个字符串，把字符串复制到动态分配的内存中，并返回该字符串的副本。
这个函数不应该对读入字符串的长度作任何限制！
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELTA 256

/*
使用getchar()逐个读取字符
*/
char *readstr()
{
    int buffer_size = DELTA;
    int cnt;
    int chr;
    char *buffer = malloc((DELTA + 1) * sizeof(char));
    if (NULL == buffer) {
        return NULL;
    }
    char *bp = buffer;  //声明一个字符指针指向分配的内存空间地址
    do {
        chr = getchar();
        if (chr == '\n' || chr == EOF) {
            chr = '\0'; //换行符和结束符都被当作字符串结尾
        }
        if(cnt > buffer_size){
            buffer_size += DELTA;
            buffer = realloc(buffer, buffer_size * sizeof(char)); //重新分配
            bp = buffer + cnt;  //由于buffer指向的内存地址有可能被重新分配了, 需要再次指向新分配的地址
        }
        *bp = chr;
        bp++;   //字符指针递进
        cnt++;  //字符串长度递增
    } while(chr != '\0');
    
    /*重新分配内存地址,避免内存浪费*/
    bp = malloc(cnt * sizeof(char));
    if (NULL == buffer) {
        return NULL;
    }
    /*返回字符串副本*/
    strcpy(bp, buffer);
    return bp;
}

int main(void)
{
    char *string;
    string = readstr();
    printf("string = %s\n", string);
    return 0;
}