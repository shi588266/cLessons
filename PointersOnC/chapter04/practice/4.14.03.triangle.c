/*
3.等边三角形的3条边长度都相等，但等腰三角形只有两条边的长度是相等的。
如果三角形的3条边长度都不等，那就称为不等边三角形。
请编写一个程序，提示用户输入3个数，分别表示三角形3条边的长度，然后由程序判断它是什么类型的三角形。
提示：除了边的长度是否相等，程序是否还应考虑一些其他的东西？
*/
#include <stdio.h>

int main(void)
{
    int line1,line2,line3;
    /*输入3个数*/
    puts("Enter three integer number, you may seperate the numbers with a space");
    if (scanf("%d %d %d", &line1, &line2, &line3) == 3) {
        if (line1 == line2 && line1 == line3) {
            printf("等边三角形\n");
        } else if (line1== line2 || line1 == line3 || line2 == line3) {
            printf("等腰三角形\n");
        } else {
            printf("普通三角形\n");
        }
    } else {
        puts("input error");
    }
}