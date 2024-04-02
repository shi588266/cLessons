/*
1.编写一个程序，从标准输入读取一些字符，并统计下列各类字符所占的百分比。
控制字符  空白字符  数字  小写字母  大写字母  标点符号  不可打印的字符  
请使用在ctype.h头文件中定义的字符分类函数。
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 10086
#define NUL '\0'

static char* s_gets(char *str, int length);

int main(void)
{
    char buffer[MAX_LEN];
    char chr;
    int cntrl_num,blank_num,digit_num,lower_num,upper_num,punctual_num,disprint_num;
    cntrl_num = blank_num = digit_num = lower_num = upper_num = punctual_num = disprint_num = 0;
    
    puts("Enter a sentence containing as many character types as possible");
    if (s_gets(buffer, MAX_LEN)) {
        int index = 0;
        while ( (chr = buffer[index++]) != NUL ) {
            if (iscntrl(chr)) {
                cntrl_num += 1;
            }
            if (isblank(chr)) {
                blank_num += 1;
            }
            if (isdigit(chr)) {
                digit_num += 1;
            }
            if (islower(chr)) {
                lower_num += 1;
            }
            if (isupper(chr)) {
                upper_num += 1;
            }
            if (ispunct(chr)) {
                punctual_num += 1;
            }
            if (!isprint(chr)) 
                disprint_num += 1;
        }
        printf("cntrl_num=%d\t,blank_num=%d\t,digit_num=%d\t,lower_num=%d\t,upper_num=%d\t,punctual_num=%d\t,disprint_num=%d", cntrl_num,blank_num,digit_num,lower_num,upper_num,punctual_num,disprint_num);
        putchar('\n');
    }
    
    return 0;
}

/*安全地获取终端输入*/
static char* s_gets(char *str, int length)
{
    char *temp;
    if (fgets(str, length, stdin) == NULL) {
        return NULL;
    }
    
    temp = strchr(str, '\n');
    if (temp != NULL) {
        *temp = '\0';
    } else {
        while (getchar() != '\n') {
            continue;
        }
    }
    return str;
}