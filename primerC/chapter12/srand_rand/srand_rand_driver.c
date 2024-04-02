/**
 * 测试驱动程序
 * 与s_and_r.c 一起编译
 *  gcc -o srand_rand_driver s_and_r.c srand_rand_driver.c
 */
#include <stdio.h>
#include <stdlib.h>
extern void srand1(unsigned int x);
extern int rand1(void);

int main(void) {
    int count;
    unsigned seed;
    printf("please enter you number for seed.\n");
    while (scanf("%u", &seed) == 1) {
        srand1(seed);   //重置种子
        for (count = 0; count < 5; count++) {
            printf("%d\n", rand1());
        }
        printf("please enter you next seed.\n");
    }
    printf("done\n");
    return 0;
}

