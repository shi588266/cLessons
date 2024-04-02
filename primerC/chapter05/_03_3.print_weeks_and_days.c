/**
3.编写一个程序，提示用户输入天数，然后将其转换成周数和天数。
例如，用户输入18，则转换成2周4天。以下面的格式显示结果:
    18 days are 2 weeks, 4 days
通过while循环让用户重复输入天数，当用户输入一个非正值时 (如0或-20)，循环结束。
 */
#include <stdio.h>

#define WEEK_DAYS 7 

int main(void)
{
    int days,weeks,day;
    
    puts("Enter number of days, quit if the number equals or below zero:");
    while (scanf("%d", &days) == 1 && days > 0) {
        weeks = days / WEEK_DAYS;
        day = days % WEEK_DAYS;
        if (day == 0) {
            printf("%d days are %d weeks", days, weeks);
        } else {
            if (weeks == 0) {
                printf("%d days are %d weeks", days, day);
            } else {
                printf("%d days are %d weeks, %d days", days, weeks, day);
            }
        }
        printf("\n");
        puts("Enter another number, quit if the number equals or less than zero:");
    }
    printf("bye!");
    printf("\n");
    return 0;
}