/*
2.编写一个程序，从标准输入读取字符，并把它们写到标准输出中。所有非字母字符都完全按照它的输入形式输出，字母字符在输出前进行加密。加密方法很简单：每个字母被修改为在字母表上距其13个位置（前或后）的字母。例如，A被修改为N，B被修改为O，Z被修改为M，以此类推。注意，大小写字母都应该被转换。提示：记住字符实际上是一个较小的整型值这一点可能对你有所帮助。
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    while ( (ch = getchar()) != EOF ) {
        if (ch >= 'A' && ch <= 'M') {
            ch += 13;
        }
        else if (ch > 'M' && ch < 'a') {
            ch -= 13;
        } else if (ch >= 'a' && ch <= 'm') {
            ch += 13;
        } else if (ch > 'm') {
            ch -= 13;
        }
        putchar(ch);
    }
}