/*
1.下面这个表达式的类型和值分别是什么？
(float)( 25 / 10 )
 
 结论: 表达式的类型是强制类型转换后的类型, 表达式的值是2.000000
*/
#include <stdio.h>

int main(void)
{
    printf("(float)(25/10) = %d, (float)(25/10) = %f, (float)(25/10) = %lf\n\n", (float)(25/10), (float)(25/10), (float)(25/10));
}

