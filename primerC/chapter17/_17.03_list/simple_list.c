/**
链表接口实现
*/
#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"
#define LSIZE 10

/*初始化链表*/
void InitializeList(List *plist)
{
    /*
    对 plist 解引用得到 链表 List (链表是个指针指向头链表头节点)
    对 List 解引用得到 链表的头节点 header
    初始化链表就是---把头节点的指针置为 null
    */
    puts("InitializeList");
    *plist = NULL;
}
/*链表是否空*/
bool ListIsEmpty(const List *plist)
{
    return *plist == NULL ? true : false;
}

/*链表是否满*/
bool ListIsFull(const List *plist)
{
    /*
    由于没有给链表设置最大元素个数,所以这里的逻辑很简单,
    就是尝试申请一个节点的内存,如果申请成功,代表链表没满(这里只是尝试申请,别忘了释放申请的内存)
    */
    bool is_full;
    Node *temp_pt;  //为了便于释放申请的内存,所以需要声明一个指向节点的指针, 稍后让他指向申请到的内存地址
    temp_pt = (Node *)malloc(sizeof(Node));
    if (NULL == temp_pt)
        is_full = true;
    else
        is_full = false;
    
    free(temp_pt);
    return is_full;
}

/*返回链表节点个数*/
unsigned int ListItemCount(const List *plist)
{
    int index = 0;
    // 声明一个指向节点的指针
    Node *current_node;
    // 指针指向链表头节点
    current_node = (*plist);
    if (NULL == current_node) {
        return 0;
    }
    index += 1;
    while (NULL != current_node->next) {
        current_node = current_node->next;
        index++;
    }
    return index;
}

/*链表末尾添加节点*/
bool AddItem(Item item, List *plist)
{
    int index = 0;
    // 声明指向节点的指针
    Node *current_pnode, *temp_pnode;
    if (ListIsFull(plist)) {
        return false;
    }
    // 当前指针指向链表头节点
    current_pnode = (*plist);
    /*
    指针的方式给节点属性赋值
    对未初始化的内存地址进行写入会出现 `Segmentation fault`, 需要先分配空间
    */
    temp_pnode = (Node *)malloc(sizeof(Node));
    //再次检查内存分配成功
    if (NULL == temp_pnode) {
        return false;
    }
    temp_pnode->item = item;
    temp_pnode->next = NULL;
    //对于刚初始化的链表, 把当前节点设为头节点即可
    if (NULL == current_pnode) {
        *plist = temp_pnode;
    } else {
        //找链表最后一个节点
        while (NULL != current_pnode->next) {
            current_pnode = current_pnode->next;
        }
        current_pnode->next = temp_pnode;
    }
    return true;
}
/*对链表中的项使用函数*/
void Traverse(const List *plist, void(*pfunc)(Item item))
{
    Node *pnode = *plist;   //指向链表的开头
    while (NULL != pnode) {
        /*
        pfunc 代表指向函数的指针, 函数的参数是 Item 类型, 函数的返回值是 void
        对 pfunc 解引用得到函数本身
        */
        (*pfunc)(pnode->item);  //对链表中的项使用函数
        pnode = pnode->next;
    }
}

/*清空链表---释放由malloc分配的内存*/
void EmptyTheList(List *plist)
{
    /*
    从头节点开始逐个释放节点
    声明指向节点的指针 pnode_save 用于临时存放新的链表头节点地址
    */
    Node *pnode_save;
    while (NULL != *plist) {
        pnode_save = (*plist)->next;
        free(*plist);
        *plist = pnode_save;
    }
}