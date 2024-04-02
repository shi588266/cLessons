
[TOC]

## 文件操作  
### 二进制与文本的区别  
文本文件内容就是ASCII码组成的, 如果把二进制文件以文本分方式显示, 就会显示二进制对应的ASCII码, 所以可能会显示乱码  
#### windows平台
```c
#include<stdio.h>
#include<stdlib.h>

void read(char *file_path){
    FILE *pfile = fopen(file_path, "rb"); //以二进制方式读取内容原封不动
    char ch;
    fread(&ch, 1, 1, pfile); //读取文件内容,每次读取1个元素,读一次, 并把内容赋值给ch
    while ( !feof(pfile) )  //没有到文件末尾就一直读取
    {
        printf("%d\n", ch);     //打印字符的ascii码
        fread(&ch, 1, 1, pfile);
    }
    fclose(pfile);
}

void main(int argc, char const *argv[])
{
    char buffer[5] = {10,10,10,10,10};// 初始化字符数组
    FILE *pfile_ascii ;// 定义文本文件指针
    FILE *pfile_bin ;// 定义二进制文件指针

    char path_ascii[15] = "E:\\ascii.c"
    pfile_ascii = fopen(path_ascii, "w");   //按照文本写入的方式打开文件
    if (pfile_ascii == NULL)
    {
        printf("%s\n", "文本文件打开失败");
    } else {
        // 把数组写入到文本文件
        fwrite(buffer, 1, 5, pfile_ascii);  // 把buffer中的元素写入到文本文件指针,每次写1个字符, 写5次
        fclose(pfile_ascii);    // 关闭文件指针
    }
    printf("%s\n", "开始读取文本文件内容");
    read(path_ascii);


    char path_bin[15] = "E:\\binary.c";
    pfile_bin = fopen(path_bin, "wb");   //按照二进制写入的方式打开文件
    if (pfile_bin == NULL)
    {
        printf("%s\n", "二进制文件打开失败");
    } else {
        // 把buffer中的元素写入到文件指针,每次写1个字符, 写5次
        fwrite(buffer, 1, 5, pfile_bin);  
        fclose(pfile_bin);    // 关闭文件指针
    }
    printf("%s\n", "开始读取二进制文件内容");
    read(path_bin);
}
```
> 在windows 下, 文本文件写入时会把换行符(ASCII码10,\n),转换为"\r\n",对应的ASCII码13,10;  
> 二进制文件原样输入输出  
> Linux下文本文件与二进制读写无差别  

### 缓冲区
为了避免频繁地对磁盘操作, 对文件的操作一般都在文件缓冲区进行, 只有在执行fclose的时候才会把缓冲区内容写入到磁盘,
可以使用fflush手动把缓冲区内容写入到磁盘  
#### int fflush( FILE *stream );
```c
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char const *argv[])
{
    char path[25] = "D:\\test.txt";
    FILE *pf;
    pf = fopen(path, "w+");   //w模式,如果文件不存在则会创建之
    if (pf == NULL)
    {
        printf("文件打开失败\n");
    } else {
        printf("文件打开成功\n");
        //写入内容 (注意写入内容不会立即生效, 只是写入到了缓冲区, 在程序运行结束后,才把缓冲区的内容写入到输出流)
        fputs("something no important\n", pf); 
        //使用fflush()立即把缓冲区内容写入到文件流
        fflush(pf);
        Sleep(10000);
        fputs("something no important again\n", pf); 
        fclose(pf);//关闭文件
    }
}
```
> 对文件的操作一般都在文件缓冲区进行,  
> 只有在执行fclose()的时候才会把缓冲区内容写入到磁盘,   
> 可以使用fflush()手动把缓冲区内容写入到磁盘  

### 以块的方式读写文件  
#### int fread(void *buffer, size_t size, size_t count, FILE *stream)  
从stream中读取count个大小为size的 **内存对象**,并按顺序存储结果到转译为 unsigned char 数组的 buffer 中的相继位置, 文件流的指针位置随着读取的字符数前进  

- buffer - 指向用来存储读到数据的数组的首地址  
- size - 每个对象的字节大小  
- count - 要读取的对象数  
- stream - 读取来源的输入文件流  
```c
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char const *argv[])
{
    char * path = "D:\\test.txt";
    FILE *pf = fopen(path, "rb");   //r模式,如果文件不存在则出错, b 二进制方式读取
    if (pf == NULL)
    {
        printf("文件打开失败\n");
    } else {
        printf("文件打开成功\n");
        //int 占4字节,每次写入相当于连续调用4次fputc()
        char buffer[100];
        size_t r_num = fread(buffer, sizeof(*buffer), 100, pf);    // 返回读取到的对象个数
        if (r_num == 100)
        {
            printf("读取%u个对象\n", r_num);
            puts("内容为:\n");
            for (int i = 0; i < 100; ++i)
            {
                printf("%c\n", buffer[i]);
            }   
        } else {
            if (feof(pf)) {
                printf("Unexpected end of file\n");
            }
            if (ferror(pf)) {
                perror("reading Error");
            }
        }
        
        fclose(pf);
    }
}
```

