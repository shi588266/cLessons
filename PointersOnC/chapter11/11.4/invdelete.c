/*
一个用于销毁存货记录的函数。这个函数适用于两种类型的存货记录。它使用一条switch语句判断传递给它的记录的类型，并释放动态分配给这个记录的所有字段的内存。
*/
#include <stdlib.h>
#include "inventor.h"

void discard_inventor_record(Invrec *record)
{
    switch (record->type) {
        case PART:
            free(record->info.part);
            break;
        
        case SUBASSY:
            free(record->info.subassy->part);   //先释放记录成员内部分配的内存
            free(record->info.subassy); //再释放分配给记录成员的内存
            break;
    }
    // 删除记录主体部分
    free(record);
}