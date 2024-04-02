#include <stdio.h>
#define JUST_CHECKING   //可以定义空宏
#define LIMIT 4

int main(void)
{
    int i;
    int total = 0;
    for (i = 0; i < LIMIT; i++) {
        /* code */
        total += 2 * i*i + 1;
        // 可以通过 #ifdef 实现调试模式
        #ifdef JUST_CHECKING
        printf("now i=%d, running total=%d\n", i, total);
        #endif
    }
    printf("Grand total = %d\n", total);
    return 0;
}