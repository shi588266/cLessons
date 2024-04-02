/*
所谓4皇后问题就是求解如何在4×4的棋盘上无冲突的摆放4个皇后棋子。在国际象棋中，皇后的移动方式为横竖交叉的，因此在任意一个皇后所在位置的水平、竖直、以及45度斜线上都不能出现皇后的棋子。
我们能不能把8个皇后放在棋盘上，让它们中的任何一个都无法攻击其余的皇后？这个问题被称为“八皇后”问题。
你的任务是编写一个程序，找到八皇后问题的所有答案，看看一共有多少种答案。

编写一个函数，把一个皇后放在某行的第1列，然后检查它是否与棋盘上的其他皇后互相攻击。
如果存在互相攻击，函数把皇后移到该行的第2列再进行检查。如果每列都存在互相攻击的局面，函数就应该返回。
但是，如果皇后可以放在这个位置，函数接着应该递归地调用自身，把另一个皇后放在下一行。
当递归调用返回时，函数再把原先那个皇后移到下一列。当一个皇后成功地放置于最后一行时，函数应该打印出棋盘，显示8个皇后的位置。
*/
#include <stdio.h>

#define DIMENSION 8     //八维

void dfs(int row);
void print_quene(int stored[DIMENSION][DIMENSION]);
int conflict(int row, int column);

static int chesspanel[DIMENSION][DIMENSION];//全局静态变量, 存储棋盘数组

int main(void)
{
    //创建 8x8 的二位数组
    int main[DIMENSION][DIMENSION] = {0};
    int init_row = 0;
    dfs(init_row);
    // print_quene(chesspanel);
}

void dfs(int row)
{
    // 从当前行的第一列开始, 找一个能够放置皇后的位置
    for (int col = 0; col < DIMENSION; col++) {
        /*
        回溯思想的核心, 
        直接先在当前位置放置皇后, 
        然后检测是否与其他位置的皇后冲突,
        如果不冲突, 就可以开始在下一行放置新的皇后,
        */
        chesspanel[row][col] = 1;
        if (conflict(row, col) == 0) {
            if (row < 7) {
                dfs(row + 1);
            } else {
                //当一个皇后成功地放置于最后一行时，函数应该打印出棋盘
                print_quene(chesspanel);
            }
        } 
        //当递归调用返回时(无论当前行找没找到不冲突的位置)，函数再把原先那个皇后移到下一列, 再试, 尝试找出更多解
        chesspanel[row][col] = 0;
    }
    
}

/*
把当前行列坐标与棋盘上已经放好的皇后做检查看是否冲突
*/
int conflict(int row, int column)
{
    // 首次放置必然不冲突
    if (row == 0) {
        return 0;
    }
    // 只考虑行参数坐标之前的行
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            if (chesspanel[i][column]) {    
                //有与待检测坐标处于同一列的皇后
                return 1;
            }
            if ( (chesspanel[i][j] && row - i == column - j) ) {
                //有与待检测坐标处于对角线上的皇后
                return 1;
            }
            if ( (chesspanel[i][j] && row - i == j - column) ) {
                return 1;
            }
        }
    }
    
    return 0;
}

void print_quene(int stored[DIMENSION][DIMENSION])
{
    puts("stored quene");
    
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            printf("%d", chesspanel[i][j]);
            putchar('\t');
        }
        putchar('\n');
    }
}