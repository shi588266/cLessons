/**
7.编写一个程序，提示用户输入一个double类型的数，并打印该数的立方值。
自己设计一个函数计算并打印立方值。main 函数要把用户输入的值传递给该函数。 
 */
#include <stdio.h>

void getLiFangPrint(double);

int main(void)
{
    double sum,num;
    sum = num = 0;
    puts("Enter a double number, non-number to quit");
    while (scanf("%lf", &num) == 1) {
        getLiFangPrint(num);
        puts("Enter a double number, non-number to quit");
    }
    
    printf("\n");
    return 0;
}

void getLiFangPrint(double dbnum) {
    printf("%lf 的立方是 %lf", dbnum, dbnum * dbnum * dbnum);
    printf("\n");
}