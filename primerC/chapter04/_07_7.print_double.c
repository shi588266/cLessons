/**
7.编写一个程序，将一个double类型的变量设置为1.0/3.0，一个float类型的变量设置为1.0/3.0。
分别显示两次计算的结果各3次:
    一次显示小数点后面6位数字;
    一次显示小数点后面12位数字:
    一次显示小数点后面16位数字。
程序中要包含float.h头文件，并显示FLT_DIG和DBL_DIG的值。1.0/3.0的值与这些值一致吗?
 */
#include <stdio.h>
#include <float.h>

int main(void)
{
    float flv = 1.0/3.0;
    double dbl = 1.0/3.0;
    
    printf("小数点后6位: %.6f \n", flv);
    printf("小数点后12位: %.12f \n", flv);
    printf("小数点后16位: %.16f \n", flv);
    
    printf("\n");
    printf("小数点后6位: %.6f \n", dbl);
    printf("小数点后12位: %.12f \n", dbl);
    printf("小数点后16位: %.16f \n", dbl);
    
    printf("\n");
    printf("FLT_DIG=%d, DBL_DIG=%d\n", FLT_DIG, DBL_DIG);
}