#include<stdio.h>
void main(int argc, char const *argv[])
{
    int arr[10] = {0};
    int *p = arr;	//arr是int类型 常量, 是数组首元素的地址
    for (; p < arr + sizeof(arr)/sizeof(int); p++)	// p是int类型的指针, p++每次前进4字节
    {
    	// p是地址, *p是元素值
        printf("%x:%d\n", p, *p);
    } 
}