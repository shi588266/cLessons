/*
修改程序清单17.2, 第一种方案:使用双向链表
*/
#include <stdio.h>
#include <stdlib.h> ///* 提供malloc()原型 */
#include <string.h>/* 提供strcpy()原型 */
#define MAXLEN 40
// #define FMAX 500    // 链表实现动态数组功能,无需设置数组元素个数

//定义结构, 新增了next 成员指向下一个结构
struct film_st {
    char name[MAXLEN];
    double rating;
    struct film_st *next;  //指向下一个结构的指针, 结构定义为有名结构体
    struct film_st *prev;   //指向上一个结构的指针
};

char * s_gets(char * st, int n);
void print_list(void *);
/**逆序显示链表*/
void print_list_desc(void *);
void free_list(void *);

int main(void)
{
    struct film_st *header,*rear = NULL;   //头指针,尾指针
    struct film_st *previous,*current;
    char input[MAXLEN]; //定义字符数组用于存放终端输入
    
    puts("Enter first movie title:");
    /*
    直到读取到文件结尾（用NULL进行判断）
    或者用户在首行按下Enter键（用'\0'进行判断），输入才会终止
    */
    while (
        NULL != s_gets(input, MAXLEN)
        && '\0' != input[0]
    ) {
        current = (struct film_st *)malloc(sizeof(struct film_st));   //分配内存, 返回的是一个指针
        
        /*创建链表*/
        if (NULL == header) {// 如果是第一个列表元素
            header = rear = current;
        } else {
            previous->next = current;
            current->prev = previous;
        }
        /*创建链表*/
        
        //拷贝全部内容
        strcpy(current->name, input);
        current->next = NULL;
        rear = current;
        // 读取评分
        puts("Enter your rating <0~10>:");
        scanf("%lf", &(current->rating));
        while(getchar() != '\n'){
            continue;
        }

        // '重置' "上一个列表元素" , 为下一次循环做准备
        previous = current;
        puts("Enter next movie title(empty line to stop):");
    }
    
    // 打印结构链表
    print_list(header);
    print_list_desc(rear);
    
    /**完成任务, 释放分配的内存**/
    free_list(header);
    puts("Done!");
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret;
    char * find;

    ret = fgets(st, n, stdin);
    if (ret) {
        find = strchr(st, '\n');
        if (NULL != ret) {
            *find = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret;
}

/**显示链表*/
void print_list(void *header)
{
    struct film_st *current;
    if (NULL == header) {
        puts("There is no data in the list.");
    } else {
        // header 形参是 void 类型,需要进行强制类型转换
        current = (struct film_st*)header;
        puts("Here is the film list in asc order:");
        while (NULL != current) {
            printf("Movie: %s, rating: %.2lf\n", current->name, current->rating);
            current = current->next;
        }
    }
}
/**逆序显示链表*/
void print_list_desc(void *rear)
{
    struct film_st *curr;
    if (NULL == rear) {
        puts("Empty list.");
    } else {
        curr = (struct film_st *)rear;
        puts("Here is the film list in desc order:");
        while (NULL != curr) {
            printf("Movie: %s, rating: %.2lf\n", curr->name, curr->rating);
            curr = curr->prev;
        }
    }
}
/**完成任务, 释放分配的内存**/
void free_list(void *header)
{
    // header 形参是 void 类型,需要进行强制类型转换
    struct film_st *current = (struct film_st*)header;
    while (NULL != current) {
        free(header);
        header = current = current->next;
    }
    puts("free successfully.");
}