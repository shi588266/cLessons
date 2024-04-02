/**
操作符的优先级问题
正常的操作符优先级和函数调用优先级
运行下面的程序观察其执行结果
    猜测: 函数调用优先级高于其他操作符, 因此给answer 变量赋值时, 先进行3次函数调用, 
    2 - 3 * 4 = -10, 结果为 -10, answer 变量被赋值为 -10
    
    程序执行结果是 -10, 跟猜测相符
 */
#include <stdio.h>

/*函数定义在main()函数之前可以免去声明函数原型*/
int func(void)
{
    static int counter = 1;/*计数器初始化为1*/
    return ++counter;
}

int main(void)
{
    int answer;
    answer = func() - func() * func();
    printf("%d\n", answer);
}
