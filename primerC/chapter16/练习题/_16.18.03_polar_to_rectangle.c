/**
极坐标用向量的模（即向量的长度）和向量相对x轴逆时针旋转的角度来描述该向量。
直角坐标用向量的x轴和y轴的坐标来描述该向量
编写一个程序，读取向量的模和角度（单位：度），然后显示x轴和y轴的坐标,
需要一个函数来完成转换，该函数接受一个包含极坐标的结构，并返回一个包含直角坐标的结构（或返回指向该结构的指针）
x = r*cos A 
y = r*sin A
 */
#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define ANG_2_RAD PI/180

//定义结构体
struct POLAR_V
{
    double length;
    double angle;   //角度
};

struct RECTANGLE_V
{
    double x;
    double y;
};
//定义函数原型
struct RECTANGLE_V trans(const struct POLAR_V *);

int main(void)
{
    double A,r,x,y;
    struct POLAR_V pv;
    struct RECTANGLE_V rv;
    puts("Enter tow double numbers,you may input a space to seperate them, (q to quit).");
    while (scanf("%lf %lf", &A, &r) == 2) {
        pv.angle = A;
        pv.length = r;
        rv = trans(&pv);
        printf("x=%lf and y=%lf\n\n", rv.x, rv.y);
        puts("Enter tow double numbers,you may input a space to seperate them, (q to quit).");
    }
    puts("done!");
    return 0;
}

struct RECTANGLE_V trans(const struct POLAR_V *pv)
{
    struct RECTANGLE_V rv;
    double radius = (pv->angle) * ANG_2_RAD;    //把角度转换为弧度
    rv.x = pv->length*cos(radius);
    rv.y = pv->length*sin(radius);
    return rv;
}