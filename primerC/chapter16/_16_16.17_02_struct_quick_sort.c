/**
 * 使用qsort快速排序
 * 对结构元素先按照姓排序, 再按照名字排序
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 20
#define NUM 100   //定义数组大小

struct names {
    char first[NUM];
    char last[NUM];
};
struct names staff[NUM] = {
    {"Tom", "Sarfar"},
    {"Jim", "Sarfar"},
    {"Meimei", "Han"},
    {"Lucy", "Green"},
    {"Lily", "Green"},
    {"David", "Smith"},
    {"Andrew", "Andson"},
    {"Jack", "Andson"}
};

// 格式化显示数组
void show(struct names star[], int n);
// 自定义比较函数
int mycompare(const void *, const void *);

int main(void)
{
    puts("Before list:");
    show(staff, 8);
    qsort(staff, 8, sizeof(struct names), mycompare);
    puts("After list:");
    show(staff, 8);
    return 0;
}

// 格式化显示结构体
void show(struct names star[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%10s %10s", star[i].first, star[i].last);
        if (i % 2 == 1) {
            putchar('\n');
        }
    }
    
    if (i % 2 != 0) {
        putchar('\n');
    }
}


// 自定义比较函数
int mycompare(const void *p1, const void *p2)
{
    int res;
    // 使用指向 实参类型一致 的指针来访问这两个值
    const struct names *pst1 = (const struct names *)p1;
    const struct names *pst2 = (const struct names *)p2;
    // 先比较姓
    res = strcmp(pst1->last, pst2->last);
    if (res != 0) {
        return res;
    } else {
        // 再比较名称
        return strcmp(pst1->first, pst2->first);
    }
}