#include <stdio.h>
#include "names_st.h"

//函数定义
void get_names(names *pname)
{
	printf("P.lease enter your first name:");
	s_gets(pname->first, SLEN);
	printf("Please enter your last name:");
	s_gets(pname->last, SLEN);
}

void show_names(const names *pname)
{
	printf("%s %s", pname->first, pname->last);
}

char * s_gets(char * st, int n)
{
	// 1.定义字符指针, 指向接收到的终端输入内容
	char * ret_val;
	// 2.定义字符指针, 用来表示换行符在字符串中的位置
	char * find;
	// 3.接收终端输入, fgets 会读入换行符
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		// 如果输入中查找到换行符, 说明st足够容纳终端输入的内容
		*find= '\0';
		// 如果输入中没有查找到换行符, 说明终端输入的内容超出st的容量, 需要清空输入缓冲区
		while (getchar() != '\n') {
			continue;
		}
	}
	//返回指向接收到输入内容的指针
	return ret_val;
}
