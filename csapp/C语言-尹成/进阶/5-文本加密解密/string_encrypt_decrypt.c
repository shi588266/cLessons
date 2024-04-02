#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * 用字符串对文件内容加密解密原理:
 *     
 * 以二进制的模式打开文件, 可以保证字符的加解密精确
 * 以文本方式打开文件, 换行符会被解析为 /r/n, 加密解密后可能不一致
 */

void stringEncrypt(const char *path, const char *salt) {
    FILE *pf;
    pf = fopen(path, "rb");
    if (pf == NULL) {
        perror("文件打开失败1:\n");
        return;
    }

    char encryptedPath[25] = "./stringEncrypt.txt";
    FILE *encryptedPf = fopen(encryptedPath, "wb");
    if (encryptedPf == NULL) {
        perror("文件打开失败2:\n");
        return;
    }
    int i = 0;
    int length = strlen(salt);
    while(!feof(pf)) {
        if ( i == length ) {
            i = 0;
        }
        int ch = fgetc(pf);
        ch += salt[i];    //字符与加密盐串的某个字符相加
        fputc(ch, encryptedPf);
        i++;
    }
    fclose(encryptedPf);
    fclose(pf);
}

void stringDecrypt(const char *path, const char *salt) {
    FILE *pf;
    pf = fopen(path, "rb");
    if (pf == NULL) {
        perror("文件打开失败3:\n");
        return;
    }

    char decryptedPath[25] = "./stringDecrypt.txt";
    FILE *decryptedPf = fopen(decryptedPath, "wb");
    if (decryptedPf == NULL) {
        perror("文件打开失败4:\n");
        return;
    }
    int i = 0;
    int length = strlen(salt);
    while(!feof(pf)) {
        if ( i == length ) {
            i = 0;
        }
        int ch = fgetc(pf);
        ch -= salt[i];    //字符与加密盐串的某个字符相减
        fputc(ch, decryptedPf);
        i++;
    }
    fclose(decryptedPf);
    fclose(pf);
}

void main() {
    char originpath[25] = "./origin.txt";
    char salt[6] = "123456";
    stringEncrypt(originpath, salt);
    char encryptedpath[25] = "./stringEncrypt.txt";
    stringDecrypt(encryptedpath, salt);
}