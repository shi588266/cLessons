/*
14.这个问题的最后部分就是编写下面的函数：
               void decrypt( char *data, char const *key );
它接受一个加过密的字符串为参数，它的任务是重现原来的信息。除了它是用于解密之外，它的工作原理应该与encrypt相同。
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define NUL '\0'
#define LEN 27

const static char alpha_table[LEN] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int prepare_key( char *key )
{
    if (!key) {
        return 0;
    }
    /*去除重复并转为大写*/
    char *origin_p, *current_p; /*记录原始字符数组指针, 新字符数组指针*/
    origin_p = current_p = key;
    int reserve_len = 0;
    do {
        if (!isalpha(*key)) {
            return 0;
        }
        
        if (!strchr(key, toupper(*origin_p))) {
            *current_p = toupper(*origin_p);
            current_p++;
        }
        origin_p++;
    } while (key && *origin_p);

    
    //用字母表中剩余的字母按照原先所选择的大小写形式填充到key数组中
    char *at_p = (char*)alpha_table;    /*声明指针指向字母表数组首元素*/
    while (*at_p) {
        if (!strchr(key, toupper(*at_p))) {
            *current_p = toupper(*at_p);
            current_p++;
        }
        at_p++;
    }
    *current_p = NUL;   /*新字符数组指针最后指向空字节*/
    //printf("1.key=%s\n", key);
    return 1;
}

/*从加密key字符数组中获取 密文 字符*/
static char get_encrypted_chr(char const *key, const char chr)
{
    int index;
    for ( index = 0; index < LEN; index++ ) {
        if (alpha_table[index] == toupper(chr)) {
            break;
        }
    }
    
    return islower(chr) ? tolower(key[index]) : key[index];
}
/*从字母表数组中获取 原文 字符*/
static char get_regular_chr(char const *key, const char chr)
{
    int index;
    for ( index = 0; index < LEN; index++ ) {
        if (key[index] == toupper(chr)) {
            break;
        }
    }
    
    return islower(chr) ? tolower(alpha_table[index]) : alpha_table[index];
}

/*
加密字符串
*/
void encrypt( char *data, char const *key )
{
    while (*data) {
        /*data中的非字母字符不做修改*/
        if (isalpha(*data)) {
            *data = get_encrypted_chr(key, *data);
        }
        data++;
    }
}
/*
解密
*/
void decrypt( char *data, char const *key )
{
    while (*data) {
        /*data中的非字母字符不做修改*/
        if (isalpha(*data)) {
            *data = get_regular_chr(key, *data);
        }
        data++;
    }
}

int main(void)
{
    char key[LEN] = "password";
    char data[10086] = "Test hello world!";
    
    printf("original data is %s\n", data);
    if (prepare_key(key)) {
        encrypt( data, key );
        printf("encrypted data is %s\n", data);
        decrypt( data, key );
        printf("decrypt data is %s\n", data);
    } else {
        puts("prepare key FAILED!");
        exit(EXIT_FAILURE);
    }
    return 0;
}