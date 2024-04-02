#include <stdio.h>

// 声明函数原型
long factor(int i_num);
long r_factor(int i_num);

/**
 * 计算阶乘
 */
int main(void)
{
    printf("This Program caculates integer factorial\n");
    printf("Enter a value in the range 0~25,q to quit\n");
    int num;
    while (scanf("%d", &num) == 1) {
        if (num < 0) {
            printf("No negtive number is permitted\n");
        }
        else if (num > 25) {
            printf("Entered number is out of range 0~25\n");
        }
        else {
            printf("loop:%d factorial is %ld\n", num, factor(num));
            printf("recursion:%d factorial is %ld\n", num, r_factor(num));
        }
        printf("Enter a value in the range 0~25,q to quit\n");
        
    }
    printf("Bye\n");
}

long factor(int i_num) 
{
    if (i_num == 0){
        return 1L;
    } else {
        long l_fact = 1;
        int i;
        for (i = 1; i <= i_num; i++) {
            l_fact *= i;
        }
        return l_fact;
    }
}

//递归方式
long r_factor(int i_num)
{
    if (i_num == 0){
        return 1L;
    } else {
        return (long)i_num * (long)r_factor(i_num - 1);
    }
}