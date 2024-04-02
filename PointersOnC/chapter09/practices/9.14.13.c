/*
13.编写下面的函数
        void encrypt( char *data, char const *key );
它使用前题prepare_key函数所产生的密匙对data中的字符进行加密。data中的非字母字符不做修改，但字母字符则用密匙所提供的编码后的字符一一取代源字符。字母字符的大小写状态应该保留。
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
        // 获取字符在字母表中的索引位置
        if (alpha_table[index] == toupper(chr)) {
            break;
        }
    }
    
    return islower(chr) ? tolower(key[index]) : key[index];
}

void encrypt( char *data, char const *key )
{
    while (*data) {
        //data中的非字母字符不做修改
        if (isalpha(*data)) {
            //printf("*data:%c\n", *data);
            //printf("get_encrypted_chr:%c\n", get_encrypted_chr(key, *data));
            *data = get_encrypted_chr(key, *data);
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
        printf("alpha_table  is %s\n", alpha_table);
        printf("key  is %s\n", key);
        encrypt( data, key );
        printf("encrypted data is %s\n", data);
    } else {
        puts("prepare key FAILED!");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}