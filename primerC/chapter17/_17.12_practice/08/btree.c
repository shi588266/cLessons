/*
接口实现
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"

/*用于记录查找到的项*/
typedef struct seek_item {
    Trnode *item_node_p;    //被查找项所在的节点
    Trnode *parent_node_p;  //被查找项所在的节点的上个节点
} Seeked;

/*内部函数*/
static Trnode* MakeNode(const Item *);
static Seeked SeekItem(const Item *, const Tree *);
static void AddNode(Trnode *, Trnode *);
static void AppendNodeItem(const Item*, Trnode *);
static bool ToLeft(const Item *item1, const Item *item2);
static bool ToRight(const Item *item1, const Item *item2);
static void DeleteNode(Trnode **);
static void InOrder(const Trnode *root, void(*pfun)(const Trnode*));
static void DeleteAllNodes(Trnode *);
static int AllPetsCount(Trnode*);

/*把树初始化为空*/
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}
/*确定树是否为空*/
bool TreeIsEmpty(const Tree * ptree)
{
    return ptree->size == 0;
}
/*确定树是否已满*/
bool TreeIsFull(const Tree * ptree)
{
    return ptree->size >= MAX_NODE_SIZE;
}
/*确定树的项数*/
int TreeItemCount(const Tree * ptree)
{
    return AllPetsCount(ptree->root);
}

/*
在树中添加一个项
*/
bool AddItem(const Item *pi, Tree *ptree)
{
    Trnode *pnode;
    Seeked seek_st;
    /*首先要检查有该树是否空间放得下一个项*/
    if (TreeIsFull(ptree)) {
        fprintf(stderr, "Error:tree is full.\n");
        return false;
    }
    /*检查树中是否有该项*/
    seek_st = SeekItem(pi, (const Tree *)ptree);
    if(NULL != seek_st.item_node_p) {
        /*同名项放到一个数组内*/
        AppendNodeItem(pi, seek_st.item_node_p);
        return false;
    }
    
    /*创建树节点*/
    pnode = MakeNode(pi);
    if (NULL == pnode) {
        fprintf(stderr, "Make Node Error.\n");
        return false;
    }
    /*更新Tree结构的size 成员*/
    ptree->size++;
    
    // 1. 树为空
    if (NULL == ptree->root) {
        ptree->root = pnode;
    } else {
        /*找出应该把这个新节点放在树中的哪个位置*/
        AddNode(pnode, ptree->root);
    }
    return true;
}
/*在树中查找一个项*/
bool InTree(const Item * pi, const Tree * ptree)
{
    // 利用 SeekItem 方法
    return SeekItem(pi, ptree).item_node_p == NULL ? false : true;
}
/*
从树中删除一个项
注意:从树中删除某一项,涉及到找出待删除节点,以及修改待删除节点的父节点的左/右子节点的指向
因为父节点是用指向 Trnode 类型的指针描述的, 为了修改指针, 必须把该指针的地址传递给执行删除任务的函数,
*/
bool DeleteItem(const Item *pi, Tree *ptree)
{
    Seeked seek_st;
    seek_st = SeekItem(pi, (const Tree *)ptree);
    /*没找到包含需要删除项的节点*/
    if (NULL == seek_st.item_node_p) {
        return false;
    }
    else {
        /*如果节点成员数组当中只有一个元素,直接删除这个节点*/
        if (seek_st.item_node_p->itemSize == 1) {
            // 要删除的项在根节点
            if(NULL == seek_st.parent_node_p){
                DeleteNode(&(ptree->root));
            }
            // 如果删除的项在父节点的左子节点
            else if (seek_st.item_node_p == (seek_st.parent_node_p)->pleft) {
                //传递的是地址,地址指向的是指向待删除节点的指针
                DeleteNode(&(seek_st.parent_node_p)->pleft);
            } 
            else {
                //传递的是地址,地址指向的是指向待删除节点的指针
                DeleteNode(&(seek_st.parent_node_p)->pright);
            }
            ptree->size--;     
        }
        /*如果节点成员数组当中还有其他元素,就从数组中删除需要删除的项*/
        else {
            // 创建新数组并复制不包含被删除元素
            int newItSize = (seek_st.item_node_p->itemSize - 1);
            Item *newItp = malloc(newItSize * sizeof(Item));
            for (int i = 0; i < seek_st.item_node_p->itemSize; i++) {
                if (strcmp(pi->petkind, seek_st.item_node_p->items[i].petkind) != 0) {
                    newItp[i] = seek_st.item_node_p->items[i];
                }
            }
            //节点成员指向新创建的数组
            memcpy(seek_st.item_node_p->items, newItp, newItSize * sizeof(Item));
            seek_st.item_node_p->itemSize--;
            free(newItp);
        }
    }
    
    return true;
}
/*
把函数应用于树中的每一项,
*/
void Traverse(const Tree *ptree, void(*pfun)(const Trnode *pnode))
{
    if (NULL != ptree->root) {
        InOrder(ptree->root, pfun);
    }
}
void MyTraverse(const Tree *ptree, const Item *pitem, void(*pfun)(const Item item))
{
    Seeked sk = SeekItem(pitem, ptree);
    if (sk.item_node_p == NULL) {
        fprintf(stderr, "No valid node found!\n");
    } else {
        for (int i = 0; i < sk.item_node_p->itemSize; i++) {
            pfun(sk.item_node_p->items[i]);
        }
    }
    
}
/*
删除树中的所有内容
清空树基本上和遍历树的过程相同，也要访问每个节点，而且要用函数释放内存。
还要重置Tree类型结构的成员，表明该树为空。
DeleteAll()函数负责处理Tree类型的结构，把释放内存的任务交给 DeleteAllNodes()函数。DeleteAllNodes()
与 IOrder0函数的构造相同，它储存了指针的值root->right，使其在释放根节点后仍然可用
*/
void DeleteAll(Tree *ptree)
{
    if (NULL != ptree) {
        DeleteAllNodes(ptree->root);
    }
    
    // 把 Tree 类型的结构体置空
    ptree->root = NULL;
    ptree->size = 0;
}

