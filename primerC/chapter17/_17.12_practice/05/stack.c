/**
 * 栈接口实现
 */
#include <stdio.h>
#include "stack.h"

void InitializeStack(Stack *pstack)
{
    pstack->top = 0;
}

/*是否满*/
bool IsStackFull(const Stack *pstack)
{
    return pstack->top == STACK_SIZE ? true : false;
}

/*是否为空*/
bool IsStackEmpty(const Stack *pstack)
{
    return pstack->top == 0 ? true : false;
}

/*成员入栈*/
bool Push(Item it, Stack *pstack)
{
    if (IsStackFull(pstack)) {
        return false;
    } else {
        /*
        pstack->items[pstack->top] = it;
        (pstack->top)++;
        */
        pstack->items[pstack->top++] = it;
        return true;
    }
}

/*元素出栈*/
bool Pop(Item *pitem, Stack *pstack)
{
    if (IsStackEmpty(pstack)) {
        free(pstack->items);
        return false;
    } else {
        pstack->top--;
        *pitem = pstack->items[pstack->top];
        return true;
    }
}