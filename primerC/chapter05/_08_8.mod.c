/**
8.编写一个程序，显示求模运算的结果。把用户输入的第1个整数作为求模运算符的第2个运算对象，该数在运算过程中保持不变。
用户后面输入的数是第1个运算对象。当用户输入一个非正值时，程序结束。其输出示例如下:
This program computes moduli
Enter an integer to serve as the second oprand: 256
now enter the first oprand: 438
438 % 256 is 182
Enter the next number for first oprand: 1234567
1234567 % 256 is 135
 */
#include <stdio.h>

int main(void)
{
    int first,second,moduli;
    puts("This program computes moduli");
    printf("Enter an integer to serve as the second oprand:");
    if (scanf("%d", &second) == 1) {
        printf("Now enter the first oprand:");
        while (scanf("%d", &first) == 1 && first > 0) {
            printf("%d %% %d is %d", first, second, first % second);
            printf("\n");
            printf("Enter the next number for first oprand:");
        }
    }

    
    printf("Done\n");
    return 0;
}

