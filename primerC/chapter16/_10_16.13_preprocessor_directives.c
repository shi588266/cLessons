/**
 * #line指令重置_ _LINE_ _和_ _FILE_ _宏报告的行号和文件名
 * #line 1000// 把当前行号重置为1000
 * #line 10 "cool.c"// 把行号重置为10，把文件名重置为cool.c
 * #error 指令让预处理器发出一条错误消息，该消息包含指令中的文本。
 */
#include <stdio.h>

int main(void)
{
    #line 10086 "cool.c"
    printf("Now the line num is %d.\n", __LINE__);
    printf("Now the filename is %s.\n", __FILE__);
    
    #if __STDC_VERSION__ != 201112L
    /**
     * 由于使用了 #error 指令, 在预处理阶段发生错误, 所以上面的内容不会输出, 而是在编译期就报错
     * 如果编译时使用支持C11标准的编译器, 就可以编译成功
     */
    #error Not C11
    #endif
}

