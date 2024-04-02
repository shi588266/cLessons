/*
3.编写函数reverse_string，它的原型如下：
        void reverse_string( char *string );
函数把参数字符串中的字符反向排列。请使用指针而不是数组下标，不要使用任何C函数库中用于操纵字符串的函数。
提示：不需要声明一个局部数组来临时存储参数字符串。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUL '\0'

void reverse_string( char *string );

int main(void)
{
    char test_str[] = "abcdefgHIJKLMN";//声明为数组而非指针
    reverse_string(test_str);
    printf("now test string is %s\n\n", test_str);
}

/*
思路:
    获取字符串的长度,对字符指针加上字符串的长度,可以获得字符串末尾的字符,
    递减字符串长度变量, 依照上法依次获取倒数第二,第三...字符 
*/
void reverse_string( char *string )
{
    int str_len = 0;
    char *str_p = string;//记录字符串最初始的指针
    while (*str_p++ != NUL) {
        str_len++;
    }
    printf("string len = %d\n", str_len);
    char temp_char;
    /*遍历字符串的一半即可全部交换*/
    for (int i = 0; i < str_len/2+1; i++) {
        temp_char = *(string + i);
        //printf("temp_char = %c\n", temp_char);
        *(string + i) = *(string + str_len - 1 - i);
        *(string + str_len - 1 - i) = temp_char;
    }
}