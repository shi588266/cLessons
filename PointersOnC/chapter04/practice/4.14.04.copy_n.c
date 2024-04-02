/*
4.编写函数copy_n，它的原型如下所示：

    void copy_n( char dst[], char src[], int n );

这个函数用于把一个字符串从数组src复制到数组dst，但有如下要求：必须正好复制n个字符到dst数组中，不能多，也不能少。如果src字符串的长度小于n，必须在复制后的字符串尾部补充足够的NUL字符，使它的长度正好为n。如果src的长度长于或等于n，那么在dst中存储了n个字符后便可停止。此时，数组dst将不是以NUL字符结尾。注意在调用copy_n时，它应该在dst[0]至dst[n-1]的空间中存储一些内容，但也只局限于那些位置，这与src的长度无关。如果你计划使用库函数strncpy来实现你的程序，祝贺你提前学到了这个知识。但这里目的是让你自己规划程序的逻辑，所以最好不要使用那些处理字符串的库函数。
*/

#include <stdio.h>
void copy_n( char dst[], char src[], int n );

int main(void)
{
    return 0;
}

void copy_n( char dst[], char src[], int n )
{
    int srcLen = sizeof(src) / sizeof(char);
    for (int i = 0; i < n; i++) {
        if (i < srcLen) {
            dst[i] = src[i];
        } else {
            dst[i] = '\0';
        }
    }
}