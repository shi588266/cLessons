/**
 * 统计输入文件的字符个数
 * 使用标准I/O 函数
 * getc()
 * putc()
 */
#include <stdio.h>
#include <stdlib.h> //exit()的原型 EXIT_FAILUER宏
int main(int argc, char *argv[])
{
    /**
     * 使用int 存储读取到的字符, 使用int除了可以正常存储ascll编码字符,还能存储Unicode字符,如汉字
     * 正常情况下 getc() 和 fgetc() 会以 unsigned char类型从输入流中读取字符, 读取成功后扩张为 int 类型,
     * 因为 EOF 这个宏的值被定义为 -1, 4字节int表示为:0xFFFFFFFF,
     * 使用char 和 unsigned char 存储字符会对文件结尾的判断会受影响
     * 如果把 ch 定义为char类型, 当读取到空格符(blank),返回 0xFF,它与EOF比较也就是:ch转化为:0xFFFFFFFF,
     * 
     * 如果把 ch 定义为unsigned char类型,假设getc(fp)读取到-1,也就是0xFFFFFFFF, 
     * 语句“ch=fgetc(fp)”对其强制转换 unsigned char是:0xFF,执行子语句“ch!=EOF”时ch 被转换成 0x000000FF,
     * 永远也不可能等于 0xFFFFFFFF, 因此表达式“ch!=EOF”将永远成立, 循环不会结束
     */
    int ch;
    unsigned long int count = 0;
    FILE *fp;
    
    if ( argc < 2 ) {
        printf("Usage:%s filename\n.", argv[0]);
        exit(EXIT_FAILURE );
    }
    
    if ( (fp = fopen(argv[1], "rb+")) == NULL ) {
        printf("open %s failed\n", argv[1]);
        exit(EXIT_FAILURE );
    }
    
    // 读取每个字符,没读取一个字符计数一次
    while ( (ch = getc(fp)) != EOF ) {
        putc(ch, stdout);
        count++;
    }
    fclose(fp); //!important程序结束前请及时关闭打开的文件
    printf("%s has %lu characters\n", argv[1], count);
    return 0;
}