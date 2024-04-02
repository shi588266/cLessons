/**
 * 切换一个整数的后n位
 * 创建一个末端 n 位全为1的掩码, 与整数按位 异或即可
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //CHAR_BIT 宏定义,表示字节占用的位数

/*integer to binary string*/
char * i2bs(int, char *);

int invert_n_bit(int);
void show_ibs(const char *);
const static size_t int_bit_size = CHAR_BIT * sizeof(int);

int main(void)
{
    int number,bitn,mask;
    char int_bin_arr[int_bit_size + 1];
    
    puts("Enter an integer number, Non-numberic will terminate");
    while ( 2 == scanf("%d %d", &number, &bitn) ) {
        while (bitn > int_bit_size) {
            printf("The number of bit should be less than %d,try again.\n", int_bit_size);
            scanf("%d", &bitn);
        }
        
        mask = invert_n_bit(bitn);
        printf("Entered int number is %d.\n", number);
        puts("The binary mode of the number is:");
        i2bs(number, int_bin_arr);
        show_ibs(int_bin_arr);
        putchar('\n');
        
        number ^= mask;
        printf("After the ended %d bits was switched,it looks like:\n", bitn);
        i2bs(number, int_bin_arr);
        show_ibs(int_bin_arr);
        putchar('\n');
        puts("Enter another integer number:");
    }
    puts("Bye!!");
    return 0;
}

// 创建最后 n 位全为1的掩码
int invert_n_bit(int n) 
{
    int mask = 0;
    int on = 1;
    while (n-- > 0) {
        // 任何数与 1 相或值为 1
        mask |= on;
        on <<= 1;
    }
    return mask;
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