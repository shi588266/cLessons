/**
 **编写一个程序，从标准输入读取几行输入。每行输入都要打印到标准输出上，前面要加上行号。
 **在编写这个程序时要试图让程序能够处理的输入行的长度没有限制。
 *      思路: 逐字符读取输入, 而不是逐行读取
 *      通过判断读取到字符是否是'\n', 确定是否到达一行的末尾
 */
#include <stdio.h>
#include <stdbool.h>


int main(void)
{
    int ch;
    int lineNo = 1; /*行号初始化为1*/
    bool atBeginning = true; /*起始状态*/
    
    puts("Enter something what you prefer:");
    while ((ch = getchar()) != EOF) {
        if (atBeginning) {
            printf("lineNo = %d: ", lineNo);
            atBeginning = false;
            lineNo++;
        }

        /*如果到达行末尾, 改变起始状态*/
        if ('\n' == ch) 
            atBeginning = true;

        putchar(ch);
    }
    puts("Done!");
    return 0;
}