/*~~~~~~~~~~~~~~~~~~内部函数~~~~~~~~~~~~~~~~~~~*/
/*统计所有成员个数*/
static int AllPetsCount(Trnode* pnode) {
    /*统计左子树所有成员
      统计当前节点所有成员
      统计右子树所有成员
    */
    //定义静态变量
    static int count = 0;
    
    if (pnode != NULL) {
        AllPetsCount(pnode->pleft);
        count += pnode->itemSize;
        AllPetsCount(pnode->pright);
    }
    return count;
}

/*把项的内容添加的拷贝到节点*/
static Trnode* MakeNode(const Item *pi)
{
    Trnode *pnode;
    pnode = (Trnode *)malloc(sizeof(Trnode));
    if (pnode != NULL) {
        /*把待添加项拷贝到该节点中*/
        pnode->items[0] = *pi;
        pnode->itemSize = 1;
        /*设置节点的左指针和右指针都为NULL*/
        pnode->pleft = NULL;
        pnode->pright = NULL;
    }
    return pnode;
}
/*
把节点添加到树中
比较新项和根项，以确定应该把新项放在左子树还是右子树中,
必须自定义用于比较的函数,
如果新项应放在左子树中，ToLeft()函数返回true；如果新项应放在右子树中，ToRight()函数返回true
假设把新项放在左子树中,如果左子树为空，只需让左子节点指针指向新项即可,
如果左子树不为空怎么办？应该把新项和左子节点中的项做比较，以确定新项应该放在该子节点的左子树还是右子树。
这个过程一直持续到函数发现一个空子树为止，并在此此处添加新节点
*/
static void AddNode(Trnode *new_node, Trnode *root_node)
{
    /*如果新项应放在左子树中*/
    if (ToLeft(&(new_node->items[0]), &(root_node->items[0]))) {
        //如果左子树为空
        if (NULL == root_node->pleft) 
            root_node->pleft = new_node;
        else //递归再找, 只不过当前根节点的左子节点作为新的根节点
            AddNode(new_node, root_node->pleft);
    } else if (ToRight(&(new_node->items[0]), &(root_node->items[0]))) {
        //如果右子树为空
        if (NULL == root_node->pright)
            root_node->pright = new_node;
        else //递归再找, 只不过当前根节点的右子节点作为新的根节点
            AddNode(new_node, root_node->pright);
    } else {
        //既不在左子树中, 又不在右子树中, 说明重复
        
    }
}
/*把同名项追加到节点的数组元素内*/
static void AppendNodeItem(const Item *pitem, Trnode *pnode){
    /*数组是否已满*/
    if (pnode->itemSize == MAX_ITEMS_SIZE) {
        printf("同名项已达到存放上限\n");
        exit(EXIT_FAILURE);
    } else {
        pnode->items[pnode->itemSize++] = *pitem;
    }
}

/*
参数是两个指向待比较项的指针
    参数1: 待比较的项
    参数2: 被比较的当前节点内的项
当待比较的项与当前节点内的项比较后应该置于当前节点项左边时, 返回 true
*/
static bool ToLeft(const Item *item1, const Item *item2)
{
    // 先比较名称
    int cmp_res = strcmp(item1->petname, item2->petname);
    if (cmp_res < 0)
        return true;
    
    return false;
}
/*参数是两个指向待比较项的指针*/
static bool ToRight(const Item *item1, const Item *item2)
{
    // 先比较名称
    int cmp_res = strcmp(item1->petname, item2->petname);
    if (cmp_res > 0)
        return true;
    
    return false;
}
/*
从树结构中查找项
函数返回一个结构,包含两个指针:
    一个指针指向包含项的节点, 未找到节点返回NULL,
    一个指针指向父节点(根节点没有父节点,返回NULL)
*/
static Seeked SeekItem(const Item *pi, const Tree *ptree)
{
    Seeked find;
    find.parent_node_p = NULL;
    find.item_node_p = ptree->root; //从根节点开始找
    if (find.item_node_p == NULL) {
        return find;
    }
    
    while (find.item_node_p != NULL) {
        /*向左找*/
        if ( ToLeft(pi, &((find.item_node_p)->items[0])) ) {
            find.parent_node_p = find.item_node_p;
            find.item_node_p = find.item_node_p->pleft;
        }
        /*向右找*/
        else if (ToRight(pi, &((find.item_node_p)->items[0]))) {
            find.parent_node_p = find.item_node_p;
            find.item_node_p = find.item_node_p->pright;
        }
        /*两种情况都不满足就是相等*/
        else {
            break;
        }
    }
    return find;
}

