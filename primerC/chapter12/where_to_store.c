/**
 * 静态存储类别变量存储在静态存储区
 * 自动存储类别变量存储的内存是栈内存
 * malloc动态分配内存的变量是堆变量
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;  //外部链接变量-------------存储在静态存储区
//字符串字面量赋值给常量指针
const char * pcg = "string literal";    //-------------存储在静态存储区


/**
 * 
    static_store:30 at 0x601048
    auto_store:40 at 0x7ffc07acde8c
    *p_int:35 at 0x1df3010
    pcg:string literal at 0x4007a0
    auto_string:Auto char Array at 0x7ffc07acde70
    pcl:Dynamic String at 0x1df3030
    Quoted String:Quoted String at 0x40081e
 * 
 */
int main(void)
{
    int auto_store = 40;    //自动变量-------------存储在栈内存
    char auto_string[] = "Auto char Array"; //自动变量-------------存储在栈内存
    int * p_int;
    char * pcl;
    
    p_int = (int*)malloc(sizeof(int));  //malloc动态分配-------------存储在堆内存
    *p_int = 35;
    
    pcl = (char*)malloc(strlen("Dynamic String") + 1);  //malloc动态分配-------------存储在堆内存
    strcpy(pcl, "Dynamic String");
    
    printf("static_store:%d at %p\n", static_store, &static_store);
    printf("auto_store:%d at %p\n", auto_store, &auto_store);
    printf("*p_int:%d at %p\n", *p_int, p_int);
    printf("pcg:%s at %p\n", pcg, pcg);
    printf("auto_string:%s at %p\n", auto_string, auto_string);
    printf("pcl:%s at %p\n", pcl, pcl);
    printf("Quoted String:%s at %p\n", "Quoted String", "Quoted String");   //字符串字面量-------------存储在静态存储区

    
    free(p_int);
    free(pcl);
    return 0;
}