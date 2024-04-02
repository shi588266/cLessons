/**
编写一个函数，它在一个字符串中进行搜索，查找在一个给定字符集合中出现的所有字符:
它的基本想法是查找source字符串中匹配chars字符串中任何字符的第1个字符，
然后返回一个指向source中第1个匹配所找到的位置的指针。如果source中的所有字符均不匹配chars中的任何字符，
就返回一个NULL指针。如果任何一个参数为NULL，或任何一个参数所指向的字符串为空，函数也返回一个NULL指针。
        char *find_char( char const *source, char const *chars );
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *find_char( char const *source, char const *chars );

int main(void)
{
    char * source = "abcdefg";
    char * chars = "xyzdog";
    char *find;
    find = find_char(source, chars);
    printf("find %c in the %s\n", *find, source);
    return 0;
}

/*
思路: 遍历source里每一个字符, 与chars里的每个字符进行比较
*/
char *find_char( char const *source, char const *chars )
{
    bool match = false;
    char *source_temp = (char*)source;
    char *chars_temp = (char*)chars;

    while (*source_temp != '\0') {
        while (*chars_temp != '\0') {
            if (*source_temp == *chars_temp) {
                return source_temp;
            }
            chars_temp++;
        }
        chars_temp = (char*)chars;/*必须重置匹配字符串指针*/
        source_temp++;
    }
    
    return NULL;
}