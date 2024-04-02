
[TOC]

## 二进制
- 1.二进制的 <mark> 最高位(首位)代表符号位 </mark>, 0表示正数,1表示负数  
- 2.<mark> 正数的原码反码补码一致 </mark>  
- 3.负数的反码=原码的符号位不变,其他位取反  
- 4.负数的补码=反码+1  
- 5.0的反码补码还是0  
- 6.计算机运算都是以 <mark> 补码的方式运算 </mark>  

在32位操作系统上, 整型占4字节(32/8=4), 整数1在内存中的二进制表示为:  
```c
自然表示法     1
原码          00000000 00000000 00000000 00000001
反码          00000000 00000000 00000000 00000001
补码          00000000 00000000 00000000 00000001

自然表示法     -1
原码          10000000 00000000 00000000 00000001
反码          11111111 11111111 11111111 11111110
补码          11111111 11111111 11111111 11111111
```

### 进制转换
### 十进制转换其他进制 ###
- **除基倒取余**
    - 10进制980转换成10进制, 结果:980  
    ```c
    10|980
      ----
    10|98..........0
    ------
    10|9...........8
    ------
    10|0...........9
    ```
    - 10进制980转换成8进制, 结果:0b0011 1101 0100  
    ```c
    2|980
      ----
    2|490..........0
    ------
    2|245..........0
    ------
    2|122..........1
    ------
    2|61...........0
    ------
    2|30...........1
    ------
    2|15...........0
    -----
    2|7............1
    -----
    2|3............1
    -----
    2|1............1
    -----
    2|0............1
    ```
    - 10进制980转换成16进制, 结果:0x3d4  
    ```c
    16|980
    ------
    16|61...........4
    ------
    16|3............13......d
    ------
    16|0............3
    ```

## 整型  
- ### 整型数据占用的空间  
```c
#include <stdio.h>
void main()
{
    // 2, 4, 8
    printf("%d, %d, %d\n", sizeof(short), sizeof(int), sizeof(long));
}
```
> 在32位操作系统上, int 与 long 占4字节(32/8=4), short 占两个字节  
> 在64位操作系统上, short 占两个字节, int 占4字节,  与 long 占8字节(64/8=8)  
- ### 数据在内存中以补码方式存在  
```c
#include <stdio.h>
void main()
{
    int i = 10;
    // 16进制打印
    printf("%x\n", &i);  //23857acc
    /**
     * 该内存地址对应的4字节整数16进制表示为:00 00 00 0A
     * 每两个16位进制占一个字节
     */
}
```

    | 自然表示 | 进制 | 数字 | 含义 |
    |:------:|:------:|:------:|:---------:|
    | 10 | 16进制 | 0000000A | 16进制的每一位对应二进制4个位(F=1111) |
    | 10 | 2进制 | 0000 0000 0000 0000 0000 0000 0000 1010 | A=1010=10 补码表示 |

- ### 整型数据范围的溢出  
```c
#include <stdio.h>
void main()
{
    short st = 100000;
    printf("工资年薪%d\n", st); //工资年薪-31072
}
```
>unsigned short类型2字节,16位,最高位表示符号位,只有15个数字位最大范围:-32768~32767, 2^15-1=32767  
>short类型2字节,16位, 最大范围:0~65535, 2^16-1=65535, 所有位都是数字为,所以表示范围更广  

-----

## 字符型型数据  
- ### 字符在内存中是用ASCII码值存储  
```c
#include <stdio.h>
void main()
{
    char ch = 'a';
    putchar('a');
    putchar(ch);
    putchar(97);    // 字符a对应的ASCII码值
    putchar('\141');    // 八进制
    putchar('\x61');    // 十六进制
}
```
- ### 字符在内存中占用的空间
```c
#include <stdio.h>
void main()
{
    char ch = 'a';
    printf("%d\n", sizeof ch);  //1
    printf("%d\n", sizeof "a"); //2
}
```
> 字符类型在内存中占 **1** 个字节  
> 单字符字符串末尾会携带一个<mark>  \0 字符 </mark>, 标识字符串的结束, <mark> 单字符字符占 **2** 个字节 </mark>

-----

## 浮点型
- ### 浮点型数据占用的空间  
```c
#include <stdio.h>
void main()
{
    printf("double:%x,float:%d",sizeof 1.0,sizeof 1.0f);//double:8,float:4
    //float:4, double:8, long double:16
    printf("float:%d, double:%d, long double:%d\n", sizeof(float), sizeof(double), sizeof(long double));  
}
```
> float 占4字节, double 占8个字节, long double 占16个字节  
> <mark> 浮点数默认是double型 </mark>  

- ### 浮点型数据的范围  
```c
#include <stdio.h>
#include<float.h>
void main()
{
    printf("float_min:%f, float_max:%f\n", FLT_MIN, FLT_MAX);
    printf("float_min:%.50f, float_max:%f\n", FLT_MIN, FLT_MAX);
    //float_min:0.00000000000000000000000000000000000001175494350822, float_max:340282346638528859811704183484516925440.000000
}
```
>float_min:0.000000  
>float_max:340282346638528859811704183484516925440.000000  

- ### 浮点数的误差  
- #### float类型只能精确到小数点后6位  
```c
#include <stdio.h>
void main()
{
    float f = 3.1415926535897;
    printf("%f\n", f);      //3.141593
}
```
- #### double类型只能精确到小数点后15位  
```c
#include <stdio.h>
void main()
{
    double db = 3.14159265358976264584685527129;
    printf("%.20f\n", db);      //3.14159265358976247384
}
```
>浮点数float只能精确到小数点后6位  
>浮点数double只能精确到小数点后15位  

