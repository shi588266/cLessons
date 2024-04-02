/**
 * 从文件或标准输入读取数字,计算算术平均值
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    double number;
    double total = 0.00;
    int count = 0;
    
    if (argc == 1) {
        // 如果没有输入使用标准输入
        fp = stdin;
    } else if( argc == 2 ) {
        // 从命令行读取输入
        puts("Enter a series of numbers,every number will be treated as float, '#' to quit.");
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Can't open file:%s.\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Wrong arguments,Usage:%s 'filename'.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(fp, "%lf", &number) == 1 && number != '#') {
        printf("Got number %lf.\n", number);
        total+= number;
        count++;
    }
    
    fclose(fp);
    //计算算数平均值
    printf("The average value of all the %d numbers is %f.\n", count, total/count);
    return 0;
}