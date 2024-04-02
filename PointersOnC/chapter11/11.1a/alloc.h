/*
不易发生错误的内存分配器
*/
#include <stdlib.h>

#define malloc  /*禁止直接调用 malloc*/
#define MOLLOC(num, type) (type*)alloc((num) * sizeof(type)) /*声明类函数宏,注意返回值的强制类型转换, 以及参数的*/

extern void* alloc(size_t size);    /*alloc声明为外部函数*/