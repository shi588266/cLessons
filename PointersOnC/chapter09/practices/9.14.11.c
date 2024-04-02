/*
11.编写一个程序，对标准输入进行扫描，并对单词“the”出现的次数进行计数。进行比较时应该区分大小写，所以“The”和“THE”并不计算在内。我们可以认为各单词由一个或多个空格字符分隔，而且输入行在长度上不会超过100字符。计数结果应该写到标准输出上。
*/
#include <stdio.h>
#include <string.h>
#define NUL '\0'
#define ENT '\n'

char *sgets(char *buffer, unsigned int len)
{
    char *temp;
    char *find;
    if ( NULL != (temp = fgets(buffer, len, stdin)) ) {
        find = strchr(buffer, ENT);
        if (NULL != find) {
            *find = NUL;
        } else {
            while (ENT != getchar())
                continue;
        }
    }
    return temp;
}

/*
因为单词是由空格分隔的, 所以可以在在字符串中匹配 "the " 和 " the" 这两个子串
*/
unsigned int count_word(const char *str, const char *substr)
{
    int counter = 0;
    int substrlen = strlen(substr);
    char *find1, *find2;
    /*
    声明指针同时初始化只会分配初始化字符串的空间, 这些内存空间进行字符串拼接会超出合法内存空间造成段错误, 必须声明为数组
    */
    char *spacestr = " ";
    char search[100] = "";
//printf("str = %s\n", strcat(spacestr, substr));
//printf("str = %s\n", strcat(strcat(search, spacestr), substr));
    do {
        find1 = strstr(str, strcat(strcat(search, spacestr), substr)); //查找" the"
        search[0] = NUL;    /*置空*/
        find2 = strstr(str, strcat(strcat(search, substr), spacestr)); //查找"the "
        search[0] = NUL;    /*置空*/
        /*看两个子字符串哪个先出现*/
        if (find1 || find2) {
            if (find1 && find2) {
                str = find1 < find2 ? find1 : find2;
            } else if (find1) {
                str = find1;
            } else {
                str = find2;
            }
            counter++;
            /*跳过匹配到的字符串,继续查找*/
            str += substrlen + 1;
        } else {
            str++;
        }
        find1 = find2 = NULL;
    } while (str && *str);
    
    return counter;
}

int main(void)
{
    char *test = "Test program.Hello world,the lucky god will award the man who work hard for what he prefer.";
    char *substr = "the";
    unsigned int cnt = 0;
    printf("found %d times totally\n", count_word(test, substr));
    
    return 0;
}