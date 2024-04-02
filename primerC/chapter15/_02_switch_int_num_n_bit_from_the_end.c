/**
 * 切换一个整数的后n位
 * 对二进制的每一位与 01 异或, 就可以切换该位上的位值
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //CHAR_BIT 宏定义,表示字节占用的位数

/*integer to binary string*/
char * i2bs(int, char *);
/*switch n bit of an integer from the end*/
char * switch_nb_r(const char *, int, char *);
void show_ibs(const char *);
const static size_t int_bit_size = CHAR_BIT * sizeof(int);

int main(void)
{
    int number,n;
    char arr_o[int_bit_size + 1];
    char arr_c[int_bit_size + 1];
    
    puts("Enter an integer number, Non-numberic will terminate");
    while ( 1 == scanf("%d", &number) ) {
        i2bs(number, arr_o);
        puts("Enter the number of bit that you will switch for the number, Non-numberic will terminate");
        while ( scanf("%d", &n) == 1 ) {
            if (n > int_bit_size) {
                printf("The number of bit should be less than %d,try again.\n", int_bit_size);
                continue;
            }
            printf("Entered int number is %d.\n", number);
            puts("The binary mode of the number is:");
            show_ibs(arr_o);
            putchar('\n');
            switch_nb_r(arr_o, n, arr_c);
            printf("After the ended %d bits was switched,it looks like:\n", n);
            show_ibs(arr_c);
            putchar('\n');
            puts("Enter the number of bit:");
        }
        puts("Enter another integer number:");
    }
    
    puts("Bye!!");
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
// 切换末端 n 位
char * switch_nb_r(const char * ibp_old, int n, char *ibp_new) 
{
    int i = 0;
    while ( ibp_old[i] ) {
        //对末端的n位进行切换
        if (i >= int_bit_size - n) {
            ibp_new[i] = (ibp_old[i] ^ 01);
        } else {
            ibp_new[i] = ibp_old[i];
        }
        i++;
    }
    ibp_new[i] = '\0';
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

