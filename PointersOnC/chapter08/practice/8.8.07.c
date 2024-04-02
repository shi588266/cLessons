/*
7.修改问题6的array_offset函数，使它访问以列主序存储的伪数组，也就是最左边的下标率先变化。这个新函数(array_offset2)在其他方面应该与原先那个函数一样。
计算这些数组下标的公式如下所示。对于一维伪数组：
loc = s1 - lo1
对于二维伪数组：
loc = (s2 – lo2) × (hi1 – lo1 + 1) + s1 – lo1
对于三维伪数组：
loc = [(s3 –lo3) × (hi2 – lo2 + 1) + s2 – lo2] × (hi1 – lo1 + 1) + s1 – lo1
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
    int loc,times;
    va_list ap;
    va_start(ap, arrayinfo);
    
    //数组第一个元素能够确定数组的维度
    if (arrayinfo[0] < 1 || arrayinfo[0] > 10) {
        return -1;
    }
    
    loc = 0;
    times = 1;
    for (int i = 0; i < arrayinfo[0]; i++) {
        sub_index = va_arg(ap, int);    //当前下标参数
        if ( arrayinfo[2*i+1] > sub_index 
            || arrayinfo[2*i+2] < sub_index 
            || arrayinfo[2*i+2] < arrayinfo[2*i+1]
        ) {
            return -1;
        } else {
            loc += (sub_index - arrayinfo[2*i+1]) * times;
            times *= (arrayinfo[2*i+2] - arrayinfo[2*i+1] + 1);
        }
    }
    
    va_end( ap );
    return loc;
}