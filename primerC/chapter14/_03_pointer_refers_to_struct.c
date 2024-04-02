/**
 * 指向结构的指针
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20

//声明姓名这个结构, 包含姓和名两个成员
struct name {
    char first[LEN];
    char last[LEN];
};

//声明'人'这个结构, 包含:姓名,爱好,工作,薪资 4个成员
struct guy {
    struct name handle;
    char favorfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    //声明含有两个元素的结构数组并初始化
    struct guy fellow[2] = {
        {
            {"Edwards", "Vanerseye"},
            "grilled salmon",
            "personality coach",
            68112.00
        },
        {
            {"Edwards", "Noten"},
            "fried chicken",
            "Athlete",
            432400.00
        }
    };
    
    struct guy *him;    //声明指向结构的指针
    
    /**
     * 打印结构成员的内存地址,
     * 两个地址值相差84(字节),因为每个guy结构都占用84字节的内存,
     * 一片连续内存两个指针的差值表示指针的偏移量,这里是1,
    */
    printf("address#1:%p #2:%p address_differ:%d.\n", &(fellow[0]), &(fellow[1]), &(fellow[1]) - &(fellow[0]));
    
    //指针指向第一个结构成员
    // him = &fellow[0];
    him = fellow;   //效果同上, 利用 "数组名指向数组第一个元素的地址" 这一特性
    printf("address#1:%p #2:%p address_differ:%d.\n", him, him + 1, him + 1 - him);
    //指针访问结构成员
    printf("him->income=%.2f, (*him).income=%.2f.\n", him->income, (*him).income);
    
    //指针指向下一个结构
    him++;
    printf("him->handle.last=%s, him->favorfood=%s.\n", him->handle.last, him->favorfood);
    
    return 0;
}