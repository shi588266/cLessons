/*
需要编写一个程序，为美元数额的打印提供这个功能。函数将把一个数字字符串（代表以美分为单位的金额）转换为美元形式
                void dollars( char *dest, char const *src );
src将指向需要被格式化的字符（可以假定它们都是数字）。函数应该像上面例子所示的那样对字符进行格式化，并把结果字符串保存到dest中。应该保证所创建的字符串以一个NUL字节结尾。src的值不应被修改。应该使用指针而不是下标。
提示：首先找到第2个参数字符串的长度。这个值有助于判断逗号应插入到什么位置。同时，小数点和最后两位数字应该是唯一需要处理的特殊情况。
*/
#include <stdio.h>
#include <string.h>
#define MAX_LEN 20

void dollars( char *dest, char const *src )
{
    if (dest == NULL || src == NULL) return; 
    //字符串的长度
    unsigned int len = strlen(src);
    // 长度减去 2 的结果, 除以 3 的商和余数
    int entire, remain;
    if (len == 0) {
        dest = "$0.00";
    }
    else if (len == 1) {
        strcat(strcat(dest, "$0.0"), src);
    }
    else if (len == 2) {
        strcat(strcat(dest, "$0."), src);
    }
    else {
        entire = (len - 2) / 3;
        remain = (len - 2) % 3;
        int idx = 0;
        *dest++ = '$';
        while (*src) {
            //每3位用逗号分隔
            if (idx > 0 && idx%3 == remain) {
                // 最后两个用 点号
                if (len - idx == 2) {
                    *dest++ = '.';
                } else {
                    *dest++ = ',';
                }
            }
            *dest++ = *src++;
            idx++;
        }
        *dest = '\0';   // NUL 字节结尾
    }
}



int main(void)
{
    char src[MAX_LEN] = "12345678";
    char dest[MAX_LEN] = "";
    
    dollars(dest, src);
    printf("dest = %s\n", dest);
}