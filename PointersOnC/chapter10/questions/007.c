/*
7.考虑下面这些声明和数据：
假定nodes数组在内存中的起始位置为200，并且在这台机器上整数和指针的长度都是4字节
*/

struct NODE {
    int a;  // 4
    struct NODE *b; //4
    struct NODE *c; //4
};  //12

struct NODE nodes[5] = {
    {5, nodes+3, NULL},     //200
    {15, nodes+4, nodes+3}, //212   npp = &(nodes+4)
    {22, NULL, nodes+4},    //224   np
    {12, nodes+1, nodes},   //236   第3个成员可以计算出 nodes 的地址是 244
    {18, nodes+2, nodes+1}  //248   *npp指向(nodes+4)也就是指向这个node, 指向(nodes+4)的指针值可以通过数组第二个node计算出来: 212 + 4 = 216 
};

struct NODE *np = nodes + 2;
struct NODE **npp = &nodes[1].b;    

// 优先级   []     ->     .(点运算符)       &(取地址运算符)    *(解引用运算符):


/*
nodes           200                 &nodes[3].c->a      200 (最终时取数组第一个元素这个node的a成员,也就是5的地址)
nodes.a         ERROR               &nodes->a           200 同上
nodes[3].a      12                  np                  224
nodes[3].c      200(nodes)          np->a               22
nodes[3].c->a   5                   np->c->c->a         15
*nodes          {5, nodes+3, NULL}  nnp                 216(通过数组第二个node元素的第二个成员地址计算出来)
*nodes.a        ERROR               nnp->a              ERROR
---------------------------------------------------------------------------------------
(*nodes).a      5                       *npp                248
nodes->a        5                       **npp               {18, nodes+2, nodes+1}
nodes[3].b->b   248                     *npp->a             ERROR
*nodes[3].b->b  {18, nodes+2, nodes+1}  (*npp)->a           18
&nodes          200(nodes的地址也是200) &np                 xxx(某个内存地址)
&nodes[3].a     236(12这个整数的地址)   &np->a            224(22 这个整数的地址)
&nodes[3].c     244(nodes的地址是244)   &np->c->c->a        212(15 这个整数的地址)
*/
