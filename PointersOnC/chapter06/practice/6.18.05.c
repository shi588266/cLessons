/**
 * 5.修改前一题的Eratosthenes程序，使用位的数组而不是字符数组，这里要用到第5章编程练习4中所开发的位数组函数。这个修改使程序的空间效率进一步提高，不过代价是时间效率降低。在你的系统中使用这个方法，你所能找到的最大质数是多少？
 * 
 */

#include <stdio.h>
#define TRUE '1'
#define FALSE '0'
#define SIZE 190001

void Eratosthenes(char *list, unsigned count);
static void init_list(char *list, unsigned count);//初始化列表

void set_bit(char [], unsigned);
void clear_bit(char [], unsigned);
void assign_bit(char [], unsigned, int);
int test_bit(char [], unsigned);

int main(void)
{
    char list[SIZE];
    Eratosthenes(list, SIZE);
    
    int line_cnt = 0;
    int number;
    for (int i = 2; i <= SIZE; i++) {
        if (test_bit(list, i) == TRUE) {
            line_cnt++;
            //数组中的元素只对应奇数
            number = i == 2 ? 2 : 2 * i - 3;
            printf("%d\t", number);
            if (line_cnt % 6 == 0) {
                printf("\n");
            }
        }
    }
    putchar('\n');
    return 0;
}

/*
利用位函数寻找列表内的质数
*/
void Eratosthenes(char *list, unsigned count)
{
    int index;
    int number;
    init_list(list, count);
    //printf("list is %s\n", list);
    /*
    序数从0开始,从序数3开始,序数(0 1 2 3 4 5 6 7 8 9)对应的值(0,1,2,3,5,7,9,11,13,15)表示为:n+n-3
    从 2 开始作为被除数, 序数的值与2相除, 余数为0的序数置为false,
    然后 3作为被除数, 序数的值与3相除, 余数为0的序数置为false,
    */
    for (index = 2; index <= count; index++)
    {
        if (test_bit(list, index) == TRUE) {
            for (int j=index+1; j <= count; j++) {
                number = 2 * j - 3; //序号对应的值
                if (list[j] == TRUE && number % index == 0) {
                    clear_bit(list, j); //把第 j 位设置为 false
                }
            }
        }
    }
}

/*初始化列表*/
void init_list(char *list, unsigned count)
{
    for (int i = 0; i <= count; i++) {
        set_bit(list, i); //把第 i 位设置为true
    }
}

void set_bit(char bit_array[], unsigned bit_number)
{
    bit_array[bit_number] = '1';
}

void clear_bit(char bit_array[], unsigned bit_number)
{
    bit_array[bit_number] = '0';
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
    bit_array[bit_number] = value == '0' ? '0' : '1';
}

int test_bit(char bit_array[], unsigned bit_number)
{
    return bit_array[bit_number] == '0' ? '0' : '1';
}