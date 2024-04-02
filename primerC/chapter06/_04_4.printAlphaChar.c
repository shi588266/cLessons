/**
4.使用嵌套循环，按下面的格式打印字母:
A
BC
DEF
GHIJ
KLMNO
PORSTU
 */
#include <stdio.h>
#define LINE_NUM 6

int main(void)
{
    int line,column,count;
    char lets[27] ="ABCDEFGHIJKLMNOPORSTUVWXYZ";
    
    for (line = 0,count = 0; line < LINE_NUM; line++) {
        for (column = 0; column <= line; column++) {
            putchar(lets[count++]);
        }
        printf("\n");
    }
}