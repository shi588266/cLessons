/*
10.给定下列声明：
        int        array[4][2];
请写出下面每个表达式的值。假定数组的起始位置为1000，整型值在内存中占据2字节的空间.
注意:
    由于数组连续存储的特性, 多维数组在内存中可以等价视为连续存储的一维数组
*/
#include <stdio.h>

int main(void)
{
    int        array[4][2];
    
    printf("array=%d\t", array);
    printf("array+2=%d\t", array+2);
    printf("array[3]=%d\t", array[3]);
    printf("array[2]-1=%d\t", array[2]-1);
    printf("&array[1][2]=%d\t", &array[1][2]);
    printf("&array[2][0]=%d\t", &array[2][0]);
    
    putchar('\n');
    putchar('\n');
    return 0;
}

/*
array                 1000                                
array+2               1008      array 指向数组第1行, array+2指向第3行           
array[3]              1012      array[3] 指向数组第4行(第1列)     
array[2]-1            1006      array[2] 指向数组第3行, array[2]-1 指向数组第2行第2列
&array[1][2]          1008      
    array[1][2] 字面上是第2行第3列的元素, 但是不存在第3列,由于数组连续存储的特性, 所以转移到第3行1列 &array[2][0]
&array[2][0]          1008      &array[2][0] 储存的是数组第3行第1列元素的地址    
*/