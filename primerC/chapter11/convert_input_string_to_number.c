/**
 * long strtol(const char * restrict orig_ptr, char ** end_ptr, int base);
 * 使用 strtol() 把输入字符串转换为 数字
 * orig_ptr 是要转换的字符串指针, 
 * end_ptr 是一个指针, 它指向的内容是 标识输入数字结束字符的地址
 * base 表示以什么进制写入数字
 */

#include <stdio.h>
#include <stdlib.h> //strtol 函数声明在这个头文件中
#include <ctype.h>

#define LIMIT 100   //限制输入字符长度

char * s_gets(char *, int n);
int main(void)
{
    char storage[LIMIT];
    char * end;
    long value;
    puts("Enter a number,empty line to quit:");
    while( (s_gets(storage, LIMIT) != NULL) && storage[0] != '\0' ) {
        printf("storage[0]=%d \n", storage[0]);
        value = strtol(storage, &end, 10);
        printf("base 10 input, base 10 output: %ld,stop at %s (%c)\n", value, end, *end);
        
        value = strtol(storage, &end, 16);
        printf("base 10 input, base 16 output: %ld,stop at %s (%c)\n", value, end, *end);
        puts("Next number please:");
    }
}

char * s_gets(char *input, int n)
{
    char * ret;
    ret = fgets(input, n, stdin);
    int i = 0;
    if ('\n' == input[0])
        input[0] = '\0';

    while ('\0' != input[i] && '\n' != input[i]) {
        i++;
        if ('\0' == input[i]) {
            while ('\n' != getchar())
                continue;
        }
        if ('\n' == input[i])
            input[i] = '\0';
    }
    return ret;
}