// 指向字符串的指針數組
//char類型 數組的數組
#include <stdio.h>
#define SLEN 40
#define CNT 5

int main(void)
{
    char your_talents[CNT][SLEN] = {
        "Walking in a strait line",
        "Sleeping",
        "Watching televison",
        "Mailing letters",
        "Reading email",
    };
    // 指向字符串的指針數組--它是一个数组, 数组里的每个元素是指向字符串的指针
    char *my_talents[CNT] = {
        "adding numbers swiftly",
        "Multiplying accurately",
        "Stashing data",
        "Following instruction to the letter",
        "Understanding the C language",
    };
    int i;
    printf("let's comparing talents\n");
    printf("%-36s  %-25s\n", "My talents", "Your talents");
    
    for (i=0; i<CNT; i++) {
        printf("%-36s  %-25s\n", my_talents[i], your_talents[i]);
    }
    // 各自的大小
    printf("sizeof my_talents=%zd, sizeof your_talents=%zd\n", sizeof(my_talents), sizeof(your_talents));
    // my_talents=40, 指针的大小 x 数组元素的个数
    //your_talents=200
    return 0;
}