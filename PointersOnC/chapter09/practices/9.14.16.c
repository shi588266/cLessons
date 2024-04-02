/*
16.这个程序与前一个练习的程序相似，但它更为通用。它按照一个指定的格式字符串对一个数字字符串进行格式化，类似于许多BASIC编译器所提供的“print using”语句。函数的原型应该如下：
        int format( char *format_string, char const *digit_string );
digit_string中的数字根据一开始在format_string中找到的字符从右到左逐个复制到format_string中。注意，被修改后的format_string就是这个处理过程的结果。在完成时要确定format_string依然是以NUL字节结尾的。根据格式化过程中是否出现错误，函数返回真或假。

提示：开始时让两个指针分别指向格式字符串和数字字符串的末尾，然后从右向左进行处理。对于作为参数传递给函数的指针，必须保留它的值，这样就可以判断是否到达了这些字符串的左端。
*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 20
#define NUL '\0'

int format( char *format_string, char const *digit_string )
{
    int fs_len,ds_len;
    fs_len = strlen(format_string);
    ds_len = strlen(digit_string);
    
    //统计格式字符串中 # 符号的个数
    unsigned int sharp_cnt = 0;
    unsigned int sharp_behind_dot_cnt = 0;
    char *fs_p = format_string;
    int contain_dot = 0;    //格式字符串是否包含小数点
    while (*fs_p) {
        if (*fs_p == '#') {
            sharp_cnt++;
            if (contain_dot) {
                sharp_behind_dot_cnt++;
            }
        }
        if (*fs_p == '.')
            contain_dot = 1;
        fs_p++;
    }
    fs_p--;
    
    if (sharp_cnt < ds_len) {
        return 0;
    }
    if (*digit_string == NUL) {
        return 0;
    }
    char *ds_p = (char*)digit_string + ds_len - 1;
    int dot_appear = 0; //小数点是否已经出现
    while (fs_p >= format_string) {
        if (ds_p >= digit_string) {
            if (*fs_p == '.' || *fs_p == ',') {
                *fs_p = *fs_p;
                if (*fs_p == '.') 
                    dot_appear = 1;
            } else {
                *fs_p = *ds_p;
                ds_p--;
                if (ds_p < digit_string && dot_appear) {
                    break;
                }
            }
        } else {
            if (*fs_p == '.') {
                dot_appear = 1;
                *fs_p = *fs_p;
            } else {
                if (contain_dot && !dot_appear) {
                    *fs_p = '0';
                } else if (contain_dot && dot_appear) {
                    if (sharp_behind_dot_cnt >= ds_len) {
                        *fs_p = '0';
                    }
                    break;
                } else {
                    break;
                }
            }
        }
        fs_p--;
    }
    
    fs_p = (sharp_cnt == ds_len) ? fs_p++ : fs_p;
    while (*fs_p) {
        *format_string++ = *fs_p++;
    }
    *format_string = NUL;
    
    return 1;
}

int main(void)
{
    char format_string[100] = "#####.#####";
    char digit_string[100] = "1";
    format(format_string, digit_string);
    printf("format_string=%s\n", format_string);
    return 0;
}