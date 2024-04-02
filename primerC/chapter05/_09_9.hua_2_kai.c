/**
9.编写一个程序，要求用户输入一个华氏温度。
程序应读取double类型的值作为温度值，并把该值作为参数传递给一个用户自定义的函数
Temperatures0。该函数计算摄氏温度和开氏温度，并以小数点后面两位数字的精度显示3种温度。
要使用不同的温标来表示这3个温度值。下面是华氏温度转摄氏温度的公式:
    摄氏温度 = 5.0/9.0*(华氏温度- 32.0)

开氏温标常用于科学研究，0表示绝对零，代表最低的温度。下面是摄氏温度转开氏温度的公式:
    开氏温度=摄氏温度 +273.16
    
Temperatures0函数中用const创建温度转换中使用的变量。在main0函数中使用一个循环让用户重复输入温度，当用户输入q 或其他非数字时，循环结束。scanf0函数返回读取数据的数量，所以如果读取数字则返回1，如果读取q则不返回1。
可以使用== 运算符将scanf0的返回值和1作比较，测试两值是否相等。
 */
#include <stdio.h>
void Temperatures(float);

int main(void)
{
    float tmpt_w;
    puts("Enter an float number as temperature in wash");
    while (1 == scanf("%f", &tmpt_w)) {
        Temperatures(tmpt_w);
        puts("Enter another float number as temperature in wash");
    }
    
    printf("Done\n");
    return 0;
}

void Temperatures(float tmpt_w) {
    const float w2s_base = 32.0;
    const float w2s_ratio = (5.0/9.0);
    printf("w2s_ratio = %f\n", w2s_ratio);
    const s2k = 273.16;
    float tmpt_s,tmpt_k;
    tmpt_s = w2s_ratio * (tmpt_w - w2s_base);
    tmpt_k = tmpt_s + s2k;
    
    printf("%.2f wash degree equals %.2f sheshi degree equals %.2f kaishi degree", 
        tmpt_w,
        tmpt_s,
        tmpt_k
    );
    printf("\n");
}