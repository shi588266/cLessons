/*
6.编写一个名叫 my_strcpy_end 的函数，用来取代strcpy函数，它返回一个指向目标字符串末尾的指针（也就是说，指向NUL字节的指针），而不是返回一个指向目标字符串起始位置的指针

*/
#include <stdio.h>

char* my_strcpy_end(char *dest, char *src)
{
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest;
}

int main(void)
{
    char dest[10] = "hello";
    char src[10] = "HELLO";
    printf("dest=%s\t", dest);
    my_strcpy_end(dest, src);
    printf("dest=%s\n", dest);
    
    return 0;
}