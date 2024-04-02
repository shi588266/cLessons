/**
 * 结构数组作为函数的参数
 * 
 */
#include <stdio.h>

#define FOUNDLEN 60    //银行卡号的长度
#define N 2    //数组元素个数

struct funds {
    char bank[FOUNDLEN];
    double bankfund;
    char savebank[FOUNDLEN];
    double savefund;
};

double sum(const struct funds banks[], int n);   //函数原型:统计银行账户金额

int main(void)
{
    //小马哥的银行账户
    struct funds mht[N] = { 
        //使用复合字面量初始化
        {
            "ACBC",
            100860000,
            "CYBC",
            1001000
        },
        {
            "BCBC",
            10086,
            "WJBC",
            10010
        }
    };
    
    printf("The mht has a total of $%.2f.\n", sum(mht, N));
    return 0;
}

double sum(const struct funds banks[], int n) {
    double total;
    int i = 0;
    for (i = 0; i < N; i++) 
        total += banks[i].bankfund + banks[i].savefund;

    return total;
}

