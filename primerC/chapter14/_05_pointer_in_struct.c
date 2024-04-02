/**
 * 14.10 
 * 如果结构变量未经初始化, 那么其内部的指针成员可能指向任何地址, 
 * 使用 malloc() 分配存储空间, 并让指针成员存储该地址, 可以避免程序出错
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 30

struct infoct {
    char * firstname;   //指针作为结构成员
    char * lastname;
    int letters;
};

void get_info(struct infoct *);
void get_letter(struct infoct *);
void show_info(const struct infoct *);
void cleanup(struct infoct *);           //调用该函数释放内存
char * s_gets(char *, int len);

int main(void) 
{
    struct infoct person;
    get_info(&person);
    get_letter(&person);
    show_info(&person);
    cleanup(&person);    //释放内存
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

void get_info(struct infoct *iptr) {
    puts("Enter your first name please.");
    /**
     * iptr可能是未经初始化的变量, 不能直接使用结构变量的成员接收用户的输入
     * 1. 使用临时变量接收用户输入
     * 2. 使用malloc分配合适的存储空间
     * 3. 使用 strcpy 拷贝临时变量的内容到malloc分配的存储空间
     * 4. 结构的指针成员指向该存储空间
     */
    char temp[LEN];
    char * temp1;
    //1. 使用临时变量接收用户输入
    s_gets(temp, LEN);
    //2. 使用malloc分配合适的存储空间
    temp1 = (char *)malloc(strlen(temp) + 1);
    //3. 使用 strcpy 拷贝临时变量的内容到malloc分配的存储空间
    strcpy(temp1, temp);
    //4. 结构的指针成员指向该存储空间
    iptr->firstname = temp1;
    
    
    puts("Enter your last name please.");
    s_gets(temp, LEN);
    iptr->lastname = (char *)malloc(strlen(temp) + 1);
    strcpy(iptr->lastname, temp);
}

void get_letter(struct infoct *iptr) {
    iptr->letters = strlen(iptr->firstname) + strlen(iptr->firstname);
}

// 显示信息
void show_info(const struct infoct *iptr) {
    printf("%s %s, your name has %d letters.\n", iptr->firstname, iptr->lastname, iptr->letters);
}

void cleanup( struct infoct *iptr ) {
    free(iptr->firstname);
    iptr->firstname = NULL;
    free(iptr->lastname);
    iptr->lastname = NULL;
}