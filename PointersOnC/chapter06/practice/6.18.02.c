/*
2.编写一个函数，删除一个字符串的一部分。函数的原型如下：
    int del_substr( char *str, char const *substr )
    
函数首先应该判断substr是否出现在str中。如果它并未出现，函数就返回0；如果出现，函数应该把str中位于该子串后面的所有字符复制到该子串的位置，从而删除这个子串，然后函数返回1。如果substr多次出现在str中，函数只删除第1次出现的子串。函数的第2个参数绝不会被修改。
一个值得注意的地方是，空字符串是每个字符串的一个子串，在字符串中删除一个空子串字符串不会产生变化。
*/

#include <stdio.h>

#define NUL '\0'

int del_substr( char *str, char const *substr );

int main(void)
{
    char test_str[] = "ABCaEFGabcXYZabcd";
    del_substr( test_str, "abcd" );
    printf("now test string is: %s\n\n", test_str);
    return 0;
}

/*
逐字符比较两个字符串的每个字符, 如果相等, 计数加一, 比较他们的下一个字符
如果不相等, 重置计数
*/
int del_substr( char *str, char const *substr) 
{
    char substr_char;
    char str_char;
    char *substr_p = (char *)substr;
    int substr_len = 0;
    int initialized = 0;/*是否是第一次匹配字符*/
    while (*substr != NUL) {
        substr_char = *substr;
        while (*str != NUL) {
            str_char = *str;
            str++;
            if (str_char == substr_char) {
                substr_len++;
                substr++;
                break;
            } else {
                //printf("substr_len = %d\n", substr_len);
                if (substr_len > 0) {
                    substr -= substr_len;
                    substr_len = 0;
                    break;
                }
            }
        }
        /*如果长字符串已到最后,但是子字符串还没结束,说明没有找到*/
        if (*str == NUL && *substr != NUL) {
            printf("没找到%s\n", substr_p);
            return 0;
        }
    }
    
    if (substr_len != 0) {
        printf("找到了%s\n", substr_p);
        do {
            *(str-substr_len) = *str;
            str++;
        } while (*str != NUL);
        *(str-substr_len) = *str;
        return 1;
    }
    printf("没找到%s\n", substr_p);
    return 0;
}