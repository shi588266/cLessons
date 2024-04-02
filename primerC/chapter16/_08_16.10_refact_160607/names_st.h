/**
 * 避免重复包含 整个头文件内容用 #ifndef 包含
*/
#ifndef NAMES_ST_H_
#define NAMES_ST_H_

#include <string.h>
#ifndef SLEN
#define SLEN 32
#endif

//结构声明
struct names_st
{
	char first[SLEN];
	char last[SLEN];
};

// 类型定义
typedef struct names_st names;

//函数原型
void get_names(names *);
void show_names(const names *);
char * s_gets(char * st, int n);

#endif
/**
 * 避免重复包含 #endif
*/