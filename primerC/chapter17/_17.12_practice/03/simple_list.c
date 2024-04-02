/**
链表接口实现
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_list.h"

/*初始化链表*/
void InitializeList(List *plist)
{
    /*
    list的 entities 成员是数组, 数组可以当作指针处理
    */
    puts("InitializeList");
    Item *pitem;
    
    pitem = (Item *)malloc(MAXSIZE * sizeof(Item));/*分配内存空间并返回分配的*/
    if (NULL == pitem) {
        puts("Initialize failed.");
        exit(EXIT_FAILURE);
    }
    //plist->entries = pitem;  /*不能直接给数组赋值*/
    memcpy(plist->entries, pitem, MAXSIZE * sizeof(Item));
    free(pitem);
    plist->items = 0;
}
/*链表是否空*/
bool ListIsEmpty(const List *plist)
{
    return plist->items == 0 ? true : false;
}

/*链表是否满*/
bool ListIsFull(const List *plist)
{
    /*
    由于没有给链表数组成员定义了最大元素个数, 直接用最大元素个数判断
    */
    return plist->items >= MAXSIZE ? true : false;
}

/*返回链表节点个数*/
unsigned int ListItemCount(const List *plist)
{
    return plist->items;
}

/*链表末尾添加节点*/
bool AddItem(Item item, List *plist)
{
    /*如果达到数组元素个数, 添加失败*/
    if (plist->items >= MAXSIZE) {
        return false;
    } else {
        (plist->entries)[plist->items] = item;
        (plist->items)++;
        return true;
    }
}
/*对链表中的项使用函数*/
void Traverse(const List *plist, void(*pfunc)(Item item))
{
    for (int i = 0; i < plist->items; i++) {
        (*pfunc)((plist->entries)[i]);
    }
}

/*清空链表---释放由malloc分配的内存*/
void EmptyTheList(List *plist)
{
    plist->items = 0;
    free(plist->entries);
}