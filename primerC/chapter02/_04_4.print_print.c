/**
4.编写一个程序，生成以下输出:
For he's a jolly good fellow!
For he's a jolly good fellow!
For he's a jolly goodfellow!
Which nobody can deny!
除了
main0函数以外，该程序还要调用两个自定义函数:一个名为jolly()，用于打印前条消息，调用一次打印一条; 另一个函数名为
deny()，打印最后一条消息
 * 
 */
#include <stdio.h>
void jolly(void);
void deny(void);

int main(void)
{
    jolly();
    jolly();
    jolly();
    deny();
}

void jolly()
{
    printf("For he's a jolly good fellow!\n");
}

void deny()
{
    printf("Which nobody can deny!\n");
}