#include<stdio.h>
#include<stdlib.h>
/**
 * 手动输入 x, y 创建动态二维数组
 */
void real_dynamic_array()
{
	printf("情输入动态数组的行数列数,逗号分割\n");
	int line,column;
	scanf("%d,%d", &line, &column);

	// 创建一个指针数组, 它的每个元素都是指针, 每个元素都指向一个   包含 column 个元素的一维数组
	// 二级指针可以存放指针, 将指针数组的首地址传递给pp保存
	int **pp = (int **)malloc(sizeof(int *) * line);

	/**
	 * 为指针数组的每一个指针分配内存
	 */
	for (int i = 0; i < line; i++)
	{
		pp[i] = (int *)malloc(sizeof(int)*column);
	}

	/**
	 * 为指针里的每个一维数组元素初始化
	 */
	int m,n,num;
	num=0;
	for (m = 0; m < line; m++)
	{
		for (n = 0; n < column; n++)
		{
			// pp[m][n] 与 *(*(pp+m)+n) 等价
			pp[m][n] = num;
			printf("%-4d", *(*(pp+m)+n));
			num++;
		}
		printf("\n");
	}

	// 释放内存
	for (int k = 0; k < line; k++)
	{
		free(pp[k]);	// 传入指针地址
	}
	//传入指针地址释放内存; 软件工程规范:释放内存后把指针赋值为NULL
	free(pp);
	pp = NULL;	//软件工程规范:释放内存后把指针赋值为NULL, 避免再次引用指针时,引用到错误的数据
}

/**
 * 手动输入 x, y 创建动态二维数组 p[x][y],列必须是常量
 * @return [description]
 */
void const_column_dynamic_array()
{
	printf("情输入动态数组的行数列数\n");
	int line,column;
	scanf("%d,%d", &line,  &column);

	// 为动态数组分配连续的内存空间, 需要知道它的元素个数, line行 column列, 以及元素值类型 int
	void *p = malloc(line * column * sizeof(int));
	// 列必须是一个已知的常量才能将这一片内存当作二维数组来使用
	int (*p2)[9] = p;  // 创建一个指向  包含9个元素的一维数组		的指针
	int i,j,num;
	for (i = 0; i < line; ++i)
	{
		for (j = 0; j < 9; ++j)
		{
			p2[i][j] = ++num;
			printf("%4d", p2[i][j]);
		}
		printf("\n");
	}
}


void main(int argc, char const *argv[])
{
	real_dynamic_array();
}