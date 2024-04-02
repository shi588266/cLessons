/*
4.编写一个名叫my_strcat的函数。它类似于strcat函数，但不会溢出目标数组。它的结果必须是一个真正的字符串。
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUL '\0'

void my_strcat(char *dest, const char *src, const int size_dest)
{
    // 获取目标字符串的长度与目标数组容量进行比较
    int dest_len = strlen(dest);
    if (dest_len + 1 > size_dest) { 
        exit(EXIT_FAILURE);
    }
    
    /*逐个追加*/
    int src_index = 0;
    while (dest_len < size_dest && *src != NUL) {
        dest[dest_len] = src[src_index];
        dest_len++;
        src_index++;
    }
    
    /*目标数组最后一个元素设置为空字节*/
    if (dest_len == size_dest) {
        dest[dest_len - 1] = NUL;
    } else {
        dest[dest_len] = NUL;
    }
}

int main(void)
{
    char src[10] = "hello";
    char dest[100] = "";
    my_strcat(dest, src, 100);
    printf("dest=%s\n", dest);
    my_strcat(dest, " world!", 100);
    printf("dest=%s\n", dest);
}