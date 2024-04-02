/**
 * 5.编写一个程序，提示用户输入以兆位每秒 (Mb/s)为单位的下载速度和以兆字节(MB) 为单位的文件大小。
 * 程序中应计算文件的下载时间。注意，这里1字节等于8位。使用float类型，并用/作为除号。
 * 该程序要以下面的格式打印 3 个变量的值 (下载速度、文件大小和下载时间)，显示小数点后面两位
 */
#include <stdio.h>

int main(void)
{
    float brandWidth,fileSize,downloadTime;
    printf("Enter the the number of the brand width of your house(Mb/s)\n");
    printf("And the the filesize that you want to download(MB).\n");
    printf("Remember to use a comma as the saperation.\n");
    if (2== scanf("%f,%f", &brandWidth, &fileSize)) {
        downloadTime = fileSize * 8.0 / brandWidth;
        printf("At %.2f megabits per second, a file of %.2f megabytes downloads in %.2f seconds.\n\n", 
        brandWidth,
        fileSize,
        downloadTime
        );
    }
}