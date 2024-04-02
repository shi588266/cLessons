/*
4.编写一组函数，实现位数组。函数的原型如下：
每个函数的第1个参数是个字符数组，用于实际存储所有的位。第2个参数用于标识需要访问的位。函数的调用者必须确保这个值不要太大，以免超出数组的边界。
第1个函数把指定的位设置为1，
第2个函数则把指定的位清零。
如果value的值为0，第3个函数把指定的位清0，否则设置为1。
至于最后一个函数，如果参数中指定的位不是0，函数就返回真，否则返回假。
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 128

void set_bit(char [], unsigned);
void clear_bit(char [], unsigned);
void assign_bit(char [], unsigned, int);
int test_bit(char [], unsigned);


int main(void)
{
    int bit_pos;
    if (bit_pos >= MAXLEN) {
        printf("out of boundry exception");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}

void set_bit(char bit_array[], unsigned bit_number)
{
    bit_array[bit_number] = '1';
}

void clear_bit(char bit_array[], unsigned bit_number)
{
    bit_array[bit_number] = '0';
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
    bit_array[bit_number] = value == '0' ? '0' : '1';
}

int test_bit(char bit_array[], unsigned bit_number)
{
    return bit_array[bit_number] == '0' ? '0' : '1';
}