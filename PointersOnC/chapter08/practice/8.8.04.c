/*
4.修改前一个问题中的identity_matrix函数，它可以对数组进行扩展，从而能够接受任意大小的矩阵参数。
函数的第1个参数应该是一个整型指针，你需要第2个参数，用于指定矩阵的大小。
*/
#include <stdio.h>
#include <math.h>   //math库不是gcc默认指定的库文件, 在编译时需要我们自己将gcc手动链接到math库。
#include <stdbool.h>

#define MAX_SIZE 4


bool identity_matrix(int *matrix, int size);

int main(void)
{
    int test_matrix[MAX_SIZE][MAX_SIZE] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0, 1}
    };
    if (identity_matrix(&test_matrix[0][0], 16) == false) {
        printf("test_matrix is not an identity_matrix\n");
    } else {
        printf("test_matrix is an identity_matrix\n");
    }
    return 0;
}

/*双层for循环*/
bool identity_matrix(int *matrix, int size)
{
    int rows = sqrt(size);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (i == j && *(matrix + i + j) != 1) {
                return false;
            }
            if (i != j && *(matrix + i + j) != 0) {
                return false;
            }
        }
    }
    
    return true;
}