#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void show_array(const double ar[], int n);
double * new_d_array(int n, ...);

int main(){
    double * p1;
    double * p2;
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);
    return 0;
}

/**
new_d_array()函数接受一个int类型的参数和double类型的参数。
该函数返回一个指针，指向由malloc()分配的内存块。(指向元素类型为double的数组)
int类型的参数指定了动态数组中的元素个数，double类型的值用于初始化元素（第1个值赋给第1个元素，以此类推） 
 */
double * new_d_array(int n, ...)
{
    double *ptr,res[n];
    // 声明 va_list 类型变量
    va_list ap;
    // 初始化 变参列表
    va_start(ap, n);
    // 分配一块内存, 并让数组指向这块内存地址
    ptr = (double *)malloc(n * sizeof(double));     //参数是分配的内存字节数, 并且强转为所需类型
    // 获取参数列表中的每一项
    for (int i=0; i<n; i++) {
        *(ptr+i) = va_arg(ap, double);
    }
    va_end(ap);
    return ptr;
}

void show_array(const double ar[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%-12.4f", ar[i]);
        if (i % 6 == 5) {
            putchar('\n');
        }
    }
    
    putchar('\n');
}