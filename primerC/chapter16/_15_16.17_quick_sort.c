/**
 * 构造随机数组, 使用qsort快速排序
 */
#include <stdio.h>
#include <stdlib.h>
#define NUM 40   //定义数组大小

//构造随机数组的函数
void fillarray(double arr[], int n);
// 格式化显示数组
void showarray(double arr[], int n);
// 自定义比较函数
int mycompare(const void *, const void *);

int main(void)
{
    double vals[NUM];
    fillarray(vals, NUM);
    puts("Random list:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(double), mycompare);
    puts("Sorted list:");
    showarray(vals, NUM);
    return 0;
}

//构造随机数组
void fillarray(double arr[], int n)
{
    for (int i = 0; i < n; i++) {
        /* code */
        arr[i] = (double)rand()/((double)rand() + 0.1);
    }
}
// 格式化显示数组
void showarray(double arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%9.4lf", arr[i]);
        if (i % 6 == 5) {
            putchar('\n');
        }
    }
    
    if (i % 6 != 0) {
        putchar('\n');
    }
}
// 自定义比较函数
int mycompare(const void *p1, const void *p2)
{
    // 使用指向 double 的指针来访问这两个值
    const double *dbnum1 = (const double *)p1;
    const double *dbnum2 = (const double *)p2;
    if (*dbnum1 > *dbnum2) {
        return 1;
    }
    if (*dbnum1 < *dbnum2) {
        return -1;
    }
    if (*dbnum1 == *dbnum2) {
        return 0;
    }
    return 0;
}