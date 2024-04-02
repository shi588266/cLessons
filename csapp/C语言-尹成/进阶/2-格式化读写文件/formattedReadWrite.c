#include<stdio.h>

/**
 * 格式化输入输出
 * scanf 是 fscanf 的一个特例, scanf 只能读取 stdin (通常是键盘)  
 */
void main1()
{
	char str[100];
	int num;
	scanf("%s%d", str, &num);
	printf("输入的内容为:%s%d\n", str, num);

	fscanf(stdin, "%s%u", str, &num);
	fprintf(stdout, "输入的内容为:%s%u\n", str, num);
}

void main()
{
	char str[100] = "D:\\A001_project\\study\\csapp\\C语言-尹成\\进阶\2-格式化读写文件\\out.txt";
	int num;
	scanf("%s%d", str, &num);
	printf("输入的内容为:%s%d\n", str, num);

	fscanf(stdin, "%s%u", str, &num);
	fprintf(stdout, "输入的内容为:%s%u\n", str, num);
}