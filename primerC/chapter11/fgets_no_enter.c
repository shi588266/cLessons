/**
 * 基于 fgets
 * 读取整行输入并用 空字符 代替 换行符
 * 或者读取一部分输入并丢弃其余部分
 * 函数命名为 s_gets()
 */
#include <stdio.h>
#define MAXLEN 10
char * s_gets(char *str, int n);
int main(void)
{
    printf("Enter a piece of words\n");
    char string[MAXLEN];    //这里需要传递字符串数组, 不能传递指针, 因为不知到指针指向的地址和它的大小
    char * str_ptr; // 如果传递 str_ptr 会出现 segmentation fault
    char * ret = s_gets(string, MAXLEN);
    printf("The contents you input is: \n");
    puts(ret);
    return 0;
}

char * s_gets(char *str, int n)
{
    // 使用fgets 读取标准输入
    char * read_val;
    read_val = fgets(str, n, stdin); //fgets 返回结果是一个指针, 如果读取错误 返回 空指针 NULL
    if (read_val != NULL) {
        if ('\n' == input[0])
            input[0] = '\0';

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