/**
两数的调和平均数这样计算：先得到两数的倒数，
然后计算两个倒数的平均值，最后取计算结果的倒数
 */
#include <stdio.h>
#define THPJ(X,Y) 1/((1/(X)+1/(Y))/2)

int main(void)
{
    double x;
    double y;
    double res;
    puts("Enter tow double numbers, q to quit.");
    while (scanf("%lf %lf", &x, &y) == 2) {
        res = THPJ(x,y);
        printf("%lf,%lf的调和平均数为%.4f\n", x, y, res);
        puts("Enter tow double numbers, q to quit.");
    }
    puts("done");
}