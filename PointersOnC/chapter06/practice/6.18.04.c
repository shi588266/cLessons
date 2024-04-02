/*
4.质数就是只能被1和本身整除的整数。Eratosthenes筛选法是一种计算质数的有效方法。这个算法的第1步就是写下所有从2至某个上限之间的所有整数。在算法的剩余部分，遍历整个列表并剔除所有不是质数的整数。

注意，除了2之外，所有的偶数都不是质数。稍微多想一下，你可以使程序的空间效率大为提高，方法是数组中的元素只对应奇数。这样，在相同的数组空间内，可以寻找到的质数的个数大约是原先的两倍。

 */
#include <stdio.h>
#define TRUE '1'
#define FALSE '0'
#define SIZE 1000000

void Eratosthenes(char *list, unsigned count);
static void init_list(char *list, unsigned count);//初始化列表

int main(void)
{
    char list[SIZE];
    Eratosthenes(list, SIZE);
    
    int line_cnt = 0;
    int number;
    for (int i = 2; i <= SIZE; i++) {
        if (list[i] == TRUE) {
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
    printf("line_cnt = %d\n\n", line_cnt);
    return 0;
}

/*寻找列表内的质数*/
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
        if (list[index] == TRUE) {
            for (int j=index+1; j <= count; j++) {
                number = 2 * j - 3; //序号对应的值
                if (list[j] == TRUE && number % index == 0) {
                    list[j] = FALSE;
                }
            }
        }
    }
}

/*初始化列表*/
void init_list(char *list, unsigned count)
{
    for (int i = 0; i < count; i++) {
        list[i] = TRUE;
    }
}