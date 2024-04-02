/**
 * 1.编写一个程序，提示用户输入名和姓，然后以“名,姓”的格式打印出
来
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 16

int main(void)
{
    char firstName[MAXLEN];
    char lastName[MAXLEN];
    
    puts("Enter your first name");
    if (1 == scanf("%s", &firstName)) {
        puts("Enter your last name");
        if (scanf("%s", &lastName) == 1) {
            printf("Your full name is %s,%s.\n", firstName, lastName);
        } else {
            exit(-2);
        }
    } else {
        exit(-1);
    }
    
    return 0;
}