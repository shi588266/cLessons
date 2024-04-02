/**
* 多次掷色子模拟程序  
*/
#include <stdio.h>
#include <stdlib.h> //srand(), rand()函数的原型
#include <time.h>
#include "dice_roll.h"  //包含该头文件后就可以使用 roll_count 变量, 可以使用 roll_and_dice() 函数

int main(void)
{
    int dice,roll,sides,status;
    
    /**
     * 随机一个种子
     * 使用系统时钟函数 time()
     * time() 参数是 time_t 类型对象的地址, 时间值就存储在这个地址上
     * time() 的返回值类型也是一个 time_t 类型, 但是可以通过强制类型转换为 unsigned int
     */
    srand((unsigned int)time(0));
    
    // 获取多面体骰子面数
    printf("Enter the number of sides per dice, 0 to stop.\n");
    while (scanf("%u", &sides) == 1 && sides != 0) {
        // 获取骰子个数
        printf("How many dice?\n");
        // 如果输入不正确
        if (status = scanf("%u", &dice) != 1) {
            // 1. 读取到了文件结束
            if (status == EOF) {
                break;  //退出循环
            }
            // 2.输入不是数字
            else {
                printf("you should have entered an integer?\n");
                printf("Let's try agin.\n");
                // 处理输入缓冲区剩余内容
                while (getchar() != '\n') {
                    continue;
                }
                printf("Enter the number of sides per dice, 0 to stop.\n");
                continue;   //跳出本轮
            }
        }
        // 进入掷骰子逻辑
        roll = roll_and_dice(dice, sides);
        printf("you have rolled %d using %d %d-sides dice\n", roll, dice, sides);
        printf("Enter the number of sides per dice, 0 to stop.\n");
    }
    printf("The rollem function was called %d times.\n", roll_count);
    return 0;
}
