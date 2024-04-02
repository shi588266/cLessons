/**
 * 字符数组可能不是一个合法的字符串
 * 字符数组要想成为合法字符串需要包含 空字符 '\0'
 */
#include <stdio.h>

int main(void)
{
    char *char_str1 = "I am char_str1";
    // 这里初始化的字符数组不是一个合法的字符串
    char char_arr[] = {'N', 'o', 't', ' ', 'a', ' ', 's', 't', 'r'};
    char *char_str2 = "I am char_str2";
    // puts 需要一个字符串地址作为参数, 然后一直读取到第一个 空字符
    puts(char_arr); //Not a str@
}
