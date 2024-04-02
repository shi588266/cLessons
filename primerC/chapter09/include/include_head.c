#include <stdio.h>
#include "hotel.h"  /*引入符号常量, 函原型*/

// 包含多文件
int main(void)
{
    int nights; //入住天数
    double hotel_rate;  //入驻费用
    int code;
    while( (code=menu()) != QUIT )
    {
        switch (code)
        {
            case 1:
                hotel_rate = HOTLE1;
                break;
            case 2:
                hotel_rate = HOTLE2;
                break;
            case 3:
                hotel_rate = HOTLE3;
                break;
            case 4:
                hotel_rate = HOTLE4;
                break;
            default:
                hotel_rate = 0.0;
                printf("wrong hotel code selection\n");
                break;
        }
        // 选择入住天数
        nights = get_nights();
        // 显示入住价格
        show_price(hotel_rate, nights);
    }
    
    printf("Thank you and bye");
    return 0;
}