#### size_t fwrite(const void *buffer,size_t size,size_t count,FILE *stream)
把buffer数组中count个大小为size的对象写入到文件流中,文件流的指针位置随着读取的字符数前进  

- buffer - 指向数组中要被写入的首个对象的指针 
- size - 每个对象的大小 
- count - 要被写入的对象数 
- stream - 指向输出流的指针 
```c
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char const *argv[])
{
    char buffer[100];
    for (int i = 0; i < 100; ++i)
    {
        buffer[i] = i;
    }
    char path[25] = "D:\\test.txt";
    FILE *pf;
    pf = fopen(path, "w+");   //w模式,如果文件不存在则会创建之
    if (pf == NULL)
    {
        printf("文件打开失败\n");
    } else {
        printf("文件打开成功\n");
        //int 占4字节,每次写入相当于连续调用4次fputc()
        int w_num = fwrite(buffer, sizeof(int), sizeof(buffer), pf);
        printf("写入%d个对象\n", w_num);
    }
}
```

### 文件型结构体
C关键字FILE本质就是文件类型结构体, 其定义在 stdio.h 头文件中
```c
#ifndef _FILE_DEFINED
struct _iobuf
{
    char    *_ptr;  //当前缓冲区内容指针
    int     _cnt;   //缓冲区还有多少个字符
    char    *_base; //缓冲区的起始地址
    int     _flag;  //文件流的状态, 是否错误或结束
    int     _file;  //文件描述符
    int     _charbuf;//双字节缓冲,缓冲2个字节
    int     _bufsiz;    //缓冲区大小
    char    *_tmpfname; //临时文件名
};
typedef _iobuf FILE;
#define _FILE_DEFINED
```
> 标准输入文件指针stdin(键盘)   
> 标准输出文件指针stdout(显示器)   
> 标准错误输出文件指针stderr(显示器)也遵循这个结构体  
> scanf 是 fscanf 的一个特例, scanf 只能读取 stdin (通常是键盘)  
> printf 是 fprintf 的一个特例, printf 只能输出到stdout(通常是显示器)  
> putchar 是 fputc 的一个特例, putchar 只能输出单个字符到stdout(通常是显示器)  
> puts 是 fputs 的一个特例, puts 只能输出到stdout(通常是显示器)  
> gets 是 fgets 的一个特例, gets 只能从stdin读取(通常是键盘)  
> 遇到错误,可以把错误信息写入 stderr , 会自动显示到显示器  

#### int ferror(FILE *fp)  
检测文件指针是否出错, 如果错误返回非零  

#### void perror(const char *tip_msg)  
获取并显示文件错误信息  
```c
#include<stdio.h>
#include<stdlib.h>
void main()
{
    char path[100] = "D:\\A001_project\\study\\csapp\\C语言-尹成\\进阶\\2-格式化读写文件\\out.txt"; //This file is read only
    FILE *pf = fopen(path, "w");
    if(pf == NULL) {
        printf("打开文件失败\n");
        perror("错误信息");         //错误信息: Permission denied
        return;
    } else {
        fputs("hehe", pf);
    }

    fclose(pf);                     //关闭文件指针
}
```

#### void clearerr(FILE *file)  
清除文件流的状态  
```c
#include<stdio.h>
#include<stdlib.h>
void main()
{
    char path[100] = "D:\\A001_project\\study\\csapp\\C语言-尹成\\进阶\\2-格式化读写文件\\out.txt";
    FILE *pf = fopen(path, "w");
    if(pf == NULL) {
        printf("打开文件失败\n");
        perror("错误信息");
        return;
    } else {
        fputs("hehe", pf);
        rewind(pf);                         //重置文件指针
        char ch = fgetc(pf);                //以w模式打开文件, 不允许读取, 读取会返回-1
        printf("读取到的字符%d", ch);
        if (ch == EOF) {
            if (ferror(pf)) {
                perror("错误信息");         //错误信息: No error
                clearerr(pf);               //重置文件流的状态
            }

            if (feof(pf)) {
                printf("读取到文件末尾");
            }
        }
    }

    fclose(pf);
}
```

#### int fseek(FILE *fp, long offset, int startPos)  
调整文件指针的位置相对于startPos的位置, 偏移offset, startPos有三种取值方式:

- SEEK_SET = 0  表示文件开头  
- SEEK_end = 2  表示文件末尾  
- SEEK_CUR = 1  表示文件当前位置  

