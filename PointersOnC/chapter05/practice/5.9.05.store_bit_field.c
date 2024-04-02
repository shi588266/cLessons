/*
5.编写一个函数，把一个给定的值存储到一个整数中指定的几个位。它的原型如下：
         int store_bit_field(int original_value,
          int value_to_store,
          unsigned starting_bit,unsigned ending_bit)；
假定整数中的位从右向左进行编号。因此，起始位的位置不会小于结束位的位置。为了更清楚地说明，函数应该返回下列值。
*/

#include <stdio.h>
#include <limits.h>
#define INT_BITS (CHAR_BIT * sizeof(int))   /*声明整型数据的在系统中占据的位数*/

/*
创建掩码:参数是起始位和结束位, 起始位不会小于结束位
    以32位整型为例, -1 的位模式表示为: 1111 1111 1111 1111 1111 1111 1111 1111
*/
static unsigned int create_mask(int starting_bit, int ending_bit)
{
    /*为保证进行逻辑移位而不是算术移位，将掩码声明为无符号类型*/
    unsigned int mask;
    mask = (unsigned)-1;
    /*对掩码进行移位操作,使得起始位和结束位为1, 其他位全为0*/
    mask >>= (INT_BITS - (starting_bit - ending_bit + 1));//起始位之前的位全部设置为0
    mask <<= (ending_bit);//结束位之后的位全部设置为0
    return mask;
}

int store_bit_field(
    int original_value,
    int value_to_store,
    unsigned starting_bit,
    unsigned ending_bit
) {
    /*步骤一:创建一个掩码, 它是一个值，其中需要存储的位置相对应的那几个位设置为1*/
    int mask = create_mask(starting_bit, ending_bit);
    printf("mask=%d\n", mask);
    /*步骤2.用掩码的反码对原值执行AND操作，将那几个位设置为0, 原值1111111111111111，操作后变为1100000111111111。*/
    original_value &= (~mask);
    /*步骤3.将新值左移，使它与那几个需要存储的位对齐。新值0000000100100011(0x123)，左移后变为0100011000000000。*/
    value_to_store <<= ending_bit;
    /*步骤4.把移位后的值与掩码进行位AND操作，确保除那几个需要存储的位之外的其余位都设置为0。进行这个操作之后，值变为0000011000000000。*/
    value_to_store &= mask;
    /*步骤5.把结果值与原值进行位OR操作，结果为1100011111111111(0xc7ff)，也就是最终的返回值。*/
    return value_to_store | original_value;
}

int main(void)
{
    printf("orignal = 0x%x, new value = 0x%x\n", 0xffff, store_bit_field(0xffff, 0x123, 13, 9));
}

