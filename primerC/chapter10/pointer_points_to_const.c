/**
 * 常量指针 const int *cst_ptr
 * 首先, int *距离 cst_ptr 比较近, 表明cst_ptr是一个指针
 * 其次, const 整体修饰后面的内容, 表明 cst_ptr 指向的内容是一个常量
 */
 #include <stdio.h>
int main(void)
{
    int intval = 10010, intval2 = 10086;
    /**
     * 声明常量指针并初始化, 注意: 初始化完全是编译器的行为，赋值则是运行时的行为
     * 常量指针如果不初始化, 将没有意义, 因为不能再运行时使用另一个对象对其赋值
     */
    const int *cst_ptr = &intval;
    cst_ptr = &intval2;     //可以重新指向其他地址
    printf("\ncst_ptr is %p, *cst_ptr=%d", cst_ptr, *cst_ptr);
    printf("\n&intval is %p, intval=%d\n", &intval, intval);    //intval的地址和内容不受影响
    
    //*cst_ptr = 100;     //常量指针指向的内容是常量, 不能通过指针修改它指向的内容
}