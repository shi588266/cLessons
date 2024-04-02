/**
2.编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确地成对出现。
注意：不必担心注释内部、字符串常量内部和字符常量形式的花括号。

    思路:使用计数器, 遇到{计数器加一, 遇到}计数器减一
    如果最终的计数值不为0, 则花括号不是成对儿出现的
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ch;
    int braces = 0; /*左大括号出现的次数*/
    
    while ((ch = getchar()) != EOF) {
        if ('{' == ch) {
            braces += 1;
        }
        
        if ('}' == ch) {
            if (braces <= 0) {
                puts("Extra closing braces");
                exit(EXIT_FAILURE);
            } else {
                braces -= 1;
            }
        }
        
        if (braces > 0) {
            printf("%d unmatched opening braces\n", braces);
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}