#include<stdio.h>

// 二维静态数组
void tow_division_static_array() {
	int a[2][6] = {1,2,3,4,5,6,7,8,9,10,11,12};
	printf("%p\n", a);	//静态二维数组在内存中线性排列

	//int (*p)[6];	//指向 包含6个元素的一维数组 的指针   二维数组指针指向类型的大小要是一个一维数组的大小
	// int *p = a; 
	int *p = &a[0][0];	// 创建指针指向 数组首元素的地址
	for (; p < &a[0][0] + 2 * 6; p++)// p是int类型的指针, p++每次前进也是4字节
	{
		printf("%p:%d\n", p, *p);
	}
}

void main(int argc, char const *argv[])
{
	tow_division_static_array();
}

