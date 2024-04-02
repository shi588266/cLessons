#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

/**
 * gbk编码下汉字是双字节
 * utf8编码下汉字是3字节
 */
int main(int argc, char const *argv[])
{
    FILE *fp;   //定义文件指针
    char filePath[100] = "./gbk.txt";
    fp = fopen(filePath, "r");  //读的方式打开文件指针
    if ( fp == NULL ) {
        perror("打开文件失败");
        return 1;
    }
    /**
     * 因为 fgetc() 的返回值是int类型, 
     * 如果使用char ascil范围内的字符没有问题, 
     * 超过2个字节的字符就有问题,使用4个字节的int可以表示双字节
     */
    int ich;
    int alphaNum = 0;  //字母字符的数量
    int digitalNum = 0;  //数字字符的数量
    int doubleByteNum = 0;  //双字节字符的数量
    while( (ich = fgetc(fp)) != EOF) {
        if ( (ich >= 'A' && ich <= 'Z') || (ich >= 'a' && ich <= 'z')) {
            alphaNum++;
        }
        else if (ich >= '0' && ich <= '9') {
            digitalNum++;
        } else if ( ich > 128) {
            // 双字节读取两个
            int sch = fgetc(fp);
            printf("%c%c\n", ich, sch); //两个字符连接起来可以正常输出为双字节字符
            
            /**
             * 3个字符连接起来可以正常输出为双字节字符, 
             * 但是控制台终端编码为GBK, 所以3字节字符无法正确显示
             */
            /*int tch = fgetc(fp);
            printf("%c%c%c\n", ich, sch, tch); */
            doubleByteNum++;
        }
    }
    printf("字母字符的数量%d, 数字字符的数量%d, 双字节字符的数量%d, \n", alphaNum, digitalNum, doubleByteNum);
    return 0;
}


