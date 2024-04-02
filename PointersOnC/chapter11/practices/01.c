/*
1.请自己尝试编写calloc函数，函数内部使用malloc函数来获取内存
*/

#include <stdio.h>
#include <stdlib.h>

void* calloc(size_t number_elements, size_t element_size)
{
    void *mp;
    int total_byte = number_elements * element_size;
    mp = malloc(total_byte);
    if (mp == NULL) {
        printf("Error allocate memory\n");
        exit(1);
    }
    return mp;
}