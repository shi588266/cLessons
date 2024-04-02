/*
5.编写一个程序，从标准输入一行一行地读取文本，并完成如下任务：如果文件中有两行或更多行相邻的文本内容相同，那么就打印出其中一行，其余的行不打印。可以假设文件中的文本行在长度上不会超过128字符（127字符加上用于终结文本行的换行符）。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 128

int main(void)
{
    char input[MAX_LEN];
    char output[MAX_LEN];
    char *(outputArray[100]) = {NULL};/*指针数组,用于存放读取到的重复的行*/
    int duplicateStoreFlag = 0;/*相邻的重复行是否已经存储*/
    int outputIndex = 0;
    
    while (fgets(input, MAX_LEN, stdin) != NULL) {//fgets()会读取换行符
        if (strcmp(input, output) == 0) {
            if (!duplicateStoreFlag) {
                duplicateStoreFlag = 1;
                //outputArray[outputIndex++] = output;/*C语言不能直接对数组赋值*/
                //数组指针每个元素未初始化需要手动分配空间
                outputArray[outputIndex] = (char*)malloc(MAX_LEN * sizeof(char));
                strcpy(outputArray[outputIndex++], output);
            }
        } else {
            /*如果输入输出不相等, 用新的输入内容替换输出内容*/
            duplicateStoreFlag = 0;
            strcpy(output, input);
        }
    }
    
    puts("duplicate line:");
    for (int i = 0; i < outputIndex; i++) {
        puts(outputArray[i]);
    }
}