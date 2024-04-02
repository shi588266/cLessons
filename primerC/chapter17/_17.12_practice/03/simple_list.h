/**
 * 封装简单链表头文件
 * 定义实现链表的数据结构和操作这些数据的方法,
 * 对外提供接口, 需要使用简单链表可以直接导入这个头文件
 */
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>    //C99新特性
#define MAXLEN 40   //存储电影名称字符数组最大长度
#define MAXSIZE 100   //最大元素数量
//声明 电影 结构
struct film
{
    char title[MAXLEN];
    int rating;
};
typedef struct film Item;

//定义链表
typedef struct list {
    Item entries[MAXSIZE];  /*内含项的数组*/
    int items;/*list中有多少项*/
} List;

/*定义操作方法函数原型*/
void InitializeList(List *);               //初始化链表
bool ListIsEmpty(const List *);            //链表是否空
bool ListIsFull(const List *);             //链表是否满
unsigned int ListItemCount(const List *);  //返回链表节点个数
bool AddItem(Item item, List *);           //聊表末尾添加节点
void Traverse(const List *, void(*pfunc)(Item));  //对链表中的项使用函数
void EmptyTheList(List *);                 //清空链表
#endif