#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

// 自定义字符串结构体
struct cstmstring
{
	char *p;	//字符串的首地址
	int reallength;	//字符串的真实长度,包含'\0', 同sizeof()
};

typedef struct cstmstring mystring;
int mystrlen(const char *p);
char* mystrcpy(char *dest, const char *src);
char *mystrcat(char *dest, const char *src);
char *mystrchr( const char *str, char ch);
char *mystrstr(const char* str, const char* substr);

/**
 * 字符串实现方法
 * 		初始化,打印, 新增字符/字符串, 删除字符/字符串, 查找字符/字符串, 替换字符/字符串
 */
//初始化, 参数是字符串结构体的地址
void init(mystring *string);
void init_with_length(mystring *string, int length);
void init_with_string(mystring *string, const char *source_string);
// 打印
void printfcstmstring(mystring *string);
//在尾部新增字符
mystring insert_at_end_with_char(mystring *string, char ch);
//在尾部新增字符串
mystring insert_at_end_with_string(mystring *string, const char *addstring);
// 查找字符
char *find_char_from_string(mystring *string, char ch);
// 查找字符串
char *find_string_from_string(mystring *string, const char *substr);
// 删除字符
int delete_char_from_string(mystring *string, char ch);
// 删除字符串
int delete_string_from_string(mystring *string, const char *substr);
//任意位置插入字符
void insert_with_char(mystring *string, char ch, char *pos);
//任意位置插入字符串
void insert_with_string(mystring *string, char *isrtstr, char *pos);