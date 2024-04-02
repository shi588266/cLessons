/**
计算20天里赚多少钱的程序(假设第1天赚S1、第2天赚S2、第3天赚S3，以此类推)。
修改程序，使其可以与用户交互，根据用户输入的数进行计算 (即,用读入的一个变量来代替20)。
 */
#include <stdio.h>

int main(void)
{
    int sum,count,start;
    sum = start = 0;
    puts("How many days?");
    if(scanf("%d", &count) == 1) {
        while (start++ < count) {
            sum += start;
        }
        
        printf("You have earned %d dollars in %d days.", sum, count);
    }
    
    printf("\n");
    return 0;
}