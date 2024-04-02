/*
12.有一种技巧可以对数据进行加密，并使用一个单词作为它的密匙。下面是它的工作原理：首先，选择一个单词作为密匙，如TRAILBLAZERS。如果单词中包含有重复的字母，则只保留第一个，其余几个丢弃。现在，修改过的那个单词列于字母表的下面，如下所示：            A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
                T R A I L B Z E S
最后，底下那行用字母表中剩余的字母填充完整：
                A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
                T R A I L B Z E S C D F G H J K M N O P Q U V W X Y
在对信息进行加密时，信息中的每个字母被固定于顶上那行，并用下面那行的对应字母一一取代原文的字母。因此，使用这个密匙，ATTACK AT DAWN（黎明时攻击）就会被加密为TPPTAD TP ITVH。

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUL '\0'
#define LEN 27

const static char alpha_table[LEN] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
/*
它接受一个字符串参数，它的内容就是需要使用的密匙单词。函数根据上面描述的方法把它转换成一个包含编好码的字符数组。假定key参数是个字符数组，其长度至少可以容纳27字符。函数必须把密匙中的所有字符要么转换为大写字母，要么转换为小写字母（随意选择），并从单词中去除重复的字母，然后再用字母表中剩余的字母按照原先所选择的大小写形式填充到key数组中。如果处理成功，函数返回一个真值。如果key参数为空或者包含任何非字母字符，函数将返回一个假值。
*/
int prepare_key( char *key )
{
    if (!key) {
        return 0;
    }
    /*去除重复并转为大写*/
    char *origin_p, *current_p; //记录原始字符数组指针, 新字符数组指针
    origin_p = current_p = key;
    do {
        if (!isalpha(*key)) {
            return 0;
        }
        
        if (!strchr(key, toupper(*origin_p))) {
            *current_p = toupper(*origin_p);
            current_p++;
        }
        origin_p++;
    } while (*origin_p);

    
    //用字母表中剩余的字母按照原先所选择的大小写形式填充到key数组中
    char *at_p = (char*)alpha_table;    /*声明指针指向字母表数组首元素*/
    while (*at_p) {
        if (!strchr(key, toupper(*at_p))) {
            *current_p = toupper(*at_p);
            current_p++;
        }
        at_p++;
    }
    *current_p = NUL;   //新字符数组指针最后指向空字节
    //printf("1.key=%s\n", key);
    return 1;
}

int main(void)
{
    char test[LEN] = "password";
    prepare_key(test);
    return 0;
}