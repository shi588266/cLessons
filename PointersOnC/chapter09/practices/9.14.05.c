/*
5.编写下面的函数：
        void my_strncat( char *dest, char *src, int dest_len );
它用于把src中的字符串连接到dest中原有字符串的末尾，但保证不会溢出长度为dest_len的dest数组。
和strncat函数不同，这个函数也会考虑原先存在于dest数组的字符串长度，因此能够保证不会超越数组边界。
*/
#include <stdio.h>
#include <string.h>

void my_strncat( char *dest, char *src, int dest_len )
{
    int dest_str_len = strlen(dest);
    if (dest_str_len + 1 >= dest_len) {
        return;
    }
    
    while (dest_str_len < dest_len && *src != '\0') {
        dest[dest_str_len] = *src++;
        dest_str_len++;
        dest_len++;
    }
}

int main(void)
{
    char dest[20] = {0};
    char test[10] = "";
    
    printf("sizeof('123')=%d\n", sizeof("123"));    //结果为 4
    printf("test len = %d\n", strlen(test));        //结果为 0
    printf("dest len = %d\n", strlen(dest));        //结果为 1
    
    printf("dest=%s\n", dest);
    my_strncat(dest, "test hello", 20);
    printf("dest=%s\n", dest);
    my_strncat(dest, " test 1234", 20);
    printf("dest=%s\n", dest);
}