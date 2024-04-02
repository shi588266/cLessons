#include <stdio.h>
#include <stlib.h>

#define MON_NAME_LEN 15

typedef struct lens {
    float foclen;   /*焦距*/
    float fstop;    /*孔径*/
    char brand[30]; /*品牌名称*/
} LENS;

LENS lens_arr_10[10];
//单独给成员赋值
lens_arr_10[2].foclen = 500; 
lens_arr_10[2].fstop =  2.50; 
lens_arr_10[2].brand = "Remarkata"; 


LENS lens_arr_10[10] = {
    [2] = {500, 2.50, "Remarkata"}
};