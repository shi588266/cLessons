/**
6.修改rearrange程序，去除输入中列标号的个数必须是偶数的限制。
如果读入的列标号为奇数个，函数就会把最后一个列范围设置为最后一个列标号所指定的列到行尾之间的范围。
从最后一个列标号直至行尾的所有字符都将被复制到输出字符串。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0
#define MAX_COL 100     /*处理的最大列号*/
#define MAX_INPUT 1000  /*输入行最大长度*/

void rearrange(char *output, char const *input, int nColumns, int const columns[]);

/*读取列标号参数列表,并返回参数列表个数*/
int readColumnNumbers(int columns[], int max);

int main(void)
{
    int columnsParamsNumber;  /*进行处理的列标号*/
    int columns[MAX_COL] = {0};  /*需要处理的列参数列表, 初始化为全0*/
    char input[MAX_INPUT];  /*输入行数组*/
    char output[MAX_INPUT];  /*输出行数组*/
    
    /*读取列标号*/
    columnsParamsNumber = readColumnNumbers(columns, MAX_COL);
    #if DEBUG
    printf("columnsParamsNumber = %d\n", columnsParamsNumber);
    for (int i = 0; i < MAX_COL; i++) {
        printf("columns[%d] = %d\n", i, columns[i]);
    }
    return 0;
    #endif
    
    /*读取打印剩余的输入行*/
    while (gets(input) != NULL) {
        printf("Orignal input: %s\n", input);
        rearrange(output, input, columnsParamsNumber, columns);
        printf("Rearranged line: %s\n", output);
    }
}

/*读取列标号参数列表,并返回参数列表个数*/
int readColumnNumbers(int columns[], int max)
{
    int num = 0;/*读取到的列参数个数*/
    int ch;
    
    /*从输入中读取列参数列表, 如果读取到 负数 结束读取*/
    while (num < max && (scanf("%d", &columns[num]) == 1) && columns[num] >= 0) {
        num++;
    }
    
    /*列参数必须有起始有截至,成对出现*/
    /*if (num % 2 != 0) {
        puts("The last column No is not paired.");
        exit(EXIT_FAILURE);
    }*/
    
    /*丢弃输入行最后一个负数值和后面剩余的部分*/
    while( (ch = getchar()) != EOF && ch != '\n' ) {
        continue;
    }
    
    return num;
}

/*处理输入行, 将指定的列的字符连接在一起, 输出行以 NUL 结尾*/
void rearrange(char *output, char const *input, int nColumns, int const columns[])
{
    int outputColumn = 0;/*输出列计数器*/
    int inputLength = strlen(input);
    
    /*成对儿处理起始字符和结束字符*/
    for (int i = 0; i < nColumns; i+=2) {
        //获取要拷贝的字符数
        int nChars;
        /*当前处理列的下一个参数为负数, 表明是列号数目是奇数, 当前处理列是最后一个列号*/
        if (columns[i+1] < 0) {
            if (inputLength > columns[i])
                nChars = inputLength - columns[i];
            else 
                break;
        } else {
            nChars = columns[i+1] - columns[i] + 1;
        }

        /*如果输出行已满就结束*/
        if (outputColumn >= MAX_INPUT - 1) {
            break;
        }
        /*如果输出行空间不足, 只复制可以容纳的部分*/
        if (outputColumn + nChars > MAX_INPUT - 1) {
            nChars = MAX_INPUT - 1 - outputColumn;
        }
        
        //执行字符串拷贝
        strncpy(output + outputColumn, input + columns[i], nChars);
        //输出行计数器步进
        outputColumn += nChars;
    }
    
    //输出行以 NUL 结尾
    output[outputColumn] = '\0';
}