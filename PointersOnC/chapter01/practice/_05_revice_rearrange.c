/**
修改rearrange 函数
        if (columns[i] >= inputLength || outputColumn >= MAX_INPUT - 1) {
            break;
        }
这条语句只有当列范围以递增顺序出现时才是正确的，但事实上并不一定如此。请修改这条语句，即使列范围不是按顺序读取时，也能正确完成任务。
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
    int columns[MAX_COL];  /*需要处理的列参数列表*/
    char input[MAX_INPUT];  /*输入行数组*/
    char output[MAX_INPUT];  /*输出行数组*/
    
    /*读取列标号*/
    columnsParamsNumber = readColumnNumbers(columns, MAX_COL);
    //printf("columnsParamsNumber = %d\n", columnsParamsNumber);
    #ifdef DEBUG
    for (int i = 0; i < columnsParamsNumber; i++) {
        printf("columns[%d] = %d\n", i, columns[i]);
    }
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
    if (num % 2 != 0) {
        puts("The last column No is not paired.");
        exit(EXIT_FAILURE);
    }
    
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
        int nChars = columns[i+1] - columns[i] + 1;
        /*如果输入行结束*/
        if (columns[i] >= inputLength) {
            continue;
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