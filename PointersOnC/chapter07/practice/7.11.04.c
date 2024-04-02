/*
4.编写一个名叫max_list的函数，用于检查任意数目的整型参数并返回它们中的最大值。
参数列表必须以一个负值结尾，用于提示列表的结束。
*/
#include <stdio.h>
#include <stdarg.h>

#define MAX_SIZE 100

/*数组方式实现*/
int max_list_a(int *int_list)
{
    int int_value;
    int max_value = 0;
    while ( (int_value = *int_list) >=0 && int_value != '\0' )
    {
        if (int_value > max_value) {
            max_value = int_value;
        }
        int_list++;
    }
    
    return max_value;
}

/*可变参数方式实现*/
int max_list(int first_number, ...)
{
    int max = first_number;
    
    if (first_number > 0) {
        // 1. 声明 va_list 类型变量, 存储参数列表
        va_list var_args;
        // 2. 使用 var_start() 宏,初始化参数列表
        va_start(var_args, first_number);
        int temp;
        while ((temp = va_arg(var_args, int)) >= 0) {
            if (temp > max) {
                max = temp;
            }
        }
        // 4. 使用var_end()宏,释放参数俩表
        va_end(var_args);
    }
    return max;
}

int main(void)
{
    int int_list[MAX_SIZE] = {100, 111, 222, 1, 2, 3, 5 ,55, 66, 88, 256, 99, 7, -10086, 33};
    printf("int_list max_value is %d\n", max_list(6, 1, 12, 234, 56, 344, 45, -1 ));
}