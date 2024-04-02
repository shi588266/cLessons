/**
编写一个函数接受这些参数：内含int类型元素的数组名、数组的大小和一个代表选取次数的值。
该函数从数组中随机选择指定数量的元素，并打印它们。每个元素只能选择一次（模拟抽奖数字或挑选陪审团成员）。
另外，如果你的实现有time()（第12章讨论过）或类似的函数，可在srand()中使用这个函数的输出来初始化随机数生成器rand()。
编写一个简单的程序测试该函数
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 100
#define PICK 50
#define DEBUG 0

void elect_print(const int[], size_t, int);
void build(int []);

int main(void)
{
    int count;
    int candidate[SIZE];
    build(candidate);
    #ifdef DEBUG
    for (int i = 0; i < SIZE; i++) {
        printf("%-8d", candidate[i]);
        if (i % 6 == 5) {
            putchar('\n');
        }
    }
    putchar('\n');
    #endif
    puts("Enter an integer number,(<0 or q to quit).");
    while (scanf("%d", &count) == 1 && count > 0 && count <= SIZE) {
        elect_print(candidate, SIZE, count);
        puts("\nEnter an integer number,(<0 or q to quit).");
    }
    
    puts("done!");
    return 0;
}

void elect_print(const int candidate[], size_t size, int pick_count)
{
    int random,elected[size];
    // 拷贝数组备份
    memcpy(elected, candidate, size * sizeof(int));
    for (int i = 0; i < pick_count; i++) {
        srand((unsigned int)time(0));     // 使用time函数返回值作为初始化种子
        random = rand() % size;    // 0~size 范围
        // 有可能多次取到重复
        while (elected[random] == 0) {
            random = rand() % size;    // 0~size 范围
        }
        // 从数组中随机选择指定的元素
        printf("%-8d", elected[random]);
        elected[random] = 0;
        // 每6个数字换行一次
        if (i % 6 == 5) {
            putchar('\n');
        }
    }
    putchar('\n');
}
//构造数组
void build(int candidate[])
{
    for (int i = 0; i < SIZE; i++) {
        candidate[i] = i + 1;
    }
}