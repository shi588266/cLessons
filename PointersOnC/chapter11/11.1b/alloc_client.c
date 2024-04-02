/*
使用 MOLLOC 宏
注意跨目录编译
    gcc -std=c11 -o alloc_client alloc_client.c ../11.1a/alloc.c
*/
#include <stdio.h>
#include "../11.1a/alloc.h"    //引入头文件

int main(void)
{
    int *new_memory;
    new_memory = MOLLOC(25, int);
    
    for (int i = 0; i < 24; i++) {
        new_memory[i] = i;
        printf("new_memory[i]=%d\n", new_memory[i]);
    }
    new_memory[24] = '\0';
    
    printf("contents is %s\n", new_memory);
}