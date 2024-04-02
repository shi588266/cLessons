#include <stdio.h>

struct {
    int a:2;
} x;

x.a = 1;
printf("x.a=%d\n", x.a);
x.a += 1;
printf("x.a=%d\n", x.a);