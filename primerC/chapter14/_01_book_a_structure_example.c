/**
 * 结构布局
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_LEN 61    //用于存储标题,长度比标题最大长度多1
#define AUTHOR_LEN 31    //用于存储作者,长度比作者名最大长度多1

char *s_gets(char *str, int len);
/**
 * 声明结构布局,标记是book
 * 每个结构布局单独定义,
 * 如果结构布局声明在函数内部, 那么结构布局对应的标记只能给这个函数内部使用
 * 结构布局标记不是必须的, 例如可以省略 book 
 * 声明结构布局,系统不会为数据分配空间
 */
struct book {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    double price;
};//结构布局定义结束

int main(void)
{
    /**
     * 声明具有book结构布局的结构变量, 此时系统会为结构变量分配空间
     * 这个空间内含一个TITLE_LEN个元素的char数组, 一个AUTHOR_LEN个元素的char数组, 一个double类型
     * 所以这个空间分配的内存占用的字节数:61x1 + 31x1 + 8 = 100
     */
    struct book libary;
    puts("Please enter the book title:");
    s_gets(libary.title, TITLE_LEN);
    puts("Please enter the book author:");
    s_gets(libary.author, AUTHOR_LEN);
    puts("Please enter the book sell price:");
    scanf("%f", &(libary.price));
    
    printf("%s \"%s\" ($%.2f).\n", libary.title, libary.author, libary.price);
    return 0;
}

char *s_gets(char *str, int len) {
    char * res;
    char * find;
    res = fgets(str, len, stdin);
    if (find = strchr(res, '\n')) {
        *find = '\0';
    } else {
        while (getchar() != '\n')
            continue;
    }
    return res;
}