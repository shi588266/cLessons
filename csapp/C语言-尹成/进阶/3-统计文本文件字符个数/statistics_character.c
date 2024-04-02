#include<stdio.h>
#include<stdlib.h>

void main() {
    // char path[100] = "C:\\Users\\shi\\inst.ini";
    char path[100] = "./AMTAG.BIN";
    FILE *pf;
    pf = fopen(path, "rb");
    if (pf == NULL)
    {
        printf("文件打开失败\n");
        return;
    }

    int numA = 0;
    int numa = 0;
    int num0 = 0;
    int numsp = 0;
    int numrn = 0;
    int numo = 0;
    //读取每个字符
    char ch;
    while((ch = fgetc(pf)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            numA++;
        } else if (ch >= 'a' && ch <= 'z') {
            numa++;
        } else if (ch >= 0 && ch <= 9) {
            num0++;
        } else if (ch == ' ') {
            numsp++;
        } else if (ch == '\n') {
            numrn++;
        } else {
            numo++;
        }
    }

    printf("大写字母个数:%d\n,小写字母个数:%d\n,数字个数:%d\n,空格个数:%d\n,换行符个数:%d\n,其他字符个数:%d\n", numA,numa,num0,numsp,numrn,numo);
}