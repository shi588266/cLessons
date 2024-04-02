/**
 * 结构作为函数的参数
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

struct infoct get_info(struct infoct);
struct infoct get_letter(struct infoct);
void show_info(const struct infoct);
char * s_gets(char *, int len);

int main(void) 
{
    struct infoct person;
    person = get_info(person);
    person = get_letter(person);
    show_info(person);
    return 0;
}
// 设置姓名
struct infoct get_info(struct infoct person) {
    puts("Enter your first name please.");
    s_gets(person.firstname, LEN);
    puts("Enter your last name please.");
    s_gets(person.lastname, LEN);
    return person;
}
// 设置字符数量
struct infoct get_letter(struct infoct person) {
    person.letters = strlen(person.firstname) + strlen(person.lastname);
    return person;
}
// 显示信息
void show_info(const struct infoct person) {
    printf("%s %s, your name has %d letters.\n", person.firstname, person.lastname, person.letters);
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