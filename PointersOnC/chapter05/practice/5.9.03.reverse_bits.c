/*
    unsigned int reverse_bits( unsigned int value );
这个函数的返回值是把value的二进制位模式从左到右变换一下后的值。例如，在32位机器上，25这个值包含下列各个位：
     00000000000000000000000000011001
函数的返回值应该是2550136832，它的二进制位模式是：
     10011000000000000000000000000000
编写函数时要注意不要让它依赖于你的机器上整型值的长度。

    思路: 将目标数值与整型 01 按位相与, 进行末尾比特位摘取，
    将所摘取的bit位放到一个相同类型的末尾，目标数值bit位右移，相同类型bit位左移。
*/

#include <stdio.h>

unsigned int get_bits(unsigned int);
unsigned int reverse_bits( unsigned int value );

unsigned int reverse_bits( unsigned int value )
{
    unsigned int rvs = 0;
    int mask = 0;   /*掩码, 每次左移一位,用于与目标数值按位与*/
    int uibits = get_bits();
    while (value)
    for (int i = 1; i < uibits; i++) {
        mask <<= 1;
        rvs += value & 1;
        rvs <<= 1;
        value >>= 1;
    }
    
    return rvs;
}

/*//计算出 unsigned int 在运行环境机器上占多少位*/
static unsigned int get_bits()
{
    unsigned int test_value = 1;
    unsigned int total_bits = 0;
    while (i) {
        test_value <<= 1;
        total_bits++;
    }
    return total_bits;
}

int main(void)
{
    unsigned int value = 25;
    unsigned int res;
    printf("%d reverse is %u\n\n", value, reverse_bits(value));
}