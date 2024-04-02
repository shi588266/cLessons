/**
4.编写一个程序，提示用户输入身高(单位:英寸) 和姓名，然后以下面的格式显示用户刚输入的信息:
Dabney, you are 6.208 feet tall
使用float类型，并用/作为除号。如果你愿意，可以要求用户以厘米为单位输入身高，并以米为单位显示出来。
 */
#include <stdio.h>

int main(void)
{
    float inchHeight,feetHeight;
    puts("Enter your your height in inches");
    if (1== scanf("%f", &inchHeight)) {
        feetHeight = inchHeight / 3.0;
        printf("Your height in feet is %.2f feets\n\n", feetHeight);
    }
    
    float cemiHeight,meterHeight;
    puts("Enter your your height in cemimeter");
    if (1== scanf("%f", &cemiHeight)) {
        meterHeight = cemiHeight / 100.00;
        printf("Your height in meter is %.2f meter\n\n", meterHeight);
    }
    return 0;
}