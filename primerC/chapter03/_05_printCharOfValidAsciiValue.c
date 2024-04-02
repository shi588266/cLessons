#include <stdio.h>
int main(void)
{
    int uint_code_value;
	printf("input a valid ASCII code value, notice that only integer value is valid:\n");
	scanf("%d", &uint_code_value);
	printf("The given value convert charactar is \'%c\'\n", uint_code_value);
	return 0;
}