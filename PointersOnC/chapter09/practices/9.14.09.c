/*
9.编写一个函数，它的原型如下：
        int count_chars( char const *str, char const *chars );
函数应该在第1个参数中进行查找，并返回匹配第2个参数所包含的字符的数量。
*/
#include <stdio.h>
#include <string.h>
#define LEN 10086
#define NUL '\0'

int count_chars( char const *str, char const *chars )
{
    unsigned int counter = 0;
    char *find;
    size_t sz;
    while ( str && *str ) {
        str = strpbrk(str, chars);
        if (str) {
            sz = strspn(str, chars);
            printf("sz=%d\n", sz);
            //return 0;
            str += sz;
            counter += sz;
        } 
    }
    
    return counter;
}

int main(void)
{
    const char* test = "ooTest hello world.Something no sence.";
    const char* sep = "aeiou";
    unsigned int cnt = 0;
    printf("counter is %d\n", count_chars(test, sep));
}