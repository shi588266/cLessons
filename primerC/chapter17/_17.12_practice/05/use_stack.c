/*
5.编写一个程序，提示用户输入一个字符串。
然后该程序把该字符串的字符逐个压入一个栈(参见复习题5)，然后从栈中弹出这些字符，并显示它们。
结果显示为该字符串的逆序。
*/
#include <stdio.h>
#include <string.h>
#include "stack.h"

/*内部函数*/
static char *s_gets(char *, int);
static void print_stack_reverse(Stack *);

int main(void)
{
    /*定义数组用于存放用户输入*/
    char arr[STACK_SIZE];
    /*声明栈的变量,栈结构内的数组成员自动分配空间*/
    Stack stack;
    Stack *pstack = &stack;
    InitializeStack(pstack);
    
    puts("Enter a string:");
    s_gets(arr, STACK_SIZE);
    
    /*把该字符串的字符逐个压入一个栈*/
    for (int i = 0; arr[i] != '\0'; i++) {
        Push(arr[i], pstack);
    }
    
    /*从栈中弹出这些字符，并显示它们*/
    print_stack_reverse(pstack);
    puts("done!");
    return 0;
}

/*从栈中弹出这些字符，并显示它们*/
void print_stack_reverse(Stack *ps)
{
    /*此处不能使用 Item *pitem 因为声明指针并没有具体的地址指向, 传递给Pop后无法通过指针修改其指向的内容*/
    Item item;  //Item *pitem 错误
    puts("Here is what you enterd:");
    while(!IsStackEmpty(ps)) {
        if (Pop(&item, ps)) {
            putchar(item);
        }
    }
    putchar('\n');
}

char *s_gets(char *str, int len)
{
    char *temp,*find;
    temp = fgets(str, len, stdin);
    if (NULL != temp) {
        find = strchr(str, '\n');
        if (find) {
            *find = '\0';
        } else {
            while (getchar() != '\n')
                continue;
        }
    }
    return temp;
}