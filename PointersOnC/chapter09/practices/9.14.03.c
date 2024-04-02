/*
3.编写一个名叫my_strcpy的函数。它类似于strcpy函数，但不会溢出目标数组。复制的结果必须是一个真正的字符串。

*/
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define NUL '\0'

char* my_strcpy(char *dest, const char *src, size_t size)
{
    strncpy(dest, src, size);
    *(dest + size-1) = NUL;
    return dest;
}

int main(void)
{
    char src[5] = "hello";
    char dest[10];
    my_strcpy(dest, src, 10);
    printf("dest=%s\n", dest);
    return 0;
}