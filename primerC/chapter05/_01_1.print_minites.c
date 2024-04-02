/**
1.编写一个程序，把用分钟表示的时间转换成用小时和分钟表示的时间。
使用#define或const创建一个表示60的符号常量或const变量。
通过while循环让用户重复输入值，直到用户输入小于或等于0的值才停止循环。
 */
#include <stdio.h>

#define HOUR 60

int main(void)
{
    int minutes,hours,minute;
    
    puts("Enter number of minutes, quit if the number equals or small than zero:");
    while (scanf("%d", &minutes) == 1 && minutes > 0) {
        hours = minutes / HOUR;
        minute = minutes % HOUR;
        if (minute == 0) {
            printf("%d equals %d hours", minutes, hours);
        } else {
            if (hours == 0) {
                printf("%d equals %d minutes", minutes, minute);
            } else {
                printf("%d equals %d hours and %d minutes", minutes, hours, minute);
            }
        }
        printf("\n");
        puts("Enter another number, quit if the number equals or small than zero:");
    }
    printf("bye!");
    printf("\n");
    return 0;
}