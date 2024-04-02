/**
 * atexit()注册函数列表中的函数，当调用exit()时就会执行这些函数。
 * ANSI保证，在这个列表中至少可以放32 个函数。最后调用exit()函数时，
 * exit()会执行这些函数（执行顺序与列表中的函数顺序相反，即最后添加的函数最先执行）
 */
#include <stdio.h>
#include <stdlib.h>
// 函数原型
void sign_off(void);
void too_bad(void);

int main(void)
{
    int n;
    atexit(sign_off);   //传递函数指针,注册函数到列表
    puts("Enter an integer:");
    if(scanf("%d", &n) != 1) {
        puts("That's no integer");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
    printf("%d is %s\n", n, (n%2) == 0 ? "even" : "odd");
    return 0;
}

void sign_off(void)
{
    puts("Thus terminates another magnificent program from xx software!");
}

void too_bad(void)
{
    puts("SeeSaw software extends its heartfelt condolences to you upon the failure of your program.");
}