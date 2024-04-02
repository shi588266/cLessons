/**
 * ctype.h
 * 利用 toupper 函数处理字符串里的每个字符, 把整个字符串转换成大写  
 * 利用 ispunct 函数过滤字符串中标点符号  
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 81    //字符串自大长度

void ToUpper(char *);           //字符串转大写
int PunctCount(const char *);   // 统计标点符号数量


int main(void)
{
    printf("Enter an line with letters less than %lu\n", LIMIT);
    char * get_line;
    char input_str_arr[LIMIT];
    
    // **The most worthless thing in the world? It is the gentleness of a man when he is getting no where.**
    if (get_line = fgets(input_str_arr, LIMIT, stdin)) {
        // 处理输入中的换行
        char *find;
        find = strchr(input_str_arr, '\n');
        if (find) 
            *find = '\0';
        
        puts("The original input content is:");
        puts(get_line);
        
        ToUpper(get_line);
        puts("The input line content changes to upper is:");
        puts(get_line);
        
        int punct_cnt = PunctCount(get_line);
        printf("The total punct count = %lu\n", punct_cnt);
    } else {
        puts("An error is accoured while reading!!");
    }

    return 0;
}

//字符串转大写
void ToUpper(char * ptr)
{
    // 便利字符串中每个字符
    while (*ptr != '\0') {
        *ptr = toupper(*ptr);
        ptr++;
    }
}

// 统计标点符号数量
int PunctCount(const char *cst_ptr) 
{
    int punct_cnt = 0;
    while (*cst_ptr != '\0') {
        if (ispunct(*cst_ptr))
            punct_cnt++;
        
        cst_ptr++;
    }
    return punct_cnt;
}

