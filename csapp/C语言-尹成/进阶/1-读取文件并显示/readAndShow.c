#include<stdio.h>

void main()
{
	char path[50] = "D:\\A001_ZQLS\\__素材__\\103.53.211.25.txt";//定义文件路径
	FILE *pf;
	pf = fopen(path, "r");

	if(pf == NULL) {
		printf("文件打开失败\n");
	} else {
		printf("文件打开成功\n");
		do {
			char ch = fgetc(pf);	//读取字符
			putchar(ch);			//输出字符
		} while(!feof(pf));

		fclose(pf);
	}
}