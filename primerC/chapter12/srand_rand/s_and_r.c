/**
 * 包含 srand1() 和 rand()
 */
#include <stdio.h>

/**初始种子**/
static unsigned long int next = 1;     //具有内部链接文件作用域静态变量

int rand1(void) {
    // 伪随机数的公式
    next = next * 1103515245 + 12345;
    
    return (next / 65536) % 32768;
}

void srand1(unsigned int seed) {
    next = seed;
}