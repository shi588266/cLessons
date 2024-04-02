/*
栈
*/
#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef char Item;
typedef struct stack {
    Item items[STACK_SIZE];
    int top;    /*栈顶元素的索引值*/
} Stack;

/*初始化*/
void InitializeStack(Stack *);
/*是否满*/
bool IsStackFull(const Stack *);
/*是否为空*/
bool IsStackEmpty(const Stack *);
/*成员入栈*/
bool Push(Item, Stack *);
/*元素出栈*/
bool Pop(Item *, Stack *);
/**/
#endif