/**
1.正数n的平方根可以通过计算一系列近似值来获得，每个近似值都比前一个更加接近准确值。第一个近似值是1，接下来的近似值则通过下面的公式来获得：

        ai+1 = (ai+n/ai)/2
        
编写一个程序，读入一个值，计算并打印出它的平方根。如果将所有的近似值都打印出来，就会发现这种方法获得准确结果的速度有多快。原则上，这种计算可以永远进行下去，它会不断产生更加精确的结果。但在实际中，由于浮点变量的精度限制，程序无法一直计算下去。当某个近似值与前一个近似值相等时，就可以让程序停止继续计算了。
*/
#include <stdio.h>

int main(void)
{
    double last;/*上一个近似值*/
    double nearly;/*新的近似值*/
    /*读入一个值*/
    double dbl;
    puts("Enter an integer value");
    last = 1;
    while ((scanf("%lf", &dbl) == 1)) { 
        /*计算读入值的平方根*/
        nearly = 1;
        do {
            last = nearly;
            nearly = (last + dbl / last) / 2;
            printf("%.15e\n", nearly);
        } while(nearly != last);
        
        printf("number %g has a sqrt %g\n", dbl, nearly);
        puts("Enter another integer value");
    }
}