#include<stdio.h>
void main()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    //arr:62fdf0,&arr:62fdf0,*arr:62fdf0,**arr:1
    printf("arr:%x,&arr:%x,*arr:%x,**arr:%x\n", arr, &arr, *arr, **arr);

    printf("%d\n", sizeof(int*)[4]);

    //*arr_size:16,*(&arr)_size:48,**arr_size:4
    printf("*arr_size:%d,*(&arr)_size:%d,**arr_size:%d\n", sizeof(*arr), sizeof(*(&arr)), sizeof(**arr));

    //arr_size=48, &arr_size=8, *arr_size=16, **arr_size=4
    printf("arr_size=%d, &arr_size=%d, *arr_size=%d, **arr_size=%d\n", sizeof(arr), sizeof(&arr), sizeof(*arr), sizeof(**arr));
}