/**
1.编写一个程序，创建一个包含26个元素的数组，并在其中储存26个小写字母。然后打印数组的所有内容。
 */
#include <stdio.h>
#define MAXLEN 26

int main(void)
{
    int charArray[MAXLEN];
    int i;
    for (i = 0; i < MAXLEN; i++) {
        charArray[i] = /*(char)*/('a' + i);
    }
    
    for (i = 0; i < MAXLEN; i++) {
        printf("Index %i of charArray value is %c", i, charArray[i]);
        printf("\n");
    }
}