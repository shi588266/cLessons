/*
10.编写函数
        int palindrome( char *string );
如果参数字符串是个回文，函数就返回真，否则就返回假。回文就是指一个字符串从左向右读和从右向左读是一样的。
函数应该忽略所有的非字母字符，而且在进行字符比较时不用区分大小写。
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
声明两个指针分别指向字符串头和尾
两个指针同时向中间移动,直到指针交叉
每次判断两个指针指向的字符是否相等
*/
int palindrome( char *string )
{
    char *head, *rear;
    int len = strlen(string);
    head = string;
    rear = string + len - 1;
    //printf("head = %c,rear=%c\n", *head, *rear);
    while (rear > head) {
        printf("head = %c,rear=%c\n", *head, *rear);
        if (!isalpha(*head)) {
            head++;
            continue;
        } else if (!isalpha(*rear)) {
            rear--;
            continue;
        } else {
            if (tolower(*head) != tolower(*rear)) {
                return 0;
            }
        }
        head++;
        rear--;
    }
    
    return 1;
}

int main(void)
{
    char *test = "a bcde dcba";
    if (palindrome(test)) {
        printf("%s is cycle text\n", test);
    } else {
        printf("%s is not cycle text\n", test);
    }
}