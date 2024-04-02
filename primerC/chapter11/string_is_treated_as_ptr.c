/**
 * 字符串常量被视为指向该字符串的指针
 * 所以直接对字符串常量使用 解引用 运算符是合法的, 
 * 获取到的是字符串常量的首个字符
*/
#include <stdio.h>
#define LENGTH 100
int main(void)
{
    // 字符串是特殊的 char 类型的数组, 数组的最后一个元素是 '\0'
    printf("%s,%p,%c\n", "The string ", "is treated as ",*"pointer");   // 输出内容: The string ,0x4005f0,p
    return 0;
}