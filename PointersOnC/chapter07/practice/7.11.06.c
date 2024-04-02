/*
6.编写如下函数：
        void written_amount( unsigned int amount, char *buffer );
它把amount表示的值转换为单词形式，并存储于buffer中。这个函数可以在一个打印支票的程序中使用。
例如，如果amount的值是16312，那么buffer中存储的字符串应该是
        SIXTEEN THOUSAND THREE HUNDRED TWELVE
调用程序应该保证buffer缓冲区的空间足够大。
有些值可以用两种不同的方法进行打印。例如，1200可以是ONE THOUSAND TWO HUNDRED或TWELVE HUNDRED。可以选择一种自己喜欢的形式。
*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10086

void written_amount( unsigned int amount, char *buffer );

static char* number[] = {
    "", "one ", "two ", "three ", "four ", "five ",
    "six ", "seven ", "eight ", "nine ","ten ",
    "elven ", "twelve ", "thirteen ", "fourteen ", "fifteen ",
    "sixteen ", "seventeen ", "eighteen ", "nineteen "
};
static char* decent[] = {
    "", "", "twenty ", "thirty ", "forty ", "fifty ",
    "sixty ", "seventy ", "eighty ", "ninety "
};
static char* degree[] = {
    "", "thousand ", "million ", "billion "
};

int main(void)
{
    char buf[MAX_SIZE];
    memset( buf, 0, sizeof(buf) );//声明数组时使用memset将数组置空
    unsigned int test = 2119850086;
    written_amount(test, buf);
    printf("%d in written is: %s\n\n", test, buf);
    return 0;
}

/*
根据题目要求可以选用千分或者百分的任意一种方式打印
使用千分位方式打印, 用数字持续除以1000, 商作为下一次的除数, 直到商为0
*/
void written_amount( unsigned int amount, char *buffer )
{
    int new_divisor,new_mod;
    int degree_depth = 0;   //千分位的深度
    int mod_arr[MAX_SIZE];
    while ( (new_divisor = amount / 1000) != 0 ) {// 1008 611  1    1 8 2    
        mod_arr[degree_depth] = amount % 1000;
        amount = new_divisor;
        degree_depth++;
    }
    
    int temp,new_temp;
    /*处理最后的余数*/
    temp = amount % 1000;
    if (temp > 0) {
        temp = temp / 100;
        if (temp > 0) {
            strcat(buffer, number[temp]);
            strcat(buffer, "hundred ");
        }
        temp = amount % 100;
        if (temp > 0) {
            int new_temp = temp / 20;
            if (new_temp == 0) {
                strcat(buffer, number[temp]);
            } else {
                temp = temp / 10;
                if (temp > 0) {
                    strcat(buffer, decent[temp]);
                }
                temp = amount % 10;
                if (temp > 0) {
                    strcat(buffer, number[temp]);
                }
            }
        }
        // 当前千分位的单位
        strcat(buffer, *(degree + degree_depth));
    }


    while (--degree_depth >= 0) {
        temp = mod_arr[degree_depth] / 100;
        if (temp > 0) {
            strcat(buffer, number[temp]);
            strcat(buffer, "hundred ");
        }
        temp = mod_arr[degree_depth] % 100;
        if (temp > 0) {
            /*除以20, 如果商为0, 说明在 0~19 之间*/
            int new_temp = temp / 20;
            if (new_temp == 0) {
                strcat(buffer, number[temp]);
            } else {
                /*超过20, 除以10, 得到的商是十位, 余数是个位*/
                temp = temp / 10;
                if (temp > 1) {
                    strcat(buffer, decent[temp]);
                }
                temp = mod_arr[degree_depth] % 10;
                if (temp > 0) {
                    strcat(buffer, number[temp]);
                }
            }
        }
        // 当前千分位的单位
        strcat(buffer, *(degree + degree_depth));
    }
    
}

