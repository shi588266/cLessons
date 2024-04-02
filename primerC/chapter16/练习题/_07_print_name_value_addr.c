/**
 * 定义一个宏，以下面的格式打印名称、值和int类型变量的地址：
 *  name: fop; value: 23; address: ff464016
 */
#include <stdio.h>
#define PR_NAME_VAL_ADDR(X) printf("name: "#X"; value: %d; address: %x\n", X, &X)
#define PR_DATE() printf("%s\n", __DATE__)
//#define IS_SKIP 0
int main(void)
{
    //第7题
    int testInt = 10086;
    PR_NAME_VAL_ADDR(testInt);
    
    // 第8题
    #ifndef IS_SKIP
    {
        printf("This probaly will be skipped\n");
    }
    #endif
    
    //第9题
    #ifdef PR_DATE
    PR_DATE();
    #endif
}