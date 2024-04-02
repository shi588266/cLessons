// 酒店管理函数
#include <stdio.h>
#include "hotel.h"
// 选择菜单
int menu(void)
{
    
    printf("\n%s%s\n",STARS,STARS);
    printf("Enter the number of the desired hotel:\n");
    printf("1)FairfieldArms         2)HotelOlympic\n");
    printf("3)ChertworthyPlaza      4)TheStockton\n");
    printf("5)quit\n");
    printf("%s%s\n",STARS,STARS);
    
    int status,code;
    while( (status = scanf("%d", &code)) != 1 || (code > 5 || code < 1) )
    {
        //处理非整数输入
        while (getchar() != '\n') {
            continue;
        }
        //scanf("%*s");
        printf("Enter an integer from 1 to 5 \n");
    }
    
    return code;
}

int get_nights(void)
{
    printf("Enter the number of nights you afforded the hotel:\n");
    int nights;
    while (scanf("%d", &nights) != 1) {
        printf("Enter an integer value\n");
    }
    
    while (nights <= 0) {
        printf("Enter an integer value, 1 at least\n");
        scanf("%d", &nights);
    }
    return nights;
}

void show_price(double rate, int nights)
{
    int i;
    double total = 0.0;
    for (i = 1; i <= nights; i++,rate *= DISCOUNT) {
        total += rate;
    }
    printf("You will pay %.2lf for %d nights \n", total, nights);
}