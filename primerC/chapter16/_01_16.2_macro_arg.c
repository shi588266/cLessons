//带参数的宏
#include <stdio.h>
#define SQUARE(X) X*X   //定义类函数宏
#define PRINTX(X) printf("The result is %d.\n", X)

int main(void)
{
    int x = 5;
    int z;
    printf("x = %d\n", x);
    /**
     * 1 先进行记号替换: z = X*X;
     * 2.使用变量x的值替换类函数宏的参数: z = 5*5;
     * 3 现在z=25, 继续执行下一个记号替换 printf("The result is %d.\n", X)
     * 4 使用z的值替换类函数宏的参数: printf("The result is %d.\n", 25)
     */
    z = SQUARE(x);
    printf("Evaluating SQUARE(x):");
    PRINTX(z);
    
    z = SQUARE(2);
    printf("Evaluating SQUARE(2):");
    PRINTX(z);
    
    /**
     * 1 SQUARE是宏标识符,先进行记号替换: PRINTX(X*X);
     * 2.使用x + 2替换类函数宏的参数: PRINTX(x + 2*x + 2);
     * 3 使用变量 x 的值替换类函数宏的参数: PRINTX(5 + 2*5 + 2);
     * 4 继续执行下一个记号替换 printf("The result is %d.\n", 5 + 2*5 + 2)
     */
    printf("Evaluating SQUARE(x+2):");
    PRINTX(SQUARE(x + 2));  //17
    
    /**
     * 1 SQUARE是宏标识符,先进行记号替换: PRINTX(100/X*X);
     * 2.使用2替换类函数宏的参数: PRINTX(100/2*2);
     * 3 继续执行下一个记号替换 printf("The result is %d.\n", 100/2*2)
     */
    printf("Evaluating 100/SQUARE(2):");
    PRINTX(100/SQUARE(2));  //100 这个例子表明, 类函数宏并不会像函数一样优先单独调用
    
    /**
     * 1 SQUARE是宏标识符,先进行记号替换: PRINTX(100/X*X);
     * 2.使用`++x`替换类函数宏的参数: PRINTX(++x*++x);
     * 3 继续执行下一个记号替换 printf("The result is %d.\n", ++x*++x)
     * 4. 根据优先级 由于标准并未对这类运算规定顺序，所以有些编译器得 7*6,
     * 有些编译器可能在乘法运算之前递增了x, 7*7=49
     * 
     * 解决这个问题最简单的方法是，避免用++x 作为宏参数。不要在宏中使用递增或递减运算符.
     */
    printf("x = %d\n", x);
    printf("Evaluating 100/SQUARE(++x):");
    PRINTX(SQUARE(++x));    // 49
    
    printf("After incrementing, x is %x.\n", x);
    return 0;
}