- ### 浮点型在内存中的存储形式  
- #### float
float类型的实数在内存中占4字节,32个bit位, 32个bit位分为3个部分:
    - 符号位:这个是最高位第31位  
    - 阶码位:30~23位共 <mark> 8位 </mark>, 这8个二进制位是规格化二进制实数的指数与 <mark> 127 </mark>之和即为阶码  
    > 8个bit位规格化二进制实数的指数只能是 -127~127   
    > 规格化二进制实数的指数与127求和后的范围是 0~254, 这样可以 <mark>  用无符号的正数来表示指数幂 </mark>   
    - 尾数位:0~22位共23位, 规格化二进制实数(形如: 1.1111)的小数部分(整数1被省略)  

- #### float 举例  
| 自然实数 | 二进制实数 | 规格化二进制 | 内存中的二进制形式 | 解释 |
|:------:|:------:|:------:|:---------:|:---------:|
| 1.5 | `1.5=1*2^0+1*2^-1`得(1.1) | 规格化(1.1)2指数为0 | 0`0111111 1`1000000 00000000 00000000 | 正数最高位是0,阶码位是127+(0)=127=01111111,尾数位是1 |
| 0.5 | `0.5=1*2^-1`得(0.1) | 规格化(1.0)2,右移一位指数为-1 | 0`0111111 0`0000000 00000000 00000000 | 正数最高位是0,阶码位是127+(-1)=126=01111110,尾数位是0 |
| 0.75 | `0.75=1*2^-1+1*2^-2`得(0.11) | 规格化(1.1)2,右移一位指数为-1 | 0`0111111 0`1000000 00000000 00000000 | 正数最高位是0,阶码位是127+(-1)=126=01111110,尾数位是1 |
| 0.375 | `0.375=1*2^-2+1*2^-3`得(0.011) | 规格化(1.1)2,右移两位指数为-2 | 0`0111110 1`1000000 00000000 00000000 | 正数最高位是0,阶码位是127+(-2)=125=01111101,尾数位是1 |

- #### double  
double 类型的实数在内存中占8字节,64个bit位, 64个bit位分为3个部分:
    - 符号位:这个是最高位第63位  
    - 阶码位:52~62位共 <mark> 11位 </mark>, 这11个二进制位是规格化二进制实数的指数与<mark> 1023 </mark>之和即为阶码  
    > 11个bit位规格化二进制实数的指数只能是 -1023~1023  
    - 尾数位:0~51位共52位, 规格化二进制实数的小数部分(整数1被省略)  

- #### double 举例  
| 自然实数 | 二进制实数 | 规格化二进制 | 内存中的二进制形式 | 解释 |
|:------:|:------:|:------:|:---------:|:---------:|
| 1.25 | `1.25=1*2^0+0*2^-1+1*2^-2`得(1.01) | 规格化(1.01)2指数为0 | 0`011 1111 1111`0100 00000000 00000000 00000000 00000000 00000000 00000000 | 正数最高位是0,阶码位是1023+(0)=1023=011 1111 1111,尾数位是01 |
| 0.625 | `0.625=0*2^0+1*2^-1+0*2^-2+1*2^-3`得(0.101) | 规格化(1.01)右移一位指数为-1 | 0`011 1111 1110`0100 00000000 00000000 00000000 00000000 00000000 00000000 | 正数最高位是0,阶码位是1023+(-1)=1022=011 1111 1110,尾数位是01 |
| 0.3125 | `0.3125=0*2^0+0*2^-1+1*2^-2+0*2^-3+1*2^-4`得(0.0101) | 规格化(1.01)右移两位指数为-2 | 0`011 1111 1110`0100 00000000 00000000 00000000 00000000 00000000 00000000 | 正数最高位是0,阶码位是1023+(-2)=1021=011 1111 1101,尾数位是01 |

- #### 十进制小数与二进制的转换  
- 口诀: <mark> 小数乘2取整, 直到结果为整, 0点顺序得值 </mark>  
```c
eg:
自然实数:   0.125
0.125 * 2 = 0.25    取整得 0
0.25 * 2 = 0.5    取整得 0
0.5 * 2 = 1    取整得 1
所以二进制小数为(0.001)
```

-----

## 位运算符
```java
/**
 * 位运算
 */
class L6BitOper
{
    public static void main(String[] args){
        /**
         * 按位相与
         * 6    00000110
         * 2    00000010
         * &    00000010    2
         */
        System.out.println(6 & 2);

        /**
         * 按位或
         * 6    00000110
         * 3    00000011
         * |    00000111    7
         */
        System.out.println(6 | 3);

        /**
         * 按位异或
         * 6    00000110
         * 3    00000100
         * ^    00000010    2
         */
        System.out.println(6 ^ 4);
        /**
         * 交换两个变量(不引入第三个变量)
         * 任何数异或另一个数两次, 结果还是自己
         */
        int a = 11;
        int b = 22;
        b = a ^ b;  // b = 11 ^ 22
        a = a ^ b;  // a = 11 ^ 11 ^ 22 = 22
        b = a ^ b;  // b = 22 ^ 11 ^ 22 = 11
        System.out.println("a=" + a + ",b=" + b);


        /**
         * 按位取反, 每一bit位都取反
         * 00000000 00000000 00000000 00000110      6
         * 11111111 11111111 11111111 11111001      按位取反        (补码)
         * 11111111 11111111 11111111 11111000      -1求     反码
         * 10000000 00000000 00000000 00000111      符号位不变,其他位取反     原码      -7
         */
        System.out.println(~6);

        /**     
         * 左移: << 左边高位舍弃,右边补0, 左移一位增大一倍
         * 右移: >> 左边补零,右边低位舍弃, 右移一位缩小一半
         *
         * 位移直接操作的是二进制,效率较高
         */
        System.out.println(8 << 1); //16
        System.out.println(12 >> 2);    //3
        System.out.println(14 >> 2);    //3,结果是整数
    }
}
```
>1. 任何数异或另一个数两次, 结果还是自己  
>2. 左移: << 左边高位舍弃,右边补0, 左移一位增大一倍  
>3. 右移: >> 左边补零,右边低位舍弃, 右移一位缩小一半  
>4. 移位直接操作的是二进制,效率较高  

