#include <stdio.h>

void swap2(int *pa, int *pb) {
	int p = *pa; // p=*(0x0062fe0c)=100
	*pa = *pb;
	*pb = p;
	printf("a=%d,b=%d\n", *pa, *pb);	//200,100 
}

void swap(int *pa, int *pb) {
	//使用中间指针 交换两个变量
	int *p = pa;	// p=0x0062fe0c
	pa = pb;
	pb = p;
	printf("a=%d,b=%d\n", *pa, *pb);	//200,100 
}

void main(int argc, char const *argv[])
{
	/**
	 * 指针交换两个变量
	 */
	int a,b;
	printf("请输入两个整数\n");
	scanf("a=%d,b=%d", &a,&b);
	int *pa = &a;
	int *pb = &b;

	printf("%d,%d\n", *pa, *pb);	//100,200 
	printf("%x,%x\n", pa, pb);	//62fe0c,62fe08   

	if (a > b)
	{
		swap2(pa, pb);
	}
	
}