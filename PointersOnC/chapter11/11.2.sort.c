/*
排序一列整型值 sort.c
*/
#include <stdio.h>
#include <stdlib.h>

/*自定义比较函数*/
int compare_integers(void const *a, void const *b)
{
    //声明寄存器指针 指向待比较的指针
    register int const *pa = a;
    register int const *pb = b;
    return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}

int main(void)
{
    int n_values;
    int *ap;
    
    /*根据输入获取整数个数*/
    puts("Enter an integer value as the number of array");
    if ( (scanf("%d", &n_values) != 1) || n_values <= 0 ) {
        printf("Invalid number provided\n");
        exit(1);
    }
    
    /*给数组分配内存*/
    ap = malloc(n_values * sizeof(int));
    if (ap == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    
    //读取值
    for (int i = 0; i < n_values; i++) {
        printf("?");
        if (scanf("%d", ap + i) != 1) {
            printf("Error reading value.\n");
            free(ap); //读取失败, 释放分配的内存空间
            exit(1);
        }
    }
    
    /*调用 qsort 对值进行排序*/
    qsort(ap, n_values, sizeof(int), compare_integers);
    /*打印这些值*/
    puts("sorted list is:")
    for (int i = 0; i < n_values; i++) {
        printf("%d\n", ap[i]);
    }
    /*释放内存*/
    free(ap);
    
    return EXIT_SUCCESS;
}

