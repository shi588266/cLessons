/**
 * 二叉搜索数结构和操作
 */
#ifndef _BTREE_H_
#define _BTREE_H_
#include <stdbool.h>
#define MAXLEN 20   /*名字和种类最大字符数*/
#define MAX_NODE_SIZE 100  /*二叉搜索树最大节点数*/
#define MAX_ITEMS_SIZE 100  /*一个节点中存放同名项最大个数*/

typedef struct pet {
    char petname[MAXLEN];/*宠物名称*/
    char petkind[MAXLEN];/*宠物类别*/
} Item;

typedef struct tree_node {
    Item items[MAX_ITEMS_SIZE];   //节点内容,同名的宠物放在同一个数组里
    int itemSize;
    struct tree_node *pleft;    /*指向左子节点*/
    struct tree_node *pright;   /*指向右子节点*/
} Trnode;

typedef struct tree {
    Trnode *root;/*指向根节点*/
    int size;   /*树的项数*/
} Tree;
    
void InitializeTree(Tree *ptree);  /*把树初始化为空*/
bool TreeIsEmpty(const Tree *ptree);  /*确定树是否为空*/
bool TreeIsFull(const Tree *ptree);  /*确定树是否已满*/
int TreeItemCount(const Tree *ptree);  /*确定树的项数*/
bool AddItem(const Item *pi, Tree *ptree);  /*在树中添加一个项*/
bool InTree(const Item *pi, const Tree *ptree);  /*在树中查找一个项*/
bool DeleteItem(const Item *pi, Tree *ptree);  /*从树中删除一个项*/
/*
pfun指向一个函数
该函数接受一个Item类型的参数，并无返回值
pfun指向的这个函数为树中的每一项执行一次
*/
void Traverse(const Tree *ptree, void(*pfun)(const Trnode *pnode));  /*把函数应用于树中的每一项*/
void DeleteAll(Tree *ptree);  /*删除树中的所有内容*/
void MyTraverse(const Tree*, const Item*, void(*pfun)(const Item item));
#endif