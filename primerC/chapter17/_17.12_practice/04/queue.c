#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

static void CopyToItem(Node *pn, Item *pi);

/*初始化*/
void InitializeQueue(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->items = 0;
}

/*队列是否为空,该函数不更改队列*/
bool QueueIsEmpty(const Queue * pq)
{
    return pq->items == 0 ? true : false;
}

/*队列是否已满,该函数不更改队列*/
bool QueueIsFull(const Queue * pq)
{
    return pq->items == MAXQUEUE ? true : false;
}

/*返回队列的项数*/
int QueueItemCount(const Queue * pq)
{
    return pq->items;
}

/*在队列末尾添加项*/
bool EnQueue(Item item, Queue * pq)
{
    /*
    （1）创建一个新节点；
    （2）把项拷贝到节点中；
    （3）设置节点的next指针为NULL，表明该节点是最后一个节点；
    （4）设置当前尾节点的next指针指向新节点，把新节点链接到队列中；
    （5）把rear指针指向新节点，以便找到最后的节点；
    （6）项数加1
    */
    Node * pnode;
    if (QueueIsFull(pq)) {
        return false;
    }
    pnode = (Node *)malloc(sizeof(Node));
    if (NULL == pnode) {
        return false;
    }
    pnode->item = item;
    pnode->next = NULL;
    if (QueueIsEmpty(pq)) {
        pq->front = pq->rear = pnode;/* 项位于队列首端　　　　*/
    } else {
        (pq->rear)->next = pnode;/* 链接到队列尾端　　　 */
        pq->rear = pnode;/* 记录队列尾端的位置　　*/
    }
    pq->items++;/* 队列项数加1　　　　 */
    return true;
}
/*删除项*/
bool DeQueue(Item * pitem, Queue * pq)
{
    /*
    （1）把项拷贝到给定的变量中；
    （2）释放空出的节点使用的内存空间；
    （3）重置首指针指向队列中的下一个项；
    （4）如果删除最后一项，把首指针和尾指针都重置为NULL；
    （5）项数减1。
    */
    Node *psave = pq->front; /*指向头节点*/
    if (pq->items <= 0) {
        return false;
    }
    
    //memcpy(pitem, &(pq->front->item), sizeof(Item));/*把项拷贝到给定的变量中*/
    CopyToItem(psave, pitem);
    pq->front = psave->next;
    if (NULL == psave->next) {
        pq->rear = NULL;    /*如果删除最后一项，把首指针和尾指针都重置为NULL*/
    } 
    free(psave);    /*释放空出的节点使用的内存空间*/
    pq->items--;
    return true;
}
/*清空队列*/
void EmptyTheQueue(Queue * pq)
{
    Item dummy;
    while (!QueueIsEmpty(pq)) {
        DeQueue(&dummy, pq);
    }
}

static void CopyToItem(Node *pn, Item *pi)
{
    *pi = pn->item;
}