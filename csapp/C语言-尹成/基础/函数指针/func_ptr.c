#include<stdio.h>
int add(int num1, int num2)
{
    return num1+num2;
}
int getMax(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}
int getMin(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

int doOpt(int num1, int num2, int (*p)(int, int))
{
    return p(num1, num2);
}
void main() {
    printf("请输入要执行的操作:1获取两个数之和,2获取较大的数,3获取较小的数\n");
    int opt;
    scanf("%d", &opt);
    // 传递不同的函数地址,调用不同的函数
    switch (opt){
    	case 1:
    		printf("%d\n", doOpt(10, 20, add));
 			break;
 		case 2:
 			printf("%d\n", doOpt(10, 20, getMax));
 			break;
 		case 3:
 			printf("%d\n", doOpt(10, 20, getMin));
 			break;
    }
}