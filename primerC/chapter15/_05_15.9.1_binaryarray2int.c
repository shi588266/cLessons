#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLEN 65

int binarr2int(char *);
char * s_gets(char *, int len);

int main(void)
{
    int num;
    char * binarystr;   
    char binaryarr[MAXLEN];
    puts("enter a binary string");
    //s_gets(binarystr, MAXLEN);//指针如果未初始化, 可能指向任何地址, 像这个地址写入数据可能出现严重问题
    s_gets(binaryarr, MAXLEN);
    printf("You entered %s, it's value is %d.\n", binaryarr, binarr2int(binaryarr));
}

int binarr2int(char * bs) 
{
    int i,total,current = 0;
    while (bs[i] != '\0') { //提取公约数,每步进一次, 多乘以一次公约数 2 
        current = current * 2 + (bs[i++] - '0');
    }

    return current;
}

char * s_gets(char * bs, int len) 
{
    char * tmp;
    char * find;
    tmp = fgets(bs, len, stdin);
    if (tmp) {
        if (find = strchr(tmp, '\n')) { //读入了换行符说明输入未超出限制长度
            *find = '\0';
        } else {    //否则说明输入超出了限制长度, 清空缓冲区的多余的输入内容
            while (getchar() != '\n')
                continue;
        }
    }
    return tmp;
}