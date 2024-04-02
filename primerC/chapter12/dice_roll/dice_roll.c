/**
 * 掷骰子
 */
#include <stdio.h>
#include <stdlib.h> //提供 rand(), srand() 函数原型
#include <time.h> //提供time()函数的原型
#include "dice_roll.h"  /**为 roll_and_dice() 提供原型, 为 roll_count 提供声明**/ 

int roll_count = 0; //掷骰子的次数

/**
 * static 私有函数
 * side 骰子表示有几个面
*/
static unsigned short rollem(unsigned int sides)
{
    unsigned short roll;
    /**
     * rand函数返回 0~RAND_MAX之间的值
     * RAND_MAX 被定义在 stdlib.h 中, 其值通常是 INT_MAX
     * 所以需要对 rand() 用sides求模
     */
    roll = rand() % sides + 1;
    ++roll_count;
    return roll;
}

/**
 * 掷骰子
 * roll_and_dice 的函数原型放在了dice_roll.h 头文件中
 * dice 表示有几副骰子
 * sides 表示有骰子有几个面
 */
int roll_and_dice(int dice, int sides)
{
    int d,points = 0;
    if (sides <3) {
        printf("need at least 3 sides.\n");
        return -2;
    }
    if (dice < 1){
        printf("need at least 1 dice.\n");
        return -1;
    }
    for(; d<dice; d++) {
        points += rollem(sides);
    }
    return points;
}
