/**
 2.编写一个程序，提示用户输入名和姓，并执行一下操作:
a.打印名和姓，包括双引号;
b.在宽度为20的字段右端打印名和姓，包括双引号;
c.在宽度为20的字段左端打印名和姓，包括双引号:
d.在比姓名宽度宽3的字段中打印名和姓
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 21

int main(void)
{
    char firstName[MAXLEN];
    char lastName[MAXLEN];
    
    puts("Enter your firstName");
    if (scanf("%s", &firstName) == 1) {
        puts("Enter your lastName");
        if (1 == scanf("%s", &lastName)) {
            printf("a. your full name is \"%s %s\".\n", firstName, lastName);
            printf("b. your full name is \"%20s %s\".\n", firstName, lastName);
            printf("c. your full name is \"%s %-20s\".\n", firstName, lastName);
            printf("d. your full name is \"%s %s   \".\n", firstName, lastName);
        } else {
            exit(-2);
        }
    } else {
        exit(-1);
    }
    
    return 0;
}