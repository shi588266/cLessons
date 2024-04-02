/**
 * 为一个进行算数运算的函数提供整数
 * 该函数计算特定范围内的所有整数的平方和
 * 范围的上限是 10000000, 下限是 -10000000
 */
 //预处理指令
 #include <stdio.h>
 #include <stdbool.h>
 
 // 函数声明
 long get_long(void);   //验证输入一个整数
 bool bad_limits(long begin, long end, long low, long high); //验证范围的上下限是否有效
 double sum_square(long a, long b); //计算a~b之间所有整数的平方和
 
int main(void)
{
    // 定义const 变量
    const long LOW = -10000000L;
    const long HIGH = 10000000L;
    
    printf("This program computes the sum of the squares integers in a range \n");
    printf("The lower bounds hould not be less than %ld,\n", LOW);
    printf("the bound upper should not be more than %ld,\n", HIGH);
    printf("enter 0 for both limits to quit)\n");
    
    long begin;
    long end;
    double sum;
    printf("lower limit:");
    begin = get_long();
    printf("upper limit:");
    end = get_long();
    // 上下限都为0 时 退出
    while (begin != 0 || end != 0) {
        if (!bad_limits(begin, end, LOW, HIGH)) {
            sum = sum_square(begin, end);
            printf("The sum of the squares from %ld to %ld is %.2lf\n", begin, end, sum);
        }
        
        printf("lower limit:");
        begin = get_long();
        printf("upper limit:");
        end = get_long();
    }
    printf("Bye!!\n");
    return 0;
}

/**
 * 获取终端输入, 如果输入不合法,提示重新输入
*/
long get_long(void)
{
    long l_int;
    int ch;
    while(scanf("%ld", &l_int) != 1) {
        while( (ch = getchar()) != '\n') {
            putchar(ch);
        }
        printf(" is not an integer value, please enter an integer value:");
    }
    return l_int;
}

/*
验证输入是否正确
*/
bool bad_limits(long begin, long end, long low, long high) 
{
    int is_bad = false;
    if(begin >= end) {
        printf("The lower is more than or equal the upper\n");
        is_bad = true;
    }
    if(begin < low) {
        printf("The lower is out of the lower bounds:%ld\n", low);
        is_bad = true;
    }
    if(end > high) {
        printf("The upper is out of the upper bounds:%ld\n", high);
        is_bad = true;
    }
    return is_bad;
}
// 范围内的整数求平方和
double sum_square(long a, long b)
{
    double total = 0;
    long i;
    for( i = a; i <= b; i++ )
        total += (double)i * (double)i;
    
    return total;
}