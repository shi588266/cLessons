/*
1.编写一个程序，从标准输入读取字符，并把它们写到标准输出中。
除了大写字母字符要转换为小写字母，所有字符的输出形式应该和它的输入形式完全相同。
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    while ( (ch = getchar()) != EOF) {
        putchar(tolower(ch));
    }
}