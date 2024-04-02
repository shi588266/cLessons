/**
 * C 语言把 字符常量 当作 int 存储, 所以字符常量占 4 1byte
 * 字符常量赋值给 char 变量后 只保留 最后面 8bit 就足以存储字符, 所以字符变量占 1 byte
 * 
 * 
 * 从技术层面看char是整数类型。因为char类型实际上储存的是整数而不是字符。
 * 计算机使用数字编码来处理字符，即用特定的整数表示特定的字符
 */
#include <stdio.h>
int main(void)
{
    // C 语言把 字符常量 当作 int 存储
    printf("sizeof char constant is %d \n", sizeof('A'));   // 4 byte
    
    // 在字符常量赋值给 char 变量后 只保留 最后面 8bit
    char testCharBit = 'B';
    printf("sizeof char variable is %d \n", sizeof(testCharBit));   // 1byte
    return 0;
}