#include <stdio.h>
# include <stdbool.h>

void check_argu();
int main(int argc, char *argv[])
{
    char ch;
    long cnt = 0;
    // 一直读取到文件结尾
    while( (ch = getchar()) != EOF ) {
        cnt++;
    }
    printf("The text file contains %ld chars\n", cnt);
}

void check_argu(int argc, char *argv[]) 
{
    bool is_invalid = true;
    while (is_invalid) {
        if (argc < 2) {
            printf("You need specify at least a text file for reading \n");
            printf("Usage:%s TEXT_FILE \n", argv[0]);
        } else {
            is_invalid = false;
        }
    }
}