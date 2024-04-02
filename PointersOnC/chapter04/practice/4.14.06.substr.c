/**
6.编写一个函数，它从一个字符串中提取一个子字符串。函数的原型如下：
      int substr( char dst[], char src[], int start, int  len );
函数的任务是从src数组起始位置向后偏移start个字符的位置开始，最多复制len个非NUL字符到dst数组。
在复制完毕之后，dst数组必须以NUL字节结尾。函数的返回值是存储于dst数组中的字符串的长度.
如果start所指定的位置越过了src数组的尾部，或者start或len的值为负，那么复制到dst数组的是个空字符串
*/
#include <stdio.h>
#include <string.h>
#define MAX_LEN 128

int substr( char dst[], char src[], int start, int  len );

int main(void)
{
    char src[] = "hello world!";
    char dst[MAX_LEN];
    substr(dst, src, 0, 5);
    
    printf("dst = %s\n", dst);
}


int substr( char dst[], char src[], int start, int  len )
{
    int num;
    //先获取整个数组的地址, 再解引用获取整个数组
    int srcEleNum = strlen(src);
    /*如果start或len的值为负，那么复制到dst数组的是个空字符串*/
    if (start < 0 || len < 0) {
        dst[0] = '\0';
        return 0;
    }
    /*如果start所指定的位置越过了src数组的尾部，那么复制到dst数组的是个空字符串*/
    if (start >= srcEleNum) {
        dst[0] = '\0';
        return 0;
    }
    
    int i;
    for (i = 0; i < len; i++) {
        if (start+i >= srcEleNum) {
            dst[i] = '\0';
        } else {
            dst[i] = src[start+i];
        }
    }
    return i+1;
}