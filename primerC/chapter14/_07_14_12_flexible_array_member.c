/**
 * 伸缩型数组成员
 * 结构的最后一个成员可以是伸缩型数组, 声明结构时这个数组不会立即存在
 * 因为是伸缩数组,数组成员数量不固定, 所以需要使用 malloc 分配存储空间
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_LEN 61    //用于存储标题,长度比标题最大长度多1
#define AUTHOR_LEN 31    //用于存储作者,长度比作者名最大长度多1

struct flex {
    size_t count;
    double average;
    double scores[];    //伸缩型数组
};
void set_flex( struct flex *, int );
void show_flex(const struct flex *);

int main(void)
{
    //声明结构体变量会分配存储空间, 但是声明的指针不会分配存储空间
    struct flex *fp_5,*fp_9;    //数组成员的数量既可以是5,也可以是9
    int i;
    int n = 5;
    int tot = 0;
    // 为结构和数组分配存储空间, malloc返回一个指针, 指向分配的内存地址
    fp_5 = malloc(sizeof(struct flex) + n * sizeof(double));
    fp_5->count = n;
    for (i = 0; i < n; i++) {
        fp_5->scores[i] = 20.0 - i / 2.0;
        tot+=fp_5->scores[i];
    }
    fp_5->average = tot / n;
//printf("%p\n", fp_5);exit(0);
    show_flex(fp_5);
    
    n = 9;
    fp_9 = malloc(sizeof(struct flex) + n * sizeof(double));
    fp_9->count = n;
    for (i = 0; i < n; i++) {
        fp_9->scores[i] = 20.0 - i / 2.0;
        tot+=fp_9->scores[i];
    }
    fp_9->average = tot / n;
    show_flex(fp_9);
    //printf("%p\n", fp_5);exit(0);
}

void set_flex(struct flex *fptr, int n) {
    printf("%p\n", fptr);
    int i;
    int tot = 0;
    // 为结构和数组分配存储空间, malloc返回一个指针, 指向分配的内存地址
    fptr = malloc(sizeof(struct flex) + n * sizeof(double));
    printf("%p\n", fptr);
    fptr->count = n;
    for (i = 0; i < n; i++) {
        fptr->scores[i] = 20.0 - i / 2.0;
        tot+=fptr->scores[i];
    }
    fptr->average = tot / n;
    printf("%p\n", fptr);
}

void show_flex(const struct flex *fptr) {
    int i;
    printf("Scores:");
    for (i = 0; i < fptr->count; i++) {
        printf("%g, ", (fptr->scores)[i]);
    }
    printf("\nAverage:%g\n", fptr->average);
}