#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include "strheader.h"
//自己实现的 获取字符串长度函数
int mystrlen(const char *p) {
	if (p == NULL)
	{
		return -1;
	}
	int len = 0;
	while(*p != '\0') {
		len++;
		p++;
	}
	return len;
}
//自己实现 字符串拷贝函数, 返回值是指针
char *mystrcpy(char *dest, const char *src) {	//const限定src不会被修改
	char *res = dest; //用于指向完成拷贝之后的字符串地址
	if (src == NULL)
	{
		return NULL; //无需拷贝
	}
	while(*src != '\0') {
		*dest = *src;
		src++;
		dest++;
	}
	//末尾追加 '\0'
	*dest = '\0';
	return res;
}
//自己实现的字符串连接函数, 返回值是拼接后的字符串指针
char *mystrcat( char *dest, const char *src) {
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	char * destbak = dest;
	// 把dest 的指针移动到末尾, 然后把 src 的内容依次追加到 dest 
	while(*dest != '\0') dest ++;

	while(*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	//末尾追加 '\0'
	*dest = '\0';
	return destbak;
}
//自己实现的获取字符串中某个字符地址的函数
char *mystrchr( const char *str, char ch) {
	if (str == NULL)
	{
		return NULL;
	}
	while (*str != '\0') {
		if (*str == ch)
		{
			return (char *)str;
		}
		str++;
	}
	return NULL;
}
//自己实现的获取字符串中子字符串地址的函数
char *mystrstr(const char* str, const char* substr) {
	if (str == NULL )
	{
		return NULL;
	}
	if ( 0 == mystrlen(substr) )
	{
		return (char*)str;
	}

	char *orgstrbak;
	char *orgstr;
	orgstrbak = orgstr = (char*)str;
	char *orgsubstrbak;
	char *orgsubstr;
	orgsubstrbak = orgsubstr = (char *)substr;
	int flag;
	while (*orgstrbak != '\0') {
		orgstr = orgstrbak;		// 确保字符进行匹配比较之后还能正确复位到下次需要匹配的位置
		orgsubstr = orgsubstrbak;	//子串指针复位, 确保每次都从子串的开始位置进行匹配
		flag = 1; //假设第一个就匹配, 如果不匹配会被置为0
		while (*orgsubstr != '\0' && '\0' != *orgstr) {
			if (*orgsubstr != *orgstr)
			{
				flag = 0;
				break;
			}
			orgsubstr++;
			orgstr++;
		}
		if (flag == 1)	// 表示子字符串完全部匹配到
		{
			return orgstrbak;
		}
		orgstrbak++;
	}
	return NULL;
}

// 初始化一个空的字符串
void init(mystring *string){
	string->p = NULL;
	string->reallength = 0;
}
void init_with_length(mystring *string, int length){
	// 分配指定length的内存空间
	string->p = (char *)calloc(length, sizeof(char));
	string->reallength = length;
}
//使用库函数strcpy拷贝源字符串到自定义字符串
void init_with_string(mystring *string, const char *source_string){
	// 获取源字符串的长度, 使用库函数 strlen
	unsigned int length = mystrlen(source_string);
	// 分配指定length的内存空间, 注意分配的空间需要多一个字节来存放结束字符'\0'
	string->p = (char *)calloc(length + 1, sizeof(source_string));
	mystrcpy(string->p, source_string);
	string->reallength = length + 1;
}

// 打印
void printfcstmstring(mystring *string) {
	printf("string->p=%s\n", string->p);
}
//尾部追加字符
mystring insert_at_end_with_char(mystring *string, char ch){
	// 两种情况:1.原字符串的空间已满
	if (string->reallength == mystrlen(string->p) + 1)
	{
		/* 重新分配内存 */
		string->reallength += 1;
		string->p = (char *)realloc(string->p, string->reallength);
		string->p[string->reallength - 2] = ch;
		string->p[string->reallength - 1] = '\0';
	} else { //2.原字符串的空间未满
		string->p[string->reallength - 2] = ch;
		string->p[string->reallength - 1] = '\0';
	}
	return *string;
}
//尾部追加字符串
mystring insert_at_end_with_string(mystring *string, const char *addstring){
	// 两种情况:1.追加后原字符串的空间满
	int afterlen = mystrlen(string->p) + mystrlen(addstring) + 1;
	if (afterlen > string->reallength)
	{
		string->p = (char *)realloc(string->p, afterlen);
		string->reallength = afterlen;
	} 
	// 拼接
	mystrcat(string->p, addstring);
	return *string;
}
// 查找字符
char *find_char_from_string(mystring *string, char ch) {
	char *pos = mystrchr(string->p, ch);
	return pos;
}
// 查找字符串
char *find_string_from_string(mystring *string, const char* substr) {
	char *strpos = mystrstr(string->p, substr);
	return strpos;
}
// 删除字符
int delete_char_from_string(mystring *string, char ch) {
	char *pos = find_char_from_string(string, ch);
	if (pos != NULL) {
		while (*pos != '\0') {
			*pos = *(pos+1); 	//后面的元素向前移动
			pos++;
		}
		return 1;
	}
	return 0;
}
// 删除字符串
int delete_string_from_string(mystring *string, const char *substr) {
	char *strpos = find_string_from_string(string, substr);
	if (strpos != NULL) {
		int len = mystrlen(substr);
		while (*strpos != '\0') {
			*strpos = *(strpos + len); 	//后面的元素向前移动
			strpos++;
		}
		return 1;
	}
	return 0;
}
//任意位置插入字符
void insert_with_char(mystring *string, char ch, char *pos) {
	if (string == NULL || pos == NULL)
	{
		return;
	}

	int oldlen = mystrlen(string->p); //原始字符串长度
	//printf("oldlen=%d\n", oldlen);
	int movelen = mystrlen(pos); //需要移动的元素长度
	//printf("movelen=%d\n", movelen);
	if (string->reallength == oldlen + 1)	//原空间已满
	{
		/* 重新分配内存 */
		string->reallength += 1;
		string->p = (char *)realloc(string->p, string->reallength);
	} 
	// 先移动最后一个, 然后依次移动前面的
	for (int i = oldlen; i >= oldlen - movelen; i--) {
		string->p[i] = string->p[i - 1];
	}
	string->p[oldlen - movelen] = ch;
	string->p[oldlen + 1] = '\0';
}
//任意位置插入字符串
void insert_with_string(mystring *string, char *isrtstr, char *pos) {
	if (string == NULL || pos == NULL)
	{
		return;
	}

	int oldlen = mystrlen(string->p);
	int isrtlen = mystrlen(isrtstr);
	int afterlen = oldlen + isrtlen;
	int movelen = mystrlen(pos); //需要移动的元素长度
	printf("pos=%c\n", *pos);
	printf("movelen=%d\n", movelen);
	// 两种情况:1.追加后原字符串的空间满
	if (afterlen + 1 > string->reallength) {
		string->p = (char *)realloc(string->p, afterlen + 1);
		string->reallength = afterlen + 1;
	} 
	// 先移动末尾 '\0', 移动 isrtlen 个位置, 然后依次移动前面的, 共移动元素个数oldlen - movelen + 1
	for (int i = oldlen; i > oldlen - movelen - 1; i--) {
		string->p[i + isrtlen] = string->p[i];
	}
	//插入
	for (int i = 0; i < isrtlen; i++)
	{
		string->p[oldlen - movelen + i] = isrtstr[i];
	}
	string->p[afterlen] = '\0';
}