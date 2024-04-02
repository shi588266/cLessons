/*
10.编写一个声明，允许根据下面的格式方便地访问一个浮点值的单独部分。
符号位 1 位
指数位 7 位
小数位 24 位
*/
struct FLT {
    unsigned sign:1;
    unsigned exponent:7;
    unsigned fraction:24;
};