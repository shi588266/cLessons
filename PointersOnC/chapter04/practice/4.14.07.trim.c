/*
7.编写一个函数，从一个字符串中去除多余的空格。函数的原型如下:
    void deblank( char string[] );
当函数发现字符串中如果有一个地方由一个或多个连续的空格组成时，就把它们改成单个空格字符。
注意，在遍历整个字符串时，要确保它以NUL字符结尾。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 128

void delblank(char string[]);
char *s_gets(char *, int);

int main(void)
{
    char input[MAX_LEN];
    puts("Enter your sentense,continuiously blank will be shorted to a space charactor");
    while (s_gets(input, MAX_LEN) != NULL) {
        printf("original input is %s\n", input);
        delblank(input);
        printf("delblank output is %s\n\n", input);
        
        puts("Enter another sentense");
    }
}

/*定义两个索引值, 一个用于记录原字符串步进值, 另一个用于记录删除空格后的字符串的步进值*/
void delblank(char string[])
{
    int i = 0;
    int j = 0;
    
    while (string[i] != '\0') {
        /*读取到连续的空格字符, 就一直循环, 直到读取到第一个非空白字符*/
        if (string[i] == ' ') {
            while (string[j] == ' ') {
                j++;
            }
            string[i] = string[j--];
        } else {
            string[i] = string[j];
        }
        i++;
        j++;
    }
}

char *s_gets(char *str, int len)
{
    char *temp,*find;
    temp = fgets(str, len, stdin);
    if (temp != NULL) {
        find = strchr(str, '\n');
        if (find) {
            *find = '\0';
        } else {
            while (getchar() != '\n')
                ;
        }
    }
    return temp;
}