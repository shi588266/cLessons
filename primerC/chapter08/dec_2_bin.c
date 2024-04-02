#include <stdio.h>
void d2b(int i_num);

// 十进制数的二进制输出
int main(void)
{
    printf("ENter an integer, it will be transfered into binary \n");
    int i_num;
    while ( (scanf("%d", &i_num)) == 1 ) {
        printf("%d transfered into binary is \n", i_num);
        d2b(i_num);
        printf("\n");
        printf("ENter an integer, it will be transfered into binary \n");
    }
    printf("bye bye\n");
    return 0;
}

void d2b(int i_num)
{
    if ( i_num < 2 ) {
        printf("%d", i_num);
    }
    else {
        // 二分法
        d2b(i_num/2);
        //倒叙计算: 先计算的值后输出
        printf("%d", i_num%2);
    }
}