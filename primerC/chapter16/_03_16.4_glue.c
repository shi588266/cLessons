/*
 * ##运算符把两个记号组合成一个记号
 */
#include <stdio.h>
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x" #n " =%d\n", x##n);

int main(void)
{
    int XNAME(1) = 14;
    int XNAME(2) = 20;
    int x3 = 30;
    
    PRINT_XN(1);
    PRINT_XN(2);
    PRINT_XN(3);
    
    return 0;
}