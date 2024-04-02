/**
8.编写一个程序，提示用户输入旅行的里程和消耗的汽油量。然后计算并显示消耗每加仑汽油行驶的英里数，
显示小数点后面一位数字。接下来,使用1加仑大约3.785升，1英里大约为1.609千米，
把单位是英里/加仑的值转换为升/100公里 (欧洲通用的燃料消耗表示法)，并显示结果，显示小数点后面 1位数字。
注意，美国采用的方案测量消耗单位燃料的行程(值越大越好)，而欧洲则采用单位距离消耗的燃料测量方案(值越低越好)。
使用#define 创建符号常量或使用 const 限定符创建变量来表示两个转换系数
 */
#include <stdio.h>
#include <float.h>

#define GARON_2_LITER 3.785
#define MILE_2_KM 1.609

int main(void)
{
    float mileage,garon;
    
    puts("Enter mileage and fuel,use a comma to saperate them");
    if ( 2 == scanf("%f,%f", &mileage, &garon)) {
        printf("Your fuel consumption in American is: %.1f miles/garon", mileage / garon);
        printf("\n\n");
        printf("Your fuel consumption in Europian is: %.1f liters/100kilometers", (100.00 * garon * GARON_2_LITER) / (mileage * MILE_2_KM));
        printf("\n\n");
    } else {
        printf("Valid enter\n\n");
    }
    
    return 0;
}