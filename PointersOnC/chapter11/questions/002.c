/*
//linux下可以调用malloc_usable_size函数来获取实际分配的内存
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p;
    p = malloc(500 * sizeof(char));
    printf("%u", malloc_usable_size(p));
    free(p);
    p = malloc(5000 * sizeof(char));
    printf("\n%u", malloc_usable_size(p));
    free(p);
    return 0;
}