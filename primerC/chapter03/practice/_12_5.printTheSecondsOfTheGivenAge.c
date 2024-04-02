/**
 5.一年大约有3.156×107秒。编写一个程序，提示用户输入年龄，
 然后显示该年龄对应的秒数。
*/
#include <stdio.h>
int main(void)
{
    // seconds of a hour
    int ages;
    long double lf_age_seconds;
    printf("Enter your ages, only integer value is valid: ");
    scanf("%d", &ages);
    
    lf_age_seconds = 3.156e+7 * ages;
    printf("total seconds of your age is about: %lle \n", lf_age_seconds);
	return 0;
}