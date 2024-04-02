/**
2.一个整数如果只能被它本身和1整除，它就被称为质数(prime)。请编写一个程序，打印出1～100之间的所有质数。
    思路:
    对于每一个整数, 从2循环到 n/2 + 1, 用 n 除以这之间的数, 如果出现整除的情况, 说明不是质数
*/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool isPrime;
    for (int i = 1; i <= 100; i++) {
        isPrime = true;
        for (int j = 2; j <= (i/2 + 1); j++) {
            if (i%j == 0 && i != j) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            printf("%d is a prime\n\n", i);
        } else {
            printf("%d is NOT a prime\n\n", i);
        }
    }
}