/**
 * 变参宏
 * 通过把宏参数列表中最后的参数写成省略号（即，3个点...）来实现这一功能。
 * 这样，预定义宏_ _VA_ARGS_ _可用在替换部分中，表明省略号代表什么
 */
#include <stdio.h>
#include<math.h>
#define PR(X, ...) printf("Message" #X ":" __VA_ARGS__)

int main(void)
{
    double x = 48;
    double y;
    y = sqrt(x);    //编译时链接上math库, `gcc -o _05_16.5_vardic _05_16.5_vardic.c -lm`
    
    PR(1, "x = %g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);
    return 0;
}