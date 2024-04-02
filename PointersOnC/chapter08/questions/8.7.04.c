/*
4.下面的循环用于测试某个字符串是否是回文，请对它进行重写，用指针变量代替下标
*/

#include <stdio.h>
#include <string.h>

#define SIZE 100

void origin()
{
    char buffer[SIZE];
    int front, rear;
    
    front = 0;
    rear = strlen(buffer) - 1;
    while ( front < rear ) {
        if (buffer[front] != buffer[rear]) {
            break;
        }
        front += 1;
        rear -= 1;
    }
    
    if (front >= rear) {
        printf("It is a palindrome!\n");
    }
}

void rewrite()
{
    char buffer[SIZE];
    int *front, *rear;/*声明两个指针指向数组的首元素和尾元素*/
    front = &buffer[0];
    rear = &buffer[SIZE] - 1;
    
    while ( front < rear ) {
        if (*front++ != *rear--) {
            break;
        }
    }
    
    if (front >= rear) {
        printf("It is a palindrome!\n");
    }
}

void rewrite2()
{
    char buffer[SIZE];
    int *front, *rear;/*声明两个指针指向数组的首元素和尾元素*/
    front = buffer;
    rear = buffer + strlen(buffer) - 1;
    
    while ( front < rear ) {
        if (*front++ != *rear--) {
            break;
        }
    }
    
    if (front >= rear) {
        printf("It is a palindrome!\n");
    }
}