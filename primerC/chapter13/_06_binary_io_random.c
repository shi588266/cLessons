/**
 * 使用二进制io进行随机访问
 * 这里的"随机"是指基于索引随机读取某块字节内存
 * 构造一个100个元素的浮点数数组,然后把数组内容以二进制的形式存储到文件中,
 * 以二进制读模式打开文件, 随机读取某个字节
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 1000
#define MAXLEN 100

int main(void)
{
    double arr_db[ARRAY_SIZE];
    const char *file = "_06_number.dat";
    FILE *fp;
    int i;
    long index,pos;
    double number;
    
    // 1.构造数组
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr_db[i] = 100.0 * i + 1.0/(i+1);
    }
    
    // 2.以二进制模式打开文件指针
    fp = fopen(file, "wb");
    if( fp == NULL ) {
        printf("Open file %s failed\n", file);
        exit(EXIT_FAILURE);
    }
    // 3.把数组内容写入到文件
    fwrite(arr_db, sizeof(double), ARRAY_SIZE, fp);
    fclose(fp);
    
    //文件内容发生改变, 需要重新打开文件
    fp = fopen(file, "rb");
    if( fp == NULL ) {
        printf("Open file %s failed\n", file);
        exit(EXIT_FAILURE);
    }
    // 4. 获取用户输入的索引
    printf("Enter the index of the file, valid range is 0 ~ %d.\n", ARRAY_SIZE - 1);
    //使用指针存储读取
    while ( scanf("%d", &index) == 1 && index >= 0 && index < ARRAY_SIZE ) {
        // 计算偏移的字节数
        pos = (unsigned long)index * sizeof(double);
        fseek(fp, pos, SEEK_SET);
        fread(&number, sizeof(double), 1, fp); //在文件当前位置读取一个double占用的字节数据
        printf("Number of index %d position is %f.\n", index, number);
        printf("Enter the next index of the file, valid range is 0 ~ %d.\n", ARRAY_SIZE - 1);
    }
    
    fclose(fp);
    puts("Bye.");
    return 0;
}