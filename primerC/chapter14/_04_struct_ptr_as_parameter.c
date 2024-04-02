/**
 * 结构指针作为函数的参数
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 30

struct infoct {
    char firstname[LEN];
    char lastname[LEN];
    int letters;
};

void get_info(struct infoct *);
void get_letter(struct infoct *);
void show_info(const struct infoct *);
char * s_gets(char *, int len);

int main(void) 
{
    struct infoct person;
    get_info(&person);
    get_letter(&person);
    show_info(&person);
    return 0;
}
// 设置姓名
void get_info(struct infoct *info_ptr) {
    puts("Enter your first name please.");
    s_gets(info_ptr->firstname, LEN);
    puts("Enter your last name please.");
    s_gets(info_ptr->lastname, LEN);
}
// 设置字符数量
void get_letter(struct infoct *info_ptr) {
    info_ptr->letters = strlen(info_ptr->firstname) + strlen(info_ptr->lastname);
}
// 显示信息
void show_info(const struct infoct *info_ptr) {
    printf("%s %s, your name has %d letters.\n", info_ptr->firstname, info_ptr->lastname, info_ptr->letters);
}

char * s_gets(char *ptr, int len) {
    char *res = fgets(ptr, len, stdin);
    char *find;
    if(res) {
        if (find = strchr(res, '\n'))
            *find = '\0';
        else {
            while (getchar() != '\n')
                continue;
        }
    }
    return res;
}