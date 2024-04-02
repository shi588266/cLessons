/**
 * 二进制读写
 * 该程序把一系列文件中的内容附加在另一个文件的末尾,
 *  询问目标文件的名称并打开它
    使用一个循环询问源文件。
    以读模式依次打开每个源文件，并将其添加到目标文件的末尾
    
 * size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict fp)
 * 
 * size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE * restrict fp)
 * 
 * char *fgets(char *buf, int bufsize, FILE *stream);
 * 
 * int setvbuf(FILE *stream, char *buffer, int mode, size_t size)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
#define OUTPUT_BUF_SIZE 4096
#define INPUT_BUF_SIZE 1024

int append_cnt(FILE *dest_io, FILE *src_io);    //返回附加写入的字节数
char * s_gets(char *name, int n);

int main(void)
{
    char dest_name[MAXLEN]; //目标文件名
    char src_name[MAXLEN];  //源文件名
    int file_cnt,ch; //写入成功的文件数,每次读取到的字符
    unsigned long pos;  //标记文件位置
    FILE *dest_io;
    FILE *src_io;

    
    // 1.询问目标文件的名称并打开它
    puts("Enter the file to be appended, blank line to quit");
    if ( s_gets(dest_name, MAXLEN) && dest_name[0] != '\0') {
        // 1.1以附加模式打开目标文件
        if ( (dest_io = fopen(dest_name, "a+")) == NULL ) {    //打开失败返回 NULL
            printf("Open dest file %s failed\n", dest_name);
            exit(EXIT_FAILURE);
        }
        // 1.2设置输出缓冲 
        if (setvbuf(dest_io, NULL, _IOFBF, OUTPUT_BUF_SIZE) != 0) {
            puts("Setting output buffer failed");
            exit(-100);
        }
        // 2.使用一个循环询问源文件
        puts("Enter the source file, blank line to quit");
        while ( s_gets(src_name, MAXLEN) && src_name[0] != '\0' ) {
            // 2.1 如果该文件与目标文件相同, 则跳过该文件
            if (strcmp(dest_name, src_name) != 0) {
                // 2.2 以读取方式打开文件
                if ( (src_io = fopen(src_name, "r"))!=NULL ) {
                    //3.将其添加到目标文件的末尾
                    // 3.1 设置输入缓冲区
                    if (setvbuf(src_io, NULL, _IOFBF, INPUT_BUF_SIZE) == 0) {
                        // 3.2 读取文件到缓冲区
                        append_cnt(dest_io, src_io);
                        if (ferror(src_io)) 
                            printf("Error in reading file %s.\n", src_name);
                        if (ferror(dest_io))
                            printf("Error in writing file %s.\n", dest_name);
                        fclose(src_io);
                        file_cnt++;
                        printf("source file %s was appended to %s\n", src_name, dest_name);
                    } else {
                        puts("Setting input buffer failed, continuing...");
                    }
                } else {
                    printf("Open source file %s failed, continuing...\n", src_name);
                }
            }
            puts("Enter another source file, blank line to quit");
        }
        
        //附加写完成  
        printf("Done appending. %d files appended.\n", file_cnt);
        
        //重置目标文件, 输出所有新的内容
        rewind(dest_io);
        puts("New contents is:");
        while (  (ch = getc(dest_io)) != EOF ) {
            putc(ch, stdout);
        }
        
        fclose(dest_io);
        return 0;
    }
}

char * s_gets(char *name, int n) {
    // fgets()会读取换行
    char *res = fgets(name, n, stdin);
//printf("filename is  %s\n", res);
    //找出换行符替换为空字符
    char *pos;
    if ( (pos = strchr(res, '\n'))!=NULL ) {
        *pos = '\0';
    } else {
        //丢弃本次多余的输入
        while (getchar() != '\n')
            continue;
    }
    return res;
}

int append_cnt(FILE *dest_io, FILE *src_io){
    size_t bytes;   //记录读取的字节数, 作为写入大小的依据
    static char temp[INPUT_BUF_SIZE];   //用于分配临时存储空间, 且只分配一次
    // 读取文件内容到缓冲区
    while ( (bytes = fread(temp, sizeof(char), MAXLEN, src_io)) > 0) {
        fwrite(temp, sizeof(char), bytes, dest_io);
    }
}