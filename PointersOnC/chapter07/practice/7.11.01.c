/*
1.Hermite Polynomials（厄密多项式）是这样定义的：
                      ----→     n ≤ 0:  1
           Hn(x) =              n = 1： 2x
                      ----→     n ≥ 2:  2xH(n–1)(x) – 2(n-1)H(n–2)(x)

例如，H3(2)的值是40。编写一个递归函数，计算Hn(x)的值。该函数应该与下面的原型匹配：
               int hermite( int n, int x)

*/
#include <stdio.h>
int hermite( int n, int x);

int main(void)
{
    printf("hermite( 3, 2 ) = %d\n",  hermite( 3, 2 ));
    return 0;
}

/*
Hermite Polynomials（厄密多项式）
*/
int hermite( int n, int x)
{
    if (n <= 0) {
        return 1;
    } else if(n == 1) {
        return 2 * x;
    } else {
        return 2 * x * hermite(n-1, x) - 2 * (n-1) * hermite(n-2, x);
    }
}