-----

## 指针  
### 地址与指针  
- 地址只是地址, 是一个常量,地址是用来标记变量的  
>地址就是一个以0x开头的16进制常量, 知道地址也仅仅只是知道地址的开始位置, 并不能确定地址所标记数据的结束位置  
- 指针是一个变量, 用于存放 <mark> 地址的量 </mark>, 可以存放任何地址, 一个指针占4字节  
>指针不仅包含所存放的地址,还包含<mark> 所指向数据的类型 </mark>, 所以指针能够确定数据的开始位置, 也能确定数据的结束位置; 抛开类型只谈地址,指针毫无意义  
- 指针变量, 存放变量地址的变量叫指针变量, 可以存放任何变量的地址  
```c
#include<stdio.h>
void main(int argc, char const *argv[])
{
    int a = 100;
    printf("%d\n", *(&a));  //100 *表示根据地址取出变量的内容

    // *p与int对称,便是int类型的数据
    int *p = &a;
    printf("%d,%d\n", a, *p);   //100,100
    printf("%x,%x\n", &a, p);   //62fe14,62fe14
    /**
     * p是一个指针变量, 里面存放了变量a的地址
     * *p是一个指针,它表示变量a的内容
     * a=*(&a)
     * *p=a;
     */
    *p = 200;   //通过指针改变变量的值
    printf("%d\n", a);  //200
    system("pause");
}
```

### 指针的运算  
#### 指针变量的赋值运算  
- p = &a  
    将变量的 地址赋值给指针  
- p = array  
    将数组的首地址赋值给指针  
```c
/**
 * 指针的方式遍历数组
 */
#include<stdio.h>
void main(int argc, char const *argv[])
{
    int arr[10] = {0};
    int *p = arr;
    for (; p < arr + sizeof(arr)/sizeof(int); p++)
    {
        // p是地址, *p是元素值
        printf("%x:%d\n", p, *p);
    } 
}
```
- p = &array[i]  
    将数组某一个元素的地址赋值给指针  
- p1 = p2  
    将另一个指针赋值给指针  

#### 数组与指针的关系
- array[i] 与 *(array + i) 等价  
- &array[i] 与 array + i 等价  
- <mark> array这里是常量指针 </mark>  
- <mark> array + i 表示数组中第i个元素的地址 </mark>  
- 以上等价关系:(限于静态数组)  

##### 一维数组
```c
#include<stdio.h>
void main(int argc, char const *argv[])
{
    int arr[5] = {10, 20, 30, 40, 50};
    printf("arr:%x,&arr:%x\n", arr, &arr);  //arr:62fe00,&arr:62fe00

    //*arr_size:4,*(&arr)_size:20
    printf("*arr_size:%d,*(&arr)_size:%d\n", sizeof(*arr), sizeof(*(&arr))); 

    // arr_size:20,&arr_size:8
    printf("arr_size:%d,&arr_size:%d\n", sizeof(arr), sizeof(&arr));

    int *p = arr;    //定义一个指针变量指向数组的首元素地址
    int (*pa)[5] = &arr;    //定义一个 包含5个元素的数组指针变量 指向数组
    printf("p:%x,pa:%x\n", p, pa);  //p:62fdf0,pa:62fdf0
    printf("*p:%d,*pa:%x\n", *p, *pa);  // *p:10,*pa:62fdf0
    printf("p_size:%d,pa_size:%x\n", sizeof(p), sizeof(pa)); // p_size:8,pa_size:8
}
```
>结论:  
>1. arr和&arr指向的地址相同, 但是指向的数据类型不同;   
>2. arr指向数组首元素的地址, 是 **常量指针** , 指向的数据是首元素int占4字节;  
>3. &arr指向整个数组,是 **指针变量** ,占8个字节,指向的数据是整个数组的大小5*4;    

##### 二维数组
```c
#include<stdio.h>
void main()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    //arr:62fdf0,&arr:62fdf0,*arr:62fdf0,**arr:1
    printf("arr:%x,&arr:%x,*arr:%x,**arr:%x\n", arr, &arr, *arr, **arr);    

    //*arr_size:16,*(&arr)_size:48,**arr_size:4
    printf("*arr_size:%d,*(&arr)_size:%d,**arr_size:%d\n", sizeof(*arr), sizeof(*(&arr)), sizeof(**arr));

    //arr_size=48, &arr_size=8, *arr_size=16, **arr_size=4
    printf("arr_size=%d, &arr_size=%d, *arr_size=%d, **arr_size=%d\n", sizeof(arr), sizeof(&arr), sizeof(*arr), sizeof(**arr));
}
```
>结论:  
1. arr,&arr,*arr指向的地址相同, 但是指向的数据类型不同;  
2. arr指向 包含4个元素一维数组数的地址, 相当于(int \*)[4], __行指针__,指向的数据是有4个元素的一维数组,4\*4=16;  
3. &arr指向整个数组, __是指针变量__,占8字节,指向的数据是整个数组,12*4=48;    
4. \*arr指向二维数组首元素的地址, __不是指针变量__,指向的数据是二维数组首元素1;  

