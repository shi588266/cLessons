/*
6.众所周知，C编译器为数组分配下标时总是从0开始。而且当程序使用下标访问数组元素时，它并不检查下标的有效性。在这个项目中，你将要编写一个函数，允许用户访问“伪数组”，它的下标范围可以任意指定，并伴以完整的错误检查。下面是将要编写的这个函数的原型：
            int array_offset ( int arrayinfo[], ... );
这个函数接受一些用于描述伪数组的维数的信息以及一组下标值。然后它使用这些信息把下标值翻译为一个整数，用于表示一个向量（一维数组）的下标。使用这个函数，用户既可以以向量的形式分配内存空间，也可以使用malloc分配空间，但按照多维数组的形式访问这些空间。这个数组之所以被称为“伪数组”，是因为编译器以为它是个向量，尽管这个函数允许它按照多维数组的形式进行访问。

对于一维伪数组:    loc = s1 - lo1
对于一维伪数组:    loc = (s1 – lo1) × (hi2 – lo2 + 1) + s2 – lo2
对于三维伪数组:    loc = [(s1 –lo1) × (hi2 – lo2 + 1) + s2 – lo2] × (hi3 – lo3 + 1) + s3 – lo3

变量s1、s2等代表下标参数s1、s2等。变量lo1和hi1代表下标s1的下限和上限，它们来源于arrayinfo参数，其余各维以此类推。变量loc表示伪数组的目标位置，它用一个距离伪数组起始位置的整型偏移量表示。
*/
#include <stdio.h>
#include <stdarg.h>


int array_offset ( int arrayinfo[], ... );

int main(void)
{
    int arrayinfo[] = { 3, 4, 6, 1, 5, -3, 3 };
    printf("loc = %d\n", array_offset( arrayinfo, 4, 2, -3 ));
    return 0;
}

/**
 * arrayinfo[0] 指定伪数组具有的维度, 值在 1~10 之间,包含10
 * arrayinfo[1] 给出第1维的下限, arrayinfo[2] 给出第1维的上限
 * arrayinfo[3] 给出第2维的下限, arrayinfo[4] 给出第2维的上限
 */
int array_offset ( int arrayinfo[], ... )
{
    int sub_index;
    int loc;
    va_list ap;
    va_start(ap, arrayinfo);
    
    //数组第一个元素能够确定数组的维度
    if (arrayinfo[0] < 1 || arrayinfo[0] > 10) {
        return -1;
    }
    
    loc = 0;
    for (int i = 0; i < arrayinfo[0]; i++) {
        sub_index = va_arg(ap, int);    //当前下标参数
        if ( arrayinfo[2*i+1] > sub_index 
            || arrayinfo[2*i+2] < sub_index 
            || arrayinfo[2*i+2] < arrayinfo[2*i+1]
        ) {
            return -1;
        }
            
        loc *= (arrayinfo[2*i+2] - arrayinfo[2*i+1] + 1);
        loc += sub_index - arrayinfo[2*i+1];
    }
    
    va_end( ap );
    return loc;
}