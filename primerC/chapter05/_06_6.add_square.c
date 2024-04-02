/**
6.修改编程练习5的程序，使其能计算整数的平方和(可以认为第1天赚S1、第2天赚$4、第3天赚S9，以此类推，这看起来很不错)。
C没有平方函数，但是可以用n*n来表示n的平方。
 */
#include <stdio.h>

int main(void)
{
    int sum,count,start;
    sum = start = 0;
    puts("How many days?");
    if(scanf("%d", &count) == 1) {
        while (start++ < count) {
            sum += start * start;
        }
        
        printf("You have earned %d dollars in %d days.", sum, count);
    }
    
    printf("\n");
    return 0;
}