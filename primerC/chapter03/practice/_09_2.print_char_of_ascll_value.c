/**
2.编写一个程序，要求提示输入一个ASCI码值(如，66)，然后打印输入的字符。
*/
#include <stdio.h>
int main(void)
{
    int character;
    printf("Enter an ASCI value,the range is between 0 and 128:\n");
    
    while (scanf("%d", &character) == 1 && 'q' != character)
    {
        printf("%d represents asci char:%c.\n\n", character, character);
        printf("Enter an ASCI value:\n");
    }
    
    printf("bye.\n");
    return 0;
}