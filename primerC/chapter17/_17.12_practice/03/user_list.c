/**
创建一个List类型的变量。
创建一个Item类型的变量。
初始化链表为空。
当链表未满且有输入时：把输入读取到Item类型的变量中。
在链表末尾添加项。
访问链表中的每个项并显示它们。
 */
#include <stdio.h>
#include <stdlib.h> //提供 exit 的原型
#include <string.h>
#include "simple_list.h"

char * s_gets(char [], int);
void print_list(Item);

int main(void)
{
    List listv; //创建一个List类型的变量
    Item itemv; //创建一个Item类型的变量

    InitializeList(&listv); //初始化链表为空
    // return 0;
    // 是否已满
    if (ListIsFull(&listv)) {
        fprintf(stderr, "List is full, no more space to storage.\n");//fprintf指定错误信息输入到哪里
        exit(EXIT_FAILURE);
    }
    /*在链表末尾添加项*/
    puts("Enter first movie title(empty line to stop):");
    while (NULL != s_gets(itemv.title, MAXLEN) && '\0' != (itemv.title)[0]) {
        //输入电影评分
        puts("Enter an integer as the film's rating");
        if(scanf("%d", &itemv.rating) == 1) {
            while (getchar() != '\n') {
                continue;
            }
            if (false == AddItem(itemv, &listv)) {
                fprintf(stderr, "Err! Problem allocating memory.\n");//fprintf指定错误信息输入到哪里
                exit(EXIT_FAILURE);
            }
            // 是否已满, 链表满停止录入
            if (ListIsFull(&listv)) {
                break;
            }
        }
        puts("Enter next movie title(empty line to stop):");
    }
    
    /*打印链表内容*/
    if (ListIsEmpty(&listv)) {
        puts("There is no data");
    } else {
        Traverse(&listv, print_list);
        /*清空链表,释放内存*/
        //EmptyTheList(&listv);
    }
    
    printf("There is %d films in the list\n", ListItemCount(&listv));
    puts("Done");
    return 0;
}


/**显示链表*/
void print_list(Item itemv)
{
    printf("Movie: %s, rating: %d\n", itemv.title, itemv.rating);
}

/*安全输入*/
char * s_gets(char inputs[], int limit)
{
    char *ret;
    char *find;
    ret = fgets(inputs, limit, stdin);
    if (NULL != ret) {
        find = strchr(inputs, '\n');
        if (NULL != find) {
            *find = '\0';
        } else {
            while (getchar() != '\n') 
                continue;
        }
    }
    
    return ret;
}