#### 二级指针创建动态数组
```c
#include<stdio.h>
/**
 * 手动输入 x, y 创建动态二维数组
 */
void real_dynamic_array()
{
    printf("情输入动态数组的行数列数,逗号分割\n");
    int line,column;
    scanf("%d,%d", &line, &column);

    // 创建一个指针数组, 它的每个元素都是指针, 每个元素都指向一个   包含 column 个元素的一维数组
    // 二级指针可以存放指针, 将指针数组的首地址传递给pp保存
    int **pp = (int**)malloc(sizeof(int *) * line);

    //为指针数组的每一个指针分配内存
    for (int i = 0; i < line; i++) {
        pp[i] = malloc(sizeof(int)*column);
    }

    //为指针里的每个一维数组元素初始化
    int m,n,num;
    num=0;
    for (m = 0; m < line; m++) {
        for (n = 0; n < column; n++) {
            // pp[m][n] 与 *(*(pp+m)+n) 等价
            pp[m][n] = num;
            printf("%-4d", *(*(pp+m)+n));
            num++;
        }
        printf("\n");
    }

    // 释放内存
    for (int k = 0; k < line; k++) {
        free(pp[i]);    // 传入指针地址
    }
    free(pp);
}

void main(int argc, char const *argv[])
{
    real_dynamic_array();
}
```

#### 指针变量的算术运算
- 自增运算  
    指针指向一个数组, 指针++表示指针的值增加一个sizeof(指针指向类型)的大小,元素类型是int,则加4,元素类型是double,则加8,  

- *p++  
    等价于 *(p++), 优先级问题, <mark> ++优先执行 </mark>  

- 指针相减  
    指针相减的结果表示 <mark> 两个地址相差几个元素 </mark>, 指针相减对于两个指针处于 **具有相同结构的同一片内存区** 才有意义  

### 函数指针
程序在编译时,编译系统为函数代码分配一段存储空间,这段存储空间的起始地址,就成为函数指针。  可以定义一个指针变量指向存放函数的起始地址。  
#### 定义函数指针变量
- 格式  
数据类型(*指针变量名)(函数形参列表)  
- 初始化指针  
指针变量名=函数地址  
- 通过指针调用函数  
指针变量名(函数实参列表)

```c
#include<stdio.h>
int add(int num1, int num2)
{
    return num1+num2;
}
void main() {
    //定义函数指针变量
    int (*padd)(int num1, int num2);
    padd=add;//初始化函数指针 
    int res = padd(6, 6);
    printf("%d\n", res);
}
```
#### 函数指针的意义
可以把函数指针作为其他函数的参数, 把函数的地址传递给需要调用的地方
```c
#include<stdio.h>
int add(int num1, int num2)
{
    return num1+num2;
}
int getMax(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}
int getMin(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

//接收函数地址作为参数
int doOpt(int num1, int num2, int (*p)(int, int))
{
    return p(num1, num2);
}
void main() {
    printf("请输入要执行的操作:1获取两个数之和,2获取较大的数,3获取较小的数\n");
    int opt;
    scanf("%d", &opt);
    // 传递不同的函数地址,调用不同的函数
    switch (opt){
        case 1:
            printf("%d\n", doOpt(10, 20, add));
            break;
        case 2:
            printf("%d\n", doOpt(10, 20, getMax));
            break;
        case 3:
            printf("%d\n", doOpt(10, 20, getMin));
            break;
    }
}
```
#### 空类型指针,空值指针
void 指针就是空类型指针, 它只有地址不指向任何类型, 但是可以接受任意类型指针的地址
```c
#include<stdio.h>
void main(){
    char ch = 'A';
    int i = 100;
    double dbl = 3.1415;

    void *vp;
    vp = &ch;
    vp = &i;
    vp = &dbl;  //可以接受任意类型指针的地址

    // error: invalid use of void expression---空指针不指向任何类型,不确定数据类型,也就无法通过地址获取其值;
    // printf("%d\n", *vp); 
    
    printf("%c\n", *(char*)vp); //o
    printf("%d\n", *(int*)vp);  //-1065151889
    printf("%.4f\n", *(double*)vp); //3.1415
}
```
空值指针就是指针等于null, 意味着指针没有初始化, 没有指向任何地址  
```c
#include<stdio.h>
void main(){
    int *ptr = NULL;
    printf("%x\n", ptr);    //0
    if (ptr == NULL)
    {
        printf("指针没有初始化\n");
    }
}
```

