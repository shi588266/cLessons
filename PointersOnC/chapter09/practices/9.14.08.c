/*
8.编写一个名叫my_strnchr的函数，它的原型如下：
        char *my_strnchr( char const *str, int ch, int which );
这个函数类似于strchr函数，但它的第3个参数指定ch字符在str字符串中第几次出现。
例如，如果第3个参数为1，这个函数的功能就和strchr完全一样。如果第3个参数为2，这个函数就返回一个指向ch字符在str字符串中第2次出现的位置的指针。
*/
#include  <stdio.h>

#define NUL '\0'

char *my_strrchr( char const *str, int ch, int which )
{
    char *find = NULL;
    int counter = 0;
    while ( *str != NUL) {
        if (*str == ch) {
            if (++counter == which) {
                find = (char*)str;
                break;
            }
        }
        str++;
    }
    
    return find;
}


int main(void)
{
    char *test = "Test hello world,and something no sence.";
    char *find;
    int search = 'e';
    int which = 3;
    if ( (find = my_strrchr(test, search, which)) != NULL ) {
        printf("Found '%c',position is %s\n", search, find);
    } else {
        puts("not found");
    }
    
    return 0;
}