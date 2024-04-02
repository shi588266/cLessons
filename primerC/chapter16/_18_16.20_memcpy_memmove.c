/**
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
_Static_assert(sizeof(double) == 2 * sizeof(int), "Double size is not int twice");

//函数原型
void show(int intarr[], int n);

int main(void)
{
    int target[SIZE];
    int intarr[SIZE] = {0,1,2,3,4,5,6,7,8,9};   //整数数组
    double dblarr[SIZE/2] = {2.0,2.0E5,2.0E10,2.0E20,5.0E30};   //浮点数组
    puts("memcpy used:");
    puts("values original data:");
    show(intarr, SIZE);
    memcpy(target, intarr, SIZE * sizeof(int));   //第三个参数是拷贝的字节数
    puts("target data:");
    show(target, SIZE);
    // 使用 memmove, 注意目标数组指针和原数组指针有重叠
    puts("\n\n使用memmove 拷贝有重叠区间");
    memmove(intarr + 2, intarr, 5 * sizeof(int));
    puts("intarr--0-4的数据内容拷贝到2-6:");
    show(intarr, SIZE);
    puts("\n\n使用memcpy,double数组拷贝到int数组");
    memcpy(target, dblarr, SIZE/2 * sizeof(double));
    puts("targe---5个double拷贝到10个int位置:");
    show(target, SIZE/2);
    show(target+5, SIZE/2);
    return 0;
}

void show(int intarr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%11d", intarr[i]);
    }
    putchar('\n');
}