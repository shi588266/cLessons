/**
4.编写一个程序，一行行地读取输入行，直至到达文件尾。
算出每行输入行的长度，然后把最长的那行打印出来。为了简单起见，你可以假定所有的输入行均不超过1000个字符
 */
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

int main(void)
{
    int ch;
    int lineLength;     /*每行的长度*/
    int maxLength;      /*已读取行的最大长度*/
    char outPut[MAX_SIZE];  /*输出内容*/
    char temp[MAX_SIZE];    /*临时存储输入内容*/
    maxLength = lineLength = 0;
    
    /*getchar()正常读入换行符*/
    while ( (ch = getchar()) != EOF ) {
        temp[lineLength++] = ch;
        /*读取到每行末尾*/
        if ('\n' == ch) {
            if (maxLength == 0 || lineLength > maxLength) {
                /*内容拷贝*/
                strcpy(outPut, temp);
            }
            /*重置每行的长度*/
            lineLength = 0;
        }
    }
    
    puts("The longest line is:");
    puts(outPut);
    return 0;
}