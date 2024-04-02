/**
2.使用嵌套循环，按下面的格式打印字符:
$
$$
$$$
$$$$
$$$$$
$$$$$$
tips: 每一行打印行数对应个数的字符
 */
#include <stdio.h>
#define PRINT_CHAR '$'
#define LINE_NUM 6

int main(void)
{
    int line,column;
    for (line = 1; line <= LINE_NUM; line++) {
        for (column = 0; column < line; column++) {
            putchar(PRINT_CHAR);
        }
        printf("\n");
    }
}