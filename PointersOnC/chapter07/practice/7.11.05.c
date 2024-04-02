/*
5.实现一个简化的printf函数，它能够处理%d、%f、%s和%c格式码。
根据ANSI标准的原则，其他格式码的行为是未定义的。可以假定已经存在函数 print_integer 和 print_float ，用于打印这些类型的值。
对于另外两种类型的值，使用putchar来打印。
*/
#include <stdio.h>
#include <stdarg.h>

#define NUL '\0'

void my_printf(const char *restrict format, ...);
void print_integer(int intval)
{
    printf("%d", intval);
}
void print_float(double fval)
{
    printf("%lf", fval);
}

int main(void)
{
    int d = 14;
    my_printf("%d===%f sdfds %c%s%f", d, 3.34, 65, "65535", 89.99);
    return 0;
}

/*
思路:
    对于参数个数不确定的函数, 并且参数与格式符一一对应的情况, 考虑使用变参函数实现
*/
void my_printf(const char *restrict format, ...)
{
    int ch;
    char *str;
    char chr;
    
    // 1. 声明变量
    va_list var_args;
    // 2. 初始化, 注意放在while循环外面
    va_start(var_args, format);
    
    while ( (ch = *format++) != NUL ) {
        if (ch != '%') {
            putchar(ch);
            continue;
        } 
        
        // 获取 % 以及 %后面的格式符
        switch ( *format != NUL ? *format++ : NUL ) {
            // 3. 获取参数
            case 'd':
                print_integer( va_arg(var_args, int) );
                break;
            case 'f':
                print_float( va_arg( var_args , double ) );
                break;
            case 's':
                str = va_arg( var_args, char * );//可以使用任何类型
                while (*str != NUL) {
                    putchar(*str++);
                }
                break;
            case 'c':
                chr = va_arg(var_args, int);
                putchar(  chr );
                break;
            default:
                putchar(va_arg(var_args, int));
                break;
        }
    }
    
    // 4. 清理参数列表, 注意放在while循环外面
    va_end( var_args );
}