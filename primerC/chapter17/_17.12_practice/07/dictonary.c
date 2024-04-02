/**
 * 编写一个程序，打开和读取一个文本文件，并统计文件中每个单词出现的次数。
 * 用改进的二叉查找树储存单词及其出现的次数。程序在读入文件 后，会提供一个有3个选项的菜单。
        第1个选项是列出所有的单词和出现的次 数。
        第2个选项是让用户输入一个单词，程序报告该单词在文件中出现的次 数。
        第3个选项是退出
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "btree.h"
#define FILENAME_MAX_SIZE 25/*文件名最大长度*/

static void readToTree(Tree *);

static int getFirstChar(void); /*获取一个有效的输入字符*/
int showMenu(void);/*显示菜单*/
void scanfDict(Tree *);/*列出所有单词*/
static void printAllWords(Item);/*打印单词信息*/
void searchWord(Tree *);/*输入单词查找是否在文件内容出现过*/
static Item makeItem(char *);/*构造单词*/
static char* s_gets(char *, int len);

int main(void)
{
    int choose;
    bool isBreak = false;
    Tree bstree;
    readToTree(&bstree);
    
    while (choose = showMenu()) {
        printf("your choose is %c.\n", choose);
        switch (choose) {
            case 'l':
                scanfDict(&bstree);/*列出所有单词*/
                break;
            case 's':
                searchWord(&bstree);
                break;
            case 'q':
                isBreak = true;/*退出while循环*/
                break;
        }
        
        if (isBreak) {
            break;
        }
    }
    
    puts("Bye!");
    return 0;
}

/*读取文件内容返回一个树指针*/
static void readToTree(Tree *ptree)
{
    char filename[FILENAME_MAX_SIZE];/*存储文件名*/
    FILE *fp;
    InitializeTree(ptree);
    
    puts("input the filename:");
    if (NULL == s_gets(filename, FILENAME_MAX_SIZE)) {
        printf("Error get input content failed.\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error open %s failed.\n", filename);
        exit(EXIT_FAILURE);
    }
    
    int tempChar;// 注意：int，非char，要求处理EOF
    char wordTemp[MAX_WORD_LEN];
    int start = 0;
    Item entry;
    const Item *seekEntry;
    while ((tempChar = fgetc(fp)) != EOF) {
        if (' ' != tempChar && '\n' != tempChar) {
            printf("The character readed is %c.\n", tempChar);
            wordTemp[start++] = tempChar;
        } else {
            wordTemp[start] = '\0';/*重要:末尾加上空字符,代表字符串结束*/
            /*忽略无效的换行*/
            if (wordTemp[0] == '\0') {
                continue;
            }
            /*把读取的完整 单词放入树*/
            printf("The first word readed is %s.\n\n", wordTemp);
            strcpy(entry.word, wordTemp);
            entry.count = 1;
            AddItem(&entry, ptree);
            start = 0;
        }
    }
    return;
}

/*列出所有单词及其出现的次数*/
void scanfDict(Tree *ptree) 
{
    if (TreeIsEmpty(ptree)) {
        puts("No words in this text.");
    } else {
        Traverse(ptree, printAllWords);
    }
}
static void printAllWords(Item item)
{
    printf("The word is '%s', it appears %d times in the file.\n", item.word, item.count);
}

/*查找用户输入的单词*/
void searchWord(Tree *ptree)
{
    if (TreeIsEmpty(ptree))
    {
        puts("No words in this text.");
        return;
    }
    
    Item seekItem;
    char wordStore[MAX_WORD_LEN];    /*定义字符数组用于存放用户输入的单词*/
    const Item *itemp;
    puts("Enter a word that you prefer:");
    if (NULL != s_gets(wordStore, MAX_WORD_LEN)) {
        /*把用户输入的单词拷贝到一个item里, 用这个item去二叉树中匹配*/
        if (NULL != strcpy(seekItem.word, wordStore)) {
            itemp = FindTreeItem(&seekItem, ptree);
            if (NULL != itemp) {
                printf("Word '%s' appeared %d times in this text.\n", wordStore, itemp->count);
                return ;
            }
        }
    }
    
    printf("Word %s doesn't exist in this text.\n", wordStore);
}

/*显示菜单*/
int showMenu(void)
{
    puts("==============================================");
    puts("Enter the letter corresponding to your choice:");
    puts("  l)short for list:list all the words with its count");
    puts("  s)short for search:enter a word to seek wheather it is in the dictonary or not");
    puts("  q)short for quit: and just Quit.");
    puts("==============================================");
    
    int ch = getFirstChar();
    while (NULL == strchr("lsq", ch)) {
        printf("Please enter s, l or q: ");
        ch = getFirstChar();
    }
    return ch;
}
/*获取一个有效的输入字符*/
static int getFirstChar(void)
{
    int ch;
    do {
        ch = tolower(getchar());
    } while (isspace(ch));  /*如果输入内容有空白符就丢弃*/
    /*接着一直读取到Enter*/
    while (getchar() != '\n')
        continue;

    return ch;
}


static char* s_gets(char *str, int len)
{
    char *temp,*find;
    temp = fgets(str,len,stdin);
    if (NULL != temp) {
        find = strchr(str, '\n');
        if (NULL != find) {
            *find = '\0';
        } else {
            while (fgetc(stdin) != '\n')
                continue;
        }
    }
    return temp;
}