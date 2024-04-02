/*
3.为下面这个函数原型编写函数定义：
               int ascii_to_integer( char *string );
这个字符串参数必须包含一个或多个数字，函数应该把这些数字字符转换为整数并返回这个整数。如果字符串参数包含了任何非数字字符，函数就返回零。不必担心算术溢出。提示：这个技巧很简单——每发现一个数字，就把当前值乘以10，并把这个值和新数字所代表的值相加
*/
#include <stdio.h>
#include <ctype.h>
#define NUL '\0'

int ascii_to_integer(char *string);

int main(void)
{
    char test_number[10] = "654123";
    printf("test_number = %d\n", ascii_to_integer(test_number));
}

/*数字字符串转整数*/
int ascii_to_integer(char *string)
{
    int int_value = 0;
    int char_value;
    while ((char_value = *string) != NUL) {
        //printf("char_value = %c\n", char_value);
        if (!isdigit(char_value)) {
            return 0;
        }
        char_value -= '0';  //数字字符与 '0' 相减得到数字字符的数值
        //printf("char_value = %d\n", char_value);
        int_value = int_value * 10 + char_value;
        string++;
    }
    return int_value;
}