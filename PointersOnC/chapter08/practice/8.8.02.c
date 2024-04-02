/*
2.美国联邦政府使用下面这些规则计算1995年每个公民的个人收入所得税：
收入: 0~23350   税率: 15%
收入: 23350~56550   税率: 28%
收入: 56550~117950   税率: 31%
收入: 117950~256500   税率: 36%
收入: 256500 ~ +∞   税率: 39.6%
为下面的函数原型编写函数定义：
            float single_tax( float income );
参数income表示应征税的个人收入，函数的返回值就是income应该征收的税额。
*/
#include <stdio.h>

float single_tax( float income );

/*工资层级*/
const static float min_income[] = {
    0, 23350, 56550, 117950, 256500
};
/*税率层级*/
const static float tax_ratio[] = {
    0.15, 0.28, 0.31, 0.36, 0.396
};

int main(void)
{
    float salary = 256500.00;
    printf("My salary is %lf, my tax is %lf\n\n", salary, single_tax(salary));
}

float single_tax( float income )
{
    int index;
    float tax = 0.00;
    float current_max;
    for (int i = 0; income >= min_income[i] && i < 5; i++) {
        current_max = i < 4 ? min_income[i+1] : income;
        current_max = income > current_max ? current_max : income;
        tax += (current_max - min_income[i] ) * tax_ratio[i];
    }
    
    return tax;
}