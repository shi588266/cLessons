/**
clock_t clock (void);
clock_t是定义在time.h中的类型,该函数返回处理器时间，
其单位取决于实现（如果处理器时间不可用或无法表示，该函数将返回-1）
CLOCKS_PER_SEC（也定义在time.h中）是每秒处理器时间单位的数量。
因此，两个clock()返回值的差值除以CLOCKS_PER_SEC得到两次调用之间经过的秒数

编写一个函数，接受一个double类型的参数表示时间延迟数，然后在这段时间运行一个循环。编写一个简单的程序测试该函数。
 */
#include <stdio.h>
#include <time.h>
void delay(const double);

int main(void)
{
    const double delay_sec;
    puts("Enter double number,(<0 or q to quit).");
    while (scanf("%lf", &delay_sec) == 1 && delay_sec > 0) {
        delay(delay_sec);
        puts("Enter double number,(<0 or q to quit).");
    }
    
    puts("done!");
    return 0;
}

void delay(const double delay_sec)
{
    clock_t begin = clock();
    clock_t end = clock();
    while ((double)(end - begin) / CLOCKS_PER_SEC < delay_sec) {
        end = clock();
    }
    printf("Delay %.4f seconds.\n", (double)(end - begin) / CLOCKS_PER_SEC);
}