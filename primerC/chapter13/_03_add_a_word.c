/**
 * 追加一个单词
 * 使用 fscanf()读入输入字符串, 使用fprintf()输出到文件
 * 第一个参数是文件指针
*/
#include <stdio.h>
#include <stdlib.h> //fprintf(),fscanf(),rewind()
#include <string.h>

#define MAXLEN 40
int main(void)
{
    FILE *fp;
    // 1.打开文件, a+表示追加读写
    if ( (fp = fopen("wordy", "a+")) == NULL ) {
        fprintf(stdout, "Can not open file \"wordy\"\n");
        exit(EXIT_FAILURE);
    }
    // 2.读取键盘输入
    char inputword[MAXLEN];
    fprintf(stdout, "Enter words to add the file;Press #");
    fprintf(stdout, "key at the beginning to terminate.\n");
    
    /// 3.接收输入追加写入文件末尾
    while ( (fscanf(stdin, "%40s", inputword) == 1) && inputword[0] != '#' ) {
        fprintf(fp, "%s\n", inputword);
    }
    
    // 4.读取文件内容并输出
    rewind(fp); //重置文件指针位置
    puts("File contents:");
    char outputword[MAXLEN];
    while ( fscanf(fp, "%s", outputword) == 1 ) {
        puts(outputword);
    }
    puts("DONE!");
    fclose(fp);
    return 0;
}