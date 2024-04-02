/*
6.编写一个函数接受 3 个参数:
    一个数组名(内含已排序的整数)、
    该数组的元素个数
    待查找的整数。
如果待查找的整数在数组中，那么该函数返回 1;如果该数不在数组中，该函数则返回0。
用二分查找法实现
*/
#include <stdio.h>
#define MAX_SIZE 100
int binary_search(const int [], int, int);
int binary_search_recursive(int *, int, int);

int main(void)
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 100, 200, 300, 400, 555, 666, 777, 888, 999};
    int find,search;
    puts("Enter which number you are looking for(q to quit):");
    while (scanf("%d", &search) == 1) {
        int arr_size = sizeof(arr) / sizeof(arr[0]);/*数组元素个数*/
        if ( 1 == (find = binary_search(arr, arr_size, search)) ) {
            printf("%d is in array.\n", search);
        } else {
            printf("%d is not in array.\n", search);
        }
        puts("Enter another number you are looking for(q to quit):");
    }
    
    puts("done");
    return 0;
}

/*递归查找*/
int binary_search_recursive(int *arr, int size, int search)
{
    int mid_index,new_size;
    /*如果数组被分的只剩一个值*/
    if(size == 1) {
        return *arr == search ? 1 : 0;
    }
    /*使用递归查找*/
    else {
        mid_index = (size-1)/2; //数组中间值的索引,保证无论是奇数还是偶数取到的中间值索引都是同一个
        /*打印中间过程看查找执行了几次*/
        printf("mid_index = %d, mid_value=%d, search = %d\n", mid_index, arr[mid_index], search);
        // 往左找
        if (search < arr[mid_index]) {
            new_size = mid_index;
            binary_search_recursive(arr, new_size, search);
        }
        // 往右找
        else if (search > arr[mid_index]) {
            new_size = size - mid_index - 1;
            binary_search_recursive(&arr[mid_index+1], new_size, search);
        }
        // 找到
        else if (search == arr[mid_index]){
            return 1;
        }
        else {
            return 0;
        }
    }
}

/*循环查找*/
int binary_search(const int arr[], int size, int search)
{
    int mid,min,max,find;
    min = 0;/*最小索引*/
    max = size - 1;/*最大索引*/
    find = 0;
    while (min < max) {
        /*
        注意这个公式
        */
        mid = (max+min)/2;/*中间索引*/
        /*打印中间过程看查找执行了几次*/
        printf("mid = %d, mid_value=%d, search = %d\n", mid, arr[mid], search);
        if (search < arr[mid]) {
            max = mid - 1;
        }
        else if (search > arr[mid]) {
            min = mid + 1;
        }
        else {
            find = 1;
            break;
        }
    }
    if (search == arr[mid]) {
        find = 1;
    }
    return find;
}