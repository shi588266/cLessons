/**
 * int strcmp(char *str1, char *str2);
 * strcmp 比较两个字符串, 逐字符地进行比较
 * 返回值
 *      如果两个字符串相等, 返回0
 *      如果字母表中第一个字符串再第二个字符串前面, 返回 负数
 *      如果字母表中第一个字符串再第二个字符串后面, 返回 正数
 */
#include <stdio.h>
#include <string.h>     //strcmp 函数原型 的头文件
#define SIZE 80
#define ANSWER "dumu"

char *s_gets(char *str, int n);

int main(void)
{
    char tryy[SIZE];
    puts("who is called the poem of gohst?");
   
    s_gets(tryy, SIZE);
    while (strcmp(tryy, ANSWER)) {
        puts("It seems you get the wrong answer, try again");
        s_gets(tryy, SIZE);
    }
    puts("That's right");
    return 0;
}

char * s_gets(char *str, int n)
{
    // 使用fgets 读取标准输入
    char * read_val;
    read_val = fgets(str, n, stdin); //fgets 返回结果是一个指针, 如果读取错误 返回 空指针 NULL
    if (read_val != NULL) {
        int i = 0;
        //对读取到的内容做循环处理, 直到读到空字符 或 换行符
        while (str[i] != '\0' && str[i] != '\n') {
            i++;
            // 如果先读到 换行符, 说明 str 字符串数组的容量足够容纳输入的字符, fgets 把最后输入的换行符也读入到了字符串中
            if ('\n' == str[i]) {  
                str[i] = '\0';  //只需要把换行符替换成空字符
            } else if('\0' == str[i]) {
                // 如果先读到 空字符, 说明 输入的字符的个数超过字符串数组的容量
                // 多余的输入内容仍存留在缓冲区, 所以需要清理掉缓冲区里的内容
                while (getchar() != '\n') {
                    continue;
                }
            }
        }
        return read_val;    // 或者也可以返回 str
    }
}