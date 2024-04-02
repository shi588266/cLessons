/*

*/
#include <stdio.h>
#include "alloc.h"
#undef malloc   /*释放宏定义, 确保当前文件后面可以正常使用 malloc 函数*/

/*实际的 alloc 函数体定义*/
void* alloc(size_t size)
{
    void *new_mem;  //声明void类型的指针
    /*内部通过调用 malloc 实现, 只是对 malloc 的调用结果进行错误处理, 以实现统一处理*/
    new_mem = malloc(size);
    if ( new_mem == NULL ) {
        printf("Error memory allocated\n");
        exit(EXIT_FAILURE);
    }
    return new_mem;
}