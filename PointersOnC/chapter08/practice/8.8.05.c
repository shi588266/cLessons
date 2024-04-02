/*
5.如果A是个x行y列的矩阵，B是个y行z列的矩阵，把A和B相乘，其结果将是另一个x行z列的矩阵C。这个矩阵的每个元素是由下面的公式决定的：
           y
    Ci,j = ∑ A i,k 乘以 B k,j + ...  (k从1到y)
          k=1
这就要求A矩阵的列数必须和B矩阵的行数相等
    
    
    2, 6                            50, 14, -144, -52
                4, -2, -4, -5       
    3, 5   X                    =   -23, -21, 18, 20    
                -7, -3, 6, 7            
    1, 1                            11, 1, -10, -12
    
结果矩阵中14这个值是通过2×-2加上-6×-3得到的。

编写一个函数，用于执行两个矩阵的乘法。函数的原型如下：
        void matrix_multiply( int *m1, int *m2, int *r,
                           int x,  int y, int z );
m1是一个x行y列的矩阵，m2是一个y行z列的矩阵。这两个矩阵应该相乘，结果存储于r中，它是一个x行z列的矩阵。记住，应该对公式做些修改，以适应C语言下标从0而不是1开始这个事实！
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 3
#define COLUMNS_ROWS 2
#define COLUMNS 4

void matrix_multiply( int *m1, int *m2, int *r, int x, int y, int z );

int main(void)
{
    int m1[ROWS][COLUMNS_ROWS] = {
        {2, -6},
        {3, 5},
        {1, -1}
    };
    int m2[COLUMNS_ROWS][COLUMNS] = {
        {4, -2, -4, -5},
        {-7, -3, 6, 7}
    };
    
    int des[ROWS][COLUMNS] = {0};
    matrix_multiply(&m1[0][0], &m2[0][0], &des[0][0], ROWS, COLUMNS_ROWS, COLUMNS);
    printf("row 1 column 1 for des is %d\n", des[2][3]);
    return 0;
}

/*
根据参数格式, 给出的两个矩阵都是指向矩阵第一个整数的指针, 
最终结果是 x 行 z 列, 使用双层for循环
*/
void matrix_multiply( int *m1, int *m2, int *r, int x, int y, int z )
{
    int *Ap,*Bp;
    //遍历第一个矩阵的每一行
    for (int i = 0; i < x; i++) {
        //遍历第二个矩阵的每一列
        for (int j = 0; j < z; j++) {
            Ap = m1+i*y;    //指向 m1的第i行
            Bp = m2+j;      //指向 m2 的第j列
            for (int k = 0; k < y; k++) {
                *r += *Ap * *Bp;
                Ap+=1;  //指向 m1的第i行, 每次前进1列
                Bp+=z;  //指向 m2 的第j列, 每次前前进 1 行
            }
            r++;
        }
    }
}
