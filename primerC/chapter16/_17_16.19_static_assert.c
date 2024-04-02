/**
 * C11 新特性
 * _Static_assert声明，可以在编译时检查assert()表达式,
 * _Static_assert()接受两个参数。第1个参数是整型常量表达式，
 * 第2个参数是一个字符串。如果第1 个表达式求值为0（或_False），
 * 编译器会显示字符串，而且不编译该程序
 */
#include <stdio.h>
#include <limits.h>

_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");

int main(void)
{
    puts("char is 16 bits.");
    return 0;
}

