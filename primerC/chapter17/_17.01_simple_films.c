/**
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 40   /* 储存片名的数组大小 */
#define FMAX 10     /* 影片的最大数量 */

typedef struct {
    char name[MAXLEN];  //名称
    int rating;         //评分
} film_st;

// 安全输入函数 原型
char * s_gets(char *, int);
void print_films(film_st [], int);

int main(void)
{
    int index = 0;
    film_st filmmovies[FMAX];
    // 直到数组已满（用  FMAX  进行判断）或者读取到文件结尾（用NULL进行判断）
    // 或者用户在首行按下Enter键（用'\0'进行判断），输入才会终止
    puts("Enter first movie title:");
    while (
        index < FMAX 
        && s_gets(filmmovies[index].name, MAXLEN) != NULL   //读取用户输入到字符指针
        && filmmovies[index].name[0] != '\0'
    ) {
        // 读取评分
        puts("Enter your rating <0~10>:");
        scanf("%d", &filmmovies[index++].rating);   //整体返回index,效果是自增
        while(getchar() != '\n'){
            continue;
        }
        
        puts("Enter next movie title(empty line to stop):");
    }
    // 打印
    print_films(filmmovies, index);
    puts("Done!");
    return 0;
}

char * s_gets(char *chararr, int limit)
{
    char * ret; //定义指向char类型的指针
    char * find;    //定义 查找字符
    ret = fgets(chararr, limit, stdin);
    if (ret) {
        //查找换行符
        find = strchr(chararr, '\n');
        // 如果找到, 说明多读取了换行符, 需要把换行符作为字符串终止字符
        if (NULL != find) {
            *find = '\0';
        }
        // 如果没找到, 说明终端输入内容超出输入缓冲区,输入被截断(不过没关系), 重要的是要把输入缓冲清空
        else {
            while (getchar() != '\n') {
                continue;   //清空输入缓冲
            }
        }
    }
    return ret;
}

//打印
void print_films(film_st fs[], int size) 
{
    if (size == 0) {
        puts("No data enterd");
    }
    
    else {
        puts("Here is the film list:");
        for (int i = 0; i < size; i++) {
            printf("Movie: %s, rating: %d\n", fs[i].name, fs[i].rating);
        }
    }
}