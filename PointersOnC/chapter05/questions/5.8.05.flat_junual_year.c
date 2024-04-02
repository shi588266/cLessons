/*
5.可以被4整除的年份是闰年，但是其中能够被100整除的年份又不是闰年。但是，这其中能够被400整除的年份又是闰年。
请写一条赋值语句，实现如下功能：如果变量year的值是闰年，把变量leap_year设置为真；如果year的值不是闰年，把leap_year设置为假
*/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int year;
    bool leap_year;
    puts("Enter an integer value");
    while (scanf("%d", &year) == 1) {
        /*四年一闰, 百年不闰, 四百年再闰*/
        if ( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ) {
            leap_year = true;
            printf("%d is leap year\n\n", year);
        } else {
            leap_year = false;
            printf("%d is not leap year\n\n", year);
        }
    }
}