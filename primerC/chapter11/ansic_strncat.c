/**
 * char * strncat(char *str1, const char *str2, size_t n);
 * strncat 第三个参数表示的是限制拼接到第一个字符串的字符个数
 */
#include <stdio.h>
#include <string.h>     //strcat 函数原型 的头文件
#define MAXLEN 80
#define BUGSIZE 15

char * s_gets(char *str, int n);

int main(void)
{
    char flower[MAXLEN];
    char bug[BUGSIZE];
    char addon[] = "s smell like old shoes.";
    puts("what's your favorite flower?");
   
    if(s_gets(flower, MAXLEN) != NULL) {
        // 拼接后的数组长度小于数组容量 可以正常拼接
        if (strlen(flower) + strlen(addon) + 1 < MAXLEN) 
            strcat(flower, addon);
        puts(flower);
    } else
        puts("End of file encountered!!");
    
    if(s_gets(bug, BUGSIZE) != NULL) {
        // 计算出可拼接字符数
        int available = MAXLEN - strlen(bug) - strlen(addon) - 1;
        strncat(bug, addon, available);
        puts(bug);
    } else
        puts("End of file encountered!!");
        
    puts("bye");
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