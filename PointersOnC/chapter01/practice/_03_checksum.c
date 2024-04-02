/**
3.写一个程序，从标准输入读取一些字符，并把它们写到标准输出中。
它同时应该计算checksum（校验和）值，并写在字符的后面。
checksum用一个singed char类型的变量进行计算，它初始为-1。
当每个字符从标准输入读取时，它的值就被加到checksum中。
如果checksum变量产出了溢出，这些溢出就会被忽略。
当所有的字符均被写入后，程序以十进制整数的形式打印出checksum的值，它有可能是负值。注意，在checksum后面要添加一个换行

在使用ASCII码的计算机中，在包含“Hello world!”这几个词并以换行符结尾的文件上运行这个程序应该产生下列输出：
    hello world!
    102
*/
#include <stdio.h>

int main(void)
{
    signed char checksum = -1;
    int ch;
    /*换行符会被正常读取, ctrl+d 按ctrl+d可以让getchar读取到EOF结束读取, windows下请使用 ctrl+z */
    while ( (ch = getchar()) != EOF ) {
        checksum += ch;
        putchar(ch);
    }
    printf("%d\n", checksum);
    
    return 0;
}