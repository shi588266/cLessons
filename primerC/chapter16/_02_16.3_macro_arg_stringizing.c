/*
 * C允许在字符串中包含宏参数。在类函数宏的替换体中，
 #号作为一个预处理运算符，可以把记号转换成字符串。
 例如，如果x是一个宏形参，那么#x就是转换为字符串"x"的形参名。
 同时利用了 ANSI C字符串的串联特性
 */
#include <stdio.h>
#define PSQR(x) printf("The square of " #x " is %d.\n",((x)*(x)))   //定义类函数宏

int main(void)
{
    int y = 5;
    PSQR(y);    //The square of y is 25.
    PSQR(2 + 4);    //The square of 2 + 4 is 36.
    
    return 0;
}