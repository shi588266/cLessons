/*
2.编写一个函数，从标准输入读取一列整数，把这些值存储于一个动态分配的数组中并返回这个数组。函数通过观察EOF来判断输入列表是否结束。数组的第1个数是数组包含的值的个数，它的后面就是这些整数值。
*/
#include <stdlib.h>
#include <stdio.h>
#define DELTA 10    //数组初始大小及增量大小
/*
读取一列整数把这些值存储于一个数组,数组的第1个数是数组包含的值的个数
*/
int *read_sequence()
{
    int value;
    int cnt = 0;
    int size = DELTA;
    int *vlp = malloc((size+1) * sizeof(int));
    if (NULL == vlp) {
        return NULL;
    }
    puts("Enter a column of values, ctr+d to finish");
    while ( scanf("%d", &value) == 1) {
        cnt++;
        // 超出已分配的数组内存大小, 需要重新分配内存
        if (cnt >= size) {
            size += DELTA;
            vlp = realloc(vlp, (size+1) * sizeof(int));
            if (NULL == vlp) {
                return NULL;
            }
        }
        // 数字存储到数组里
        vlp[cnt] = value;
    }
    /*
    修改数组的长度,使其刚刚好
    */
    if (size > cnt) {
        vlp = realloc(vlp, (cnt+1) * sizeof(int));
        if (NULL == vlp) {
            return NULL;
        }
    }
    //数组的第1个数是数组包含的值的个数
    vlp[0] = cnt;
    return vlp;
}

int main(void)
{
    int *array = read_sequence();
    printf("array = %d\n", array[0]);
    printf("array = %s\n", array);
}