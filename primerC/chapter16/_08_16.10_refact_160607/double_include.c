/**
 * 包含头文件两次
 * 编译时需要链接 names_st.c
 * `gcc -o double_include double_include.c names_st.c`
 */

#include <stdio.h>
#include "names_st.h"
#include "names_st.h"   // 不小心第2次包含头文件

/**
 * 需要链接 names_st.c
 */
int main(void)
{
	names winner = {"Less", "Ismore"};
	printf("The winner is %s %s.\n", winner.first, winner.last);
	return 0;
}