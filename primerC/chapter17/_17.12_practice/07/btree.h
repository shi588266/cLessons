/**
 * 二叉搜索数结构和操作
 */
#ifndef _BTREE_H_
#define _BTREE_H_
#include <stdbool.h>
#define MAXLEN 20
#define MAX_WORD_LEN 15

typedef struct word {
    char word[MAX_WORD_LEN];/*单词*/
    int count;/*单词出现的次数*/
} Item;

typedef struct tree_node {
    Item item;//节点内容
    struct tree_node *pleft;    /*指向左子节点*/
    struct tree_node *pright;   /*指向右子节点*/
} Trnode;

typedef struct tree {
    Trnode *root;/*指向根节点*/
    int size;   /*树的项数*/
} Tree;
/*用于记录查找到的项*/
typedef struct seek_item {
    Trnode *item_node_p;    //被查找项所在的节点
    Trnode *parent_node_p;  //被查找项所在的节点的上个节点
} Seeked;
    
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
void Traverse(const Tree *ptree, void(*pfun)(Item item));  /*把函数应用于树中的每一项*/
void DeleteAll(Tree * ptree);  /*删除树中的所有内容*/

const Item* FindTreeItem(const Item*, const Tree*);
#endif