### 动态分配内存
#### void  \* malloc(int bytesize)
malloc用于动态分配内存, 参数是需要分配的字节数int, 成功返回值是void * 空类型指针,失败返回NULL;   
如果要用这篇内存存储其他类型的数据, 需要进行强制类型转换  
```c
#include<stdio.h>
#include<stdlib.h>
void main(){
    printf("请输入分配的内存字节数\n");
    int size;
    scanf("%d", &size);
    int *ptr = (int *)malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++)
    {
        ptr[i] = i;
        printf("%d\n", ptr[i]);
    }
    free(ptr);  //释放内存
    ptr = NULL;  //软件工程规范:释放内存后把指针赋值为NULL, 避免再次引用指针时,引用到错误的数据
}
```
#### void \* calloc(int num, size_type size)
效果等同与malloc, 区别是参数不同,并且calloc分配内存后会自动把内存里的数据初始化为0;  
```c
#include<stdio.h>
#include<stdlib.h>
typedef unsigned int tt;

void main(){
    printf("请输入分配的存储数据个数\n");
    int size;
    scanf("%d", &size);
    tt * ptr = (tt *)calloc(size, sizeof(tt));
    for (int i = 0; i < size; ++i)
    {
        ptr[i] = i;
        printf("%u\n", ptr[i]);
    }
    free(ptr);  //释放内存
    ptr = NULL;  //软件工程规范:释放内存后把指针赋值为NULL, 避免再次引用指针时,引用到错误的数据
}
```
#### void \* realloc(void \*ptr, int bytesize)
relloc 拷贝指针对应的一片内存的数据, 重新分配一片新的内存, 并把拷贝放进去  
```c
#include<stdio.h>
#include<stdlib.h>
void main(){
    printf("请输入分配的字节数\n");
    int size;
    scanf("%d", &size);
    // 分配内存空间
    int * ptr = (int *)malloc(sizeof(int)*size);
    if (NULL == ptr)
    {
        printf("分配内存失败\n");
    } else {
        for (int i = 0; i < size; ++i)
        {
            ptr[i] = i;
            printf("%u\n", ptr[i]);
        }
        //printf("\n\n\n\n");
        printf("请输入扩展后的字节数\n");
        int resize;
        scanf("%d", &resize);
        // 重新分配内存空间
        int * newptr = (int *)realloc((void *)ptr, sizeof(int)*resize);
        if (NULL == newptr)
        {
            printf("分配内存失败\n");
        } else {
            printf("扩展后的数据:\n");
            for (int i = size; i < resize; ++i)
            {
                newptr[i] = i;
            }
            for (int i = 0; i < resize; ++i)
            {
                printf("%u\n", newptr[i]);
            }
            free(newptr);
            newptr = NULL;  //软件工程规范:释放内存后把指针赋值为NULL, 避免再次引用指针时,引用到错误的数据
        }   
    }
}
```

#### 内存泄露  
记录分配内存空间的指针在释放前消亡或发生变化,这片内存空间将不会被回收, 就会发生内存泄露   
```c
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void main(){
    while (1) {
        Sleep(1000);
        // 分配内存空间
        int * ptr = malloc(1024 * 1024 * 100);
        if (ptr == NULL)
        {
            printf("分匹配内存失败\n");
        } else {
            printf("分匹配内存成功\n");
            ptr = NULL;     
            // 记录分配内存空间的指针在释放前消亡或发生变化,这片内存空间将不会被回收, 就会发生内存泄露
            free(ptr);
            Sleep(1000);
        }
    }
}
```

-----

