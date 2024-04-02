/**
 * 枚举类型
 * 是整型,是一种可以通过一系列字符标识的有限的整型, 所以其具有整型的用法
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN 30    //用于存储标题,长度比标题最大长度多1

enum spectrum {red, orange, yellow, green, blue, violet};   /*枚举类型*/
const char * colors[] = {"red", "orange", "yellow", "green", "blue", "violet"}; /*值不可变的字符串数组*/
char *s_gets(char *st, int n);  /**/

int main(void)
{
    char choice[LEN];
    enum spectrum color;
    _Bool is_find = false;
    
    puts("Enter a color, empty to quit.");
    while (NULL != s_gets(choice, LEN) && choice[0] != '\0' ) {
        for (color = red; color <= violet; color++) {
            if ( 0 == strcmp(colors[color], choice) ) {
                is_find = true;
                break;
            }
        }
        
        if (is_find) {
            switch (color) {
                case red:
                    puts("color is red");
                    break;
                case orange:
                    puts("color is orange");
                    break;
                case yellow:
                    puts("color is yellow");
                    break;
                case green:
                    puts("color is green");
                    break;
                case blue:
                    puts("color is blue");
                    break;
                case violet:
                    puts("color is violet");
                    break;
            }
        } else {
            printf("%s is not recognized as a valid color.\n", choice);
        }
        is_find = false;    //重置
        puts("Enter a color again, empty to quit");
    }
    puts("Bye!");
    return 0;
}

char * s_gets(char *str, int len) {
    char *res = fgets(str, len, stdin);
    char *find;
    if (res) {
        if (find = strchr(res, '\n')) 
            *find = '\0';
        else {
            while (getchar() != '\n')
                continue;
        }
    }
    return res;
}