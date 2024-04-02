/**
 * 结构数组  
    程序创建了一个内含100个结构变量的数组。由于该数组是自动存储类别的对象，其中的信息被储存在栈(stack)中。
    如此大的数组需要很大一块内存，这可能会导致一些问题。如果在运行时出现错误，可能抱怨栈大小或栈溢出，
    你的编译器可能使用了一个默认大小的栈，这个栈对于该例而言太小。
    要修正这个问题，可以使用编译器选项设置栈大小为10000，以容纳这个结构数组;或者可以创建静态或外部数组(这样，编译器就不会把数组放在栈中);
    而是放在静态存储区
    或者可以减小数组大小为16。为何不一开始就使用较小的数组?这是为了让读者意识到栈大小的潜在问题，以便今后再遇到类似的问题，可以自已处理好
    
    
  Borland C和浮点数
    如果程序不使用浮点数，旧式的BorlandC编译器会尝试使用小版本的scanf()来压缩程序。
    然而，如果在一个结构数组中只有一个浮点值(如本程序中那样)，
    那么这种编译器(DOS的BorlandC/C++ 3.1之前的版本，不是Borland C/C++ 4.0) 就无法发现它存在。
    结果，编译器会生成如下消息:
        scanf : floating point formats not linked
        Abnormal program termination
    一种解决方案是，在程序中添加下面的代码:
        #include <math.h>
        double dummy = sin(0.0);
    这段代码强制编译器载入浮点版本的scanf()
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_LEN 61    //用于存储标题,长度比标题最大长度多1
#define AUTHOR_LEN 31    //用于存储作者,长度比作者名最大长度多1
#define MAXBKS 100

char *s_gets(char *str, int len);

//先定义结构布局
struct book {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    double price;
};
//结构布局定义结束

int main(void)
{
    // 结构数组的每个元素都是一个结构布局
    struct book library[MAXBKS];
    int count=0,index;
    
    puts("Please enter the book title.");
    puts("Press [enter] at the start of a line to stop.");
    /**
     * 使用s_gets()获取用户输入
     * 如果读取到换行符会被转化为空字符,这被认为是用户要结束输入的意思
     */
    while (count < MAXBKS && s_gets(library[count].title, TITLE_LEN) && library[count].title[0] != '\0' ) {
        puts("Please enter the book author.");
        s_gets(library[count].author, AUTHOR_LEN);    //不做空白验证
        
        puts("Please enter the book price.");
        /**
         * 数组一旦声明就生效
         * 所以只要下标在数组合法的范围内就能直接通过下标访问数组
         * scanf()遇到空格或换行就停止读取, 例如:输入 3.14[enter], 会被识别为3.14\n
         * scanf()只读取 3,.,1,4, \n会被忽略,继续留在输入缓冲区
         * 为避免下次循环读取到不想要的换行符, 需要处理一下
         */
        scanf("%f", &(library[count].price));
        while (getchar() != '\n') {
            continue;
        }
        count++;
        // 数组元素未填满则继续
        if ( count < MAXBKS ) {
            puts("Please enter the next book title.");
        }
    }
    
    // 获取数组内容
    if ( count > 0 ) {
        for (index = 0; index < MAXBKS; index++ ) {
            printf("%s by %s: $%.2f.\n", library[index].title, library[index].author, library[index].price);
        }
    } else {
        puts("No book? That's too bad.");
    }
    
    return 0;
}

char * s_gets(char *str, int len) {
    char *res = fgets(str, len, stdin);
    char *find;
    if (res) {
        if (find = strchr(res, '\n')) 
            *find = '\0';
        else {
            while (getchar() != '\n')
                continue;
        }
    }
    return res;
}