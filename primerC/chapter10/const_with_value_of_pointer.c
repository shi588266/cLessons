/**
 * 指针常量
 * 首先, const距离ptr_cst比较近, 使用const修饰ptr_cst, 表明ptr_cst是一个常量
 * 其次, int * 表明 ptr_cst 的值是一个指向int类型值的指针, 也就是它的值是一个地址(有地址,也有类型)
 */
#include <stdio.h>
int main(void)
{
    int intval = 10086;
    /**
     * 声明指针常量并初始化, 注意: 初始化完全是编译器的行为，赋值则是运行时的行为
     * 指针常量如果不初始化, 将没有意义, 因为不能再运行时使用另一个对象对其赋值
     */
    int * const ptr_cst = &intval;
    //ptr_cst = &intval;  // 操作不合法:常量不可被赋值
    int intval2 = 10010;
    //ptr_cst = &intval2;   // 操作不合法, ptr_cst 是常量, 它的值不可改变, 不能再指向另一个地址
    *ptr_cst = 200;     //虽然常量的值不能改变, 但是指针常量指向的值却可以改变(这将导致intval的值也变为200)
    printf("\nptr_cst is %p, *ptr_cst=%d", ptr_cst, *ptr_cst);
    printf("\n&intval is %p, intval=%d\n", &intval, intval);
}
































