/*
3.单位矩阵(identity matrix)就是一个正方形矩阵，它除了主对角线的元素值为1之外，其余元素的值均为0。
                  1  0  0
                  0  1  0
                  0  0  1
就是一个3×3的单位矩阵。编写一个名叫 identity_matrix 的函数，它接受一个10×10整型矩阵为参数，并返回一个布尔值，提示该矩阵是否为单位矩阵。
*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 4


bool identity_matrix(int matrix[MAX_SIZE][MAX_SIZE]);

int main(void)
{
    int test_matrix[MAX_SIZE][MAX_SIZE] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0, 1}
    };
    if (identity_matrix(test_matrix) == false) {
        printf("test_matrix is not an identity_matrix\n");
    } else {
        printf("test_matrix is an identity_matrix\n");
    }
    return 0;
}

/*双层for循环*/
bool identity_matrix(int matrix[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (i == j && matrix[i][j] != 1) {
                return false;
            }
            if (i != j && matrix[i][j] != 0) {
                return false;
            }
        }
    }
    
    return true;
}