## 字符串
### 定义字符串
- char 数组名[常量] = 字符串常量
```c
void main(int argc, char const *argv[])
{
    char str[11] = "notepad";
    printf("%s\n", str);
    printf("str[]=%d,str=%d,strlen=%d\n", sizeof(str), sizeof("notepad"), strlen("notepad")); //str[]=11,str=8,strlen=7
}
```
- char 数组名[常量] = {'c1', 'c2', ..., '\0'}  
字符串遇到'\0'才认为结束  
```c
void main(int argc, char const *argv[])
{
    char str[5] = {'c','a','l','c'}; // 初始值个数小于数组长度, 后面的元素默认填充0,编号为0的字符就是'\0'
    printf("%s\n", str);
    system(str);
    printf("str[]=%d,strlen=%d\n", sizeof(str), strlen(str)); //str[]=5,strlen=4
}
```
### 指针遍历字符数组
```c
void main(int argc, char const *argv[])
{
    char *str = "C is powerfull";   //定义常量指针指向字符串常量的首地址
    printf("str=%x,str=%s,*str=%c\n", str, str, *str); //str=404000,str=C is powerfull,*str=C

    //*str = 'R';       //不能对常量字符串的字符赋值
    printf("*str=%c\n", *str);

    // loop
    while(*str != '\0') {
        putchar(*str);
        str++;
    }
}
```
### 数组和指针两种方式定义字符串的区别  
```c
void main(int argc, char const *argv[])
{
    char str[100] = "notepad";  // 合法,声明的时候直接赋值
    char str1[100]; 
    //str1[100] = "calc"; //不合法:str1[100]代表str1的第101个元素,产生越界
    //str1 = "calc";    //不合法:str1是常量表达式,不可以赋值

    char *p;
    p = "tasklist"; //合法:p是指针变量,看可以指向常量字符串的首地址
    p[0] = 's'; //不合法, p指向的是常量字符的地址, 常量不可以被修改
    system(p);
}
```
### 字符串与字符数组  
```c
#include<stdio.h>
void change(char str[]) {
    /**
     * 函数的参数如果是数组,就没有副本机制, 传递的是指针
     * 所以, 改变形参的值,会直接作用到实参
     */
    str[0] = 'p';
}
void main(int argc, char const *argv[])
{
    char str[100] = "notepad";
    printf("%s\n", str);//notepad
    change(str);
    printf("%s\n", str);    //potepad
}
```
### 字符串应用
#### strstr
`char * strstr(const char* str, const char* substr)`  
返回 str 中首次出现子串substr的地址, 如果没有找到返回NULL  
```c
//自己实现的获取字符串中子字符串地址的函数
char *mystrstr(const char* str, const char* substr) {
    if (str == NULL ) {
        return NULL;
    }
    if ( 0 == mystrlen(substr) ) {
        return (char*)str;
    }

    char *orgstrbak;
    char *orgstr;
    orgstrbak = orgstr = (char*)str;
    char *orgsubstrbak;
    char *orgsubstr;
    orgsubstrbak = orgsubstr = (char *)substr;
    int flag;
    while (*orgstrbak != '\0') {
        orgstr = orgstrbak;     // 确保字符进行匹配比较之后还能正确复位到下次需要匹配的位置
        orgsubstr = orgsubstrbak;   //子串指针复位, 确保每次都从子串的开始位置进行匹配
        flag = 1; //假设第一个就匹配, 如果不匹配会被置为0
        while (*orgsubstr != '\0' && '\0' != *orgstr) {
            if (*orgsubstr != *orgstr) {
                flag = 0;
                break;
            }
            orgsubstr++;
            orgstr++;
        }
        if (flag == 1) { // 表示子字符串完全部匹配到
            return orgstrbak;
        }
        orgstrbak++;
    }
    return NULL;
}
```
#### strcmp
`int strcmp( const char *lhs, const char *rhs );`  
比较两个字符串, 如果两个字符串相等返回0, 如果str1的值大于str2返回1, 如果str1的值小于str2返回-1, 注:按照字符顺序依次比较, 比较的是 <mark> ASCII值 </mark>  
```c
int mystrcmp( const char *lhs, const char *rhs ) {
    if (lhs == NULL || rhs == NULL)
    {
        return 0;
    }
    if (strlen(lhs) == strlen(rhs))
    {
        int flag = 0;
        while (*lhs != '\0') {
            if (*lhs != *rhs)
            {
                flag = -1;
            }
            lhs++;
            rhs++;
        }
        return flag;
    }
    return -1;
}
```
#### strncmp
`int strncmp(const char* str1, const char* str2)`  
比较两个字符串前n个字符, 如果两个字符串相等返回0, 如果str1的值大于str2返回1, 如果str1的值小于str2返回-1, 注:按照字符顺序依次比较, 比较的是 <mark> ASCII值 </mark>  
#### strchr
`char * strchr(const char* str1, const char char)`  
返回 str 中首次出现字符 char 的地址, 如果没有找到返回NULL  
```c
//自己实现的获取字符串中某个字符地址的函数
char *mystrchr( const char *str, char ch) {
    if (str == NULL)
    {
        return NULL;
    }
    while (*str != '\0') {
        if (*str == ch)
        {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}
```
#### strncat
`char * strchr(char *dest, const char *src, size_t count )`  
截取 src 中前count个字符 拼接到dest后面, 如果没有找到返回NULL  
```c
char * mystrncat(char *dest, const char *src, size_t count ) {
    if (dest == NULL || src == NULL)
    {
        return dest;
    }
    // 循环的身体到指针末尾
    char *p = dest;
    while (*p != '\0') {
        p++;
    }
    for (int i = 0; i < count; i++)
    {
        *p = *(src + i);
        p++;
    }
}
void main() {
    char str1[10] = "note";
    char str2[10] = "pad123";
    mystrncat(str1, str2, 3);
    system(str1);
}
```
#### atoi 
`int atoi( const char *str );`  
转译 str 所指的字节字符串中的整数值。舍弃任何空白符，直至找到首个非空白符，然后接收尽可能多的字符以组成合法的整数表示，并转换之为整数值。转换失败返回0, 出现任何非数字字符都会转换失败  
```c
// 数字字符串 转整型
int strtoint(char *str) {
    if (str == NULL) {
        return -1;
    }
    char * p = str; //备份保留字符串的首地址
    while(*str != '\0') {
        if (*str < '0' || *str > '9') {
            return -1;
        }
        str++;
    }

    int digits = 0;
    for (int i = 0; i < strlen(p); i++) {
        digits *= 10;   // 0  10  120  1230  12340  12345
        digits += (p[i] -48); //1  12  123  1234  12345
        //printf("digits=%d\n", digits);
    }
    return digits;
}
void main() {
    char str2[10] = "12345";
    int res = strtoint(str2);
    printf("%d\n", res);
    if (res == -1) {
        printf("%s\n", "给定的字符串无法转换成整数");
    } else {
        printf("转化后的整数=%d\n", res);
    }
}
```
```c
// 数字字符串 转整型
void inttostr(int num, char * str) {
    int i = 0;
    // 获取每个位上得值
    while(num % 10) {
        int digits = num % 10;
        // printf("%d\n", digits);
        // 获取整数对应的字符
        char ch = digits + 48;
        // printf("%c\n", ch);
        str[i] = ch;
        num /= 10;
        i++;
    }
    strrev(str);
}
void main() {
    int a = 123456;
    char str[32] = {0};
    inttostr(a, str);
    printf("%s\n", str);
}
```
#### strrev
`char *strrev(char *str)`
返回逆转字符顺序后的字符串指针  
```c
void *mystrrev(char *str) {
    if (str == NULL)  {
        return NULL;
    }
    int len = strlen(str);
    //循环一般, 交换字符串
    for (int i = 0; i < len / 2; i++) {
        char ch = str[len - 1 - i];
        str[len - 1 - i] = str[i];
        str[i] = ch;
    }
}
void main() {
    char str2[10] = "pad123";
    mystrrev(str2);
    printf("%s\n", str2);
}
```
#### memset
`void *memset( void *dest, int ch, size_t count );`  
复制值 ch （如同以 (unsigned char)ch 转换到 unsigned char 后）到 dest 所指向对象的首 count 个字节。  