##### 文本文件  
```c
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char const *argv[])
{
    char * path = "D:\\test.txt";
    FILE *fp = fopen(path, "rb");   //r模式,如果文件不存在则出错, b 二进制方式读取
    if (fp == NULL) {
        printf("文件打开失败\n");
        perror("Open file error");
    } else {
        printf("文件打开成功\n");
        fseek(fp, 0, SEEK_END);     //文件指针直接移动到文件末尾
        long length = ftell(fp);    //指针来到文件末尾, 获取文件末尾到文件开头的字节数
        printf("文件大小%d字节\n", length);
    }
    fclose(fp);
}
```
##### 二进制文件  
```c
void main(int argc, char const *argv[])
{
    char * path = "D:\\test.bin";
    FILE *fp = fopen(path, "wb+");   //w模式,如果文件不存在则创建, b 二进制方式读取
    if (fp == NULL) {
        printf("文件打开失败\n");
        perror("Open file error");
    } else {
        double data[10] = {0.14,1.1,2.50,3.14,4.444,5.51,6.66,7.7,8.888,9.9};
        fprintf(stdout, "数组长度%d\n", sizeof(data)/sizeof(double));
        /**写入二进制数据*/
        {
            //第一个参数是写入数据首个对象的指针
            fwrite(&data, sizeof(double), sizeof(data)/sizeof(double), fp);
        }

        /**修改某个数据*/
        {
            // 依次读取出每个对象
            rewind(fp);
            double db;
            for (int i = 0; i < sizeof(data)/sizeof(double); ++i) {
                size_t read = fread(&db, sizeof(double), 1, fp);  //每次读取一次,文件指针向下移动一位
                if (read != 1) {
                    if (feof(fp)) {
                        printf("%s\n", "Error reading: unexpected end of file");
                    } else if (ferror(fp)) {
                        perror("Error reading ");
                    }
                }
                // 找到某个元素并替换之
                if (3.14 == db) {
                    fseek(fp, -8, SEEK_CUR);    //文件指针已经移动到下一位
                    double replace = 3.1415;
                    fwrite(&replace, sizeof(double), 1, fp);
                    break;
                }
            }
        }
        /**输出二进制数据*/
        {
            rewind(fp);
            double db;
            for (int i = 0; i < sizeof(data)/sizeof(double); ++i) {
                fread(&db, sizeof(double), 1, fp);  //每次读取文件指针向下移动
                printf("%f\n", db);
            }
        }
    }
    fclose(fp);
}
```
#### long ftell(FILE *fp)  
返回文件当前指针位置到文件开头的 **字节数**  
```c
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char const *argv[])
{
    char * path = "D:\\test.txt";
    FILE *fp = fopen(path, "rb");   //r模式,如果文件不存在则出错, b 二进制方式读取
    if (fp == NULL) {
        printf("文件打开失败\n");
        perror("Open file error");
    } else {
        printf("文件打开成功\n");
        do{
            char st[100];
            fgets(st, 100, fp);
        } while(!feof(fp));
        long length = ftell(fp);    //读取结束时,指针来到文件末尾
        if (length == -1) {
            printf("读取失败\n");
            return;
        }
        printf("文件大小%d字节\n", length);
    }
    fclose(fp);
}
```

#### int remove(const char *filename)  
删除文件

- 删除成功返回值为0  
- 删除失败返回值为-1  

#### char * mktemp(const char *path_tpl)
根据传入的模板, 生成唯一的临时文件/目录名  
```c
#include<stdio.h>
#include<stdlib.h>
#include<io.h>  // mktemp函数所在头文件

int main(int argc, char const *argv[])
{
    char path_tpl[100] = "C:\\XXXXXX";
    char *newName = mktemp(path_tpl);
    printf("%s, %s", newName, path_tpl);
    // 写入到格式化字符串
    char cmd[50] = {0};
    sprintf(cmd, "md %s", path_tpl);
    system(cmd);    //调用系统指令
    return 0;
}
```

#### FILE * tmpfile()  
创建临时文件返回文件指针,关闭文件指针或者程序运行结束, 临时文件会被删除  

#### char * mkstmp(const char *path_tpl)
根据传入的模板, 生成唯一的临时文件/目录名, 注意只是生成临时文件名,并不会创建文件/目录  
```c
#include<stdio.h>
#include<stdlib.h>    //Linux 系统 mktemp 在 stdlib.h
#include<io.h>        //windows系统 mktemp 在 io.h
void main(int argc, char const *argv[])
{
    char temp[] = "E:\\XXXXXX";         //必须是数组的形式,必须以XXXXXX结尾
    char *path_name = mktemp(temp);   //位于 <io.h>
    printf("生成临时目录名:%s\n", path_name);

    // 创建目录
    char cmd[10] = {};
    sprintf(cmd, "md %s", path_name);   //初始化 创建命令 字符串
    printf("创建目录命令:%s\n", cmd);
    system(cmd);
}
```


### windows键盘无缓冲模式分析  
