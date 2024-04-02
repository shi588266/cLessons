/**
 * char * strcpy(char *str1, char *str2);
 * strcpy 把字符串2的内容拷贝到字符串1
 *      字符串1 应该是指向数据对象的指针(数组), 并且该数据对象应该有足够的空间存储源字符串2的副本
 *      返回第一个参数的值, 即第一个字符的地址
 * 注意: 第一个参数不一定指向数组的开始
 * 
 * 声明数组将分配储存数据的空间, 儿声明指针只分配储存一个地址的空间
 */
#include <stdio.h>
#include <string.h>     //strcpy 函数原型 的头文件
#define SIZE 80
#define LIMIT 6

char *s_gets(char *str, int n);

int main(void)
{
    // 声明指向数组的指针
    char *(words_begin_wt_q_ptr_2_arr[SIZE]);

    char words_begin_wt_q[LIMIT][SIZE];
    char temp[SIZE];
    printf("Enter %d words begin with q\n", LIMIT);
    
    int i = 0;
    while (i < LIMIT && s_gets(temp, SIZE)) {
        if (temp[0] != 'q') {
            printf("%s is not beigin with q\n", temp);
        } else {
            strcpy(words_begin_wt_q[i], temp);
            /**
             * 指针指向另一个指针的地址, 并没有拷贝字符串,
             * 这会导致所有的单词都被替换为最后一次输入的字符串
             */
            words_begin_wt_q_ptr_2_arr[i] = temp;
            
            words_begin_wt_q_arr_of_ptr + i = temp;
            i++;
        }
    }
    
    
    // 打印
    puts("Here are accepted words stores in array:");
    for (int n = 0; n < LIMIT; n++){
        puts(words_begin_wt_q[n]);
    }
    
    puts("Here are accepted words stores in ptr of array:");
    for (int m = 0; m < LIMIT; m++){
        puts(words_begin_wt_q_ptr_2_arr[m]);
    }
    
    puts("Here are accepted words stores in array of ptr:");
    for (int l = 0; l < LIMIT; l++){
        puts(words_begin_wt_q_arr_of_ptr[l]);
    }
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