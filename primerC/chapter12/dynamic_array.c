/**
 * 使用 malloc() 创建动态数组, malloc 创建的动态数组只在程序运行时才为其分配内存
 * malloc() 函数的参数是需要分配内存块的字节数
 * 返回值是指向分配内存块的指针  
 * 
 * free() 用于释放参数指向的内存块, 但是不能释放静态数组占用的内存
 */
#include <stdio.h>
#include <stdlib.h> //提供 malloc(), free() 函数原型 EXIT_FAILURE

int main(void)
{
    int max;    //动态数组内实体数量
    int number;
    int i = 0;  //动态无链接块作用域(函数块)
    double * dptr;
    
    printf("What the maximum number of double entities.\n");
    if(scanf("%lu", &max) != 1) {   //输入错误
        puts("Number not correctlly entered. Bye.");
        exit(EXIT_FAILURE);
    }
    //把内存块赋值给指针
    dptr = (double *)(malloc(max * sizeof(double)));
    if (NULL == dptr) { //内存分配失败
        puts("Memory allocation failed.Bye.");
        exit(EXIT_FAILURE);
    }
    
    // dptr 现在指向有 max 个double 元素的数组
    // 通过下面while循环内的scanf语句给数组元素赋值
    puts("Enter the values:");
    while (i < max && scanf("%lf", &dptr[i]) == 1) {
        i++;    //动态无链接块作用域(while 块)
    }
    
    //输出所有元素
    printf("Here are all the %d entities:\n", number = i);
    for (i = 0; i < number; i++) {
        printf("%7.2f", dptr[i]);
        if (i % max == max - 1) {   //最后需要输出换行
            putchar('\n');
        }
    }
    puts("Done.");
    free(dptr);     //如果不主动使用free释放内存, malloc申请的内存在程序结束前会一直占用
    return 0;
}