/**
6.编写一个程序，先提示用户输入名，然后提示用户输入姓。
在一行打印用户输入的名和姓，下一行分别打印名和姓的字母数。
字母数要与相应名和姓的结尾对齐，如下所示:
Melissa     Honeybee
      7            8

接下来，再打印相同的信息，但是字母个数与相应名和姓的开头对齐，如下所示:
Melissa     Honeybee
7           8
 */
#include <stdio.h>
#include <string.h>

#define MAXLEN 21

int main(void)
{
    char firstName[MAXLEN],familyName[MAXLEN];
    int firstNameLen,familyNameLen;
    
    printf("Enter your first name please.\n");
    if (1 == scanf("%s", firstName)) {
        printf("Enter your family name please.\n");
        scanf("%s", familyName);
        firstNameLen = strlen(firstName);
        familyNameLen = strlen(familyName);
        
        printf("%s %s\n", firstName, familyName);
        //使用*号修饰符占位
        printf("%*d %*d\n", firstNameLen, firstNameLen, familyNameLen, familyNameLen);
        printf("%*d %*d\n", -firstNameLen, firstNameLen, -familyNameLen, familyNameLen);
    }
}