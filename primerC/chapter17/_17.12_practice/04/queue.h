/*
队列是一种“先进先出”（first in,first out，缩写为FIFO）的数据形式
*/
#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdbool.h>
#define MAXQUEUE 10 /*队列的大小*/

typedef struct item {
    long arrive_time;   //到达时间
    int pocess_time;    //咨询时间
} Item;

//定义节点
typedef struct node{
    Item item;
    struct node * next;
} Node;
//定义队列
typedef struct queue {
    struct node * front; /* 指向队列首项的指针 */
    struct node * rear;/* 指向队列首尾项的指针 */
    int items;/* 队列中的项数*/
} Queue;

void InitializeQueue(Queue * pq);  //初始化
bool QueueIsEmpty(const Queue * pq);  //队列是否为空,该函数不更改队列
bool QueueIsFull(const Queue * pq);  //队列是否已满,该函数不更改队列
int QueueItemCount(const Queue * pq);//返回队列的项数
bool EnQueue(Item item, Queue * pq);//在队列末尾添加项涉及标识项和队列。这次要更改队列
Item DeQueueItem(Queue q);//删除项，可以通过函数返回待删除的项
bool DeQueue(Item * pitem, Queue * pq);//删除项
void EmptyTheQueue(Queue * pq);//清空队列

#endif