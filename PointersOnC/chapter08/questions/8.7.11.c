/*
11.给定下列声明：
    Int     array[4][2][3][6];
计算上表中各个表达式的值。同时，写出变量x所需的声明，这样表达式不用进行强制类型转换就可以赋值给x。
假定数组的起始位置为1000，整型值在内存中占据4字节的空间。
*/
#include <stdio.h>

int main(void)
{
    int     array[4][2][3][6];
    printf("array=%d\t", array);
    printf("array+2=%d\t", array+2);
    printf("array[3]=%d\t", array[3]);
    printf("array[2]-1=%d\t", array[2]-1);
    putchar('\n');
    printf("array[2][1]=%d\t", array[2][1]);
    printf("array[1][0]+1=%d\t", array[1][0]+1);
    printf("array[1][0][2]=%d\t", array[1][0][2]);
    putchar('\n');
    printf("array[0][1][0]+2=%d\t", array[0][1][0]+2);
    printf("array[3][1][2][5]=%d\t", array[3][1][2][5]);
    printf("&array[3][1][2][5]=%d\t", &array[3][1][2][5]);
    putchar('\n');
    putchar('\n');
    return 0;
}

/*
array                 1000                                      int (*x)[2][3][6]       
array+2               1000+(2*3*6)*2*4=1288                     int (*x)[2][3][6]  
array[3]              1000+(2*3*6)*3*4=1432                     int (*x)[3][6]    
array[2]-1            1000+(2*3*6)*2*4-3*6*4=1216               int (*x)[3][6]            
array[2][1]           1000+(2*3*6)*2*4+(3*6)*4=1360             int (*x)[6]  
array[1][0]+1         1000+(2*3*6)*1*4+6*1*4=1168               int (*x)[6]      
array[1][0][2]        1000+(2*3*6)*1*4+(6*2)*4=1192             int (*x)    
array[0][1][0]+2      1000+(3*6)*4+2*4=1080                     int (*x)
array[3][1][2][5]     0                                         int
&array[3][1][2][5]    1000+(2*3*6)*3*4+(3*6)*1*4+6*2*4+5*4=1572 int *x                
*/