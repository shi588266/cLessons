/**
 * stdarg.h 头文件提供了实现 变参函数 需要的几个宏
 *      va_list 类型, 用于存储参数列表
 *      va_start(va_list ap, int arg_count); // 把ap初始化为参数列表
 *      va_arg(va_list ap, typeof); //一个va_list类型的变量和一个类型名
 *      va_end(va_list ap); //释放动态分配用于储存参数的内存。该宏接受一个va_list类型的变量
 *      va_copy(); //C99新增,该宏接受两个va_list类型的变量作为参数，它把第2个参数拷贝给第1个参数
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/** 
变参函数原型, 至少包含两个参数,
    倒数第一个...,表示被省略的参数列表
    倒数第二个paramN,表示被省略的参数数量
*/
double sum(int, ...);

int main(void)
{
    double res1,res2;
    res1 = sum(3, 1,2,3);
    res2 = sum(6, 1.0,2.0,3.0,4.0,5.0,6.0);
    printf("sum(3, 1,2,3) is %10.4f\n", res1);
    printf("sum(6, 1.0,2.0,3.0,4.0,5.0,6.0) is %10.4f\n", res2);
    return 0;
}

double sum(int omittedArgCnt, ...)
{
    int i;
    double total = 0.0;
    // 1. 声明一个 va_list 对象, 用于存储参数列表
    va_list argList;
    // 2. 初始化参数列表
    va_start(argList, omittedArgCnt);
    // 获取参数列表中的每一项
    for (i=0; i<omittedArgCnt; i++) {
        total += va_arg(argList, double);
    }
    return total;
}