#include<stdio.h>
#include<stdlib.h>

/**
 * 文件内容异或加密解密原理:
 *     原文: 10100101
 *     密码: 00111100
 *     密文: 10011001
 *
 *     密文: 10011001
 *     密码: 00111100
 *     解密: 10100101
 * 以二进制的模式打开文件, 可以保证字符的加解密精确
 * 以文本方式打开文件, 换行符会被解析为 /r/n, 加密解密后可能不一致
 */

void XorEncrypt(char *path, int salt) {
    FILE *pf;
    pf = fopen(path, "rb");
    if (pf == NULL)
    {
        perror("文件打开失败1:\n");
        return;
    }

    char encryptedPath[25] = "./XorEncrypt.txt";
    FILE *encryptedPf = fopen(encryptedPath, "wb");
    if (encryptedPf == NULL)
    {
        perror("文件打开失败2:\n");
        return;
    }
    while(!feof(pf)) {
        int ch = fgetc(pf);
        ch ^= salt;    //字符与整数异或
        fputc(ch, encryptedPf);
    }
    fclose(encryptedPf);
    fclose(pf);
}

void XorDecrypt(char *path, int salt) {
    FILE *pf;
    pf = fopen(path, "rb");
    if (pf == NULL)
    {
        perror("文件打开失败3:\n");
        return;
    }

    char decryptedPath[25] = "./XorDecrypt.txt";
    FILE *decryptedPf = fopen(decryptedPath, "wb");
    if (decryptedPf == NULL)
    {
        perror("文件打开失败4:\n");
        return;
    }
    while(!feof(pf)) {
        int ch;
        ch = fgetc(pf);
        ch ^= salt;    //字符与整数异或
        fputc(ch, decryptedPf);
    }
    fclose(decryptedPf);
    fclose(pf);
}

void main() {
    char originpath[25] = "./origin.txt";
    XorEncrypt(originpath, 6);
    char encryptedpath[25] = "./XorEncrypt.txt";
    XorDecrypt(encryptedpath, 6);
}