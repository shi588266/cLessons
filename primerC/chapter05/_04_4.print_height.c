/**
4.编写一个程序，提示用户输入一个身高 (单位:厘米)，并分别以厘米和英寸为单位显示该值，允许有小数部分。
程序应该能让用户重复输入身高，直到用户输入一个非正值。其输出示例如下:
    Enter a height in centimeters: 182
    182.0 cm = 5 feet, 11.7 inches
    Enter a height in centimeters: (<=0 to quit): 
 */
#include <stdio.h>

#define CENTI_2_FEET 36.4
#define FEET_2_INCH 2.34

int main(void)
{
    float height,feet,inches;
    
    printf("Enter a height in centimeters(<=0 to quit):");
    while (scanf("%f", &height) == 1 && height > 0) {
        feet = height / CENTI_2_FEET;
        inches = feet * FEET_2_INCH;
        printf("%.1f cm = %.1f feet, %.1f inches", height, feet, inches);
        printf("\n");
        printf("Enter a height in centimeters(<=0 to quit):");
    }
    printf("bye!");
    printf("\n");
    return 0;
}