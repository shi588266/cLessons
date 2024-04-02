#include <stdio.h>

void up_and_down(int level);    //递归函数原型

int main(void)
{
    up_and_down(1);
    /**
    level:1, location:0x7ffeb482bdec
    level:2, location:0x7ffeb482bdcc
    level:3, location:0x7ffeb482bdac
    level:4, location:0x7ffeb482bd8c
    after level:4, location:0x7ffeb482bd8c
    after level:3, location:0x7ffeb482bdac
    after level:2, location:0x7ffeb482bdcc
    after level:1, location:0x7ffeb482bdec
    */
}

void up_and_down(int level)
{
    printf("level:%d, location:%p\n", level, &level);
    //进行4次递归
    if (level < 4) {
        up_and_down(level + 1);
    }
    printf("after level:%d, location:%p\n", level, &level);
}