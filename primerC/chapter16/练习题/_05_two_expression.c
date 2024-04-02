/**
 * 
 */
#include <stdio.h>

#define EXP(X,Y) printf(#X " is %d and " #Y " is %d\n", X, Y)

int main(void)
{
    EXP(3+4, 4*12);
}