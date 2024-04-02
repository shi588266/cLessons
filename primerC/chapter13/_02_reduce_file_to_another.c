/**
 * 该程序同时打开了两个文件，以"r"模式打开一个，以"w"模式打开另一个。
 * 以保留每3个字符中的第1个字符的方式压缩第1个文件的内容。
 * 最后，把压缩后的文本存入第2个文件。
 * 第2个文件的名称是第1个文件名加上.red后缀(此处的red代表reduced) 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100
int main(int argc, char *argv[])
{
    unsigned long index = 0;    //用于记录读取到的位置
    int ch; //用于存储读取到每个字符
    char name[LEN];
    FILE *input, *output;   //输,入输出文件指针
    
    // 1.验证命令行输入参数
    if (argc < 2) {
        //练习 fprintf()
        fprintf(stderr,"Usage:%s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // 2.打开输入文件
    if ( (input = fopen(argv[1], "r")) == NULL ) {
        //练习 fprintf()
        printf("Open file %s failed\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    // 3.构造输出文件名
    printf("input filename is %s\n", argv[1]);
    //3.1 预留出5个字符的空间使之能够存放".red\0"
    strncpy(name, argv[1], LEN - 5);    // 如果 argv[1] 长度超过len-5, 拷贝不了结尾空字符
    name[LEN-5] = '\0';
    printf("output filename is %s\n", name);
    strcat(name, ".red");
    printf("output filename is %s\n", name);
    
    //4.打开输出,读取输入的内容写入到输出
    if ( (output = fopen(name, "w")) == NULL ) {
        //练习 fprintf()
        fprintf(stderr, "Open file %s failed\n", name);
        exit(EXIT_FAILURE);
    }
    
    // 读取内容,写入到输出指针
    while ( (ch = getc(input)) != EOF ) {
        //这里有个技巧:index++有两个效果:1.整体返回index,2.index的值自增1
        if (index++ % 3 == 0) {
            putc(ch, output);
        }
    }
    
    if(fclose(input) != 0 || fclose(output) != 0) {
        fprintf(stderr, "Error in closing files \n");
    }
    return 0;
}
