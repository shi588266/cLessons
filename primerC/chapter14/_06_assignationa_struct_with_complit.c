/**
 * 使用复合字面量为结构赋值
 */
#include <stdio.h>

#define TITLE_LEN 61    //用于存储标题,长度比标题最大长度多1
#define AUTHOR_LEN 31    //用于存储作者,长度比作者名最大长度多1

struct book {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    double value;
};

int main(void)
{
    struct book book1;
    int score;
    puts("Enter the socre:");
    scanf("%d", &score);
    
    if( score >= 84 ) {
        book1 = (struct book){"Wakeup of Acknowlage", "ZhouLing", 11.25};   //使用复合字面量为结构赋值
    } else {
        book1 = (struct book){"The power of habit", "Alexander", 5.99};   //使用复合字面量为结构赋值
    }
    puts("Your assigned reading is:");
    printf("%s \"%s\" ($%.2f).\n", book1.title, book1.author, book1.value);
    return 0;
}