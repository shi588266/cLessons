/*
1.根据下面给出的声明和数据，对每个表达式进行求值并写出它的值。在对每个表达式进行求值时使用原先给出的值（也就是说，某个表达式的结果不影响后面的表达式）。假定ints数组在内存中的起始位置是100，整型值和指针的长度都是4字节。
*/

#include <stdio.h>

int main(void) {
    int ints[20] = {
        10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200
    };
    int *ip = ints + 3;
    printf("ints=%d\t", ints);
    printf("ints[4]=%d\t", ints[4]);
    printf("ints + 4=%d\t", ints + 4);
    printf("*ints + 4=%d\t", *ints + 4);
    printf("*(ints + 4)=%d\t", *(ints + 4));
    printf("ints[-2]=%d\t", ints[-2]);
    printf("&ints=%d\t", &ints);
    printf("&ints[4]=%d\t", &ints[4]);
    printf("&ints + 4=%d\t", &ints + 4);
    printf("&ints[-2]=%d\t", &ints[-2]);
    
    putchar('\n');
    putchar('\n');
    
    printf("ip=%d\t", ip);
    printf("ip[4]=%d\t", ip[4]);
    printf("ip + 4=%d\t", ip + 4);
    printf("*ip + 4=%d\t", *ip + 4);
    printf("*(ip + 4)=%d\t", *(ip + 4));
    printf("ip[-2]=%d\t", ip[-2]);
    printf("&ip=%d\t", &ip);
    printf("&ip[4]=%d\t", &ip[4]);
    printf("&ip + 4=%d\t", &ip + 4);
    printf("&ip[-2]=%d\t", &ip[-2]);
}

/*
ints:                   100         数组首元素的地址值
ints[4]:                50
ints + 4:               116         数组第5个元素的地址值
*ints + 4:              14
*(ints + 4):            50
ints[-2]:               xxx         指向数组首元素地址向左移动8位的内容, 值取决于如何解析位模式   
&ints:                  100         整个数组的地址, 值和数组首元素地址值相同
&ints[4]:               116         []运算优先级高于&
&ints + 4:              420         这个数组的地址, 加上4个数组大小的值: 100 + 4*20*4 = 420
&ints[-2]:              xxx         数组首元素地址值向左移动8位: 100 - 2*4 = 92

ip:                     112     数组第4个元素的地址
ip[4]:                  80      数组第8个元素的值
ip + 4:                 128     指向数组第8个元素
*ip + 4:                44      
*(ip + 4):              80      数组第8个元素的值
ip[-2]:                 20      数组第2个元素的值
&ip:                    xxx     一个内存地址, 值指向一个指针,
&ip[4]:                 128     指向数组第8个元素
&ip + 4:          xxx + 4*4     用于指向ip这个指针的地址值 加上 4个指针大小: xxx + 4*4
&ip[-2]:                104     指向数组第2个元素
*/