/*
执行删除任务的函数
    参数是指向待删除的节点指针的指针, 待删除节点指针是从父节点 root->pleft 或者 pnode->pright 传递来的

注意:从树中删除某一项,涉及到找出该项所在的节点作为待删除节点,以及修改待删除节点的父节点的左/右子节点的指针
因为父节点左右子节点是用指向 Trnode 类型的指针描述的,为了修改指针,必须把该指针的地址传递给执行删除任务的函数,
分多钟情况:
    1. 如果待删除节点是叶节点, 没有左右子节点, 
        这种情况只需把父节点中的左/右子节点指针重置为NULL，并使用free函数释放已删除节点所占用的内存.

    2. 如果待删除节点只有一个子节点,不管是左子节点还是右子节点, 
        直接把待删除节点父节点中存储该节点的地址更新为该节点子树的地址

    2. 如果待删除节点有两个子树
        首先把待删除节点左子树连接在被删除节点之前连接的位置,
        根据二叉查找树的特点, 待删除节点右子树在待删除节点的右边,那它必然在待删除节点左子树所有项的右边
        所以可以沿着待删除节点树的右支向右一直查找,直到找到空位,然后把这个右子树连接到这个位置

tobe_deleted_node_p_p 是指向目标节点的父节点左右指针成员的地址(也就是指向待删除节点指针的地址)
*/
static void DeleteNode(Trnode **tobe_deleted_node_p_p)
{
    Trnode *temp_node_p;   //声明临时指针用于记录待删除节点父节点 左/右 指针成员的原指向
    temp_node_p = *tobe_deleted_node_p_p;//记录原指向
    //如果待删除节点只有右子树或者没有子树(没有左右子树可以作为只有右子树的一个特例)
    if (NULL == (*tobe_deleted_node_p_p)->pleft) {
        //修改父节点中指针的指向
        *(tobe_deleted_node_p_p) = (*tobe_deleted_node_p_p)->pright;
    }
    //如果待删除节点只有左子树
    else if (NULL == (*tobe_deleted_node_p_p)->pright) {
        //修改父节点中指针的指向
        *(tobe_deleted_node_p_p) = (*tobe_deleted_node_p_p)->pleft;
    }
    //待删除节点有两个子树
    else {
        //声明临时指针变量用于查找待删除节点右子树右支上的最后一个节点
        Trnode *right_tree_last_node_p = (*tobe_deleted_node_p_p)->pright;
        while (NULL != right_tree_last_node_p->pright) {
            right_tree_last_node_p = right_tree_last_node_p->pright;
        }
        //待删除节点的右子树连接到找到的位置
        right_tree_last_node_p->pright = (*tobe_deleted_node_p_p)->pright;
        //修改父节点中指针的指向
        *(tobe_deleted_node_p_p) = (*tobe_deleted_node_p_p)->pleft;
    }
    free(temp_node_p);
}

/*
处理树中的每个节点
像树这种每个节点下面又是一棵树的结构, 最容易的处理方案是使用递归,处理流程是:
    从树的根节点开始, 先处理左子树,再处理当前根节点, 最后处理右子树,
    左右子树的处理方法跟处理当前树的逻辑一样(先处理左子树的左子树,再处理左子树根节点, 最后处理左子树的右子树)
    实现过程交给递归
    跳出递归的条件是要处理的节点是一个空树
参数:
    把每次要处理的节点当作树的根,
    第二个参数是实际用来处理每个项的函数指针
*/
static void InOrder(const Trnode *root, void(*pfun)(const Trnode *pnode))
{
    if (NULL != root) {
        InOrder(root->pleft, pfun);
        (*pfun)(root);
        InOrder(root->pright, pfun);
    }
}

/*
参数: 一个指向待清空的树的根节点的指针

清空所有节点的步骤,以根节点为例:
    1. 清空根节点的左子树, 清空根节点的右子树, 释放根节点指针的内存地址
*/
static void DeleteAllNodes(Trnode *root_node_p)
{
    if (NULL!= root_node_p) {
        DeleteAllNodes(root_node_p->pleft);
        DeleteAllNodes(root_node_p->pright);
        free(root_node_p);
    }
}