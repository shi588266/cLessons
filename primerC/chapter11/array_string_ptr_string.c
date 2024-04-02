/**
 * 初始化数组时把静态存储区的字符串字面量拷贝到数组
 * 初始化指针时只把字符串字面量的地址拷贝给指针
 */
#include <stdio.h>
#define MSG "I am const string literal"

int main(void)
{
    char arr[] = MSG;    //字符串字面量赋值给数组
    const char * ptr = MSG;   //字符串字面量赋值给指针
    
    
    /**
     * "I am const string literal" store address is 0x400670
        MSG store address is 0x400670
        arr store address is 0x7ffcd68e90a0
        ptr store address is 0x400670
        "I am const string literal" store address is 0x400670
     */
    printf("\"I am const string literal\" store address is %p\n", "I am const string literal");
    printf("MSG store address is %p\n", MSG);
    printf("arr store address is %p\n", arr);
    printf("ptr store address is %p\n", ptr);
    printf("\"I am const string literal\"  store address is %p\n", "I am const string literal");
}