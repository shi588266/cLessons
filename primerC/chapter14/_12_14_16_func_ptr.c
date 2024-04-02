/**
 * 函数指针
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  //各种转换函数的原型的头文件

#define MAXLEN 81    //长度比最大字符长度多1

char *s_gets(char *, int);
char show_menu_get_choice(void);
void eatline(void);
void show(void(*funcp)(char *), char *);    //第一个参数是[参数是字符指针返回值是void的函数指针]
void ToUpper(char *);
void ToLower(char *);
void TransPose(char *);
void Dummy(char *); //原样不更改

char input_str[MAXLEN];

int main(void)
{
    //char input_str[MAXLEN];
    char input_str_copy[MAXLEN];    //字符串拷贝
    void(*function_pointer)(char *);    //声明函数指针
    char choice;
    
    puts("Enter a string [empty ling to quit]:");
    while(s_gets(input_str, MAXLEN) != NULL && input_str[0] != '\0') {
        while ( 'n' != (choice = show_menu_get_choice()) ) {   //赋值运算符也有返回值, 返回值就是等号左边的值
            switch (choice) {
                case 'u':
                    function_pointer = ToUpper;break;
                case 'l':
                    function_pointer = ToLower;break;
                case 't':
                    function_pointer = TransPose;break;
                case 'd':
                default:
                    function_pointer = Dummy;break;
            }
            strcpy(input_str_copy, input_str);
            show(function_pointer, input_str_copy);
        }
        puts("Enter a new string [empty ling to quit]:");
    }
    
    puts("Bye!");
    return 0;
}

/**
 * 给出提示选项
 * 获取用户输入
 * 返回用户输入
 */
char show_menu_get_choice(void) {
    char ans;
    puts("Enter your choice");
    puts("u) To Upper       l) To Lower");
    puts("t) TransPose       d) nothing to do");
    puts("n) Next String Please");
    ans = tolower(getchar());
    eatline();
    while (NULL == strchr("ultdn", ans)) {
        puts("Warnning:please enter one char of \"ultdn\"");
        ans = tolower(getchar());
        eatline();
    }
    
    return ans;
}

void eatline(void){
    while (getchar() != '\n')
        continue;
}

/**
 * 
 */
void show(void(*funcp)(char *), char * str) {
    printf("Original string is: %s.\n", input_str);
    (*funcp)(str);
    printf("and now it is converted to: %s.\n", str);
}

void ToUpper(char * str) {
    while ( *str ) {
        *str = toupper(*str);
        str++;
    }
}
void ToLower(char * str) {
    while ( *str ) {
        *str = tolower(*str);
        str++;
    }
}
void TransPose(char * str) {
    while ( *str ) {
        *str = (*str >= 'a' && *str <= 'z') ? toupper(*str) : tolower(*str);
        str++;
    }
}
void Dummy(char * str) {
    //
}

char *s_gets(char *st, int len) {
    char *temp;
    char *findwrap;
    
    if ( temp = fgets(st, len, stdin) ) {
        findwrap = strchr(temp, '\n');
        if (findwrap) {
            *findwrap = '\0';
        } else {
            while (getchar() != '\n')
                continue;
        }
    }
    return temp;
}