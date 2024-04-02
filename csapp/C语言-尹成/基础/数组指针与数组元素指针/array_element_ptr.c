#include<stdio.h>
void main(int argc, char const *argv[])
{
    int arr[5] = {10, 20, 30, 40, 50};
    printf("arr:%x,&arr:%x\n", arr, &arr);	//arr:62fe00,&arr:62fe00
    printf("arr_size:%d,&arr_size:%d\n", sizeof(arr), sizeof(&arr));// arr_size:20,&arr_size:8
    printf("*arr_size:%d,*(&arr)_size:%d\n", sizeof(*arr), sizeof(*(&arr))); //*arr_size:4,*(&arr)_size:20

    int *p = (int *)arr;	//定义一个指针变量指向数组的首元素地址
    int (*pa)[5] = &arr;	//定义一个 包含5个元素的数组指针变量 指向数组
    printf("p:%x,pa:%x\n", p, pa);	//p:62fdf0,pa:62fdf0
    printf("*p:%d,*pa:%x\n", *p, *pa);	// *p:10,*pa:62fdf0
    printf("p_size:%d,pa_size:%x\n", sizeof(p), sizeof(pa));	// p_size:8,pa_size:8
}