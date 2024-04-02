/**
 * 给定一个整数
 * 通过移位操作打印他的二进制形式
 * 用整数的每一位与 01 相与得到每一个位上的二进制
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //CHAR_BIT 宏定义,表示字节占用的位数

/*integer to binary string*/
char * i2bs(int, char *);
void show_ibs(const char *);

int main(void)
{
    int num;
    // 字符数组:用于存储二进制字符串,多一位用于存储字符串结尾的空字符
    char binstrarr[CHAR_BIT * sizeof(int) + 1];
    //char * binstrptr = binstrarr; 
    
    puts("Enter an integer number,a not number will terminate");
    while( 1 == scanf("%d", &num) ) {
        printf("The input number is %d.\n", num);
        i2bs(num, binstrarr);
        show_ibs(binstrarr);
        putchar('\n');
        puts("Enter another integer number:");
    }
    
    puts("Bye!");
    return 0;
}

// 整型数字的二进制位表示
char * i2bs(int num_int, char * cp) 
{
    int i;
    int int_bit = CHAR_BIT * sizeof(int);
    //char binstrarr[int_bit + 1];    // 字符数组:用于存储二进制字符串,多一位用于存储字符串结尾的空字符
    
    // 循环整数二进制表示的每一位, 注意每次循环整数右移一位
    for (i = int_bit - 1; i >= 0; i--, num_int >>= 1) {
        /* code */
        // 把位模式上的每一位与 1 相与, 得到的结果就是当前位上的真实表示
        *(cp + i) = ( num_int & 01 ) + '0';    //这里需要明确,整个过程是从位模式的末端开始处理的
    }
    *(cp+int_bit) = '\0';  //字符串结尾
    //cp = binstrarr;
    return cp;
}

/**
 * 4位一组展示整数的二进制形式
 */
void show_ibs(const char * ibs)
{
    int i = 0;
    while(ibs[i]) {
        putchar(ibs[i]);
        if (++i % 4 == 0 && ibs[i])
            putchar(' ');
    }
}