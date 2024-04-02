/**
 * 3.设计一个结构模板储存一个月份名、该月份名的3个字母缩写、该月的天数以及月份号
 */
#include <stdio.h>
#include <stlib.h>

#define MON_NAME_LEN 15

struct month {
    char name[MON_NAME_LEN];
    char abbrev[4];
    unsigned short days;
    unsigned short index;
};

int main(void)
{
    //4.定义一个数组，内含12个结构（第3题的结构类型）并初始化为一个年份（非闰年）
    struct month normal_year[12] = {
        {
            "January",
            "Jan",
            31,
            1
        },
        {
            "February",
            "Feb",
            29,
            2
        },
        {
            "March",
            "Mar",
            31,
            3
        },
        {
            "April",
            "Apr",
            30,
            4
        },
        {
            "May",
            "May",
            31,
            5
        },
        {
            "June",
            "Jun",
            30,
            6
        },
        {
            "July",
            "Jul",
            31,
            7
        },
        {
            "August",
            "Aug",
            31,
            8
        },
        {
            "September",
            "Sep",
            30,
            9
        },
        {
            "October",
            "Oct",
            31,
            10
        },
        {
            "November",
            "Nov",
            30,
            11
        },
        {
            "December",
            "Dec",
            31,
            12
        },
    };
    
    return 0;
}

/**
* 5.编写一个函数，用户提供月份号，该函数就返回一年中到该月为止（包括该月）的总天数。
* 假设在所有函数的外部声明了第3题的结构模版和一个该类型结构的数组。
*/
int get_days(int month_no) {
    int i;
    int total = 0;
    for ( i = 1; i <= month_no; i++) {
        total += normal_year[i].days;
    }
    
    return i;
}


