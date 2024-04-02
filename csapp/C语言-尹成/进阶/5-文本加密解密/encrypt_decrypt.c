#include<stdio.h>
#include<stdlib.h>

/**
 * 文件内容加密解密原理:
 *     加密:读取每个字符, 进行一个位操作
 *     解密:读取每个字符, 进行一个逆向位操作
 * 以二进制的模式打开文件, 可以保证字符的加解密精确
 * 以文本方式打开文件, 换行符会被解析为 /r/n, 加密解密后可能不一致
 */

void encrypt(char *path) {
    FILE *pf;
    pf = fopen(path, "rb");
    if (pf == NULL)
    {
        perror("文件打开失败1:\n");
        return;
    }

    char encryptedPath[25] = "./encrypted.txt";
    FILE *encryptedPf = fopen(encryptedPath, "wb");
    if (encryptedPf == NULL)
    {
        perror("文件打开失败2:\n");
        return;
    }
    while(!feof(pf)) {
        int ch;
        ch = fgetc(pf);
        ch += 1;    //字符加1, 比如abc会变成bcd
        fputc(ch, encryptedPf);
    }
    fclose(encryptedPf);
    fclose(pf);
}

void decrypt(char *path) {
    FILE *pf;
    pf = fopen(path, "rb");
    if (pf == NULL)
    {
        perror("文件打开失败3:\n");
        return;
    }

    char decryptedPath[25] = "./decrypted.txt";
    FILE *decryptedPf = fopen(decryptedPath, "wb");
    if (decryptedPf == NULL)
    {
        perror("文件打开失败4:\n");
        return;
    }
    while(!feof(pf)) {
        int ch;
        ch = fgetc(pf);
        ch -= 1;    //
        fputc(ch, decryptedPf);
    }
    fclose(decryptedPf);
    fclose(pf);
}

void main() {
    char originpath[25] = "./origin.txt";
    encrypt(originpath);
    char encryptedpath[25] = "./encrypted.txt";
    decrypt(encryptedpath);
}