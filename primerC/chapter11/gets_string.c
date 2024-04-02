/*
* 使用gets 获取输入的字符串
*/
#include <stdio.h>
#define SLEN 1

int main(void)
{
    char str[SLEN];
    printf("Enter a string\n");
    
    gets(str);  //获取键盘输入, 获取一整行
    printf("The content you input is:\n");
    printf("%s\n", str);
    puts(str);
    printf("done\n");
    return 0;
}