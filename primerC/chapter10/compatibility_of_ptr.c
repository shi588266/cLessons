/**
 * 不用类型转换就可以把int类型的变量赋值给double类型变量
 * 但是不同类型的指针不能赋值
 */
 
#include <stdio.h>
 
int main(void)
{
    int i_x = 5;
    double db_y;
    
    int * ptr_int = &i_x;
    double * ptr_db = &db_y;
    
    db_y = i_x;    //隐式类型转换
    
    //ptr_db = ptr_int;    //编译时错误--警告：从不兼容的指针类型赋值 [默认启用]
    
    int * ptr_i;
    int (*ptr_arr)[3];  //一个指向含有3个int类型元素的数组的指针
    int arr1[2][3];
    int arr2[3][2];
    int ** ptr_ptr;
    
    ptr_i = &arr1[0][0];    //合法 都是指向int 类型的指针
    ptr_i = arr1[0];        //合法: 都是指向int 类型的指针(隐含的表达式 ar2[0] = &ar2[0][0])
    //ptr_i = arr1;   //赋值无效---警告：从不兼容的指针类型赋值 [默认启用]
    //ptr_i = arr2;   //赋值无效---警告：从不兼容的指针类型赋值 [默认启用]
    
    ptr_arr = arr1;     //合法: 都是指向含有3个int类型元素的数组的指针
    //ptr_arr = arr2;     //赋值无效---警告：从不兼容的指针类型赋值 [默认启用]
    
    ptr_ptr = &ptr_i;     //合法: 都是指向 int* 的指针
    *ptr_ptr = arr1[0];     //合法: 都是指向 int 的指针(隐含的表达式 arr1[0] = &arr1[0][0])
    *ptr_ptr = arr2[0];
    
    //ptr_ptr = arr1;     //赋值无效--- 一个指向 int* , 一个指向 arr*
}