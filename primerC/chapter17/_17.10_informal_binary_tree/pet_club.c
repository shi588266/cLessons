/**
 * 宠物俱乐部程序
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "btree.h"

/*显示菜单*/
char menu(void);
void addPet(Tree *pt);  /*添加宠物*/
void dropPet(Tree *pt);  /*去除宠物*/
void showPets(const Tree *pt);  /*展示宠物*/
void findPet(const Tree *pt);  /*展示宠物*/
void showPetsNumber(const Tree *pt);  /*展示宠物数量*/

void printItem(Item item);  /*展示每个宠物成员信息*/
void upperCase(char *str);  /*字符转大写*/
char *s_gets(char *str, int cnt);

int main(void)
{
    Tree pets;
    char choice;
    InitializeTree(&pets);
    /*读取菜单输入指令*/
    while ( 'q' != (choice = menu()) ) {
        switch (choice) {
            case 'a':
                addPet(&pets);
                break;
            case 'l':
                showPets((const Tree *)&pets);
                break;
            case 'f':
                findPet((const Tree *)&pets);
                break;
            case 'n':
                showPetsNumber((const Tree *)&pets);
                break;
            case 'd':
                dropPet(&pets);
                break;
            default:
                puts("Something error!");
        }
    }
    
    DeleteAll(&pets);
    puts("bye!");
    return 0;
}

/*显示菜单并读取用户输入*/
char menu(void)
{
    int ch;
    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a)add a pet           1) show list of pets");
    puts("n)number of pets      f) find pets");
    puts("d)delete a pet        q) quit");
    
    while(EOF != (ch = getchar())) {
        while (getchar() != '\n') {
            continue;
        }
        ch = tolower(ch);
        /*验证字符串*/
        if (NULL == strchr("alnfdq", ch)) {
            puts("Please enter an a, 1, f, n, d, or g:");
        } else {
            break;
        }
    }
    
    /*设置默认指令*/
    if (EOF == ch)
        ch = 'q';
    return ch;
}

/*用户输入宠物信息, 并录入到宠物俱乐部*/
void addPet(Tree *pt)
{
    Item temp;
    if (TreeIsFull(pt)) {
        puts("No room in the Club");
    } else {
        puts("Please enter name of pet:");
        s_gets(temp.petname, MAXLEN);
        puts("Please enter kind of pet:");
        s_gets(temp.petkind, MAXLEN);
        upperCase(temp.petname);
        upperCase(temp.petkind);
        AddItem(&temp, pt);
    }
}
/*字符转大写*/
void upperCase(char *str)
{
    for (int i = 0; i < MAXLEN; i++) {
        if (EOF == *str) {
            continue;
        }
        str[i] = toupper(str[i]);
    }
    /*while (*str) {
        *str = toupper(*str);
        str++;
    }*/
}

/*展示宠物数量*/
void showPetsNumber(const Tree *pt)
{
    if (TreeIsEmpty(pt)) {
        puts("Empty Club found");
    } else {
        printf("There are %-3d members totally in the Club.\n", TreeItemCount(pt));
    }
}

/*显示所有宠物俱乐部成员*/
void showPets(const Tree *pt)
{
    if (TreeIsEmpty(pt)) {
        puts("No entries.");
    }
    else {
        Traverse(pt, printItem);
    }
}
/*展示每个宠物成员信息*/
void printItem(Item item)
{
    printf("Pet: %-19s kind: %-19s\n", item.petname, item.petkind);
}

/*用户输入宠物名称, 到宠物俱乐部查找该宠物*/
void findPet(const Tree *pt)
{
    Item temp;
    if (TreeIsEmpty(pt)) {
        puts("No entries.");
        return; /*如果树为空则退出*/
    }
    puts("Please enter name of pet you want to find:");
    puts("Please enter name of pet:");
    s_gets(temp.petname, MAXLEN);
    puts("Please enter kind of pet:");
    s_gets(temp.petkind, MAXLEN);
    upperCase(temp.petname);
    upperCase(temp.petkind);
    
    printf("%s the %s ", temp.petname, temp.petkind);
    if (InTree(&temp, pt)) {
        printf("is a member.\n");
    } else {
        printf("is not a member.\n");
    }
}
/*用户输入宠物名称, 去除宠物*/
void dropPet(Tree *pt)
{
    Item temp;
    if (TreeIsEmpty(pt)) {
        puts("No entries.");
        return; /*如果树为空则退出*/
    }
    puts("Please enter name of pet you want to drop:");
    puts("Please enter name of pet:");
    s_gets(temp.petname, MAXLEN);
    puts("Please enter kind of pet:");
    s_gets(temp.petkind, MAXLEN);
    upperCase(temp.petname);
    upperCase(temp.petkind);
    
    /*执行删除*/
    printf("Dropping %s the %s from the Club ", temp.petname, temp.petkind);
    if (DeleteItem(&temp, pt)) {
        printf("success.\n");
    } else {
        printf("failed, not found.\n");
    }
}

/*接收安全输入内容*/
char *s_gets(char *str, int cnt)
{
    char *temp, *find;
    temp = fgets(str, cnt, stdin);
    if (NULL != temp) {
        find = strchr(temp, '\n');
        if (NULL != find) {
            *find = '\0';
        } else {
            while (getchar() != '\n')
                continue;
        }
    }
    
    return temp;
}