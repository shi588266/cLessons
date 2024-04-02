#include <stdio.h>

// 指针的操作
int main(void)
{
    int lst[5] = {100,200,300,400,500};
    int * ptr1,* ptr2,* ptr3;
    ptr1 = lst; //数组首元素地址赋值给指针
    ptr2 = &lst[2];
    // 解引用指针, 指针的地址
    printf("pointer value, derefrenced pointer, pointer adderss \n");
    printf("ptr1=%p, *ptr1=%d, &ptr1=%p \n", ptr1, *ptr1, &ptr1);
    
    // 指针的加法
    ptr3 = ptr1 + 4;    //数组首元素地址向后移动4个元素
    printf("\n\nadding an int to a pointer \n");
    printf("ptr1+4=%p, *(ptr1+4)=%d\n", ptr1+5, *(ptr1+5));
    
    //递增指针
    ptr1++;
    printf("\n\nafter pointer ++ \n");
    printf("ptr1=%p, *ptr1=%d, &ptr1=%p\n", ptr1, *ptr1, &ptr1); //指针的地址没有发生改变
    
    // 递减指针
    ptr2--;
    printf("\n\nafter pointer -- \n");
    printf("ptr2=%p, *ptr2=%d, &ptr2=%p\n", ptr2, *ptr2, &ptr2); //虽然指针指向同一个地址, 但是是两个不同的指针, 因为指针的地址不同
    
    // 回复为初始值
    ptr1--;
    ptr2++;
    printf("\n\nreset ptr1 PTR2 to original value \n");
    printf("ptr1=%p, ptr2=%p\n", ptr1, ptr2);
    
    // 一个指针减去另一个指针
    printf("\n\n subtracting one pointer from another \n");
    printf("ptr1=%p, ptr2=%p, ptr2-ptr1=%td\n", ptr1, ptr2, ptr2-ptr1); //对同一个数组而言两个指针的差值是他们之间元素的距离
    
    // 一个指针减去另一个整数
    printf("\n\n subtracting an int from a pointer \n");
    printf("ptr3=%p, ptr3-2=%p \n", ptr3, ptr3-2);  //指针减去一个整数, 相当于指针后移了整数个元素
}

