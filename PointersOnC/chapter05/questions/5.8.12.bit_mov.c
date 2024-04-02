/*
12.在你的机器上对一个有符号值进行右移位操作时，如何判断执行的是算术移位还是逻辑移位？
    打印出移位后的二进制表示, 查看最左边的位数字,如果是1表明是算数右移, 如果是0表明是逻辑右移
*/
#include <stdio.h>


void print_binary(int x) 
{
    if (x > 1) {
        print_binary(x >> 1);
    }
    putchar((x & 1) ? '1' : '0');
}

int main(void)
{
    signed int si = 100;
    printf("original binary bits is:\n");
    print_binary(si);
    printf("\t\n");
    printf("after right move is:\n");
    print_binary(si>>1);
    printf("\t\n");
}