### 字符串二级指针
```c
#include<stdio.h>
#include<stdlib.h>
char str1[] = "calc";
char str2[] = "notepad";
void change(char *p) 
{
    /**
     * 函数参数有副本机制, 如果参数不是数组, 在函数调用时会为形式参数单独开辟内存空间
     * 这里的p代表字符串的首个字符的地址
     * *p代表字符串的首个字符
     */
    p = str2;
    printf("p_addr=%p,p=%c\n", p, *p);
}

void changep(char **pp)
{
    /**
     * pp是指向存储字符串首地址指针的指针
     * *pp是指向字符串首地址的指针
     */
    *pp = str2;
    //p_addr=000000000062FE18,*p_addr=0000000000403015,p=n
    printf("pp_addr=%p,*pp_addr=%p,pp=%c\n", pp, *pp, **pp);
}
void main()
{
    char *p = str1;
    // change(p);//不会改变p的值
    changep(&p);
    printf("p_addr=%p,p=%c\n", p, *p);
    system(p);
}
```

-----

## 结构体 共用体
### 结构体定义
struct stctname {};
```c
struct user
{
    int age;
    char name[15];
    char mobile[15];
};
void main(int argc, char const *argv[])
{
    //直接实例化结构体
    struct user u1 = {25,"handsome_boy", "15565136666"};
    printf("u1.age=%du1.name=%su1.mobile=%s\n", u1.age, u1.name, u1.mobile);

    struct user u2;
    u2.age = 30;
    //u2.name = "braveman"; //字符数组常量不能赋值给表达式
    sprintf(u2.name, "braveman");
    sprintf(u2.mobile, "18838288888");
    printf("u2.age=%du2.name=%su2.mobile=%s\n", u2.age, u2.name, u2.mobile);
}
```
### 匿名结构体
```c
//外部任何地方都不能实例化匿名结构体
struct
{
    int age;
    char gender;
} admin,superadmin; //声明匿名结构体时直接实例化

void main(int argc, char const *argv[])
{
    //外部任何地方都不能实例化匿名结构体
    admin.age = 25;
    admin.gender = 'Y';
    printf("u1.age=%du1.name=%c\n", admin.age, admin.gender); //u1.age=25u1.name=Y
}
```
>有名结构体同样支持定义的时候就实例化  
### 结构体的大小
出于cpu寻址的效率考虑, 结构体的成员在内存中 会遵守 <mark> 字节对齐 </mark>的原则, 结构体的大小必须满足:  

- 大于等于 所有成员所占大小之和  
- 结构体的大小是 <mark> 最宽基本数据类型 </mark>成员大小的整数倍  
- 字节对齐  
    - 每个成员所占大小必须是 <mark> 成员基本数据类型大小 </mark>的整数倍  
    - 结构体每个成员相对于结构体首地址的偏移量offset是成员基本数据类型大小的整数倍  

#### 内存字节对齐  
```c
/**
 * 按照正常的逻辑下面的结构体会占用1+4+1+8+9=23字节
 * 但实际该结构体占 4+4+8+8+16 = 40 字节
 */
struct alignment    // 假设首地址是 0x00300500
{
    char a;     //300500  offset=0 拓宽为4字节   
    int b;  //300504  offset=4 
    char c;     //300508 offset=8  拓宽为8字节
    double d;   //300510 offset=16  最宽基本数据类型 占8字节
    char str[9];//300518 offset=24  既要能能容纳9个, 又要是8的倍数, 拓宽为16字节
};

void main(int argc, char const *argv[])
{
    printf("%d\n", sizeof(struct alignment));   // 40
}
```
> 字节对齐:出于cpu寻址的效率考虑, 保证访问每个成员地址的时候偏移量是有规律的  
> 这种特性实在编译器层面实现的

### 结构体数组
```c
struct user
{
    int age;
    char name[15];
    char mobile[15];
};
void main(int argc, char const *argv[])
{
    //直接实例化结构体数组
    struct user u1[10] = {{25,"handsome_boy", "15565136666"},{18,"honest_person", "13000000000"}};
    //u1[0].age=25,u1[0].name=handsome_boy,u1[1].name=honest_person
    printf("u1[0].age=%d,u1[0].name=%s,u1[1].name=%s\n", u1[0].age, u1[0].name, u1[1].name);
}
```

### 共用体  
共用体内的所有成员属性共用同一片内存  

- 共用体所有属性共用同一片内存  
- 共用体的大小就是其内最大成员占用的大小  
- 出于字节对齐, 共用体的大小既要能容纳其内最大成员, 又要是最小成员的整数倍  

```c
union myunion
{
    int age;
    char gender;
    char name[32];
};  
union myunion2
{
    int age;
    char name[9];
}; 

void main(int argc, char const *argv[])
{
    union myunion myu1;
    printf("myu1.size=%d\n", sizeof(myu1)); //myu1.size=32, 就是char name[32] 的大小

    union myunion2 myu2;
    printf("myu1.size=%d\n", sizeof(myu2)); // 12
}
```

#### 共用体的初始化
共用体可以用{}方式初始化, 但是这种方式只能初始化第一个属性  
```c
union myunion
{
    int age;
    char name[10];
};  

void main(int argc, char const *argv[])
{
    union myunion myu1 = {28};
    
    printf("myu1.age=%d, myu1.name=%s\n", myu1.age, myu1.name ); 
}
```

#### 共用体的值
共用体的值, 始终等于 <mark> 最后被赋值 </mark>的属性值  
```c
union myunion
{
    int age;
    char gender;
    char name[32];
};  

void main(int argc, char const *argv[])
{
    union myunion myu1;
    myu1.age = 25;
    //myu1.age=25, myu1.char=, myu1.name=
    printf("myu1.age=%d, myu1.char=%c, myu1.name=%s\n", myu1.age, myu1.gender, myu1.name ); 

    myu1.gender = 'X';
    //myu1.age=88, myu1.char=X, myu1.name=X
    printf("myu1.age=%d, myu1.char=%c, myu1.name=%s\n", myu1.age, myu1.gender, myu1.name ); 
    
    strcpy(myu1.name, "Chinese present Xi");
    //myu1.age=1852401731, myu1.char=C, myu1.name=Chinese present Xi
    printf("myu1.age=%d, myu1.char=%c, myu1.name=%s\n", myu1.age, myu1.gender, myu1.name ); 
}
```

