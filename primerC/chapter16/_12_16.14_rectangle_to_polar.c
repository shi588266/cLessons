/**
 * 直角坐标转换为极坐标
 *      程序中用到了math函数, 编译时需要指定 -lm 参数
 *      `gcc -std=c11 -Wall -o _12_16.14_rectangle_to_polar _12_16.14_rectangle_to_polar.c -lm`
 */
#include <stdio.h>
#include <math.h>
//弧度转换为角度的计算方式: 弧度除以 Π 乘以 180
#define RADIUS_TO_DEGREE (180 / (4 * atan(1)))
typedef struct rect_v {
    double x;   //x轴
    double y;
} Rect_V;

typedef struct polar_v {
    double magnitute;   //极轴长度
    double angle;       //极轴与原点的夹角
} Polar_V;

Polar_V rect_to_polar(Rect_V);

int main(void)
{
    Rect_V input;
    Polar_V result;
    puts("Enter x and y coordinates,you may use a comma to seperate the tow args, q to quit.");
    while (scanf("%lf,%lf", &input.x, &input.y) == 2) {
        result = rect_to_polar(input);
        printf("magnitute=%.2f,angle=%.2f.\n\n", result.magnitute, result.angle);
        puts("Enter x and y coordinates, q to quit.");
    }
    
    puts("bye!");
    return 0;
}

//直角坐标值转换为极坐标值
// 由于使用了数学库函数, 在编译指令最后面加上 -lm, 指定链接库函数
Polar_V rect_to_polar(Rect_V rect)
{
    Polar_V polar;
    polar.magnitute = sqrt(rect.x * rect.x + rect.y * rect.y);  //对平方和求平方根
    polar.angle = RADIUS_TO_DEGREE * atan2(rect.y, rect.x);
    return polar;
}