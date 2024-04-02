/*
13.给定下列声明：
    int        array[4][5][3];
把下列各个指针表达式转换为下标表达式。
*/

#include <stdio.h>
int main(void)
{
    int        array[4][5][3];
    
}

/*
数组名是指针常量,指向数组中首元素的地址, 多维数组亦是如此, 只不过,这里的'数组首元素'又是一个数组
这里着重理解, *array 就是数组首元素(是个数组,数组首元素就是这个数组本身),
对指针的算术加减后的值执行间接访问 就得到数组对应数字序号的那个元素

*array                          array[0]
*(array + 2)                    array[2]
*(array + 1) + 4                array[1] + 4
*(*(array + 1) + 4)             array[1][4]
*(*(*(array + 3) + 1) + 2)      array[3][1][2]
*(*(*array + 1) + 2)            array[0][1][2]
*(**array + 2)                  array[0][0][2]
**(*array + 1)                  array[0][1][0]
***array                        array[0][0][0]
*/