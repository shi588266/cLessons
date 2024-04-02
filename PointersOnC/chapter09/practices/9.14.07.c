/*
7.编写一个名叫my_strrchr的函数，它的原型如下：
        char *my_strrchr( char const *str, int ch );
这个函数类似于strchr函数，只是它返回的是一个指向ch字符在str字符串中最后一次出现（最右边）的位置的指针。
*/
#include  <stdio.h>

#define NUL '\0'

char *my_strrchr( char const *str, int ch )
{
    char *find = NULL;
    while ( *str != NUL) {
        if (*str == ch) {
            find = (char*)str;
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
    if ( (find = my_strrchr(test, search)) != NULL ) {
        printf("Found %c,position is %s\n", search, find);
    } else {
        puts("not found");
    }
    
    return 0;
}