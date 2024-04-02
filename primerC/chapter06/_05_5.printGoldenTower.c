/**
5.编写一个程序，提示用户输入大写字母。使用嵌套循环以下面金字塔型的格式打印字母:
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

打印这样的图形，要根据用户输入的字母来决定。例如，上面的图形是在用户输入E后的打印结果。
提示:用外层循环处理行，每行使用3个内层循环，分别处理空格、以升序打印字母、以降序打印字母。
如果系统不使用ASCII或其他以数字顺序编码的代码，请参照练习3的解决方案。
 */
#include <stdio.h>
#define LINE_NUM 8

int main(void)
{
    char charIn;
    int line,column,totalLine;
    char lets[27] ="ABCDEFGHIJKLMNOPORSTUVWXYZ";
    
    puts("Enter an upper alpha");
    while (scanf("%c", &charIn) == 1 && charIn >= 'A' && charIn <= 'Z') {
        // 处理行
        totalLine = charIn - lets[0] + 1;
        
        for (line = 1; line <= totalLine; line++) {
            // 处理空格:左侧空格数量= t-1
            for (column = 1; column <= totalLine - line; column++) {
                putchar(' ');
            }
            // 以升序打印字母: 字母个数为 n-1
            for (column = 1; column <= line - 1; column++) {
                putchar(lets[column - 1]);
            }
            putchar(lets[line - 1]);
            for (column = 1; column <= line - 1; column++) {
                putchar(lets[line - 1 - column]);
            }
            printf("\n");
        }
        
        puts("Enter another upper alpha");
    }
    
    puts("Done!");
    return 0;
}