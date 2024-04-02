/*
4.编写一个程序，按照下图所示创建数据结构。最后3个对象都是动态分配的结构。第1个对象可能是一个静态的指向结构的指针。
不必使这个程序过于全面——我们将在下一章讨论这个数据结构。
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE {
    int num;
    struct NODE *next;
} Node; 

typedef struct {
    struct NODE *head;
} List;

Node *make_node(int data)
{
    Node *np = (Node*)malloc(sizeof(Node));
    np->num = data;
    np->next = 0;
}

int main(void)
{
    List *lp = (List*)malloc(sizeof(List));
    lp->head = make_node(5);
    lp->head->next = make_node(10);
    lp->head->next->next = make_node(15);
    return 0;
}