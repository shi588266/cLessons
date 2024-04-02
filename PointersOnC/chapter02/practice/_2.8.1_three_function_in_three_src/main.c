/**
    最后一个函数是main，保存于文件main.c中，它分别用参数10、0和10调用另外两个函数，并打印出结果
*/
#include <stdio.h>

//声明函数原型
int increment(int orignal);
int negate(int orignal);

int main(void)
{
    int org1,org2,org3;
    org1 = 10;
    org2 = 0;
    org3 = 10;
    printf("org1=%d increment org1=%d negate org1=%d\n", org1, increment(org1), negate(org1));
    printf("org2=%d increment org2=%d negate org2=%d\n", org2, increment(org2), negate(org2));
    printf("org3=%d increment org3=%d negate org3=%d\n", org3, increment(org3), negate(org3));
}



