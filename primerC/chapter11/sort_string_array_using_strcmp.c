/**
 * 用字符串数组存储用户输入
 * 并自定义字符串排序函数 使用 strcmp 对字符串数组进行排序
 */

#include <stdio.h>
#define MAXLIMIT 100
#define CNT 5

char * s_gets(char *input, size_t size);
void str_arr_sort(char *ptr_arr[], int count);  //参数传递指针数组
int main(void)
{
    char store_str_arr[CNT][MAXLIMIT]; //用于存储输入得字符串数组
    char input[MAXLIMIT];
    char *ptr_arr[CNT];   // 指针数组
    printf("Enter up to %d lines, and I will sort them \n", CNT);
    puts("To stop , press Enter at a lines start");
    //获取用户合法输入, 存储到字符串数组
    int i = 0;
    while (i < CNT && s_gets(store_str_arr[i], MAXLIMIT) && store_str_arr[i][0] != '\0') {
        ptr_arr[i] = store_str_arr[i];
        i++;
    }
    // 字符串排序
    str_arr_sort(ptr_arr, CNT);
    puts("Here is the sorted list:");
    int k;
    for (k = 0; k < CNT; k++) {
        puts(ptr_arr[k]);
    }
    return 0;
}
// 获取安全输入
char * s_gets(char *str, size_t n)
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

void str_arr_sort(char *ptr_arr[], int count) {
    // 双重循环排序, 类似冒泡
    int top, seek;
    char *temp;
    //最后一个字符串不必再比较
    for (top = 0; top < count - 1; top++) {
        // 比较未排序的第一个字符串 及其下一个字符串, 不相等则交换, 然后未排序的第一个字符串与下一个比较
        for (seek = top + 1; seek < count; seek++) {
            if (strncmp(ptr_arr[top], ptr_arr[seek], MAXLIMIT) > 1) {
                temp = ptr_arr[top];
                ptr_arr[top] = ptr_arr[seek];
                ptr_arr[seek] = temp;
            }
        }
    }
}