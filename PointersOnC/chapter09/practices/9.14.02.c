/*
2.编写一个名叫my_strlen的函数。它类似于strlen函数，但它能够处理由于使用strn---函数而创建的未以NUL字节结尾的字符串。
需要向函数传递一个参数，它的值就是这样一个数组的长度，即这个数组保存了需要进行长度测试的字符串。
*/
#include <stdio.h>
#include <stddef.h>



size_t my_strlen(char *string, int size);

int main(void)
{
    
}

size_t my_strlen(char *string, int size)
{
    register int len;
    for (len = 0; len < size; len++) {
        //如果字符串以 NUL 字节结尾, 就统计到 NUL 字节
        if (*(string++) == '\0')
            break;
    }
    
    return len;
}