/**
 * 需要链接 names_st.c
 * `gcc -o useHeader use_header.c names_st.c`
 */

#include <stdio.h>
#include "names_st.h"

/**
 * 需要链接 names_st.c
 */
int main(void)
{
	names candidate;
	get_names(&candidate);
	printf("Let's welcome ");
	show_names(&candidate);
	printf("to this program\n");
	return 0;
}