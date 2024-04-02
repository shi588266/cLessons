/**
3.使用嵌套循环，按下面的格式打印字母:
F
FE
FED
FEDC
FEDCB
FEDCBA

注意:如果你的系统不使用ASCII或其他以数字顺序编码的代码，可以把字符数组初始化为字母表中的字母:
char lets[27] ="ABCDEFGHIKLMNOPORSTUVWXYZ"
 */
#include <stdio.h>
#define INIT_CHAR 'F'
#define LINE_NUM 8

int main(void)
{ 
    int line,column;
    for (line = 1; line <= LINE_NUM; line++) {
        for (column = 0; column < line; column++) {
            putchar(INIT_CHAR - column);
        }
        printf("\n");
    }
}