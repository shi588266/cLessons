#include<stdio.h>
#include<stdlib.h>

/**
 * 天梯问题:
 * 现有一个天梯,向上爬的时候每次可一个阶梯或两个阶梯, 问要爬到第50层总公共有多少种爬法可能
 * 分析:
 * 		爬到第50层有两种可能:1.从第48层爬两个阶梯到第50层;2.从第49层爬一个阶梯到第50层
 * 		问题转化为求出要爬到第48层和要爬到第49层的爬法数
 * 		爬到第 49 层有两种可能:1.从第 48 层爬两个阶梯到第 49 层;2.从第 48 层爬一个阶梯到第 49 层
 * 		爬到第 48 层有两种可能:1.从第 46 层爬两个阶梯到第 48 层;2.从第 47 层爬一个阶梯到第 48 层
 * 		以此类推
 * 		爬到第 4 层有两种可能:1.从第 2 层爬两个阶梯到第 4 层;2.从第 3 层爬一个阶梯到第 4 层
 * 		爬到第 3 层有两种可能:1.从第 1 层爬两个阶梯到第 3 层;2.从第 2 层爬一个阶梯到第 3 层
 */
double climb_number (int level) {
	if (level==1)
	{
		return 1.0;
	} else if (level==2)
	{
		return 2.0;
	} else {
		return climb_number(level - 2) + climb_number(level - 1);
	}
}

int main() {
	int level;
	printf("请输入层数, 建议不超过50\n");
	scanf("%d", &level);
	if (level == 0)
	{

		printf("请输入大于0的数");
	}
	double number;
	number = climb_number(level);
	printf("爬到%d层共有%f种爬法\n", level, number);
	return 1;
}