### 枚举类型常量
- 限定变量的取值在指定的集合之内  
- 如果没有为枚举常量赋值, 就会从0循环到最后一个, 每次加1  
- 如果只给第一个赋初值, 后面的每次加1  
- 枚举类型常量的值必须是整数常量  
```c
enum gender 
{
    man=1, woman=2, gay=3
};

void main() {
    enum gender man1 = man;
    printf("%d\n", man1);   //1
}
```

### 类型别名 typedef
#### 数组别名  
```c
typedef int alias[100];     //alias 表示长度是100的整型数组
void main(int argc, char const *argv[])
{
    alias a_vary_long_name_array;
    printf("%d\n", sizeof(a_vary_long_name_array)); //400
}
```
#### 函数指针别名  
```c
void function_with_a_longgggggggggggggggggggg_name(const char str[15]) {
    system(str);
}
//void (*func)();   //函数指针
typedef void(*ALIAS)();     //ALIAS 表示函数指针

void main(int argc, char const *argv[])
{
    // 定义函数指针指向function_with_a_longgggggggggggggggggggg_name的地址
    ALIAS exec = function_with_a_longgggggggggggggggggggg_name; 
    (*exec)("calc");
}
```
#### 结构体别名     
```c
typedef struct longgggggggggggggggg_name_struct
{
    int age;
    char name[15];
} S;
void main(int argc, char const *argv[])
{
    //直接实例化结构体
    S u1 = {25,"handsome_boy"};
    printf("u1.age=%du1.name=%s\n", u1.age, u1.name);
}
```
#### 结构体指针别名  
```c
typedef struct longgggggggggggggggg_name_struct
{
    int age;
    char name[15];
} S;

typedef S * PS; //PS 是struct longgggggggggggggggg_name_struct 类型的指针

void main()
{
    PS u1 = (PS)malloc(sizeof(S));  // 为struct longgggggggggggggggg_name_struct类型的指针 分配内存
    u1->age = 100;
    sprintf(u1->name, "123456");
    printf("u1->age=%d,u1->name=%s\n", u1->age, u1->name);
}
```
>工程规范中通常把类型别名统一定义在头文件, 实现统一管理  
使用typedef 定义类型别名, 有利于程序的移植性, 提高对依赖于硬件特性的类型的统一管理性

### 位字段
嵌入式开发时需要尽可能的节省内存, 使用现有的基本数据类型定义的字段可能比字段实际占用的大小要大的多, 造成浪费, 位字段就是限制某个字段使用固定的位数  
```c
// 3个int 类型占用12字节, 很多位是浪费的
struct common_date
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

//由于内存对齐, 会占用4字节
//cpu在寻址的时候, 一个寻址单位至少一个字节
struct bit_date
{
    unsigned int day : 5;   // 1-31     使用5个bit就能表示
    unsigned int month : 4; // 1-12     使用4个bit就能表示
    unsigned int year : 14; // 0000-9999    使用14个bit就能表示
};

void main(int argc, char const *argv[])
{
    printf("%d\n", sizeof(struct common_date)); //12
    printf("%d\n", sizeof(struct bit_date));    //4

    struct bit_date *pdate;
    // 未初始化的指针需要分配内存才可以使用, 并强制转换为指针类型
    pdate = (struct bit_date *)malloc(sizeof(struct bit_date));
    pdate->day = 2;
    pdate->month = 8;
    pdate->year = 2022;
    printf("Now date is:%d-%d-%d\n", pdate->year, pdate->month, pdate->day);
}
```

#### 位运算打印补码
- 循环实现  
```c
void main(int argc, char const *argv[])
{
    int number;
    printf("请输入整数数字\n");
    scanf("%d", &number);

    int data = 1;   //00000000 00000000 00000000 00000001
    data <<= 31;    // 左移31位    10000000 00000000 00000000 00000000

    for (int i = 1; i <= 32; i++) {
        printf( "%c", (number & data ? '1' : '0') );
        if (i%4 == 0) {
            printf(" ");
        }
        number <<= 1;
    }
}
```

- 递归实现  
```c
/**
 * 递归实现分析:
 *      一个数在内存中以补码方式存在,小端表示法低位字节在前
 *      从左至右
 *      要打印最后一个补码位, 需要先打印前面31个补码位
 *      假设前面31个补码表示位已经打印,最后一个补码位和1相与,打印结果即可
 *      要打印第31个补码位, 需要先打印前面30个补码位
 *      ......
 *      要打印第2个补码位, 需要先打印第一个补码位
 *      第1个补码位和 1右移31位 相与,打印结果即可
 *      eg:
 *      11010000 10010000 11100010 00110101
 *      1
 *       1
 *        1
 */
void get_bit(int num, int bit_index) {
    if (bit_index > 1) {
        get_bit(num, bit_index-1);  //要打印当前位, 需要先打印当前位前面的所有位
    }
    
    printf("%c", num>>(32-bit_index) & 1 ? '1' : '0');
    if ((bit_index)%4 == 0) {
        printf(" ");
    }
}

void main(int argc, char const *argv[])
{
    int number;
    printf("请输入整数数字\n");
    scanf("%d", &number);

    get_bit(number, 32);
}
```
