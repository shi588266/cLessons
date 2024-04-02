/*
2.两个整型值M和N（M、N均大于0）的最大公约数可以按照下面的方法计算：
                              ----→      M % N = 0:      N
           gcd(M, N) =
                          ----→      M%N = R, R>0:   gcd(N, R)
                          
请编写一个名叫gcd的函数，它接受两个整型参数，并返回这两个数的最大公约数。
如果这两个参数中的任何一个不大于零，函数应该返回零。
*/
#include <stdio.h>

int gcd(int m, int n);

int main(void)
{
    printf("gcd(25, 24) = %d\n", gcd(25, 24));
}

int gcd(int m, int n)
{
    if (m <= 0 || n <= 0) {
        return 0;
    }
    
    int mod = m % n;
    if (mod == 0) {
        return n;
    } else {
        return gcd(n, mod);
    }
}