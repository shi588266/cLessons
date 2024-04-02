/**
 * 泛型表达式
 * _Generic 是 C11的关键字, 编译时请加上 -std=c11 参数 `gcc -std=c11 -Wall -o _11_16.13_generic_mytype _11_16.13_generic_mytype.c`
 * Linux下旧版本的gcc(低于V4.9), 不支持C11的_Generic新特性, 可以升级gcc编译器
 *  详情参考: https://www.cnblogs.com/jixiaohua/p/11732225.html
 */
#include <stdio.h>
// 使用泛型表达式定义类函数宏的替换内容, 使用\把逻辑行分割成多个物理行
#define MYTYPE(X) _Generic((X),\
int:"int",\
float:"float",\
double:"double",\
default:"other"\
)

int main(void)
{
    int d = 5;
    printf("%s\n", MYTYPE(d));
    printf("%s\n", MYTYPE(2.0*d));
    printf("%s\n", MYTYPE(3L));
    printf("%s\n", MYTYPE(&d));
    return 0;
}