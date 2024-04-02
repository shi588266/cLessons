/**
* 一些预定义宏和预定义标识符
* __STDC_VERSION__ 是C99新增的，所以不支持C99的编译器可能无法识别它们
* 如果使用GCC，必须设置-std=c99或-std=c11。
* 支持C99标准，设置为199901L;支持C11标准，设置为201112L
*   `gcc -std=c99 -o _09_16.12_predef_macro_predef_identifier _09_16.12_predef_macro_predef_identifier.c`
*/
#include <stdio.h>
void whyme(void);

int main(void)
{
    printf("The file is %s.\n", __FILE__);
    printf("The date is %s.\n", __DATE__);
    printf("The time is %s.\n", __TIME__);
    printf("The version is %ld.\n", __STDC_VERSION__);
    printf("This is line %ld.\n", __LINE__);
    printf("This function is %s.\n\n", __func__);
    
    whyme();
    return 0;
}

void whyme(void)
{
    printf("This is line %ld.\n", __LINE__);
    printf("This function is %s.\n\n", __func__);
}