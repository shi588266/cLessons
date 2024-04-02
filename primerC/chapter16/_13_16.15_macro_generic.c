/**
 * 泛型宏
 * 基本浮点类型数学函数的参数都是 double, 也可以传递float 和long double 类型, 会被自动转换为double
 * 但是这种转化并不是最好的处理方式, 我们需要根据传递的参数类型使用对应的数学函数
 */
#include <stdio.h>
#include <math.h>
#define RADIUS_TO_DEGREE (180 / (4 * atanl(1)))

/**
 * 泛型平方根函数
 * 泛型表达式的值是函数名/函数指针
 * 先对泛型选择表达式求值得一个指针，然后通过该指针调用它所指向的函数
 */
#define SQRT(X) _Generic((X),\
float:sqrtf,\
long double:sqrtl,\
default:sqrt\
)(X)

/**
 * 泛型正弦函数
 * 泛型表达式的值是函数调用
 * 函数调用在泛型选择表达式内部完成
 */
#define SIN(X) _Generic((X),\
float:sinf((X) / RADIUS_TO_DEGREE),\
long double:sinl((X) / RADIUS_TO_DEGREE),\
default:sin((X) / RADIUS_TO_DEGREE)\
)

int main(void)
{
    float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0L;
    
    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);
    
    printf("%.17Lf\n", y);
    printf("%.17Lf\n", yy);
    printf("%.17Lf\n", yyy);
    
    int i = 45;
    yy = SQRT(i);
    printf("%.17Lf\n", yy);
    
    yyy = SIN(xxx);
    printf("%.17Lf\n", yyy);
    return 0;
}
